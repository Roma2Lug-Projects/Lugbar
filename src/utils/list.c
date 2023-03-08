#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"


char *lookup_list(struct node **first_node, int p)
{
        struct node *cursor;
        cursor = *first_node;
        
        while(cursor) {
                if(cursor->pos != p)
                        cursor = cursor->next;
                else
                        return cursor->item_name;
        }

        return NULL;
}


struct head_node *create_list()
{    
        struct head_node *temp;
        
        temp = malloc(sizeof(struct head_node));
        temp->count = 0;
        temp->next = NULL;
        
        return temp;
}


void insert_node(struct head_node **head, char *item)
{    
        struct node *temp = malloc(sizeof(struct node));
        strcpy(temp->item_name, item);
        temp->next=NULL;
        int i = 1;
        
        if((*head)->next == NULL) {
                (*head)->next = temp;
                (*head)->count = 1;
        } else {
                struct node *current;
                current = (*head)->next;

                while(current->next!=NULL) {
                    i++;
                    current=current->next;
                }

                temp->pos = i;
                current->next=temp;
                (*head)->count = ((*head)->count) + 1;
        }
}