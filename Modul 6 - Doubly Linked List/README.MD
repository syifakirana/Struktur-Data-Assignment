# <h1 align="center">Laporan Praktikum Modul Doubly Linked List </h1>
<p align="center">Syifa Kirana Putri Surya</p>
<p align="center">103112400111</p>

## Dasar Teori
Materi ini merupakan 

---

## Guided

### 1. 

File: dii_hapus.cpp
```cpp
// dll_hapus.cpp
#include <iostream> 
using namespace std; 
#define Nil NULL 

typedef int infotype; // Definisikan tipe data infotype sebagai integer untuk menyimpan informasi elemen
typedef struct elmlist *address; // Definisikan tipe address sebagai pointer ke struct elmlist

struct elmlist { 
    infotype info; // Deklarasikan field info untuk menyimpan data elemen
    address next;   
    address prev; 
}; 

struct List { 
    address first; 
    address last;
}; 

address alokasi(infotype x) { // Definisikan fungsi alokasi untuk membuat elemen baru
    address P = new elmlist; // Alokasikan memori baru untuk elemen
    P->info = x; P->next = Nil; P->prev = Nil; return P; // Set nilai info, next, prev, dan kembalikan pointer
} 
void dealokasi(address &P) { delete P; P = Nil; } // Definisikan fungsi dealokasi untuk mengosongkan memori elemen
void insertFirst(List &L, address P) { 
    P->next = L.first; P->prev = Nil; // Set pointer next P ke first saat ini dan prev ke Nil
    if (L.first != Nil) L.first->prev = P; else L.last = P; // Jika list tidak kosong, update prev first; jika kosong, set last ke P
    L.first = P; // Update first list menjadi P
}

void printInfo(List L) { 
    address P = L.first; while (P != Nil) { cout << P->info << " "; P = P->next; } cout << endl; // Loop melalui list dan cetak info setiap elemen
} 
void deleteFirst(List &L, address &P) { 
    P = L.first; L.first = L.first->next; // Set P ke first dan update first ke next-nya
    if (L.first != Nil) L.first->prev = Nil; else L.last = Nil; // Jika list tidak kosong, set prev first baru ke Nil; jika kosong, set last ke Nil
    P->next = Nil; P->prev = Nil; // Kosongkan pointer next dan prev P
}

void deleteLast(List &L, address &P) { 
    P = L.last; L.last = L.last->prev; // Set P ke last dan update last ke prev-nya
    if (L.last != Nil) L.last->next = Nil; else L.first = Nil; // Jika list tidak kosong, set next last baru ke Nil; jika kosong, set first ke Nil
    P->prev = Nil; P->next = Nil; // Kosongkan pointer prev dan next P
} 
    
void deleteAfter(List &L, address &P, address R) { 
    P = R->next; R->next = P->next; // Set P ke next R dan update next R ke next P
    if (P->next != Nil) P->next->prev = R; else L.last = R; // Jika ada next P, update prev-nya ke R; jika tidak, set last ke R
    P->prev = Nil; P->next = Nil; // Kosongkan pointer prev dan next P
} 

int main() { 
    List L; L.first = Nil; L.last = Nil; 
    insertFirst(L, alokasi(1)); insertFirst(L, alokasi(2)); insertFirst(L, alokasi(3)); // Sisipkan elemen 1, 2, 3 di awal list
    printInfo(L);
    address P; deleteFirst(L, P); dealokasi(P); // Deklarasikan P, hapus first, dealokasi P
    deleteAfter(L, P, L.first); dealokasi(P); // Hapus setelah first, dealokasi P
    printInfo(L); 
    return 0; 
}
```
Program ini digunakan untuk 

