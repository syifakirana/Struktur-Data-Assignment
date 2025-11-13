# <h1 align="center">Laporan Praktikum Modul Stack</h1>
<p align="center">Syifa Kirana Putri Surya</p>
<p align="center">103112400111</p>

## Dasar Teori
Materi ini merupakan lanjutan dari Singly Linked List. Membahas operasi yang lebih kompleks, yaitu update (perubahan data) dan searching (pencarian data). Jika pada pertemuan sebelumnya list hanya digunakan untuk menambah, menghapus, dan menampilkan data, maka pada bagian ini list akan dikembangkan.

Operasi update membuat pengguna bisa mengubah isi data pada node tertentu tanpa harus menghapusnya terlebih dahulu. Perubahan dapat dilakukan pada node pertama (updateFirst), node terakhir (updateLast), maupun node setelah node tertentu (updateAfter).

Operasi searching, yaitu proses pencarian data dalam list. Pencarian dapat dilakukan berdasarkan isi data (FindNodeByData), alamat node (FindNodeByAddress), atau range nilai tertentu (FindNodeByRange). Dengan cara ini, pengguna dapat menemukan dan menampilkan data yang spesifik sesuai kebutuhan program.

Secara umum, konsep dasar Singly Linked List tetap sama setiap node memiliki dua bagian, yaitu info dan pointer next, dan seluruh node saling terhubung satu arah. Perbedaan utamanya adalah pada kemampuan program dalam memperbarui dan mencari data secara lebih efisien, tanpa harus membuat atau menghapus node baru.

---

## Guided

### 1. Program Implementasi Operasi Lengkap pada Single Linked List (List Buah)

File: listBuah.h
```cpp
//Header guard digunakan untuk mencegah file header yg sama
// di-include lebih dari sekali dalam satu program 
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL 

#include <iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah; //memberikan nama alias dataBuah untuk struct buah

typedef struct node *address; //mendefinisikan alias address sebagai pointer ke struct node

struct node{ //node untuk isi linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{//ini linked listnya 
    address first;
};

//semua function &prosedur yg akan dipakai 
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
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

//materi modul 5 (part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (part 2 - searching)
void FindNodeByData(linkedlist List, string data);
void FindNodeByAddress(linkedlist List, address node);
void FindNodeByRange(linkedlist List, float hargaAwal, float HargaAkhir);

#endif
```
File: listBuah.cpp
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

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
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
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
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
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
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
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
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 2 (SEARCHING) -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```
File: main.cpp
```C++
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

   updateFirst(List);
   updateLast(List);
   updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData (List, "Kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

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
Program ini digunakan untuk mengelola data buah menggunakan struktur data Singly Linked List (SLL).
Setiap node pada list menyimpan informasi nama buah, jumlah, dan harga, serta pointer yang menghubungkan antar node.
Program dibagi menjadi tiga file agar lebih terstruktur:
- listBuah.h berisi deklarasi struct, tipe data, dan prototype fungsi/prosedur,
- listBuah.cpp berisi implementasi fungsi dan prosedur seperti insert, delete, update, dan searching,
- main.cpp sebagai file utama untuk menjalankan semua proses.<br>

Fungsi utama yang digunakan dalam program ini antara lain:
- insertFirst, insertAfter, insertLast untuk menambahkan data buah di awal, tengah, dan akhir list,
- delFirst, delAfter, delLast untuk menghapus node dari berbagai posisi,
- updateFirst, updateAfter, updateLast untuk memperbarui isi data buah tanpa membuat node baru,
- FindNodeByData, FindNodeByAddress, FindNodeByRange untuk melakukan pencarian data berdasarkan nama, alamat node, dan range harga,
- deleteList untuk menghapus seluruh isi list dari memori sepenuhnya.

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

