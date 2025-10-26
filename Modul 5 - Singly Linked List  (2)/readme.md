# <h1 align="center">Laporan Praktikum Modul Singly Linked List (2)</h1>
<p align="center">Syifa Kirana Putri Surya</p>
<p align="center">103112400111</p>

## Dasar Teori
1. Variabel dan Tipe Data  
Variabel merupakan wadah untuk menyimpan data dalam program. Setiap variabel memiliki tipe data tertentu yang menentukan jenis nilai yang dapat disimpan, seperti int untuk bilangan bulat, float untuk bilangan desimal, dan string untuk teks. Pemilihan tipe data yang tepat penting agar program dapat berjalan secara efisien dan meminimalisir kesalahan.

2. Input dan Output  
Input adalah proses memasukkan data ke dalam program, biasanya menggunakan fungsi cin pada C++. Output merupakan proses menampilkan data ke layar, contohnya menggunakan cout. Dengan mekanisme input dan output, program dapat berinteraksi secara langsung dengan pengguna.

3. Operator Aritmatika  
Operator aritmatika digunakan untuk melakukan perhitungan matematis, seperti penjumlahan (+), pengurangan (-), perkalian (*), dan pembagian (/). Operator ini dapat diterapkan pada berbagai tipe data numerik untuk menghasilkan nilai baru.

4. Operator Perbandingan  
Operator perbandingan digunakan untuk membandingkan dua nilai dan menghasilkan hasil berupa nilai logika true atau false. Contohnya == (sama dengan), != (tidak sama dengan), < (lebih kecil), > (lebih besar), <= (lebih kecil atau sama dengan), dan >= (lebih besar atau sama dengan). Operator ini sering digunakan dalam percabangan dan perulangan untuk pengambilan keputusan.

5. Percabangan (Conditional Statement)  
Percabangan memungkinkan program memilih jalannya eksekusi berdasarkan kondisi tertentu. Struktur if, else if, dan else memungkinkan kode tertentu dijalankan hanya jika kondisi terpenuhi, sehingga program dapat berjalan secara fleksibel dan responsif terhadap input pengguna.

6. Perulangan (Loop)  
Perulangan digunakan untuk mengeksekusi sekelompok perintah secara berulang hingga kondisi tertentu terpenuhi. Contohnya for, while, dan do-while. Penggunaan perulangan membantu mengurangi penulisan kode berulang dan mempermudah pengolahan data dalam jumlah besar.

7. Array  
Array adalah struktur data yang menyimpan sekumpulan nilai dengan tipe yang sama dalam satu variabel. Nilai-nilai dalam array dapat diakses melalui indeksnya. Array mempermudah pengelolaan data yang banyak, sehingga program dapat dijalankan dengan lebih efisien dan terstruktur.

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
Program ini digunakan untuk mengelola data buah menggunakan struktur data Single Linked List (SLL).
Setiap node pada list menyimpan informasi nama buah, jumlah, dan harga, serta pointer yang menghubungkan antar node.
Program dibagi menjadi tiga file agar lebih terstruktur:
- listBuah.h berisi deklarasi struct, tipe data, dan prototype fungsi/prosedur,
- listBuah.cpp berisi implementasi fungsi dan prosedur seperti insert, delete, update, dan searching,
- main.cpp sebagai file utama untuk menjalankan semua proses.
Fungsi utama yang digunakan dalam program ini antara lain:
- insertFirst, insertAfter, insertLast untuk menambahkan data buah di awal, tengah, dan akhir list,
- delFirst, delAfter, delLast untuk menghapus node dari berbagai posisi,
- updateFirst, updateAfter, updateLast untuk memperbarui isi data buah tanpa membuat node baru,
- FindNodeByData, FindNodeByAddress, FindNodeByRange untuk melakukan pencarian data berdasarkan nama, alamat node, dan range harga,
- deleteList untuk menghapus seluruh isi list dari memori sepenuhnya.
Program ini menunjukkan bagaimana operasi dasar dan tambahan pada linked list saling terhubung membentuk satu sistem yang efisien.

## Unguided

### 1. Program Manajemen Menu Minuman Menggunakan Single Linked List

File: listMinuman.h
```cpp
#include <iostream>
using namespace std;


```
File: listMinuman.cpp

File: main.cpp

### Output:
<img width="513" height="306" alt="Image" src="https://github.com/user-attachments/assets/820d5bb0-69d5-4c2d-9600-63f8594d1b98" />