### 2.
File: dll_insert.cpp
```cpp
// dll_insert.cpp
#include <iostream>
#define Nil NULL
using namespace std;

typedef int infotype; // Definisikan tipe data infotype sebagai integer untuk menyimpan informasi elemen
typedef struct elmlist *address; // Definisikan tipe address sebagai pointer ke struct elmlist


struct elmlist {
    infotype info; // Deklarasikan field info untuk menyimpan data elemen
    address next;
    address prev;
};


struct List { 
    address first; 
    address last; 
}; 


void insertFirst(List &L, address P) { 
    P->next = L.first; // Set pointer next dari P ke elemen pertama saat ini
    P->prev = Nil; // Set pointer prev dari P ke Nil karena menjadi elemen pertama
    if (L.first != Nil) L.first->prev = P; // Jika list tidak kosong, set prev elemen pertama lama ke P
    else L.last = P; // Jika list kosong, set last juga ke P
    L.first = P; // Update first list menjadi P
} 


void insertLast(List &L, address P) { 
    P->prev = L.last; // Set pointer prev dari P ke elemen terakhir saat ini
    P->next = Nil; // Set pointer next dari P ke Nil karena menjadi elemen terakhir
    if (L.last != Nil) L.last->next = P; // Jika list tidak kosong, set next elemen terakhir lama ke P
    else L.first = P; // Jika list kosong, set first juga ke P
    L.last = P; // Update last list menjadi P
} 


void insertAfter(List &L, address P, address R) { // Definisikan fungsi insertAfter untuk menyisipkan elemen setelah R
    P->next = R->next; // Set pointer next dari P ke elemen setelah R
    P->prev = R; // Set pointer prev dari P ke R
    if (R->next != Nil) R->next->prev = P; // Jika ada elemen setelah R, set prev elemen tersebut ke P
    else L.last = P; // Jika R adalah terakhir, update last menjadi P
    R->next = P; // Set next dari R ke P
}


address alokasi(infotype x) { // Definisikan fungsi alokasi untuk membuat elemen baru
    address P = new elmlist; // Alokasikan memori baru untuk elemen
    P->info = x; // Set info elemen dengan nilai x
    P->next = Nil; // Set next elemen ke Nil
    P->prev = Nil; // Set prev elemen ke Nil
    return P; 
} 


void printInfo(List L) { // Definisikan fungsi printInfo untuk mencetak isi list
    address P = L.first; // Set P ke elemen pertama list
    while (P != Nil) { // Loop selama P tidak Nil
        cout << P->info << " "; // Cetak info dari P 
        P = P->next; // Pindah ke elemen berikutnya
    } 
    cout << endl; 
}


int main() { 
    List L; 
    L.first = Nil; 
    L.last = Nil;
    address P1 = alokasi(1); 
    insertFirst(L, P1); 
    address P2 = alokasi(2); 
    insertLast(L, P2); 
    address P3 = alokasi(3); 
    insertAfter(L, P3, P1); 
    printInfo(L); 
    return 0; 
}
```
Program ini digunakan untuk 

## Unguided

### 1. Modifikasi dari soal guided dengan tema yang berbeda (list minuman di cafe)

