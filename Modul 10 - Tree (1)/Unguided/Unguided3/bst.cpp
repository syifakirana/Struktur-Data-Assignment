#include "bst.h"
#include <iostream>
using namespace std;

address newNode(int x) {
    address P = new Node;
    P->info = x;
    P->left = Nil;
    P->right = Nil;
    return P;
}

void printPreOrder(BinTree root) {
    if (root == Nil) return;
    cout << root->info << " - ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printPostOrder(BinTree root) {
    if (root == Nil) return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->info << " - ";
}