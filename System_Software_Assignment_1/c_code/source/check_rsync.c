#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    char *cmdrsync = "sudo rsync";
    char *args1[]={"sudo rsync", "-avrt", "--delete", "/var/www/c15410232.com/html/internal/ /var/www/c15410232.com/html/live/", NULL};

    int pid = fork ();
    if((pid = fork()) == -1){
        perror("Fork error rsync");
        exit(0);
    }
    else if(pid == 0){

        execvp(cmdrsync, args1);
        exit(0);
    }
    else{
        perror("Parent code check_rsync");
        exit(0);
    }
}