File: listMinuman.h
```C++
#ifndef LISTMINUMAN_H
#define LISTMINUMAN_H
#define Nil NULL

#include <iostream>
using namespace std;

// menyimpan informasi menu minuman
struct minuman {
    string nama;
    string ukuran;
    float harga;
};

typedef minuman dataMinuman;
typedef struct node *address;

struct node {
    dataMinuman isidata;
    address next;
};

struct linkedlist {
    address first;
};

// deklarasi fungsi dan prosedur
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string ukuran, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

// update data
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

// searching
void FindNodeByData(linkedlist List, string data);
void FindNodeByAddress(linkedlist List, address node);
void FindNodeByRange(linkedlist List, float hargaAwal, float hargaAkhir);

#endif
```
File: listMinuman.cpp
```C++
#include "listMinuman.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    return (List.first == Nil);
}

void createList(linkedlist &List) {
    List.first = Nil;
}

address alokasi(string nama, string ukuran, float harga) {
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.ukuran = ukuran;
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address bantu = List.first;
        while (bantu->next != Nil) {
            bantu = bantu->next;
        }
        bantu->next = nodeBaru;
    }
}

void delFirst(linkedlist &List) {
    if (!isEmpty(List)) {
        address hapus = List.first;
        List.first = hapus->next;
        dealokasi(hapus);
        cout << "Menu pertama berhasil dihapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List) {
    if (!isEmpty(List)) {
        address hapus = List.first, prev = Nil;
        while (hapus->next != Nil) {
            prev = hapus;
            hapus = hapus->next;
        }
        if (prev == Nil)
            List.first = Nil;
        else
            prev->next = Nil;
        dealokasi(hapus);
        cout << "Menu terakhir berhasil dihapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev) {
    if (!isEmpty(List) && nodePrev != Nil && nodePrev->next != Nil) {
        nodeHapus = nodePrev->next;
        nodePrev->next = nodeHapus->next;
        dealokasi(nodeHapus);
        cout << "Menu setelah " << nodePrev->isidata.nama << " berhasil dihapus!" << endl;
    } else {
        cout << "Tidak dapat menghapus node!" << endl;
    }
}

void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List menu kosong." << endl;
    } else {
        address bantu = List.first;
        while (bantu != Nil) {
            cout << "Nama Minuman: " << bantu->isidata.nama
                 << ", Ukuran: " << bantu->isidata.ukuran
                 << ", Harga: Rp" << bantu->isidata.harga << endl;
            bantu = bantu->next;
        }
    }
}

int nbList(linkedlist List) {
    int count = 0;
    address bantu = List.first;
    while (bantu != Nil) {
        count++;
        bantu = bantu->next;
    }
    return count;
}

void deleteList(linkedlist &List) {
    address bantu = List.first, hapus;
    while (bantu != Nil) {
        hapus = bantu;
        bantu = bantu->next;
        dealokasi(hapus);
    }
    List.first = Nil;
    cout << "Semua menu berhasil dihapus!" << endl;
}

// update
void updateFirst(linkedlist List) {
    if (isEmpty(List))
        cout << "List kosong!" << endl;
    else {
        cout << "Update menu pertama:\n";
        cout << "Nama Minuman: ";
        cin >> List.first->isidata.nama;
        cout << "Ukuran: ";
        cin >> List.first->isidata.ukuran;
        cout << "Harga: ";
        cin >> List.first->isidata.harga;
    }
}

void updateLast(linkedlist List) {
    if (isEmpty(List))
        cout << "List kosong!" << endl;
    else {
        address bantu = List.first;
        while (bantu->next != Nil)
            bantu = bantu->next;
        cout << "Update menu terakhir:\n";
        cout << "Nama Minuman: ";
        cin >> bantu->isidata.nama;
        cout << "Ukuran: ";
        cin >> bantu->isidata.ukuran;
        cout << "Harga: ";
        cin >> bantu->isidata.harga;
    }
}

void updateAfter(linkedlist List, address prev) {
    if (isEmpty(List))
        cout << "List kosong!" << endl;
    else if (prev != Nil && prev->next != Nil) {
        address target = prev->next;
        cout << "Update menu setelah " << prev->isidata.nama << ":\n";
        cout << "Nama Minuman: ";
        cin >> target->isidata.nama;
        cout << "Ukuran: ";
        cin >> target->isidata.ukuran;
        cout << "Harga: ";
        cin >> target->isidata.harga;
    } else
        cout << "Node tidak valid!" << endl;
}

// searching berdasarkan data
void FindNodeByData(linkedlist List, string data) {
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
        return;
    }
    address bantu = List.first;
    int pos = 0;
    bool found = false;
    while (bantu != Nil) {
        pos++;
        if (bantu->isidata.nama == data) {
            cout << "Menu \"" << data << "\" ditemukan pada posisi ke-" << pos << endl;
            cout << "Ukuran: " << bantu->isidata.ukuran << ", Harga: Rp" << bantu->isidata.harga << endl;
            found = true;
            break;
        }
        bantu = bantu->next;
    }
    if (!found)
        cout << "Menu " << data << " tidak ditemukan!" << endl;
}
// berdasarkan alamat
void FindNodeByAddress(linkedlist List, address node) {
    address bantu = List.first;
    int pos = 0;
    while (bantu != Nil) {
        pos++;
        if (bantu == node) {
            cout << "Node ditemukan di posisi ke-" << pos << endl;
            cout << "Nama Minuman: " << bantu->isidata.nama << endl;
            return;
        }
        bantu = bantu->next;
    }
    cout << "Node tidak ditemukan!" << endl;
}
// berdasarkan range harga
void FindNodeByRange(linkedlist List, float min, float max) {
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
        return;
    }
    address bantu = List.first;
    bool found = false;
    cout << "--- Menu dengan harga antara Rp" << min << " - Rp" << max << " ---" << endl;
    while (bantu != Nil) {
        if (bantu->isidata.harga >= min && bantu->isidata.harga <= max) {
            cout << bantu->isidata.nama << " (" << bantu->isidata.ukuran << ") - Rp" << bantu->isidata.harga << endl;
            found = true;
        }
        bantu = bantu->next;
    }
    if (!found)
        cout << "Tidak ada menu dalam range harga tersebut." << endl;
}
```
File: main.cpp
```C++
#include "listMinuman.h"
#include <iostream>
using namespace std;

int main() {
    linkedlist List;
    address A, B, C, D, E = Nil;
    createList(List);

    A = alokasi("Milkshake", "Small", 18000);
    B = alokasi("Cappuccino", "Medium", 25000);
    C = alokasi("Latte", "Large", 28000);
    D = alokasi("Matcha", "Medium", 27000);
    E = alokasi("Juice", "Large", 23000);

    insertFirst(List, A);
    insertLast(List, B);
    insertAfter(List, C, A);
    insertAfter(List, D, C);
    insertLast(List, E);

    cout << "--- MENU SETELAH INSERT ---" << endl;
    printList(List);
    cout << "Total menu: " << nbList(List) << endl << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, D);

    cout << "--- MENU SETELAH UPDATE ---" << endl;
    printList(List);
    cout << endl;

    FindNodeByData(List, "Latte");
    FindNodeByAddress(List, C);
    FindNodeByRange(List, 20000, 27000);

    delFirst(List);
    delLast(List);
    delAfter(List, D, C);

    cout << "--- MENU SETELAH DELETE ---" << endl;
    printList(List);
    cout << endl;

    deleteList(List);
    cout << "--- MENU SETELAH DIHAPUS SEMUA ---" << endl;
    printList(List);

    return 0;
}
```

