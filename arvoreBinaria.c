#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria.h" 
//-----------------------------------------------------------------------------------
// node:

struct  node 
{
    struct node* right;
    struct node* left;
    int inf;
};

//-----------------------------------------------------------------------------------
// binary tree create:

BinaryTree* binary_tree_create ()
{
    BinaryTree* root = (BinaryTree*) malloc(sizeof(BinaryTree));
    if (root != NULL) 
    {
        *root = NULL;   // root is a special node there pointer to tree top.
    }
    return root;
}

//-----------------------------------------------------------------------------------
// insert:

int binary_tree_insert (BinaryTree* root, int value)
{
    if (root == NULL)
    {
        return 0;
    }
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    
    if (new_node == NULL)
    {
        return 0;
    }
    new_node->inf = value;
    new_node->right = NULL;
    new_node->left = NULL;

    if (*root == NULL)
    {
        *root = new_node;
    }
    else
    {
        struct node* actual = *root;
        struct node* anterior = NULL;
        
        while (actual != NULL)  // walks to a leaf node.
        {
            anterior = actual;
            if (value == actual->inf)
            {
                free(new_node);
                return 0;       // The element already exists.
            }
            if (value > actual->inf)   
            {
                actual = actual->right;         
            }
            else
            {
                actual = actual->left;
            }
        }

        // 
        if (value > anterior->inf)
        {
            anterior->right = new_node;
        }
        else
        {
            anterior->left = new_node;
        }
    }
    return 1;    
}

//-----------------------------------------------------------------------------------
// remove:

BinaryTree* remove_actual (struct node* actual)
{
    struct node* node1;
    struct node* node2;

    if (actual->left == NULL)   // do not have children in left or do not have children's
    {
        node2 = actual->right;
        free (actual);
        return node2;
    }
    // the actual have 2 children's
    node1 = actual;
    node2 = actual->left;
    while (node2->right != NULL)    
    {
        node1 = node2;
        node2 = node2->right;
    }
    if (node1 != actual)
    {
        node1->right = node2->left;
        node2->left = actual->left; 
    }
    node2->right = actual->right;
    free (actual);
    return node2;    
}

int binary_tree_remove (BinaryTree* root, int value)
{
    if (root == NULL)
    {
        return 0;
    }
    struct node* anterior = NULL;
    struct node* actual = *root;
    while (actual != NULL)
    {
        if (value == actual->inf)
        {
            if (actual->inf == *root)
            {
                *root = remove_actual (actual);
            }
            else
            {
                if (anterior->right == actual)
                {
                    anterior->right = remove_actual (actual);
                }
                else
                {
                    anterior->left = remove_actual (actual);        
                }            
            }
            return 1;
        }
        // if still don't find follow by left or right.
        anterior = actual;
        if (value > actual->inf)
        {
            actual = actual->right;
        }
        else
        {
            actual = actual->left;
        }       
    }
    return 0;    
}

//-----------------------------------------------------------------------------------
// search:

int binary_tree_search (BinaryTree* root, int value)
{
    if (root == NULL)
    {
        return 0;
    }    
    struct node* actual = *root;
    while (actual != NULL)
    {
        if (value == actual->inf)
        {
            return 1;
        }
        else if (value > actual->inf)
        {
            actual = actual->right;
        }
        else
        {
            actual = actual->left;
        }   
    }
    return 0;    
}

//-----------------------------------------------------------------------------------