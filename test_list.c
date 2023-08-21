#include <stdio.h>
#include <stdlib.h>


typedef struct NODE
{
    struct Node *pre;
    struct Node *next;
    int value;
} Node;

void print_list(Node **root)
{
    Node **index = root;
    while (index && *index) {
        printf("%d ",(*index)->value);
        (*index) = (*index)->next;
    }
    printf("\n");
}

int single_list_insert(Node **root, int value) 
{
    Node *pre_ptr = NULL;
    Node *cur_ptr = *root;

    while (cur_ptr && cur_ptr->value < value)
    {
        pre_ptr = cur_ptr;
        cur_ptr = cur_ptr->next;
    }
    
    Node *node = (Node *)malloc(sizeof(Node));
    if (!node)
        return 0;
    node->value = value;
    node->next = cur_ptr;

    if (!pre_ptr)
        *root = node;
    else 
        pre_ptr->next = node;
    return 1;
}

int single_list_insert_v2(Node **linkp, int value) 
{
    Node *cur_ptr = NULL;

    while ((cur_ptr = *linkp) != NULL && cur_ptr->value < value)
        linkp = &cur_ptr->next;
    
    Node *node = (Node *)malloc(sizeof(Node));
    if (!node)
        return 0;
    node->value = value;
    node->next = cur_ptr;

    *linkp = node;
    node->next = cur_ptr;
    return 1;
}

int double_list_insert(Node *root_ptr, int value)
{
    
}


int main() 
{
    Node **root = (Node **)malloc(sizeof(Node *));
    single_list_insert_v2(root, 1);
    single_list_insert_v2(root, 5);
    single_list_insert_v2(root, 12);
    print_list(root);

    return 0;
}