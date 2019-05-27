#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int runpermlock()
{
    char *cmdcp = "sh";
    char *args[]={"sh", "/home/dan/Desktop/Assignment1/bash_code/lock.sh", NULL};

    int pid = fork();

    if(pid == -1)
    {
        perror("Error: creating fork in lockpermissions.h");
    }
    else if(pid == 0)
    {
        execvp(cmdcp, args);
        exit(1);
    }
    return 0;
}