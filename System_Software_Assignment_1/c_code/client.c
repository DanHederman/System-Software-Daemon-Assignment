#include <stdio.h>
#include <string.h>
#include <mqueue.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    mqd_t mq;
    char buffer[1024];

    //Open message q
    mq = mq_open("/messageQueue", O_WRONLY);

    fflush(stdout);
    memset(buffer,0,1024);        
    strcpy(buffer,argv[1]);
    mq_send(mq,buffer,1024,0);

    printf("%s", buffer);

    mq_close(mq);

    return 0;

}