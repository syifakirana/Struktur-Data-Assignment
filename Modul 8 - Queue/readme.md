<h1 align="center">Laporan Praktikum Modul Queue</h1>
<p align="center">Syifa Kirana Putri Surya</p>
<p align="center">(103112400111)</p>


## Dasar Teori
Queue adalah struktur data yang cara kerjanya seperti antrian. Data yang masuk duluan akan keluar duluan (FIFO – First In First Out). Di dalam queue ada dua posisi penting:<br>
Head : menunjuk ke data paling depan (yang akan keluar dulu).<br>
Tail : menunjuk ke data paling belakang (tempat data baru masuk).<br>
Queue bisa dibuat dengan array, dan biasanya ada beberapa cara untuk menggerakkan head dan tail:
1. Queue Linear Alternatif 1(head diam, tail bergerak)
Tail bergerak maju setiap kali ada data baru, sedangkan head tetap di posisi awal. Kalau dequeue, semua elemen digeser ke kiri supaya head tetap di depan. Cara ini masih jalan, tapi kurang efisien karena harus menggeser data.
2. Queue Linear Alternatif 2 (head bergerak, tail bergerak)
Pada cara ini, head dan tail sama-sama bergerak sesuai operasi yang dilakukan. Tidak ada proses menggeser elemen, sehingga lebih cepat dibanding cara pertama.
3. Circular Queue (head dan tail berputar)
Circular queue membuat head dan tail bisa “muter” kembali ke indeks awal kalau sudah mencapai batas array. Dengan begitu, ruang kosong bisa dipakai lagi tanpa menggeser elemen. Ini cara yang paling efisien untuk queue berbasis array. <br>

Operasi dasar pada queue :<br>
enqueue() menambah data pada posisi tail  
dequeue() menghapus data dari posisi head  
isEmpty() mengecek apakah queue kosong  
isFull() mengecek apakah queue penuh  
print/view menampilkan isi queue  

## Guided 

### 1. Implementasi Queue Menggunakan Linked List (Guided1)

Folder Guided1  
File: queue.h
```C++
// guided 1 queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

struct queue {
    Node* head;
    Node* tail;
};

void CreateQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enQueue(queue &Q, const string &nama);
void deQueue(queue &Q);
void viewQueue(queue Q);
void clearQueue(queue &Q);

#endif
```

File: queue.cpp
```C++
// guided 1 queue.cpp
#include "queue.h"
using namespace std;

void CreateQueue(queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(queue Q) {
    return Q.head == nullptr;
}

bool isFull(queue) {
    return false;
}

void enQueue(queue &Q, const string &nama) {
    Node* baru = new Node{nama, nullptr};
    if (isEmpty(Q)) {
        Q.head = Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr) {
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node* p = Q.head; p != nullptr; p = p->next) {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q) {
    while (!isEmpty(Q)) {
        deQueue(Q);
    }
}
```

File: main.cpp
```C++
// guided 1 main.cpp
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    queue Q;
    CreateQueue(Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);
    return 0;
}
```
Program ini digunakan untuk membuat dan menjalankan antrian (queue) menggunakan linked list. Queue bekerja dengan aturan FIFO, yaitu data yang pertama masuk akan menjadi data pertama yang keluar. Fungsi enQueue menambah data baru di bagian belakang antrian, sementara deQueue menghapus data paling depan. Untuk melihat seluruh isi antrian, program menggunakan fungsi viewQueue, dan fungsi clearQueue dipakai untuk menghapus semua data hingga antrian benar-benar kosong. Pada fungsi main, beberapa nama dimasukkan ke dalam antrian lalu sebagian dihapus, sehingga terlihat perubahan isi queue sebelum dan sesudah proses tersebut. Secara keseluruhan, program ini menunjukkan cara kerja queue sederhana dengan operasi dasar tambah, hapus, tampilkan, dan kosongkan antrian menggunakan linked list.

### 2. Implementasi Circular Queue Menggunakan Array (Guided2)

Folder Guided2
File: queue.h
```C++
// guided2 queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue{
    string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void CreateQueue(queue &Q); //terbentuk queue dengan head = -1 dan tail = -1 
void enQueue(queue &Q, string nama);
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif
```

