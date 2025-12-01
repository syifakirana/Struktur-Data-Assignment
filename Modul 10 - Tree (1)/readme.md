# <h1 align="center">Laporan Praktikum Modul Tree (1)</h1>
<p align="center">Syifa Kirana Putri Surya</p>


## Dasar Teori
Binary Tree adalah struktur data yang bentuknya bercabang, di mana setiap node bisa punya dua anak: kiri dan kanan. Tree dipakai ketika kita butuh menyimpan data yang punya hubungan bertingkat atau ketika proses pencarian harus dibuat lebih cepat dari struktur linear biasa.

Supaya isi tree bisa dibaca atau diproses, kita butuh yang namanya traversal, yaitu cara mengunjungi node-node dalam urutan tertentu. Ada tiga jenis traversal dasar:  
Pre-Order (Root -> Left -> Right)  
Mengunjungi akar dulu, lalu ke anak kiri, dan terakhir anak kanan. Biasanya dipakai untuk menampilkan bentuk tree dari atas ke bawah.  
In-Order (Left -> Root -> Right)  
Kalau tree-nya BST, hasil traversal ini bakal otomatis terurut dari kecil ke besar.  
Post-Order (Left -> Right -> Root)  
Mengunjungi anak-anak dulu, baru induknya. Umumnya dipakai ketika kita ingin menghapus tree dari bawah ke atas.  
Traversal biasanya dibuat pakai rekursi, karena struktur tree memang alami untuk diproses secara berulang dari setiap cabangnya.  

---

## Guided

### 1. Program Binary Search Tree (BST)
File: cpp.h
```cpp
#ifndef BST_H
#define BST_H
#define Nil NULL

using namespace std;

typedef struct BST *node; //alias pointer = node

struct BST{ // nama struct nya BST
int angka;
node left;
node right;
};

typedef node BinTree; //alias tree BinTree (merujuk ke node root dari BST)

bool isEmpty (BinTree tree);
void createTree(BinTree &tree);
node alokasi(int angka);
void dealokasi (node nodeHapus);

void insertNode (BinTree &tree, node nodeBaru);
void searchByData (BinTree tree, int angka);
void preOrder (BinTree tree);
void inOrder (BinTree tree);
void postOrder (BinTree tree);

bool deleteNode (BinTree &tree, int angka);
node mostRight (BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree &tree);
int size(BinTree tree);
int height(BinTree tree);

#endif
```
File: bst.cpp
```cpp
#include "bst.h"
#include <iostream>

using namespace std;

//NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}



bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree tree){ //mengembalikan jumlah level tree
    if(isEmpty(tree) == true){
        return -1; //tree kosong jika height = -1
    } else {
        int hl = height(tree->left);
        int hr = height(tree->right);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
}
```
File: main.cpp
```cpp
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9: 
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;
        
        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
```
Program ini mengimplementasikan struktur Binary Search Tree (BST) untuk menyimpan data angka dengan aturan nilai lebih kecil disimpan di kiri dan nilai lebih besar di kanan. Program menyediakan berbagai operasi utama seperti menambah node (insertNode), menghapus node dengan semua kemungkinan kasus (leaf, satu child, dua child), dan mencari data sekaligus menampilkan informasi parent, sibling, serta child dari node tersebut. Isi tree dapat ditampilkan menggunakan traversal preOrder, inOrder, dan postOrder. Program ini juga memiliki fitur tambahan seperti menghitung jumlah node (size), tinggi tree (height), mencari nilai terkecil dan terbesar (mostLeft, mostRight), serta menghapus seluruh tree. Semua fungsi tersebut dapat dijalankan melalui menu interaktif, sehingga pengguna bisa melihat langsung cara kerja BST secara lengkap.

## Unguided 

### 1. Buatlah ADT Binary Search Tree menggunakan Linked list sebagai berikut di dalam file “bstree.h”:<br>
<img width="672" height="202" alt="Image" src="https://github.com/user-attachments/assets/6aed2a54-ba74-4d28-9280-6c891166bedc" /><br>
Buatlah implementasi ADT Binary Search Tree pada file “bstree.cpp” dan cobalah hasil
implementasi ADT pada file “main.cpp”  
<img width="800" height="609" alt="Image" src="https://github.com/user-attachments/assets/2e04b202-9433-47f5-9807-238f76267c5e" /><br>
File: bst.h
```cpp
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
```

File: bst.cpp
```cpp
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
```

File: main.cpp
```cpp
#include <iostream>
#include "bst.h"
using namespace std;

int main() {
    cout << "Hello World!" << endl;

    address root = Nil;

    insertNode(root, alokasi(1));
    insertNode(root, alokasi(2));
    insertNode(root, alokasi(6));
    insertNode(root, alokasi(4));
    insertNode(root, alokasi(5));
    insertNode(root, alokasi(3));
    insertNode(root, alokasi(7));

    cout << "InOrder : ";
    printInOrder(root);

    cout << endl;
    return 0;
}
```
### Output:
<img width="566" height="290" alt="Image" src="https://github.com/user-attachments/assets/ec2ea695-b49e-4c39-9f77-2d2e3e6a1f56" />

