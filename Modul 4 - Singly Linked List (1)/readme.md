<h1 align="center">Laporan Praktikum Modul Singly Linked List (1)</h1>
<p align="center">Syifa Kirana Putri Surya</p>
<p align="center">(103112400111)</p>


## Dasar Teori
Singly Linked List adalah salah satu jenis struktur data yang terdiri dari rangkaian node yang saling terhubung satu arah.
Setiap node memiliki dua bagian utama:
- Info (data) untuk menyimpan nilai yang ingin disimpan.
- Next (pointer) untuk menyimpan alamat node berikutnya.<br>

Struktur ini tidak memiliki ukuran tetap seperti array. Artinya, jumlah datanya bisa bertambah atau berkurang sesuai kebutuhan program. Penambahan atau penghapusan elemen juga lebih mudah dilakukan karena tidak perlu menggeser data lain.
Beberapa operasi dasar yang digunakan pada Singly Linked List antara lain:
- CreateList() membuat list kosong.
- Alokasi() membuat node baru.
- Dealokasi() menghapus node dari memori.
- InsertFirst(), InsertAfter(), InsertLast() → menambah node pada list.
- DeleteFirst(), DeleteAfter(), DeleteLast() → menghapus node pada list.
- PrintInfo() menampilkan isi list.
- NbList() menghitung jumlah node dalam list.
- DeleteList() menghapus seluruh isi list.<br>

Dalam implementasinya, list memiliki pointer first yang menunjuk ke node pertama. Dari node pertama ini, program bisa menelusuri node-node berikutnya sampai pointer next bernilai NULL.

## Guided 

### 1. Program Implementasi List Sederhana (menggunakan multiple file)

Folder Guided1  
File: list.h
```C++
//Header guard digunakan untuk mencegah file header yg sama

#ifndef LIST_H
#define LIST_H
#define Nil NULL 

#include <iostream>
using namespace std;

// deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //mendefinisikan alias address sebagai pointer ke struct node

struct node{ //node untuk isi linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{//ini linked listnya 
    address first;
};

//semua function &prosedur yg akan dipakai 
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodebaru);
void insertAfter(linkedlist &List, address nodebaru, address prev);
void insertLast(linkedlist &List, address nodebaru);

#endif
```

File: list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```

File: main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
Program di atas digunakan untuk mengimplementasikan Single Linked List yang berisi data mahasiswa, dengan operasi dasar seperti membuat list kosong, menambahkan elemen di awal, di tengah (setelah node tertentu), dan di akhir list. Program dibagi menjadi tiga file agar lebih terstruktur:
- list.h berisi deklarasi struktur data dan fungsi,
- list.cpp berisi implementasi fungsi-fungsi linked list seperti insertFirst, insertAfter, insertLast, dan printList,
- main.cpp berfungsi sebagai file utama untuk membuat list dan menampilkan hasilnya.

### 2. Program Operasi Penghapusan pada Single Linked List (menggunakan Multiple File)

Folder Guided2  
File: list.h
```C++
//Header guard digunakan untuk mencegah file header yg sama

#ifndef LIST_H
#define LIST_H
#define Nil NULL 

#include <iostream>
using namespace std;

// deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //mendefinisikan alias address sebagai pointer ke struct node

struct node{ //node untuk isi linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{//ini linked listnya 
    address first;
};

