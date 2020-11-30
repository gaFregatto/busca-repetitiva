#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

typedef struct _nodeTree{
    Board board;
    List childrens;
    int depth;
    int isMaximazing;
    int isLeaf;
    int result;
} nodeTree;

typedef struct _tree{
    nodeTree *root;
} tree;

nodeTree* newNodeT(int op){
    nodeTree *n = (nodeTree*)malloc(sizeof(nodeTree));
    n->board = createBoard(op);
    n->childrens = newList(showInGame, freeBoard);
    n->depth = 0;

    if(op == 1) n->isMaximazing = 0;
    else n->isMaximazing = 1;

    if(n->board == 9) n->isLeaf = 1;
    else n->isLeaf = 0;

    if(n->isMaximazing)  n->result = -__INT_MAX__;
    else n->result = __INT_MAX__;

    return n;
}

Tree treeGen(int op){
    tree *newT = (tree*)malloc(sizeof(tree));
    newT->root = newNodeT(op);
}