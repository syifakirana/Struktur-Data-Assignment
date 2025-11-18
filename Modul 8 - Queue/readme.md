<h1 align="center">Laporan Praktikum Modul Queue</h1>
<p align="center">Syifa Kirana Putri Surya</p>
<p align="center">(103112400111)</p>


## Dasar Teori

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
Program ini digunakan untuk membuat dan menjalankan antrian (queue) menggunakan linked list. Antrian bekerja dengan aturan FIFO, yaitu data yang masuk pertama akan keluar terlebih dahulu. Fungsi enQueue menambah data baru di bagian belakang antrian, sedangkan deQueue menghapus data yang berada di bagian depan. Fungsi viewQueue dipakai untuk menampilkan seluruh isi antrian, dan clearQueue digunakan untuk menghapus semua data sampai antrian benar-benar kosong. Pada fungsi main, program menambahkan beberapa nama ke dalam antrian, lalu menghapus beberapa di antaranya. Setelah itu, isi queue ditampilkan sebelum dan sesudah proses penghapusan. Program ini menunjukkan cara kerja antrian sederhana dengan operasi dasar tambah, hapus, lihat, dan mengosongkan antrian menggunakan linked list.

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
Program ini membuat queue menggunakan array dengan teknik circular queue, di mana posisi head dan tail bisa kembali ke indeks awal ketika sudah mencapai batas array. Dengan cara ini, ruang yang sudah kosong dapat digunakan lagi sehingga lebih efisien dibanding queue linear biasa.
Fungsi enQueue digunakan untuk menambah data di bagian belakang antrian. Jika queue masih kosong, head dan tail berada di indeks 0. Jika sudah ada isi, tail digeser ke indeks berikutnya secara melingkar dengan rumus (tail + 1) % MAKSIMAL. Fungsi deQueue menghapus data dari bagian depan. Jika hanya ada satu data, head dan tail di-reset menjadi -1. Jika masih ada elemen lain, head cukup digeser satu langkah secara melingkar.
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

Program ini membuat sebuah queue menggunakan array berukuran 5. Queue yang dipakai adalah tipe head tetap, jadi head selalu berada di indeks 0, sementara tail bertambah setiap kali ada data baru. Operasi enqueue digunakan untuk menambah data ke bagian belakang queue. Jika queue masih kosong, head dan tail di-set ke 0. Kalau sudah ada isi, tail cukup ditambah satu lalu data dimasukkan. Operasi dequeue menghapus data paling depan. Karena head tidak bergerak, setelah data pertama dihapus semua elemen di dalam array digeser satu posisi ke kiri supaya urutannya tetap benar. Setelah itu tail dikurangi satu, dan kalau elemen habis head dan tail dikembalikan ke -1. Fungsi printInfo digunakan untuk menampilkan posisi head, tail, dan isi queue setiap kali terjadi perubahan. Di bagian main, program melakukan beberapa kali enqueue dan dequeue sesuai langkah pada soal. Dari hasil outputnya bisa dilihat bagaimana queue bekerja dengan prinsip FIFO, yaitu data yang masuk duluan akan keluar lebih dulu.

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

Program ini menggunakan queue berbasis array dengan mekanisme linear, di mana baik head maupun tail akan bergerak sesuai operasi yang dilakukan. Pada model ini, setiap kali enqueue dijalankan, data baru dimasukkan ke posisi tail dan tail akan maju satu langkah. Jika queue sebelumnya kosong, head dan tail sama-sama berada pada indeks 0. Berbeda dengan Alternatif 1, pada mekanisme ini tidak ada proses menggeser elemen ketika terjadi dequeue. Saat dequeue dijalankan, data yang berada di posisi head diambil, lalu head cukup digeser ke indeks berikutnya. Queue akan kembali dianggap kosong ketika head sudah melewati posisi tail, sehingga head dan tail di-reset menjadi -1.
Fungsi enqueue bertugas menambah data ke bagian belakang antrian selama queue belum penuh. Fungsi dequeue mengambil data paling depan sesuai prinsip FIFO dan hanya menggerakkan head tanpa memindahkan elemen di dalam array. Fungsi printInfo menampilkan posisi head, tail, serta isi queue berdasarkan rentang indeks head hingga tail. Pada fungsi main, beberapa operasi enqueue dan dequeue dijalankan secara berurutan untuk memperlihatkan perubahan isi queue sekaligus pergerakan head dan tail. Melalui mekanisme ini terlihat bahwa model linear dengan head dan tail bergerak dapat menjalankan operasi antrian tanpa perlu melakukan shifting elemen, sehingga proses dequeue menjadi lebih sederhana.

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

Pada program ini digunakan struktur circular queue, yaitu antrian yang posisi head dan tail-nya dapat kembali ke awal array ketika sudah mencapai indeks terakhir. Mekanisme ini membuat pemakaian memori lebih efisien, karena ruang kosong yang ada di depan bisa dipakai lagi tanpa perlu menggeser elemen.
Fungsi enqueue menambahkan data di posisi tail. Jika tail sudah berada di indeks terakhir, nilai tail akan kembali ke 0 menggunakan operasi (tail + 1) % MAKSIMAL. Saat queue kosong, head dan tail sama-sama diatur menjadi 0. Sementara itu, fungsi dequeue menghapus data dari posisi head, lalu head digeser ke indeks berikutnya secara melingkar dengan rumus yang sama. Bila setelah penghapusan head melewati tail, berarti queue kosong dan kedua indeks di-reset ke -1.
Fungsi printInfo digunakan untuk menampilkan isi antrian dengan membaca elemen secara berurutan mulai dari head sampai tail, mengikuti pola circular. Dalam main, program mengisi queue hingga penuh, menghapus beberapa data, lalu menambah data baru sehingga tail berputar ke awal array. Dari hasil output terlihat bahwa head dan tail bergerak melingkar sesuai konsep circular queue.


#### Full code Screenshot:
<img width="1919" height="978" alt="image" src="https://github.com/user-attachments/assets/586a23a6-9018-4d62-9c8f-14674971ee1f" />


## Kesimpulan
Dari praktikum ini bisa disimpulkan bahwa .............

