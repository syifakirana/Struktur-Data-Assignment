# <h1 align="center">Laporan Praktikum Modul Singly Linked List (2)</h1>
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
#include <iostream>
using namespace std;


```
File: listMinuman.cpp
```C++

```
File: main.cpp
```C++

```

### Output:
<img width="513" height="306" alt="Image" src="https://github.com/user-attachments/assets/820d5bb0-69d5-4c2d-9600-63f8594d1b98" />

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
<img width="1913" height="1028" alt="Image" src="https://github.com/user-attachments/assets/d9656c1b-a2c0-4f81-91c5-ceec7868c327" />


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
<img width="687" height="118" alt="image" src="https://github.com/user-attachments/assets/5319e3b1-a70a-4217-af67-00621f86eb12" />

Program di atas digunakan untuk membuat dan menampilkan data dalam struktur data Single Linked List.
Data bertipe int dan disimpan dalam node-node yang saling terhubung satu arah.
Program dibagi menjadi tiga file agar lebih terstruktur:
- Singlylist.h berisi deklarasi struct dan fungsi.
- Singlylist.cpp berisi implementasi fungsi seperti membuat list, menambah node, dan menampilkan isi list.
- main.cpp berisi program utama untuk menjalankan operasi insert dan menampilkan isi list ke layar.
Fungsi utamanya adalah menampilkan cara kerja penambahan data di awal list (insertFirst).

#### Full code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/ef7be654-ba67-4c25-ac6a-366ac7ede603" />


### 3. Carilah elemen dengan info 8 dengan membuat fungsi baru.<br>
fungsi findElm( L : List, x : infotype ) : address<br>
<img width="602" height="70" alt="image" src="https://github.com/user-attachments/assets/f3193ac1-62e1-4d57-aeb4-2ddb5462e8eb" />

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan angka: ";
    cin >> n;

    for (int i = n; i >= 1; i--) {
        // cetak spasi di depan
        for (int s = 0; s < (n - i); s++) {
            cout << "  "; // 2 spasi biar rapi
        }

        // kiri menurun
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        // bintang
        cout << "* ";

        // kanan menaik
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        cout << endl;
    }

    // baris terakhir spasi terus bintang
    for (int s = 0; s < n; s++) {
        cout << "  ";
    }
    cout << "*";

    return 0;
}

```
### Output:
<img width="733" height="340" alt="image" src="https://github.com/user-attachments/assets/f9f8f7a5-34aa-4a08-a028-be52fc6cb79c" />

Program di atas menambahkan fungsi findElm() untuk mencari elemen tertentu dalam Single Linked List berdasarkan nilai datanya. Jika data ditemukan, program akan menampilkan bahwa elemen tersebut ada dalam list. 

### Full Code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/d2a1cbda-901b-47e3-b430-8d8a1cd9cffd" />


### 4. Hitunglah jumlah total info seluruh elemen (9+12+8+0+2=31).<br>
<img width="609" height="73" alt="image" src="https://github.com/user-attachments/assets/5833d2c2-fdd0-410e-aad2-0150ad68df76" />


```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan angka: ";
    cin >> n;

    for (int i = n; i >= 1; i--) {
        // cetak spasi di depan
        for (int s = 0; s < (n - i); s++) {
            cout << "  "; // 2 spasi biar rapi
        }

        // kiri menurun
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        // bintang
        cout << "* ";

        // kanan menaik
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        cout << endl;
    }

    // baris terakhir spasi terus bintang
    for (int s = 0; s < n; s++) {
        cout << "  ";
    }
    cout << "*";

    return 0;
}

```
### Output:
<img width="691" height="154" alt="image" src="https://github.com/user-attachments/assets/41a17050-bc74-41fa-b533-7c84dd835cad" />

Program di atas menambahkan fungsi sumElm() untuk menghitung jumlah total seluruh data pada Single Linked List. Fungsi ini menelusuri setiap node dan menjumlahkan nilai info pada tiap elemen, lalu menampilkan hasil totalnya ke layar

### Full Code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/d2a1cbda-901b-47e3-b430-8d8a1cd9cffd" />


## Kesimpulan
Dari praktikum ini dapat disimpulkan bahwa Singly Linked List tidak hanya digunakan untuk menambah dan menghapus data, tetapi juga dapat dikembangkan untuk melakukan proses update dan searching.
Operasi update memungkinkan pengguna mengubah isi node tertentu tanpa perlu membuat node baru, sedangkan operasi searching membantu menemukan data berdasarkan nama, alamat node, atau rentang nilai tertentu.
Konsep pointer menjadi bagian penting, karena semua proses seperti penelusuran, pengubahan, maupun pencarian data dilakukan melalui hubungan antar-node yang dibentuk oleh pointer tersebut.
