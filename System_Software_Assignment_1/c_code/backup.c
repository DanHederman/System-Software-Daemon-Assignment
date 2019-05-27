#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int pid = fork();

    char *cmdrsync = "rsync";
    char *args1[]={cmdrsync, "-avrt", "--delete", "/var/www/c15410232.com/html/dev/.", "/var/www/c15410232.com/html/live/", NULL};

    if(pid == -1){
        perror("Error: creating fork in rsync.h");
    }

    else if(pid == 0)
    {
        execvp(cmdrsync, args1);
        exit(1);
    }
    return 0;
}
