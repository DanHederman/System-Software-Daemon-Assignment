#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mqueue.h>
#include <syslog.h>

int startMessageQueue(){
    openlog("Message Queue", LOG_PID|LOG_CONS, LOG_USER);
    syslog(LOG_INFO, "Starting Message Q");
    
    
    mqd_t mq;
    struct mq_attr queue_attributes;
    char buffer[1024+1];
    int terminate = 0;

    //Set attributes
    queue_attributes.mq_flags = 0;
    queue_attributes.mq_maxmsg = 10;
    queue_attributes.mq_msgsize = 1024;
    queue_attributes.mq_curmsgs = 0;

    mq = mq_open("/messageQueue", O_CREAT | O_RDONLY, 0644, &queue_attributes);

    do{
        openlog("Message Queue", LOG_PID|LOG_CONS, LOG_USER);
        
        ssize_t bytes_read;

        bytes_read = mq_receive(mq, buffer, 1024, NULL);

        buffer[bytes_read] = '\0';

        if(! strncmp(buffer, "exit", strlen("exit"))){
            syslog(LOG_INFO, "Shutdown");
            terminate = 1;
        }
        else if(strcmp(buffer, "Backup") == 0){
            syslog(LOG_INFO, "Backing up");
            return(1);
        }
        else if(strcmp(buffer, "Update") == 0){
            syslog(LOG_INFO, "Updating");
            return(2);
        }
        
    } while (!terminate);

    mq_close(mq);
    mq_unlink("/messageQueue");

    return 0;
}
