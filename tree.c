#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

typedef struct __node{
    struct _node *left, *right;
    int value;
} node;

typedef struct _tree{
    node *root;
    int size;
} tree;

Node newNode(int v){
    node *n = malloc(sizeof(node));
    n->value = v;
    n->left = NULL;
    n->right = NULL;
    return n;
}

Tree newTree(){
    tree *t = malloc(sizeof(tree));
    t->size = 0;
    t->root = NULL;
    return t;
}

void freeNode(Node nd){
    node *n = nd;
    free(n);
}

void freeTree(Tree tr){
    tree *t = tr;
    free(t);
}