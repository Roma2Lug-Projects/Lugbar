#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "load_fileitem.h"
#include "email.h"
#include "validation.h"
#include "utils/list.h"

int main(int argc, char **argv)
{
        int i = 0;
        struct head_node *item_list = loadfile();
        struct node *current = item_list->next;
        int max_item = item_list->count;

        if (valid() == -1)
                return 0;

        if(argc == 1) {
                printf("Uso: %s [OPZIONE]...[NUMERO] ...\n\nPer ordinare usa %s [NUMERO]\nOpzioni disponibili:\n--lista\tlista gli elementi col corrispettivo numero di ordinazione\n", argv[0], argv[0]);
                return 0;
        } else if (strcmp(argv[1], "--lista") == 0) {
                while(i++ < max_item){
                    printf("%d. %s\n", i, current->item_name);
                    current = current->next;
                }
                return 0;
        } else if (strcmp(argv[1], "versamento") == 0) {
                if (argc < 3) {
                    printf("Assente l'importo del versamento\n");
                } else {
                    char subject[16];
                    sprintf(subject, "versamento %s", argv[2]);

                    if(!sendemail(subject))
                        printf("Versato %s\n", argv[2]);
                }
        } else if (atoi(argv[1]) > max_item) {
                puts("Acquisto non valido. Usa lugbar -lista per listare gli elementi");
                return 0;
        } else if (atoi(argv[1]) < max_item && atoi(argv[1]) > 0) {
                char *choice_item = lookup_list(&current, atoi(argv[1])-1);
                char subject[16];

                sprintf(subject, "acquisto %s", choice_item);
                if(!sendemail(subject))
                        printf("Acquistato %s\n", choice_item);
        } else {
                printf("Uso: %s [OPZIONE]...[NUMERO] ...\n\nPer ordinare usa %s [NUMERO]\n\nOpzioni disponibili:\n--lista lista gli elementi col corrispettivo numero di ordinazione\n", argv[0], argv[0]);
                return 0;
        }
        
        return 0;
}