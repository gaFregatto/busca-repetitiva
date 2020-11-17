#ifndef tree_h
#define tree_h

typedef void *Tree;
typedef void *Node;

Tree newTree();
Node newNode();
void freeTree(Tree tr);
void freeNode(Node nd);

#endif