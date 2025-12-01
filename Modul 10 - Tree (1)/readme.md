# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (2)</h1>
<p align="center">Syifa Kirana Putri Surya</p>


## Dasar Teori


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
<img width="513" height="300" alt="Image" src="https://github.com/user-attachments/assets/8357e0ea-2c26-4271-8c7b-97ea5fc0c9de" />

Program ini menggunakan Binary Search Tree (BST) yang dibangun dengan pointer dan rekursi. Setiap node menyimpan sebuah angka serta pointer ke anak kiri dan kanan. Data dimasukkan menggunakan insertNode, di mana angka yang lebih kecil masuk ke kiri dan yang lebih besar masuk ke kanan, sedangkan angka yang sama tidak dimasukkan lagi.  
Program juga memiliki beberapa fungsi tambahan, yaitu:  
hitungJumlahNode untuk menghitung berapa banyak node dalam tree  
hitungTotalInfo untuk menjumlahkan semua nilai yang ada  
hitungKedalaman untuk mengetahui kedalaman maksimum tree secara rekursif  
Di fungsi main, program membuat BST dari beberapa angka, menampilkan isinya dengan inorder traversal, lalu menampilkan kedalaman tree, jumlah node, dan total nilai. Program ini menunjukkan cara kerja dasar BST dan bagaimana rekursi dipakai untuk operasi perhitungan di dalam tree.

### Full Code Screenshot:
<img width="1357" height="875" alt="Image" src="https://github.com/user-attachments/assets/0b3c558a-1808-45c1-9037-b108d8d03c39" />

### 3. Diketahui sebuah array 1 dimensi sebagai berikut : arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55}
Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan menu switch-case seperti berikut ini :  
--- Menu Program Array ---
1. Tampilkan isi array
2. cari nilai maksimum
3. cari nilai minimum
4. Hitung nilai rata - rata

```cpp
#include <iostream>
using namespace std;

// Function untuk mencari nilai minimum
int cariMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Function untuk mencari nilai maksimum
int cariMaksimum(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Prosedur untuk menghitung rata-rata
void hitungRataRata(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    double rata = (double)total / n;
    cout << "Nilai rata-rata dari array adalah: " << rata << endl;
}

int main() {
    int arrA[] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int n = sizeof(arrA)/sizeof(arrA[0]);
    int pilihan;

    do {
        // Menampilkan menu
        cout << "\n--- Menu Program Array ---\n";
        cout << "1. Tampilkan isi array\n";
        cout << "2. Cari nilai maksimum\n";
        cout << "3. Cari nilai minimum\n";
        cout << "4. Hitung nilai rata-rata\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                cout << "Isi array: ";
                for (int i = 0; i < n; i++) {
                    cout << arrA[i] << " ";
                }
                cout << endl;
                break;
            case 2:
                cout << "Nilai maksimum dari array adalah: " << cariMaksimum(arrA, n) << endl;
                break;
            case 3:
                cout << "Nilai minimum dari array adalah: " << cariMinimum(arrA, n) << endl;
                break;
            case 4:
                hitungRataRata(arrA, n);
                break;
            case 5:
                cout << "Program selesai. Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 5);

    return 0;
}

```
### Output:
<img width="1141" height="758" alt="Image" src="https://github.com/user-attachments/assets/2aa86a38-7096-4577-a220-b1d41ef647ac" />

Program ini bertujuan untuk melakukan beberapa operasi pada array satu dimensi arrA, yaitu menampilkan isi array, mencari nilai maksimum, minimum, dan menghitung rata-rata. Function cariMinimum() digunakan untuk menemukan nilai terkecil, cariMaksimum() untuk nilai terbesar, dan prosedur hitungRataRata() untuk menghitung dan menampilkan rata-rata. Program menampilkan menu interaktif menggunakan switch-case, sehingga pengguna dapat memilih opsi yang diinginkan, dan setiap pilihan akan dijalankan sampai pengguna memilih keluar.
### Full Code Screenshot:
<img width="1364" height="1022" alt="Image" src="https://github.com/user-attachments/assets/85f33b1e-9610-4762-aa5e-b0f5a6a92998" />
<img width="1322" height="1033" alt="Image" src="https://github.com/user-attachments/assets/3f256afc-08c0-48e1-bd90-0c35957a61dd" />

## Kesimpulan
Dari praktikum ini, saya mendapatkan pemahaman tentang bagaimana menggunakan array, function, prosedur, pointer, reference, perulangan, dan percabangan untuk membangun program yang efektif. Praktikum ini membantu memperkuat konsep teori melalui penerapan langsung, sehingga kita bisa melihat bagaimana function dan prosedur mempermudah pengolahan data, bagaimana pointer dan reference memungkinkan pengubahan nilai variabel secara efisien, serta bagaimana switch-case dan loop mempermudah interaksi dan pengolahan data dalam program.