File: queue.cpp
```C++
// guided2 queue.cpp
#include "queue.h"
#include <iostream>

using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

// //isFull implmenetasi 1 & 2
// bool isFull(queue Q){
//     if(Q.tail == MAKSIMAL - 1){
//         return true;
//     } else {
//         return false;
//     }
// }

//isFull implementasi 3
bool isFull(queue Q){
    if((Q.tail + 1) % MAKSIMAL == Q.head){
        return true;
    } else {
        return false;
    }
}

void CreateQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}
 
// //enqueue implementasi 1 & 2
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail++;
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

//enQueue implementasi 3
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //dequeue implementasi 1
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         for(int i = 0; i < Q.tail; i++){
//             Q.nama[i] =  Q.nama[i+1];
//         }
//         Q.tail--;
//         if(Q.tail < 0){ //kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

//deQueue implementasi 3
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
        }
    }
}

// //viewQueue implementasi 1 & 2
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         for(int i = Q.head; i <= Q.tail; i++){
//             cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
//         }
//     }
//     cout << endl;
// }

//viewQueue implementasi 3
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        int i = Q.head;
        int count = 1;
        while(true){
            cout << count << ". " << Q.nama[i] << endl;
            if(i == Q.tail){
                break;
            }
            i = (i + 1) % MAKSIMAL;
            count++;
        }   
    }
}
```

File: main.cpp
```C++
// guided2 main.cpp
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    CreateQueue(Q);
    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}
```
Program ini membuat queue menggunakan array dengan teknik circular queue, di mana posisi head dan tail bisa kembali ke indeks awal ketika sudah mencapai batas array. Dengan cara ini, ruang yang sudah kosong dapat digunakan lagi sehingga lebih efisien dibanding queue linear biasa. Fungsi enQueue digunakan untuk menambah data di bagian belakang antrian. Jika queue masih kosong, head dan tail berada di indeks 0. Jika sudah ada isi, tail digeser ke indeks berikutnya secara melingkar dengan rumus (tail + 1) % MAKSIMAL. Fungsi deQueue menghapus data dari bagian depan. Jika hanya ada satu data, head dan tail direset menjadi -1. Jika masih ada elemen lain, head cukup digeser satu langkah secara melingkar.
Fungsi viewQueue menampilkan seluruh isi antrian dari head sampai tail dengan mengikuti pola circular. Pada fungsi main, program menambahkan beberapa nama ke queue, menghapus beberapa di antaranya, lalu menampilkan isi antrian sebelum dan sesudah penghapusan. Program ini menunjukkan cara kerja circular queue yang memanfaatkan array secara lebih efisien.

## Unguided 

### 1. Buatlah ADT Queue menggunakan ARRAY sebagai berikut di dalam file “queue.h”:
<img width="491" height="161" alt="image" src="https://github.com/user-attachments/assets/d2620aa6-c82c-4aa4-b0ce-c1912581e1e0" /><br>
Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme
queue Alternatif 1 (head diam, tail bergerak).
<img width="570" height="289" alt="image" src="https://github.com/user-attachments/assets/29d13277-8d93-4adf-94b5-753e5a269e51" /><br>

File: queue.h  
```cpp
#ifndef QUEUE_H
#define QUEUE_H

const int MAKSIMAL = 5;

struct Queue {
    int info[MAKSIMAL];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```
File: queue.cpp  
```cpp
#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmpty(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFull(Queue Q) {
    return (Q.tail == MAKSIMAL - 1);
}

void enqueue(Queue &Q, int x) {
    if (isFull(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }
    if (isEmpty(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }
    Q.info[Q.tail] = x;
}

int dequeue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    int nilai = Q.info[Q.head];

    // geser semua elemen ke kiri
    for (int i = 0; i < Q.tail; i++) {
        Q.info[i] = Q.info[i + 1];
    }

    Q.tail--;

    // jika kosong reset
    if (Q.tail < 0) {
        Q.head = -1;
        Q.tail = -1;
    }

    return nilai;
}

void printInfo(Queue Q) {
    if (isEmpty(Q)) {
        cout << Q.head << "  -  " << Q.tail << "    | empty queue" << endl;
        return;
    }

    cout << Q.head << "  -  " << Q.tail << "    | ";

    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i];
        if (i < Q.tail) cout << " ";
    }

    cout << endl;
}

```
File: main.cpp  
```cpp
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World!" << endl;

    Queue Q;
    createQueue(Q);

    cout << "----------------------------" << endl;
    cout << "H  -  T    | Queue Info" << endl;
    cout << "----------------------------" << endl;

    printInfo(Q);

    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);

    dequeue(Q); printInfo(Q);   
    dequeue(Q); printInfo(Q);   

    enqueue(Q, 4); printInfo(Q); 

    dequeue(Q); printInfo(Q);   
    dequeue(Q); printInfo(Q);   

    return 0;
}
```
#### Output:
<img width="533" height="298" alt="Image" src="https://github.com/user-attachments/assets/e2262dd5-dc76-4cf6-a180-99b9ff2bb61b" /><br>

