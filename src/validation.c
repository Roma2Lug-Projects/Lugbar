#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int check_fileitem(){
    
    char* fullpath = "/etc/lugbar/item.txt";
        
    FILE *file;
    
    if ((file = fopen(fullpath, "r")) == NULL) {
        if (errno == ENOENT) {
            return -1;
        }
    }
    
    fclose(file);
    return 1;
}
    
int check_msmtp(){
    if (system("which msmtp > /dev/null 2>&1")){
        return -1;
    }
    return 1;
}

int check_config(){
    char* fullpath = "/etc/msmtprc";
        
    FILE *file;
    
    if ((file = fopen(fullpath, "r")) == NULL) {
        if (errno == ENOENT) {          
            return -1;
        }
    }
    
    fclose(file);
    return 1;
}



int valid(){
    
    if(check_fileitem() == -1) {
        printf("File /etc/lugbar/item.txt assente\n");
        return -1;
    }
    if(check_msmtp() == -1) {
        printf("Programma msmtp non installato\n");
        return -1;
    }
    
    if(check_config() == -1) {
        printf("File in /etc/msmtprc assente\n");
        printf("Esempio file:\n\n"
                "defaults\n"
                "syslog LOG_MAIL\n"
                "auth on\n"
                "tls on\n"
                "aliases /etc/aliases\n"
                "# Example with GMAIL\n"
                "account lugbar\n"
                "host smtp.gmail.com\n"
                "port 465\n"
                "tls on\n"
                "tls_starttls off\n"
                "from \"tuo nome\"\n"
                "user example@gmail.com\n"
                "password \"password\"""\n"
                "set_from_header on\n\n"
                "Se usi Gmail devi generare una password per app https://myaccount.google.com/apppasswords\n");
        return -1;
    }
    
    return 1;
    
}