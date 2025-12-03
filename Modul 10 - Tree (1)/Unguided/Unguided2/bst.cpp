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

void insertNode(BinTree &root, int x) {
    if (root == Nil) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
}

address findNode(int x, BinTree root) {
    if (root == Nil) return Nil;

    if (x < root->info) return findNode(x, root->left);
    if (x > root->info) return findNode(x, root->right);

    return root;
}

void printInOrder(BinTree root) {
    if (root == Nil) return;

    printInOrder(root->left);
    cout << root->info << " - ";
    printInOrder(root->right);
}

int hitungJumlahNode(BinTree root) {
    if (root == Nil) return 0;
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(BinTree root) {
    if (root == Nil) return 0;
    return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
}

int hitungKedalaman(BinTree root, int start) {
    if (root == Nil) return start - 1;

    int kiri = hitungKedalaman(root->left, start + 1);
    int kanan = hitungKedalaman(root->right, start + 1);

    return (kiri > kanan ? kiri : kanan);
}
