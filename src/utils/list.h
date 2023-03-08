struct node {
    int pos;
    char item_name[32];
    struct node* next;
};


struct head_node {
    int count;
    struct node* next;
};


void insert_node(struct head_node **head, char *item);
struct head_node *create_list();
char *lookup_list(struct node **first_node, int p);

