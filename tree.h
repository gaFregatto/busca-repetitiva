#ifndef tree_h
#define tree_h

typedef void *Tree;
typedef void *Node;

Tree newTree();
Node newNode();
void freeTree(Tree tr);
void freeNode(Node nd);

// Funcoes a criar
Node insertNode(Tree tr, Node newNode);
/* Dado um no ja instanciado, Adiciona-o
 * na arvore.
*/

Node minNode(Tree tr, Node nd);
/* Dado o no da arvore, deve-se setar seu valor como
 * o no filho de MENOR valor (Recursivo)
*/

Node maxNode(Tree tr, Node nd);
/* Dado o no da arvore, deve-se setar seu valor como
 * o no filho de MAIOR valor (Recursivo)
*/

#endif