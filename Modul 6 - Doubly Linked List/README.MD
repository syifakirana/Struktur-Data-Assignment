# <h1 align="center">Laporan Praktikum Modul Doubly Linked List </h1>
<p align="center">Syifa Kirana Putri Surya</p>
<p align="center">103112400111</p>

## Dasar Teori
Materi ini merupakan 

---

## Guided

### 1. Implementasi Operasi Penghapusan pada Doubly Linked List (Guided1)

File: dll_hapus.cpp
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
Program ini digunakan untuk mempraktikkan operasi penghapusan elemen pada Doubly Linked List (DLL). Pada DLL, setiap node memiliki dua pointer, yaitu next (menuju elemen berikutnya) dan prev (menuju elemen sebelumnya), sehingga pergerakan data dapat dilakukan dua arah.  
Program ini menyediakan tiga jenis operasi hapus:  
deleteFirst: menghapus node pertama  
deleteLast: menghapus node terakhir  
deleteAfter: menghapus node setelah node tertentu  
Sebelumnya, program juga memuat operasi alokasi untuk membuat node baru dan insertFirst untuk menambahkan data di awal list. Pada fungsi main, program memasukkan tiga elemen (3, 2, 1), lalu melakukan penghapusan node pertama dan penghapusan node setelah head. Setelah setiap proses, pointer prev dan next diperbarui agar struktur list tetap konsisten. Hasil akhirnya ditampilkan dengan fungsi printInfo.

### 2. Implementasi Operasi Penyisipan pada Doubly Linked List (Guided 2)

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
Program ini digunakan untuk menyisipkan data ke dalam Doubly Linked List menggunakan tiga operasi utama, yaitu insertFirst, insertLast, dan insertAfter. Doubly linked list memungkinkan setiap node terhubung ke node sebelum dan sesudahnya melalui pointer prev dan next.
insertFirst menambah node baru di bagian paling depan list. Jika list kosong, node tersebut akan langsung menjadi elemen pertama sekaligus terakhir.
insertLast menambah node baru di bagian paling belakang list. Jika sebelumnya list kosong, node akan menjadi elemen pertama dan terakhir.
insertAfter digunakan untuk menyisipkan node di tengah list, yaitu setelah node tertentu (node R). Jika node R adalah node terakhir, maka node baru akan menjadi elemen terakhir list.
Di fungsi main, program membuat list kosong, lalu menambahkan tiga elemen: elemen pertama dimasukkan ke depan, elemen kedua dimasukkan ke belakang, dan elemen ketiga dimasukkan di tengah (setelah node pertama). Terakhir, printInfo digunakan untuk menampilkan seluruh isi list.

## Unguided

### 1. Buatlah ADT Doubly Linked list sebagai berikut di dalam file “Doublylist.h”:
<img width="546" height="285" alt="Image" src="https://github.com/user-attachments/assets/0b38ba77-f770-4c5a-bfae-bcb60abd7446" /><br>
Buatlah implementasi ADT Doubly Linked list pada file “Doublylist.cpp” dan coba hasil
implementasi ADT pada file “main.cpp”.<br>
<img width="505" height="354" alt="Image" src="https://github.com/user-attachments/assets/18393c6e-357e-46f6-bac0-e696f4adb33e" /><br>