### Output:
<img width="1698" height="899" alt="image" src="https://github.com/user-attachments/assets/f7bd2f33-025d-48c4-ab73-0817e7627b68" />

Program ini merupakan pengembangan dari contoh soal Guided dengan tema berbeda, yaitu daftar menu minuman.
Setiap node menyimpan informasi nama minuman, ukuran cup/gelas, dan harga, serta pointer untuk menghubungkan antar data.
Program ini juga dibagi menjadi tiga file:
Program dibagi menjadi tiga file agar lebih rapi:
- listMinuman.h berisi deklarasi struktur data dan fungsi.
- listMinuman.cpp berisi implementasi operasi seperti insert, delete, update, dan searching.
- main.cpp menjalankan operasi seperti menambah, memperbarui, mencari, dan menghapus data menu.<br>
Fitur-fitur utama yang diimplementasikan:
- Insert (insertFirst, insertAfter, insertLast) untuk menambah menu,
- Update (updateFirst, updateAfter, updateLast) untuk mengubah data minuman tertentu,
- Search (FindNodeByData, FindNodeByAddress, FindNodeByRange) untuk mencari menu berdasarkan nama, alamat, atau harga,
- Delete (delFirst, delAfter, delLast, deleteList) untuk menghapus menu dari list.

### Full Code Screenshot:
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/2aa2cd23-9913-4a22-a6a5-285ce575f1b1" />

