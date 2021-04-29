#include <stdio.h>
#include <stdlib.h>

typedef struct node* BinaryTree;

BinaryTree* binary_tree_create ();
int binary_tree_insert (BinaryTree* root, int value);
//void remove_node (struct node* node);
BinaryTree* remove_actual (struct node* actual);
int binary_tree_remove (BinaryTree* root, int value);
int binary_tree_search (BinaryTree* root, int value);