File: doublylist.h
```cpp
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <string>
using namespace std;

struct infotipe {
    string nopol;
    string warna;
    int thnBuat;
};

struct ElmList;
typedef ElmList* address;

struct ElmList {
    infotipe info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotipe x);
void dealokasi(address P);
void insertLast(List &L, address P);
void printInfo(List L);

#endif
```
File: doublylist.cpp
```cpp
#include "Doublylist.h"
#include <iostream>
using namespace std;

void CreateList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

address alokasi(infotipe x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void dealokasi(address P) {
    delete P;
}

void insertLast(List &L, address P) {
    if (L.First == nullptr) {
        L.First = P;
        L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

void printInfo(List L) {
    cout << "DATA LIST 1\n\n";

    address Q = L.Last; 
    while (Q != nullptr) {
        cout << "no polisi : " << Q->info.nopol << endl;
        cout << "warna     : " << Q->info.warna << endl;
        cout << "tahun     : " << Q->info.thnBuat << endl;
        cout << endl;
        Q = Q->prev;
    }
}
```
File: main.cpp
```cpp
#include <iostream>
#include "Doublylist.h"
using namespace std;

int main() {
    List L;
    CreateList(L);

    const int JUMLAH_INPUT = 4; 
    for (int i = 0; i < JUMLAH_INPUT; ++i) {
        infotipe x;

        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;

        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;

        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        cout << endl;

        // cek duplikat
        bool exists = false;
        for (address Q = L.First; Q != nullptr; Q = Q->next) {
            if (Q->info.nopol == x.nopol) {
                exists = true;
                break;
            }
        }

        if (exists) {
            cout << "nomor polisi sudah terdaftar" << endl;
            cout << endl;
        } else {
            address P = alokasi(x);
            insertLast(L, P);
        }
    }

    printInfo(L);

    address curr = L.First;
    while (curr != nullptr) {
        address toDel = curr;
        curr = curr->next;
        dealokasi(toDel);
    }
    L.First = L.Last = nullptr;

    return 0;
}
```
### Output:
<img width="1019" height="759" alt="Image" src="https://github.com/user-attachments/assets/3bcaa261-439e-45c6-923c-032fde9acb90" />  

Program ini mengimplementasikan struktur data Doubly Linked List untuk menyimpan data kendaraan, yaitu nomor polisi, warna kendaraan, dan tahun. Setiap data disimpan dalam satu node yang memiliki pointer next dan prev, sehingga list bisa ditelusuri ke depan maupun ke belakang. Pertama, list diinisialisasi kosong menggunakan CreateList(), pointer First dan Last diset menjadi nullptr. Setelah itu, program meminta pengguna memasukkan data kendaraan. Setiap kali data dimasukkan, dilakukan pengecekan apakah nomor polisi sudah ada atau belum, dengan menelusuri list dari node pertama (First). Jika ditemukan nomor polisi yang sama, program menampilkan pesan bahwa data sudah terdaftar dan tidak menambahkan node baru ke list. Jika nomor polisi belum ada, program membuat node baru melalui alokasi() lalu menambahkannya ke bagian belakang list menggunakan insertLast(). mengatur pointer next dan prev agar node baru terhubung dengan benar, dan memperbarui pointer Last. Setelah semua selesai diinput, program menampilkan seluruh isi list dengan printInfo(). Penelusuran dilakukan dari node terakhir menuju node pertama menggunakan pointer prev. Dengan cara ini, data kendaraan muncul dari urutan input yang terakhir hingga yang pertama, sesuai format contoh pada soal. Di bagian akhir program, semua node yang masih ada di list dihapus satu per satu menggunakan dealokasi() supaya memori yang dipakai tidak dibiarkan begitu saja. Setelah seluruh node dihapus, pointer First dan Last diset kembali menjadi nullptr sebagai tanda bahwa list sudah kosong.

### Full Code Screenshot:
<img width="1919" height="989" alt="Image" src="https://github.com/user-attachments/assets/981ab268-e96d-4d4f-bea4-562e1a6d5828" />  

### 2. Carilah elemen dengan nomor polisi D001 dengan membuat fungsi baru.
fungsi findElm( L : List, x : infotype ) : address<br>

<img width="524" height="222" alt="Image" src="https://github.com/user-attachments/assets/ce6315ea-cc33-492a-b687-63f8f57c81b3" /><br>

