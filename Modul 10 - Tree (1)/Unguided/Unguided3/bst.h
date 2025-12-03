#ifndef BST_H
#define BST_H
#define Nil NULL

typedef struct Node *address;

struct Node {
    int info;
    address left;
    address right;
};

typedef address BinTree;

address newNode(int x);
void printPreOrder(BinTree root);
void printPostOrder(BinTree root);

#endif