Program ini membuat struktur Binary Search Tree (BST) untuk menyimpan data angka. Setiap angka yang dimasukkan akan ditempatkan mengikuti aturan BST: jika nilainya lebih kecil, ia masuk ke bagian kiri, dan jika lebih besar, masuk ke bagian kanan. Program menyediakan beberapa fungsi utama, seperti:  
alokasi(x) untuk membuat node baru  
insertNode(root, x) untuk menambah angka ke dalam tree sesuai aturan BST  
findNode(x, root) untuk mencari angka tertentu  
printInOrder(root) untuk menampilkan isi tree dari yang terkecil sampai terbesar  
Di file main.cpp, program mulai dengan membuat tree kosong, menampilkan “Hello World!”, lalu menambahkan beberapa angka ke dalam tree menggunakan insertNode(). Setelah semua data dimasukkan, tree ditampilkan dengan traversal inorder sehingga hasilnya muncul dalam bentuk angka yang sudah terurut. Program ini menunjukkan cara kerja dasar BST untuk menyimpan dan mengurutkan data secara otomatis.

### Full Code Screenshot:
<img width="1919" height="802" alt="Image" src="https://github.com/user-attachments/assets/1c842ece-2d39-4b7c-a5a6-94f68cf59030" />

### 2. Buatlah fungsi untuk menghitung jumlah node dengan fungsi berikut.  
➢ fungsi hitungJumlahNode( root:address ) : integer  
/* fungsi mengembalikan integer banyak node yang ada di dalam BST*/  
➢ fungsi hitungTotalInfo( root:address, start:integer ) : integer  
/* fungsi mengembalikan jumlah (total) info dari node-node yang ada di dalam BST*/  
➢ fungsi hitungKedalaman( root:address, start:integer ) : integer  
/* fungsi rekursif mengembalikan integer kedalaman maksimal dari binary tree */  

File: bst.h
```cpp
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
void insertNode(BinTree &root, int x);
address findNode(int x, BinTree root);
void printInOrder(BinTree root);

// tambahan 
int hitungJumlahNode(BinTree root);
int hitungTotalInfo(BinTree root);
int hitungKedalaman(BinTree root, int start);

#endif

```

File: bst.cpp
```cpp
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

```

File: main.cpp
```cpp
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    cout << "Hello World!" << endl;

    address root = Nil;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6); 
    insertNode(root, 7);

    cout << "InOrder : ";
    printInOrder(root);
    cout << endl;

    cout << "kedalaman : " << hitungKedalaman(root, 1) << endl;

    cout << "jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root) << endl;

    return 0;
}
```
### Output:
<img width="781" height="263" alt="Image" src="https://github.com/user-attachments/assets/b5aa0c8a-3f4d-479a-8926-b9a286162e3e" />  

Program ini menggunakan Binary Search Tree (BST) yang dibangun dengan pointer dan rekursi. Setiap node menyimpan sebuah angka serta pointer ke anak kiri dan kanan. Data dimasukkan menggunakan insertNode, di mana angka yang lebih kecil masuk ke kiri dan yang lebih besar masuk ke kanan, sedangkan angka yang sama tidak dimasukkan lagi.  
Program juga memiliki beberapa fungsi tambahan, yaitu:  
hitungJumlahNode untuk menghitung berapa banyak node dalam tree  
hitungTotalInfo untuk menjumlahkan semua nilai yang ada  
hitungKedalaman untuk mengetahui kedalaman maksimum tree secara rekursif  
Di fungsi main, program membuat BST dari beberapa angka, menampilkan isinya dengan inorder traversal, lalu menampilkan kedalaman tree, jumlah node, dan total nilai. Program ini menunjukkan cara kerja dasar BST dan bagaimana rekursi dipakai untuk operasi perhitungan di dalam tree.

### Full Code Screenshot:
<img width="1919" height="920" alt="Image" src="https://github.com/user-attachments/assets/715cd153-7f93-4005-8379-4240b78204c2" />  

### 3. <br>
<img width="494" height="280" alt="Image" src="https://github.com/user-attachments/assets/669947c7-2e86-4b61-bc0d-bab65e9b2924" />  

File: bst.h
```cpp
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
```

File: bst.cpp
```cpp
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
```

File: main.cpp
```cpp
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
```
### Output:
<img width="663" height="227" alt="Image" src="https://github.com/user-attachments/assets/2b9023d3-0d5d-4920-bc63-664244a61cfa" />

Program ini membuat sebuah Binary Tree berdasarkan gambar yang ada di modul. Setiap node dibuat dengan fungsi newNode.  
Setelah tree terbentuk, program menampilkan isinya menggunakan dua traversal:
Pre-Order (Root -> Left -> Right)
Pada traversal ini, program mencetak akar dulu, lalu bagian kiri, kemudian bagian kanan. Urutannya menunjukkan cara tree dijelajahi dari atas ke bawah.
Post-Order (Left -> Right -> Root)
Di traversal ini, subtree kiri dicetak dulu, lalu subtree kanan, dan terakhir akarnya. Urutan ini cocok untuk melihat bagaimana tree “dibongkar” dari bawah ke atas.  

### Full Code Screenshot:
<img width="1919" height="856" alt="Image" src="https://github.com/user-attachments/assets/74372a04-5b1a-4fe4-8128-0612fa6f14cb" />

## Kesimpulan
Dari praktikum ini, menunjukkan cara dasar bekerja dengan Binary Tree: membuat node, menyusun node menjadi tree, dan membaca isinya lewat traversal. Tree ini menunjukkan bagaimana data bisa disusun dalam bentuk bertingkat, bukan hanya dalam barisan seperti array atau linked list.

Dengan membuat tree dan menampilkan hasilnya menggunakan pre-order dan post-order, kita jadi paham bahwa urutan traversal akan mengubah urutan tampilnya data. Kita juga melihat bagaimana rekursi dipakai untuk menelusuri tree karena setiap node bisa punya anak dan subtree sendiri.
