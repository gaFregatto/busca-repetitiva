#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct _nodeList{
    Item item;
    struct _nodeList *previous, * next;
} nodeList;

typedef struct _list{
    nodeList *head, *tail;
    fr printItem, freeItem;
    int size;
} list;

int isEmpty(List lt){
    list *l = lt;
    if(l->head == NULL && l->tail == NULL)  return 1;
    else return 0;
}

nodeList *newNodeList(Item item){
    nodeList *n = (nodeList*)malloc(sizeof(nodeList));
    n->item = item;
    n->previous = NULL;
    n->next = NULL;
    return n;
}

List newList(fr printItem, fr freeItem){
    list *newList = (list*)malloc(sizeof(list));
    newList->head = NULL;
    newList->tail = NULL;
    newList->freeItem = freeItem;
    newList->printItem = printItem;
    newList->size = 0;
    return newList;
}

Item getItem(List lt, Posic p){
    list *l = lt;
    nodeList *n = p;
    if (isEmpty(l))
        return NULL;
    else
        return n->item;
}

Posic getNext(List lt, Posic p){
    list *l = lt;
    nodeList *n = p;
    if (isEmpty(l))
        return NULL;
    else
        return n->next;
}

Posic getPrevious(List lt, Posic p){
    list *l = lt;
    nodeList *n = p;
    if (isEmpty(l))
        return NULL;
    else
        return n->previous;
}

Posic getFirst(List lt){
    list *l = lt;
    return l->head;
}

Posic getLast(List lt){
    list *l = lt;
    if (isEmpty(l))
        return NULL;
    else
        return l->tail;
}

void insertList(List lt, Item item){
    list *l = lt;
    nodeList *n = newNodeList(item);
    if (isEmpty(l))
    {
        l->head = n;
        l->tail = n;
    }
    else
    {
        n->previous = l->tail;
        l->tail->next = n;
        l->tail = n;
    }
    l->size += 1;
}

void printList(List lt){
    list *l = lt;
    nodeList *n = l->head;
    while (n != NULL)
    {
        l->printItem(n->item);
        n = getNext(l, n);
    }
}


void freeList(List lt){
    list *l = lt;
    nodeList *nAux, *n = l->head;
    while (n != NULL)
    {
        nAux = n;
        n = n->next;
        if (nAux->item != NULL)
            l->freeItem(nAux->item);
        free(nAux);
    }
    free(l);
}

int sizeList(List lt){
    list *l = lt;
    return l->size;
}