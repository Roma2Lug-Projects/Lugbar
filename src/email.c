#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sendemail(char *item)
{
        char command[100];

        sprintf(command, "printf 'Subject:%s' | msmtp -a lugbar acquisti.roma2lug@gmail.com", item);    

        if(system(command) == -1)
            	perror("Error: ");
}