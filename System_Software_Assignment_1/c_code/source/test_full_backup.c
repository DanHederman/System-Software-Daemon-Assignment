#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int main()
{
	char *args[] = {"cp", "-r", "/var/www/c15410232.com/html/live/.", "/var/www/c15410232.com/html/backup", NULL};

    int pid = fork();
    if((pid = fork()) == -1)
    {
        perror("Fork Error backup");
		exit(0);
    }
    else if(pid == 0){
        execvp("/bin/cp", args);
        exit(0);
    }
    else
    {
        perror("Parent code backup");
		exit(0);
    }
}
