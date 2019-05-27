// Orphan Example
// The child process is adopted by init process, when parent process dies.
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <syslog.h>
#include <sys/stat.h>
#include <time.h>
#include <rsync.h>
#include <track.h>
#include <backup.h>

void runscript();


 
int main()
{
   time_t now;
   struct tm newyear;
   struct tm newyear2;
   double seconds;
   double seconds2;
   /* get current time; same as: now = time(NULL) */
   time(&now);  
   newyear = *localtime(&now);
   newyear.tm_hour = 23; 
   newyear.tm_min = 59; 
   newyear.tm_sec = 0;

   newyear2 = *localtime(&now);
   newyear2.tm_hour = 2; 
   newyear2.tm_min = 47; 
   newyear2.tm_sec = 0;

   char *livedir = "/var/www/c15410232/html/live/.";
   char *backupdir = "/var/www/c15410232/html/backup/";
   char *internal = "/var/www/c15410232/html/internal/";
   //newyear.tm_mon = 21;  
   //newyear.tm_mday = 3;

   // Implementation for Singleton Pattern if desired (Only one instance running)

   // Create a child process      
   int pid = fork();
 
   if (pid > 0) {
      // if PID > 0 :: this is the parent
      // this process performs printf and finishes
      printf("Parent process");
      sleep(10);  // uncomment to wait 10 seconds before process ends
      exit(EXIT_SUCCESS);
   } else if (pid == 0) {
      // Step 1: Create the orphan process
      printf("Child process");
       
      // Step 2: Elevate the orphan process to session leader, to loose controlling TTY
      // This command runs the process in a new session
      if (setsid() < 0) { exit(EXIT_FAILURE); }

      // We could fork here again , just to guarantee that the process is not a session leader
      int pid = fork();
      if (pid > 0) {
         exit(EXIT_SUCCESS);
      } else {
       
         // Step 3: call umask() to set the file mode creation mask to 0
         // This will allow the daemon to read and write files 
         // with the permissions/access required 
         umask(0);

         // Step 4: Change the current working dir to root.
         // This will eliminate any issues of running on a mounted drive, 
         // that potentially could be removed etc..
         if (chdir("/") < 0 ) { exit(EXIT_FAILURE); }

         // Step 5: Close all open file descriptors
         /* Close all open file descriptors */
         int x;
         for (x = sysconf(_SC_OPEN_MAX); x>=0; x--)
         {
            close (x);
         } 

         // Signal Handler goes here

         // Log file goes here

         // Orphan Logic goes here!! 
         // Keep process running with infinite loop
         // When the parent finishes after 10 seconds, 
         // the getppid() will return 1 as the parent (init process)
         
         int pid2 = fork();
         if(pid2 == 0){
            runscript();
            exit(0);
         }

         while(1) {
            sleep(1);
            //printf("child 1: my parent is: %i\n", getppid());
            time(&now);
            seconds = difftime(now,mktime(&newyear));
            seconds2 = difftime(now,mktime(&newyear2));
            printf("\n%.f", seconds);
            if (seconds == 0) {
               char *cmddeny = "000";
               //change permissions
               
               //check permissions were changed
               char mode[] = "0000";
	            //char buf[100] = livedir;
               //if();
               int i;
	            i = strtol(mode, 0, 8);

               //if(chmod(buf,i) < 0)
               //{

               //}
               char *cmdcp = "/bin/cp";
               char *args[]={"cp", "-R", "-f", livedir, backupdir, NULL};
               execvp(cmdcp, args);

               //char *paramList[] = {"/bin/chmod", "0644", "livedir", NULL}
               //execvp("chmod", paramList);
	         }
            if(seconds2 == 0){
               char *cmdrsync = "sudo rsync";
               char *args1[]={"sudo rsync", "-avrt", "--delete", "/var/www/c15410232/html/internal/ /var/www/c15410232/html/live/", backupdir, NULL};
               execvp(cmdrsync, args1);
            }
         }
      }

   }
   return 0;
}

void runscript(){
   char *cmdcp = "sh";
   char *args[]={"sh", "/home/dan/Desktop/Assignment1/track.sh", NULL};
   execvp(cmdcp, args);
}