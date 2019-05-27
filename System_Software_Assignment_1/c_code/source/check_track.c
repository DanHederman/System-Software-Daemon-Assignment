#include <stdio.h>
#include <stdlib.h>

void runscript()
{
    char *cmdcp = "sh";
    char *args[]={"sh", "/home/dan/Desktop/Assignment1/bash_code/track.sh", NULL};
  
    execvp(cmdcp, args);
}