//semua function &prosedur yg akan dipakai 
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodebaru);
void insertAfter(linkedlist &List, address nodebaru, address prev);
void insertLast(linkedlist &List, address nodebaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &list, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif
```

File: list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    /* I.S. list tidak kosong
    F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    /* I.S. list tidak kosong
    F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev→next, menghapus Prev→next dari list */
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}
```

File: main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```

Program di atas digunakan untuk menambahkan, menampilkan, menghitung jumlah, dan menghapus data mahasiswa pada struktur data Single Linked List.  
Data mahasiswa berisi nama, NIM, dan umur.  
Program dibagi menjadi tiga file agar lebih terstruktur:  
- list.h untuk deklarasi struct, tipe data, dan fungsi/prosedur,
- list.cpp untuk implementasi fungsi dan prosedur,
- main.cpp sebagai file utama yang menjalankan proses insert, delete, dan menampilkan isi list menggunakan cout.

Fungsi utama dari program ini adalah menunjukkan cara kerja operasi dasar Single Linked List, yaitu:  
- insert (menambahkan node di awal, tengah, atau akhir),
- delete (menghapus node di awal, tengah, atau akhir),
- deleteList untuk menghapus semua data dari memori.

## Unguided 

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”
<img width="668" height="249" alt="Image" src="https://github.com/user-attachments/assets/9fb99399-ca92-43ea-979a-7afd58e8f554" />  
Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file “Singlylist.cpp”<br> 
Kemudian buat program utama didalam file “main.cpp” dengan implementasi sebagai berikut :  
<img width="900" height="506" alt="Image" src="https://github.com/user-attachments/assets/e41e3550-65c3-4dbd-a870-f0d0829f01c8" />  
Sehingga linkedlist yang dibuat akan seperti ini :  
<img width="904" height="131" alt="Image" src="https://github.com/user-attachments/assets/856d373e-a75a-46ac-8892-ea0d26ff55c8" />  
Output yang diharapkan :  


file: Singlylist.h
```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

// Deklarasi tipe data dasar
typedef int infotype;
typedef struct ElmtList *address;

// Struktur elemen list
struct ElmtList {
    infotype info;
    address next;
};

// Struktur list
struct List {
    address first;
};

// Deklarasi function dan procedure
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void printInfo(List L);

#endif // SINGLYLIST_H_INCLUDED
```

file: Singlylist.cpp
```C++
#include "SinglyList.h"

// Membuat list kosong
void createList(List &L) {
    L.first = NULL;
}

// Mengalokasikan node baru
address alokasi(infotype x) {
    address P = new ElmtList;
    P->info = x;
    P->next = NULL;
    return P;
}

// Menghapus alokasi node dari memori
void dealokasi(address &P) {
    delete P;
    P = NULL;
}

// nambah elemen di awal list
void insertFirst(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

// Menampilkan semua isi list
void printInfo(List L) {
    address P = L.first;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}
```

file: main.cpp
```C++
#include "SinglyList.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    // Inisialisasi list kosong
    createList(L);

    // Menambahkan elemen ke list
    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    // Menampilkan isi list
    cout << "Isi Linked List: ";
    printInfo(L);

    return 0;
}
```

#### Output:
<img width="1426" height="681" alt="Image" src="https://github.com/user-attachments/assets/d985f22f-0053-4c6c-adae-297099949bb5" />

Program di atas digunakan untuk membuat dan menampilkan data dalam struktur data Single Linked List.
Data bertipe int dan disimpan dalam node-node yang saling terhubung satu arah.
Program dibagi menjadi tiga file agar lebih terstruktur:
- Singlylist.h berisi deklarasi struct dan fungsi.
- Singlylist.cpp berisi implementasi fungsi seperti membuat list, menambah node, dan menampilkan isi list.
- main.cpp berisi program utama untuk menjalankan operasi insert dan menampilkan isi list ke layar.
Fungsi utamanya adalah menampilkan cara kerja penambahan data di awal list (insertFirst).

#### Full code Screenshot:
<img width="1919" height="1019" alt="Image" src="https://github.com/user-attachments/assets/747027a1-babb-4f62-b765-7b414b1a41b8" />

### 2. Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList().
Output yang diharapkan :
<img width="722" height="125" alt="Image" src="https://github.com/user-attachments/assets/048b2ed8-33ad-4015-bc5a-813596a7348f" /><br>

File : Singlylist.h
```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmtList *address;

struct ElmtList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void printInfo(List L);

// tambahan
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
int nbList(List L);
void deleteList(List &L);

#endif
```

File : Singlylist.cpp
```C++
#include "SinglyList.h"

void createList(List &L) {
    L.first = NULL;
}

address alokasi(infotype x) {
    address P = new ElmtList;
    P->info = x;
    P->next = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void printInfo(List L) {
    address P = L.first;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

// tambahan
// Menghapus elemen pertama
void deleteFirst(List &L, address &P) {
    if (L.first != NULL) {
        P = L.first;
        L.first = P->next;
        dealokasi(P);
    }
}

// Menghapus elemen terakhir
void deleteLast(List &L, address &P) {
    if (L.first != NULL) {
        if (L.first->next == NULL) {
            P = L.first;
            L.first = NULL;
            dealokasi(P);
        } else {
            address Q = L.first;
            while (Q->next->next != NULL) {
                Q = Q->next;
            }
            P = Q->next;
            Q->next = NULL;
            dealokasi(P);
        }
    }
}

// Menghapus setelah node tertentu
void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != NULL && Prec->next != NULL) {
        P = Prec->next;
        Prec->next = P->next;
        dealokasi(P);
    }
}

// Menghitung jumlah node
int nbList(List L) {
    int n = 0;
    address P = L.first;
    while (P != NULL) {
        n++;
        P = P->next;
    }
    return n;
}

// Menghapus seluruh list
void deleteList(List &L) {
    address P;
    while (L.first != NULL) {
        deleteFirst(L, P);
    }
}
```

File : main.cpp
```C++
#include "SinglyList.h"

int main() {
    List L;
    address P, Prec;

    createList(L);

    insertFirst(L, alokasi(2));
    insertFirst(L, alokasi(0));
    insertFirst(L, alokasi(8));
    insertFirst(L, alokasi(12));
    insertFirst(L, alokasi(9));

    // Hapus node 9 
    deleteFirst(L, P);

    // Hapus node 2 
    deleteLast(L, P);

    // Cari node sebelum 8 (yaitu 12), lalu hapus setelahnya (node 8)
    Prec = L.first; // 12
    deleteAfter(L, Prec, P);

    // Tampilkan hasil
    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    // Hapus seluruh list
    deleteList(L);
    cout << endl << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```

#### Output:
<img width="503" height="236" alt="Image" src="https://github.com/user-attachments/assets/d679d261-5748-416f-889e-d4a2fcfc042c" />  

Program ini merupakan lanjutan dari latihan pertama.
Fungsinya untuk menghapus elemen-elemen dari Single Linked List menggunakan berbagai operasi penghapusan:
- deleteFirst() menghapus node pertama.
- deleteLast() menghapus node terakhir.
- deleteAfter() menghapus node setelah node tertentu.
- nbList() menghitung jumlah node di list.
- deleteList() menghapus seluruh isi list.<br>
Output akhirnya menunjukkan isi list setelah penghapusan sebagian, lalu hasil setelah seluruh list dihapus.

#### Full code Screenshot:
File : pelajaran.h
<img width="1131" height="661" alt="Image" src="https://github.com/user-attachments/assets/a032c586-183b-4f7d-b5ae-f806106b6833" />

File : pelajaran.cpp
<img width="999" height="648" alt="Image" src="https://github.com/user-attachments/assets/c9c2076d-a55d-475d-bea4-6b0fb6bde9c0" />

File : main2.cpp
<img width="931" height="563" alt="image" src="https://github.com/user-attachments/assets/16805382-8cbf-4bb0-bf71-a3231e99e624" />



## Kesimpulan
Dari praktikum ini bisa disimpulkan bahwa Singly Linked List adalah struktur data yang terdiri dari beberapa node yang saling terhubung satu arah lewat pointer. Setiap node punya dua bagian, yaitu data dan alamat menuju node berikutnya. Dengan struktur ini, kita bisa menambah dan menghapus data dengan lebih mudah tanpa perlu menggeser elemen seperti pada array. Dalam percobaan guided dan unguided, kita belajar cara membuat list, menambah data (insert), menghapus data (delete), dan menampilkan isi list (printInfo). Program juga dibuat dengan tiga file terpisah supaya lebih rapi, mudah dibaca, dan gampang dikelola.