Program ini membuat sebuah queue menggunakan array berisi 5 elemen. Queue yang dipakai adalah queue dengan head tetap, jadi posisi head selalu di indeks 0, sedangkan tail bergerak setiap kali ada data baru masuk. Saat melakukan enqueue, data ditambahkan di bagian belakang. Jika queue masih kosong, head dan tail dibuat menjadi 0, dan kalau sudah ada isinya, tail cukup dinaikkan satu lalu data dimasukkan. Saat dequeue, data paling depan diambil. Karena head tidak pindah, semua elemen di dalam array digeser satu posisi ke kiri supaya urutannya tetap benar. Setelah itu tail dikurangi satu, dan jika queue sudah kosong maka head dan tail direset kembali menjadi -1. Fungsi printInfo menampilkan posisi head, tail, dan isi queue setelah setiap operasi. Di bagian main, program melakukan beberapa kali enqueue dan dequeue sesuai langkah pada soal.

#### Full code Screenshot:
<img width="1919" height="1022" alt="Image" src="https://github.com/user-attachments/assets/690c8d28-ecb1-4c66-b06e-9445ed83216d" />

### 2. Buatlah implementasi ADT Queue pada file "queue.cpp" dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak).

File: queue.h  
```cpp
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAKSIMAL = 5;

struct Queue {
    int info[MAKSIMAL];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```
File: queue.cpp  
```cpp
#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmpty(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFull(Queue Q) {
    return (Q.tail == MAKSIMAL - 1);
}

void enqueue(Queue &Q, int x) {
    if (isFull(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmpty(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }

    Q.info[Q.tail] = x;
}

int dequeue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    int nilai = Q.info[Q.head];

    Q.head++;

    if (Q.head > Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    }

    return nilai;
}

void printInfo(Queue Q) {
    if (isEmpty(Q)) {
        cout << Q.head << "  -  " << Q.tail << "    | empty queue" << endl;
        return;
    }

    cout << Q.head << "  -  " << Q.tail << "    | ";

    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i];
        if (i < Q.tail) cout << " ";
    }

    cout << endl;
}
```

File: main.cpp  
```cpp
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World!" << endl;

    Queue Q;
    createQueue(Q);

    cout << "----------------------------" << endl;
    cout << "H  -  T    | Queue Info" << endl;
    cout << "----------------------------" << endl;

    printInfo(Q);

    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);

    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    enqueue(Q, 4); printInfo(Q);

    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}
```

#### Output:
<img width="1071" height="444" alt="image" src="https://github.com/user-attachments/assets/ee83270c-f3b7-4419-9e1e-2c1566717e4c" />

Program ini menggunakan queue berbasis array dengan mekanisme linear, di mana baik head maupun tail akan bergerak mengikuti operasi yang dijalankan. Pada model ini, setiap kali enqueue dilakukan, data baru dimasukkan ke posisi tail, lalu tail maju satu langkah. Jika queue sebelumnya kosong, maka head dan tail sama-sama berada di indeks 0. Berbeda dengan Alternatif 1, pada mekanisme ini tidak ada penggeseran elemen saat dequeue. Saat dequeue dijalankan, data yang berada pada posisi head diambil, kemudian head cukup digeser ke indeks berikutnya. Queue akan kembali dianggap kosong ketika head sudah melewati tail, sehingga head dan tail di-reset menjadi -1. Fungsi enqueue bertugas menambah data ke bagian belakang antrian selama queue belum penuh, sedangkan dequeue mengambil data paling depan sesuai prinsip FIFO dan hanya menggerakkan head tanpa memindahkan elemen apa pun. Fungsi printInfo menampilkan nilai head, tail, serta isi queue berdasarkan rentang indeks head sampai tail. Pada fungsi main, beberapa operasi enqueue dan dequeue dijalankan secara berurutan untuk memperlihatkan perubahan isi queue sekaligus pergerakan head dan tail. Mekanisme ini menunjukkan bagaimana queue linear dengan head dan tail bergerak dapat bekerja lebih sederhana tanpa proses shifting seperti pada alternatif sebelumnya.