### 2. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”
<img width="668" height="249" alt="Image" src="https://github.com/user-attachments/assets/9fb99399-ca92-43ea-979a-7afd58e8f554" /><br>
Kemudian buat implementasi ADT Singly Linked list pada file “Singlylist.cpp”.
Adapun isi data <br> 
<img width="670" height="132" alt="image" src="https://github.com/user-attachments/assets/69e24f6f-6abd-416f-822a-b9a28fde841c" /><br>
Cobalah hasil implementasi ADT pada file “main.cpp”  
<img width="900" height="506" alt="Image" src="https://github.com/user-attachments/assets/e41e3550-65c3-4dbd-a870-f0d0829f01c8" /><br>

<img width="861" height="156" alt="Image" src="https://github.com/user-attachments/assets/e6fa0a81-fbfa-42f2-8cb2-784252028208" /><br>

file: Singlylist.h
```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

// deklarasi tipe data dasar
typedef int infotype;
typedef struct ElmtList *address;

//struktur elemen list
struct ElmtList {
    infotype info;
    address next;
};

// struktur list
struct List {
    address first;
};

// deklarasi function dan procedure
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

// buat list kosong
void createList(List &L) {
    L.first = NULL;
}

// alokasi node baru
address alokasi(infotype x) {
    address P = new ElmtList;
    P->info = x;
    P->next = NULL;
    return P;
}

// hapus alokasi node dari memori
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

// menampilkan semua isi list
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

    // inisialisasi list kosong
    createList(L);

    // menambahkan elemen ke list
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

    // menampilkan isi list
    cout << "Isi Linked List: ";
    printInfo(L);

    return 0;
}
```

#### Output:
<img width="687" height="118" alt="image" src="https://github.com/user-attachments/assets/5319e3b1-a70a-4217-af67-00621f86eb12" />

Program di atas digunakan untuk membuat dan menampilkan data dalam struktur data Single Linked List.
Data bertipe int dan disimpan dalam node-node yang saling terhubung satu arah.
Program dibagi menjadi tiga file agar lebih terstruktur:
- Singlylist.h berisi deklarasi struct dan fungsi.
- Singlylist.cpp berisi implementasi fungsi seperti membuat list, menambah node, dan menampilkan isi list.
- main.cpp berisi program utama untuk menjalankan operasi insert dan menampilkan isi list ke layar.
Fungsi utamanya adalah menampilkan cara kerja penambahan data di awal list (insertFirst).

#### Full code Screenshot:
<img width="1915" height="1026" alt="image" src="https://github.com/user-attachments/assets/8d726cec-2496-43ef-b684-f8f6285dee7d" />

### 3. Carilah elemen dengan info 8 dengan membuat fungsi baru.<br>
fungsi findElm( L : List, x : infotype ) : address<br>
<img width="602" height="70" alt="image" src="https://github.com/user-attachments/assets/f3193ac1-62e1-4d57-aeb4-2ddb5462e8eb" />

File: Singlylist.h
```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

// deklarasi tipe data dasar
typedef int infotype;
typedef struct ElmtList *address;

// struktur elemen list
struct ElmtList {
    infotype info;
    address next;
};

// struktur list
struct List {
    address first;
};

// deklarasi function dan procedure
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void printInfo(List L);

address findElm(List L, infotype x); //tambahan

#endif // SINGLYLIST_H_INCLUDED
```
File: Singlylist.CPP
```C++
#include "SinglyList.h"

// buat list kosong
void createList(List &L) {
    L.first = NULL;
}

// alokasikan node baru
address alokasi(infotype x) {
    address P = new ElmtList;
    P->info = x;
    P->next = NULL;
    return P;
}

// hapus alokasi node dari memori
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

// menampilkan semua isi list
void printInfo(List L) {
    address P = L.first;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

//tambahan
address findElm(List L, infotype x) {
    address P = L.first;
    while (P != NULL) {
        if (P->info == x) {
            return P; // kalau ketemu, balikin alamat node
        }
        P = P->next;
    }
    return NULL; // kalau gak ketemu
}
```

