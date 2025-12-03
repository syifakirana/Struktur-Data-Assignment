#include <iostream>
#include "bst.h"
using namespace std;

int main() {

    BinTree root = newNode(6);
    root->left = newNode(4);
    root->right = newNode(7);

    root->left->left = newNode(2);
    root->left->right = newNode(5);

    root->left->left->left = newNode(1);
    root->left->left->right = newNode(3);

    cout << "PreOrder  : ";
    printPreOrder(root);
    cout << endl;

    cout << "PostOrder : ";
    printPostOrder(root);
    cout << endl;

    return 0;
}