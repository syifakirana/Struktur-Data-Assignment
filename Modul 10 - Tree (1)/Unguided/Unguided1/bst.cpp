#include <iostream>
#include "bst.h"
using namespace std;

address alokasi(int x) {
    address P = new Node;
    P->info = x;
    P->left = Nil;
    P->right = Nil;
    return P;
}

void insertNode(BinTree &root, address P) {
    if (root == Nil) {
        root = P;
    } else if (P->info < root->info) {
        insertNode(root->left, P);
    } else if (P->info > root->info) {
        insertNode(root->right, P);
    }
}

address findNode(int x, BinTree root) {
    if (root == Nil) {
        return Nil;
    } else if (x < root->info) {
        return findNode(x, root->left);
    } else if (x > root->info) {
        return findNode(x, root->right);
    } else {
        return root;
    }
}

void printInOrder(BinTree root) {
    if (root != Nil) {
        printInOrder(root->left);
        cout << root->info << " - ";
        printInOrder(root->right);
    }
}