File: doublylist.h
```cpp
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <string>
using namespace std;

struct infotipe {
    string nopol;
    string warna;
    int thnBuat;
};

struct ElmList;
typedef ElmList* address;

struct ElmList {
    infotipe info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotipe x);
void dealokasi(address P);
void insertLast(List &L, address P);
void printInfo(List L);

address findElm(List L, string nopol); //tambahan

#endif
```
File: doublylist.cpp
```cpp
#include "Doublylist.h"
#include <iostream>
using namespace std;

void CreateList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

address alokasi(infotipe x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void dealokasi(address P) {
    delete P;
}

void insertLast(List &L, address P) {
    if (L.First == nullptr) {
        L.First = P;
        L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

void printInfo(List L) {
    cout << "DATA LIST 1\n\n";

    address Q = L.Last; 
    while (Q != nullptr) {
        cout << "no polisi : " << Q->info.nopol << endl;
        cout << "warna     : " << Q->info.warna << endl;
        cout << "tahun     : " << Q->info.thnBuat << endl;
        cout << endl;
        Q = Q->prev;
    }
}

address findElm(List L, string nopol) { //tambahan
    address P = L.First;
    while (P != nullptr) {
        if (P->info.nopol == nopol) {
            return P;       
        P = P->next;
    }
    return nullptr;         
}
```
File: main.cpp
```cpp
#include <iostream>
#include "Doublylist.h"
using namespace std;

int main() {
    List L;
    CreateList(L);

    const int JUMLAH_INPUT = 4;
    for (int i = 0; i < JUMLAH_INPUT; ++i) {
        infotipe x;

        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;

        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;

        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        cout << endl;

        // cek duplikat
        bool exists = false;
        for (address Q = L.First; Q != nullptr; Q = Q->next) {
            if (Q->info.nopol == x.nopol) {
                exists = true;
                break;
            }
        }

        if (exists) {
            cout << "nomor polisi sudah terdaftar" << endl;
            cout << endl;
        } else {
            address P = alokasi(x);
            insertLast(L, P);
        }
    }

    // Tampilkan isi list
    printInfo(L);
    
    //tambahan
    string cari;
    cout << "Masukkan Nomor Polisi yang dicari : ";
    cin >> cari;

    address hasil = findElm(L, cari);
    cout << endl;

    if (hasil != nullptr) {
        cout << "Nomor Polisi : " << hasil->info.nopol << endl;
        cout << "Warna        : " << hasil->info.warna << endl;
        cout << "Tahun        : " << hasil->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan!" << endl;
    }

    address curr = L.First;
    while (curr != nullptr) {
        address toDel = curr;
        curr = curr->next;
        dealokasi(toDel);
    }
    L.First = L.Last = nullptr;

    return 0;
}
```

#### Output:
<img width="1310" height="731" alt="Image" src="https://github.com/user-attachments/assets/c7f85c5f-7a5c-4510-8f81-ad4c37dd45dc" />  

Program masih menggunakan Doubly Linked List yang sama seperti sebelumnya, namun kali ini ditambahkan fitur untuk mencari elemen berdasarkan nomor polisi. Setelah seluruh data kendaraan dimasukkan dan list terbentuk, program meminta pengguna memasukkan nomor polisi yang ingin dicari. Proses pencarian dilakukan dengan menelusuri list dari node pertama menggunakan pointer next, dan setiap node dicek apakah nomor polisinya sesuai dengan input pengguna.
Jika data ditemukan, program menampilkan informasi lengkap dari node tersebut, seperti nomor polisi, warna kendaraan, dan tahun pembuatannya. Sebaliknya, jika tidak ada node yang memiliki nomor polisi tersebut, program menampilkan pesan bahwa data tidak ditemukan. Fitur pencarian ini memanfaatkan fungsi findElm(), yang mengembalikan alamat node jika cocok, atau nullptr jika tidak.

#### Full code Screenshot:
<img width="1919" height="894" alt="Image" src="https://github.com/user-attachments/assets/65353859-0d01-4427-8e58-9020d2e6008c" />  

### 3. Hapus elemen dengan nomor polisi D003 dengan procedure delete.
- procedure deleteFirst( input/output L : List, P : address )
- procedure deleteLast( input/output L : List, P : address )
- procedure deleteAfter( input Prec : address, input/output P : address )  <br>

<img width="665" height="313" alt="Image" src="https://github.com/user-attachments/assets/af7786d5-a12d-4b99-b3c7-b84dc2b33a13" /><br>

