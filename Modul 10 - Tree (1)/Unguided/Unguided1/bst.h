#ifndef BSTREE_H
#define BSTREE_H

#define Nil NULL

typedef struct Node *address;

struct Node {
    int info;
    address left;
    address right;
};

typedef address BinTree;

address alokasi(int x);
void insertNode(BinTree &root, address P);
address findNode(int x, BinTree root);
void printInOrder(BinTree root);

#endif
