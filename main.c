/*
Exercício
Implemente um programa em C que tenhas as operações de criação, inclusão, remoção e busca em
uma árvore binária. O dado do nó da árvore deve ser um número inteiro.
O trabalho deve ser apresentado na terça-feira dia 10 na sala do professor Marcelo. A apresentação é
individual. Horário: 10h – 12h / 14h-16h
*/
#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria.h"

int main ()
{
    BinaryTree* root = binary_tree_create ();

    int x = 0, y = 0;
    int a = 50, b = 25;

    x = binary_tree_insert (root, 30);
    printf (":%d:\n", x);
    x = binary_tree_insert (root, 10);
    printf (":%d:\n", x);
    x = binary_tree_insert (root, 50);
    printf (":%d:\n", x);
    x = binary_tree_insert (root, 40);
    x = binary_tree_insert (root, 60);
    struct node *no = *root;
    binary_tree_remove (root, 50);
    printf (":%d:\n", x);
    x = binary_tree_insert (root, b);
    printf (":%d:\n", x);

    printf ("-------------------\n");

    y = binary_tree_search (root, a);
    printf ("encontrou o %d? :%d:\n", a, y);

    binary_tree_remove (root, a);

    printf ("\nEu removi o %d.\n", a);

    y = binary_tree_search (root, a);
    printf ("\nencontrou o %d? :%d:\n", a, y);
    y = binary_tree_search (root, b);
    printf ("encontrou o %d? :%d:\n", b, y);

    return 0;
}