Program ini merupakan pengembangan dari contoh soal Guided dengan tema berbeda, yaitu daftar menu minuman.
Setiap node menyimpan informasi nama minuman, ukuran cup/gelas, dan harga, serta pointer untuk menghubungkan antar data.
Program ini juga dibagi menjadi tiga file:
Program dibagi menjadi tiga file agar lebih rapi:
- listMinuman.h berisi deklarasi struktur data dan fungsi.
- listMinuman.cpp berisi implementasi operasi seperti insert, delete, update, dan searching.
- main.cpp menjalankan operasi seperti menambah, memperbarui, mencari, dan menghapus data menu.
Fitur-fitur utama yang diimplementasikan:
- Insert (insertFirst, insertAfter, insertLast) untuk menambah menu,
- Update (updateFirst, updateAfter, updateLast) untuk mengubah data minuman tertentu,
- Search (FindNodeByData, FindNodeByAddress, FindNodeByRange) untuk mencari menu berdasarkan nama, alamat, atau harga,
- Delete (delFirst, delAfter, delLast, deleteList) untuk menghapus menu dari list.

### Full Code Screenshot:
<img width="1913" height="1028" alt="Image" src="https://github.com/user-attachments/assets/d9656c1b-a2c0-4f81-91c5-ceec7868c327" />


### 2. Unguided1

```cpp
#include <iostream>
using namespace std;

int main() {
    string satuan[] = {"nol","satu","dua","tiga","empat","lima",
                       "enam","tujuh","delapan","sembilan"};
    string belasan[] = {"sepuluh","sebelas","dua belas","tiga belas","empat belas",
                        "lima belas","enam belas","tujuh belas","delapan belas","sembilan belas"};
    string puluhan[] = {"","sepuluh","dua puluh","tiga puluh","empat puluh",
                        "lima puluh","enam puluh","tujuh puluh","delapan puluh","sembilan puluh"};

    int n;
    cout << "Masukkan angka (0-100): ";
    cin >> n;

    if (n < 10) cout << satuan[n];
    else if (n < 20) cout << belasan[n - 10];
    else if (n < 100) {
        cout << puluhan[n/10];
        if (n % 10 != 0) cout << " " << satuan[n%10];
    }
    else if (n == 100) cout << "seratus";
    else cout << "di luar jangkauan";

    cout << endl;
    return 0;
}

```
### Output:
<img width="506" height="330" alt="Image" src="https://github.com/user-attachments/assets/76789aec-e9bf-4cb6-a24c-ca0cdcecd4fc" />

Program di atas bertujuan untuk mengubah angka dari 0 hingga 100 menjadi kata dalam bahasa Indonesia. Program ini menggunakan tiga array satuan, belasan, dan puluhan untuk menyimpan representasi kata dari angka 0–9, 10–19, dan kelipatan puluhan. Pengguna diminta memasukkan sebuah angka n, lalu program memeriksa nilainya: jika kurang dari 10, ditampilkan dari array satuan; jika antara 10–19, ditampilkan dari array belasan; jika 20–99, ditampilkan dari array puluhan dan, jika ada sisa, ditambahkan kata dari array satuan; jika 100, ditampilkan "seratus"; selain itu, program menampilkan pesan "di luar jangkauan".

### Full Code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/f1096193-6b67-4107-89cc-c71d1c0962a5" />

### 3. Unguided2
<img width="116" height="138" alt="Image" src="https://github.com/user-attachments/assets/e0581782-5025-4c82-84b3-aaf78da073c9" />


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
<img width="580" height="447" alt="Image" src="https://github.com/user-attachments/assets/27b301a3-0129-4a4b-a5d9-e5873750104f" />

Program di atas bertujuan untuk mencetak pola segitiga angka dengan simbol bintang di tengah berdasarkan input angka n. Program meminta pengguna memasukkan sebuah angka n, kemudian menggunakan loop for untuk mencetak setiap baris dari atas ke bawah. Pada setiap baris: pertama dicetak spasi agar pola rata tengah, lalu deretan angka menurun dari i ke 1 di sebelah kiri, diikuti simbol *, lalu deretan angka menaik dari 1 ke i di sebelah kanan. Setelah semua baris dicetak, program menambahkan baris terakhir yang hanya berisi spasi dan satu simbol * di tengah.

### Full Code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/d2a1cbda-901b-47e3-b430-8d8a1cd9cffd" />


## Kesimpulan
Dari praktikum ini, yang saya dapatkan adalah pemahaman konsep dasar pemrograman seperti variabel, tipe data, input-output, operator aritmatika dan perbandingan, percabangan, perulangan, serta array sangat penting untuk membangun program yang efektif. Praktikum ini membantu memperkuat pemahaman teori melalui penerapan langsung, sehingga kita dapat melihat bagaimana setiap konsep bekerj. misalnya bagaimana percabangan mempengaruhi alur program, atau bagaimana loop mempermudah pengolahan data berulang.