File: main.cpp
```C++
#include "SinglyList.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    // inisialisasi list kosong
    createList(L);

    // menambahkan elemen ke list
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

    // menampilkan isi list
    cout << "Isi Linked List: ";
    printInfo(L);

    address hasil = findElm(L, 8); //tambahan
    if (hasil != NULL) {
        cout << hasil->info << " ditemukan dalam list" << endl;
    } else {
        cout << "Elemen tidak ditemukan dalam list" << endl;
    }


    return 0;
}
```
### Output:
<img width="733" height="340" alt="image" src="https://github.com/user-attachments/assets/f9f8f7a5-34aa-4a08-a028-be52fc6cb79c" />

Program di atas menambahkan fungsi findElm() untuk mencari elemen tertentu dalam Single Linked List berdasarkan nilai datanya. Jika data ditemukan, program akan menampilkan bahwa elemen tersebut ada dalam list. 

### Full Code Screenshot:
<img width="1919" height="1023" alt="image" src="https://github.com/user-attachments/assets/ae9a8c8a-0694-43d7-a026-e527c200bdc4" />

### 4. Hitunglah jumlah total info seluruh elemen (9+12+8+0+2=31).<br>
<img width="609" height="73" alt="image" src="https://github.com/user-attachments/assets/5833d2c2-fdd0-410e-aad2-0150ad68df76" /><br>  

File: Singlylist.h
```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

// deklarasi tipe data dasar
typedef int infotype;
typedef struct ElmtList *address;

// struktur elemen list
struct ElmtList {
    infotype info;
    address next;
};

// struktur list
struct List {
    address first;
};

// deklarasi function dan procedure
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void printInfo(List L);

int sumElm(List L); //tambahan

#endif // SINGLYLIST_H_INCLUDED
```

File: Singlylist.cpp
```C++
#include "SinglyList.h"

// buat list kosong
void createList(List &L) {
    L.first = NULL;
}

// alokasi node baru
address alokasi(infotype x) {
    address P = new ElmtList;
    P->info = x;
    P->next = NULL;
    return P;
}

// hapus alokasi node dari memori
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

// menampilkan semua isi list
void printInfo(List L) {
    address P = L.first;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

int sumElm(List L) { //tambahan
    int total = 0;
    address P = L.first;
    while (P != NULL) {
        total += P->info;
        P = P->next;
    }
    return total;
}
```

File: main.cpp
```C++
#include "SinglyList.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    // inisialisasi list kosong
    createList(L);

    // menambahkan elemen ke list
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

    // menampilkan isi list
    cout << "Isi Linked List: ";
    printInfo(L);

    int total = sumElm(L); //tambahan
    cout << "Total info dari kelima elemen adalah " << total << endl;
    return 0;
}
```
### Output:
<img width="691" height="154" alt="image" src="https://github.com/user-attachments/assets/41a17050-bc74-41fa-b533-7c84dd835cad" />

Program di atas menambahkan fungsi sumElm() untuk menghitung jumlah total seluruh data pada Single Linked List. Fungsi ini menelusuri setiap node dan menjumlahkan nilai info pada tiap elemen, lalu menampilkan hasil totalnya ke layar

### Full Code Screenshot:
<img width="1919" height="1023" alt="image" src="https://github.com/user-attachments/assets/ec0b7fff-f3ec-4b33-a4d5-b329f8247f25" />

## Kesimpulan
Dari praktikum ini dapat disimpulkan bahwa Singly Linked List tidak hanya digunakan untuk menambah dan menghapus data, tetapi juga dapat dikembangkan untuk melakukan proses update dan searching.
Operasi update memungkinkan pengguna mengubah isi node tertentu tanpa perlu membuat node baru, sedangkan operasi searching membantu menemukan data berdasarkan nama, alamat node, atau rentang nilai tertentu.
Konsep pointer menjadi bagian penting, karena semua proses seperti penelusuran, pengubahan, maupun pencarian data dilakukan melalui hubungan antar-node yang dibentuk oleh pointer tersebut.

