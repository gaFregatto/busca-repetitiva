#ifndef list_h
#define list_h

typedef void* List;
typedef void* Posic;
typedef void* Item;
typedef void (*fr)(Item);

List newList(fr printItem, fr freeItem);
Item getItem(List lt, Posic p);
Posic getNext(List lt, Posic p);
Posic getPrevious(List lt, Posic p);
Posic getFirst(List lt);
Posic getLast(List lt);
void insertList(List lt, Item item);
void printList(List lt);
void freeList(List lt);
int sizeList(List lt);


#endif