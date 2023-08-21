#include <stdio.h>
#include <stdlib.h>

typedef struct TREE {
    int value;
    struct TREE *left_ptr;
    struct TREE *right_ptr;
} tree;

void insert(tree **root, int value) {
    if (!*root) {
        *root = (tree *)malloc(sizeof(tree));
        (*root)->value = value;
        (*root)->left_ptr = NULL;
        (*root)->right_ptr = NULL;
    }
    else if ((*root)->value > value)
        insert(&(*root)->left_ptr, value);
    else 
        insert(&(*root)->right_ptr, value);
}

void print_tree(tree *root) {
    if (!root)
        return;
    print_tree(root->left_ptr);
    printf("%d ", root->value);
    print_tree(root->right_ptr);
}

tree* search(tree *root, int value) {
    tree *index_ptr = root;
    while (index_ptr)
    {
        if (index_ptr->value == value)
            return index_ptr;
        else if (index_ptr->value > value) 
            index_ptr = index_ptr->left_ptr;
        else 
            index_ptr = index_ptr->right_ptr;
    }

    return NULL;
}

void del(tree *root, int value) {
    
}

int main() {
    tree *a = NULL;
    insert(&a, 2);
    insert(&a, 1);
    insert(&a, 3);
    print_tree(a);
    printf("\n");

    insert(&a, 8);
    print_tree(a);
    printf("\n");

    tree *b = search(a, 8);
    if (b)
        printf("find %d\n", b->value);

    return 0;
}