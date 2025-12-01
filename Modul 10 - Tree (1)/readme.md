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
#include <iostream>
using namespace std;

int main() {
    // Matriks A
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Matriks B
    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int C[3][3]; // hasil operasi

    // Penjumlahan matriks
    cout << "=== HASIL PENJUMLAHAN (A + B) ===" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] + B[i][j];
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }

    // Pengurangan matriks
    cout << "\n=== HASIL PENGURANGAN (A - B) ===" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] - B[i][j];
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }

    // Perkalian matriks
    cout << "\n=== HASIL PERKALIAN (A x B) ===" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            C[i][j] = 0;
            for(int k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}

```
File: bst.cpp

File: main.cpp

### Output:
<img width="585" height="344" alt="Image" src="https://github.com/user-attachments/assets/c3fe043b-1092-4dbd-b204-e94a0d1f1fa1" />

Program di atas bertujuan untuk 

### Full Code Screenshot:
<img width="1331" height="1003" alt="Image" src="https://github.com/user-attachments/assets/962a3d8e-3679-4cf4-bfff-4e50212b5ed2" />


### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel

```cpp
#include <iostream>
using namespace std;

// Fungsi menukar 3 variabel menggunakan POINTER
void tukarPointer(int *x, int *y, int *z) {
    int temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

// Fungsi menukar 3 variabel menggunakan REFERENCE
void tukarReference(int &x, int &y, int &z) {
    int temp = x;
    x = y;
    y = z;
    z = temp;
}

int main() {
    int a = 10, b = 20, c = 30;

    cout << "=== Sebelum Ditukar ===" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    // Menukar dengan POINTER
    tukarPointer(&a, &b, &c);
    cout << "\n=== Setelah Tukar (Pointer) ===" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    // Menukar lagi dengan REFERENCE
    tukarReference(a, b, c);
    cout << "\n=== Setelah Tukar (Reference) ===" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    return 0;
}

```
### Output:
<img width="513" height="300" alt="Image" src="https://github.com/user-attachments/assets/8357e0ea-2c26-4271-8c7b-97ea5fc0c9de" />

Program ini bertujuan untuk menukar nilai tiga variabel (a, b, c) dengan dua cara, yaitu menggunakan pointer dan reference. Fungsi pointer memakai alamat variabel untuk mengubah nilainya, sedangkan reference langsung mengubah variabel aslinya. Di main(), program menampilkan nilai awal, menukar dengan pointer, menampilkan hasilnya, lalu menukar lagi dengan reference dan menampilkan hasil akhirnya. Program ini menunjukkan cara mengubah nilai variabel lewat fungsi dengan dua metode berbeda.

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