File: doublylist.h
```cpp
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <string>
using namespace std;

struct infotipe {
    string nopol;
    string warna;
    int thnBuat;
};

struct ElmList;
typedef ElmList* address;

struct ElmList {
    infotipe info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotipe x);
void dealokasi(address P);
void insertLast(List &L, address P);
void printInfo(List L);

// soal 2
address findElm(List L, string nopol);

// tambahan soal 3
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif
```
File: doublylist.cpp
```cpp
#include "Doublylist.h"
#include <iostream>
using namespace std;

void CreateList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

address alokasi(infotipe x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void dealokasi(address P) {
    delete P;
}

void insertLast(List &L, address P) {
    if (L.First == nullptr) {
        L.First = P;
        L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

void printInfo(List L) {
    cout << "DATA LIST 1\n\n";
    address Q = L.Last;
    while (Q != nullptr) {
        cout << "no polisi : " << Q->info.nopol << endl;
        cout << "warna     : " << Q->info.warna << endl;
        cout << "tahun     : " << Q->info.thnBuat << endl;
        cout << endl;
        Q = Q->prev;
    }
}

address findElm(List L, string nopol) {
    address Q = L.First;
    while (Q != nullptr) {
        if (Q->info.nopol == nopol) return Q;
        Q = Q->next;
    }
    return nullptr;
}

// deleteFirst (soal 3)
void deleteFirst(List &L, address &P) {
    if (L.First == nullptr) {
        P = nullptr;
        return;
    }

    P = L.First;
    if (L.First == L.Last) {
        // only one node
        L.First = nullptr;
        L.Last = nullptr;
    } else {
        L.First = P->next;
        L.First->prev = nullptr;
        P->next = nullptr;
    }
}

// deleteLast (soal 3)
void deleteLast(List &L, address &P) {
    if (L.Last == nullptr) {
        P = nullptr;
        return;
    }

    P = L.Last;
    if (L.First == L.Last) {
        // only one node
        L.First = nullptr;
        L.Last = nullptr;
    } else {
        L.Last = P->prev;
        L.Last->next = nullptr;
        P->prev = nullptr;
    }
}
//deleteAfter 
void deleteAfter(address Prec, address &P) {
    if (Prec == nullptr || Prec->next == nullptr) {
        P = nullptr;
        return;
    }
    P = Prec->next;
    Prec->next = P->next;
    if (P->next != nullptr) {
        P->next->prev = Prec;
    }
    P->next = nullptr;
    P->prev = nullptr;
}
```
File: main.cpp
```cpp
#include <iostream>
#include "Doublylist.h"
using namespace std;

int main() {
    List L;
    CreateList(L);

    const int JUMLAH_INPUT = 4;

    for (int i = 0; i < JUMLAH_INPUT; ++i) {
        infotipe x;

        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;

        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;

        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        cout << endl;

        bool exists = false;
        for (address Q = L.First; Q != nullptr; Q = Q->next) {
            if (Q->info.nopol == x.nopol) {
                exists = true;
                break;
            }
        }

        if (exists) {
            cout << "nomor polisi sudah terdaftar" << endl << endl;
        } else {
            insertLast(L, alokasi(x));
        }
    }

    printInfo(L);

    string key;
    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> key;
    cout << endl;

    address target = findElm(L, key);

    if (target == nullptr) {
        cout << "Data dengan nomor polisi " << key << " tidak ditemukan" << endl;
    } else {
        address P = nullptr;

        if (target == L.First) {
            deleteFirst(L, P);
        } else if (target == L.Last) {
            deleteLast(L, P);
        } else {
            deleteAfter(target->prev, P);
            if (target->prev->next == nullptr) {
                L.Last = target->prev;
            }
        }

        if (P != nullptr) {
            cout << "Data dengan nomor polisi " << key << " berhasil dihapus." << endl << endl;
            dealokasi(P);
        } else {
            cout << "Gagal menghapus data." << endl << endl;
        }

        printInfo(L);
    }

    address cur = L.First;
    while (cur != nullptr) {
        address toDel = cur;
        cur = cur->next;
        dealokasi(toDel);
    }

    return 0;
}
```

### Output:
<img width="1204" height="675" alt="Image" src="https://github.com/user-attachments/assets/61b014e3-512a-46c9-b215-c9bd892a2926" />

Program di atas 

### Full Code Screenshot:
<img width="1919" height="932" alt="Image" src="https://github.com/user-attachments/assets/ec903dc6-306c-490e-a26d-3966f036d297" />


## Kesimpulan
Dari praktikum ini dapat disimpulkan bahwa 

