#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int runbackup()
{
    char *cmdcp = "cp";
    char *args[] = {"cp", "-R", "-f", "/var/www/c15410232.com/html/live/.", "/var/www/c15410232.com/html/backup/", NULL};

    int pid = fork();

    if(pid == -1)
    {
        perror("Error: creating fork in backup.h");
    }
    else if(pid == 0)
    {
        execvp(cmdcp, args);
        exit(1);
    }
    return 0;
}
