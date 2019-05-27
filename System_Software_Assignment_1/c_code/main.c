#include <stdio.h>
#include "rsync.h"
#include <time.h>

int main()
{
    system("rsync -avrt --delete /var/www/c15410232.com/html/dev/. /var/www/c15410232.com/html/live/");
}
