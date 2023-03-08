#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils/list.h"

struct head_node *loadfile(){
    
    char const* const file_name = "/etc/lugbar/item.txt";
    FILE* file = fopen(file_name, "r");
    char line[32];
    
    struct head_node *item_list = create_list();
    
    while (fgets(line, sizeof(line), file)) {
        
        insert_node(&item_list, line);
    }

    fclose(file);

    return item_list;
}