#### Full code Screenshot:
<img width="1919" height="1001" alt="image" src="https://github.com/user-attachments/assets/e5e648ad-1a33-46a2-8391-0e29a4893bd4" />

### 3. Buatlah implementasi ADT Queue pada file "queue.cpp" dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar).

File: queue.h  
```cpp
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAKSIMAL = 5;

struct Queue {
    int info[MAKSIMAL];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```
File: queue.cpp  
```cpp
#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmpty(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFull(Queue Q) {
    return ((Q.tail + 1) % MAKSIMAL == Q.head);
}

void enqueue(Queue &Q, int x) {
    if (isFull(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmpty(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % MAKSIMAL;
    }

    Q.info[Q.tail] = x;
}

int dequeue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    int nilai = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % MAKSIMAL;
    }

    return nilai;
}

void printInfo(Queue Q) {
    if (isEmpty(Q)) {
        cout << Q.head << "  -  " << Q.tail << "    | empty queue" << endl;
        return;
    }

    cout << Q.head << "  -  " << Q.tail << "    | ";

    int i = Q.head;
    while (true) {
        cout << Q.info[i];
        if (i == Q.tail) break;
        cout << " ";
        i = (i + 1) % MAKSIMAL;
    }
    cout << endl;
}
```
File: main.cpp  
```cpp
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World!" << endl;

    Queue Q;
    createQueue(Q);

    cout << "----------------------------" << endl;
    cout << "H  -  T    | Queue Info" << endl;
    cout << "----------------------------" << endl;

    printInfo(Q);

    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    enqueue(Q, 6); printInfo(Q);   // penuh terakhir

    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    enqueue(Q, 9); printInfo(Q);   // harus berputar
    enqueue(Q, 8); printInfo(Q);   // putaran lagi

    return 0;
}
```

#### Output:
<img width="539" height="314" alt="image" src="https://github.com/user-attachments/assets/b95d8544-eccc-4710-aa65-29c5ab0fe219" />

Program ini menggunakan circular queue, yaitu antrian yang posisi head dan tail-nya bisa berputar kembali ke awal ketika sudah mencapai indeks terakhir. Cara ini membuat ruang array dapat dipakai kembali tanpa perlu menggeser data. Pada operasi enqueue, data baru dimasukkan ke posisi tail. Jika queue masih kosong, head dan tail berada di indeks 0. Jika sudah terisi, tail digeser ke indeks berikutnya dengan rumus (tail + 1) % MAKSIMAL sehingga bisa kembali ke awal array. Pada operasi dequeue, data yang diambil selalu data paling depan pada posisi head, lalu head juga digeser dengan cara yang sama. Jika setelah penghapusan head dan tail berada pada posisi yang sama, queue dianggap kosong dan kedua indeks di-reset ke -1. Fungsi printInfo menampilkan posisi head, tail, serta isi queue sesuai urutan dari head sampai tail mengikuti pola circular. Di fungsi main, program memasukkan data hingga penuh, menghapus beberapa elemen, lalu menambahkan data baru sehingga tail berputar ke awal. Dari proses tersebut dapat terlihat bagaimana circular queue bekerja sambil tetap mengikuti prinsip FIFO dengan penggunaan memori yang lebih efisien.

#### Full code Screenshot:
<img width="1919" height="978" alt="image" src="https://github.com/user-attachments/assets/586a23a6-9018-4d62-9c8f-14674971ee1f" />

## Kesimpulan
Dari praktikum ini bisa disimpulkan bahwa struktur data queue dapat diimplementasikan dengan beberapa cara, dan setiap pendekatan memiliki cara kerja yang berbeda. Pada queue linear dengan head tetap, proses penghapusan membutuhkan penggeseran elemen sehingga kurang efisien. Pada model head dan tail bergerak, operasi menjadi lebih sederhana karena elemen tidak perlu dipindahkan. Sedangkan circular queue menawarkan penggunaan memori yang lebih optimal karena head dan tail bisa berputar kembali ke awal array. Melalui ketiga percobaan ini, kita dapat memahami bagaimana prinsip FIFO diterapkan.
