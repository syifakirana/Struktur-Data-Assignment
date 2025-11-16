# <h1 align="center">Laporan Praktikum Modul Stack</h1>
<p align="center">Syifa Kirana Putri Surya</p>
<p align="center">103112400111</p>

## Dasar Teori
Stack adalah struktur data yang cara kerjanya seperti menyusun barang bertumpuk. Data yang terakhir dimasukkan akan menjadi data yang pertama diambil (LIFO – Last In, First Out). Stack disimpan menggunakan array, dan posisi data paling atas ditandai oleh variabel top. Jika stack masih kosong, nilai top adalah -1. Operasi Push digunakan untuk menambah data ke atas stack, sedangkan Pop digunakan untuk mengambil dan menghapus data teratas.

Ada juga beberapa fungsi tambahan seperti Fungsi balikStack digunakan untuk membalik urutan isi stack. Fungsi pushAscending digunakan untuk menambah data ke stack tetapi tetap menjaga agar data di dalamnya tersusun secara urut dari kecil ke besar. Lalu ada getInputStream, yang membaca input dari pengguna satu karakter demi satu dan memasukkannya ke dalam stack sampai pengguna menekan ENTER.

---

## Guided

### 1. Program implementasi stack menggunakan linked list (Guided1)

File: stack.h
```cpp
#ifndef STACK
#define STACK
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi (int angka);
void dealokasi (address &node);
void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update (stack &listStack, int posisi);
void view(stack listStack);
void searchData (stack listStack, int data);

#endif
```
File: stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```
File: main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);
    
    return 0;
}
```
Program ini membuat stack menggunakan linked list, di mana setiap node menyimpan angka dan pointer ke node berikutnya. Fungsi push menambah node baru ke bagian atas stack, sedangkan pop menghapus node teratas. Program juga menyediakan fungsi update untuk mengubah data pada posisi tertentu, searchData untuk mencari angka dalam stack, dan view untuk menampilkan isi stack dari atas ke bawah. Di fungsi main, beberapa node dibuat, dimasukkan ke stack, kemudian diuji dengan operasi pop, update, dan pencarian. Program ini menunjukkan cara kerja stack dengan aturan LIFO secara sederhana.

2. program implementasi stack menggunakan array (Guided2)
File: stack.h
```cpp
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

// Ubah kapasitas sesuai kebutuhan
const int MAX = 10;

struct stackTable {
    int data[MAX];
    int top; // -1 = kosong
};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif
```
File: stack.cpp
```cpp
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stackTable s){
    return s.top == -1;
}

bool isFull(stackTable s){
    return s.top == MAX - 1;
}

void createStack(stackTable &s){
    s.top = -1;
}

void push(stackTable &s, int angka){
    if(isFull(s)){
        cout << "Stack penuh!" << endl;
    } else {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan kedalam stack!" << endl;
    }
}

void pop(stackTable &s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        int val = s.data[s.top];
        s.top--;
        cout << "Data " << val << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    if(posisi <= 0){
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    // index = top - (posisi - 1)
    int idx = s.top - (posisi - 1);
    if(idx < 0 || idx > s.top){
        cout << "Posisi " << posisi << " tidak valid!" << endl;
        return;
    }

    cout << "Update data posisi ke-" << posisi << endl;
    cout << "Masukkan angka : ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
}

void view(stackTable s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        for(int i = s.top; i >= 0; --i){
            cout << s.data[i] << " ";
        }
    }
    cout << endl;
}

void searchData(stackTable s, int data){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    cout << "Mencari data " << data << "..." << endl;
    int posisi = 1;
    bool found = false;

    for(int i = s.top; i >= 0; --i){
        if(s.data[i] == data){
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
            cout << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if(!found){
        cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
        cout << endl;
    }
}
```
File: main.cpp
```cpp
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    // Posisi dihitung dari TOP (1-based)
    update(s, 2);
    update(s, 1);
    update(s, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}
```
Program ini memembuat stack menggunakan array dengan ukuran tetap, di mana data selalu ditambahkan dan dihapus dari bagian atas sesuai aturan LIFO. Operasi yang digunakan adalah push untuk menambah data ke posisi paling atas, pop untuk menghapus data teratas, update untuk mengganti nilai pada posisi tertentu yang dihitung dari TOP, view untuk menampilkan isi stack dari atas ke bawah, dan searchData untuk mencari apakah suatu nilai ada di dalam stack. Di fungsi main, program menambahkan beberapa angka, menghapus dua data, memperbarui nilai pada beberapa posisi, lalu menampilkan hasilnya.

## Unguided

### 1. Buatlah ADT Stack menggunakan ARRAY sebagai berikut di dalam file "stack.h":
<img width="622" height="284" alt="image" src="https://github.com/user-attachments/assets/d88e55c8-87fa-4132-85ed-33140d402501" /><br>
Buatlah implementasi ADT Stack menggunakan Array pada file "stack.cpp" dan "main.cpp"
<img width="601" height="409" alt="image" src="https://github.com/user-attachments/assets/37ba0807-dc46-4bf9-bee8-db337c833bbf" />

File: stack.h
```C++
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
using namespace std;

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

void CreateStack(Stack &S);
void Push(Stack &S, infotype x);
infotype Pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
```

File: stack.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

void CreateStack(Stack &S) {
    S.top = -1;
}

void Push(Stack &S, infotype x) {
    if (S.top < 19) {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype Pop(Stack &S) {
    if (S.top >= 0) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    }
    return -1;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    CreateStack(temp);

    while (S.top >= 0) {
        Push(temp, Pop(S));
    }

    S = temp; // hanya 1 kali pembalikan
}
```

File: main.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    CreateStack(S);

    Push(S, 3);
    Push(S, 4);
    Push(S, 2);
    Push(S, 9);
    Push(S, 8);

    Pop(S);       // hapus 8

    printInfo(S); // hasil sebelum balik
    cout << "balik stack" << endl;

    balikStack(S);
    printInfo(S);

    return 0;
}
```
### Output:
<img width="428" height="125" alt="image" src="https://github.com/user-attachments/assets/9342033b-0924-4ab1-a968-6a473f5ab2d3" />

Program ini membuat struktur data Stack menggunakan array berkapasitas 20 elemen, dengan aturan LIFO di mana data terakhir masuk akan menjadi data pertama yang keluar. Fungsi CreateStack mengatur stack agar kosong, Push menambah data ke posisi paling atas selama kapasitas belum penuh, dan Pop menghapus data teratas. Fungsi printInfo menampilkan isi stack dari TOP ke bawah, sedangkan balikStack membalik isi stack menggunakan stack sementara. Pada main, beberapa nilai dimasukkan, satu nilai dihapus, lalu isi stack dicetak sebelum dan sesudah dibalik. Program ini menunjukkan cara kerja stack sederhana berbasis array dengan kapasitas tetap.

### Full Code Screenshot:
<img width="1919" height="1021" alt="image" src="https://github.com/user-attachments/assets/c64f0d62-57be-48f7-831a-df98b07686aa" />

### 2. Tambahkan prosedur pushAscending(in/out S: Stack, in x: integer)
<img width="648" height="44" alt="Image" src="https://github.com/user-attachments/assets/05dfeddb-c82b-4a66-b0d3-24a4321c01f5" /><br>
<img width="647" height="315" alt="Image" src="https://github.com/user-attachments/assets/833ca5de-f5e2-4813-b9f3-439ff5285951" /><br>

file: stack.h
```C++
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
using namespace std;

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

void CreateStack(Stack &S);
void Push(Stack &S, infotype x);
infotype Pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

void pushAscending(Stack &S, infotype x); //tambahan


#endif
```

file: stack.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

void CreateStack(Stack &S) {
    S.top = -1;
}

void Push(Stack &S, infotype x) {
    if (S.top < 19) {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype Pop(Stack &S) {
    if (S.top >= 0) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    }
    return -1;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    CreateStack(temp);

    while (S.top >= 0) {
        Push(temp, Pop(S));
    }

    S = temp; // hanya 1 kali pembalikan
}

//tambahan
void pushAscending(Stack &S, infotype x) {
    Stack temp;
    CreateStack(temp);

    // pindahkan elemen yang lebih besar ke temp
    while (S.top >= 0 && S.info[S.top] > x) {
        Push(temp, Pop(S));
    }

    // push elemen baru
    Push(S, x);

    // kembalikan elemen dari temp
    while (temp.top >= 0) {
        Push(S, Pop(temp));
    }
}
```

file: main.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    CreateStack(S);

    pushAscending(S,3);
    pushAscending(S,4);
    pushAscending(S,8);
    pushAscending(S,2);
    pushAscending(S,3);
    pushAscending(S,9);

    printInfo(S);
    cout << "balik stack" << endl;

    balikStack(S);
    printInfo(S);

    return 0;
}
```

#### Output:
<img width="429" height="123" alt="Image" src="https://github.com/user-attachments/assets/8031cf8a-b874-40f4-b742-5f7eee0ee077" />

Program ini menambahkan fitur pushAscending, yaitu proses memasukkan data ke dalam stack sambil menjaga agar isinya tetap tersusun secara ascending. Prosesnya dilakukan dengan memindahkan sementara elemen-elemen yang lebih besar ke stack bantuan, lalu memasukkan data baru ke stack utama, dan akhirnya mengembalikan elemen bantuan tersebut. Operasi lainnya tetap sama seperti sebelumnya, yaitu CreateStack, Push, Pop, printInfo, dan balikStack. Pada main, beberapa angka dimasukkan menggunakan pushAscending sehingga urutan stack otomatis terjaga, lalu isi stack ditampilkan sebelum dan sesudah dibalik. Program ini menunjukkan cara menggabungkan operasi stack biasa dengan aturan penyisipan terurut menggunakan struktur array.

#### Full code Screenshot:
<img width="1913" height="1020" alt="Image" src="https://github.com/user-attachments/assets/87bbe506-ea09-4bea-8740-c3e1c45ade28" />

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
Dari praktikum ini dapat disimpulkan bahwa struktur data Stack tidak hanya digunakan untuk menambah dan mengambil data secara LIFO, tetapi juga bisa dikembangkan untuk berbagai operasi tambahan seperti membalik urutan data, menjaga data tetap terurut, dan membaca input karakter satu per satu. Operasi dasar Push dan Pop menjadi inti dari semua proses, karena setiap pengolahan data selalu dilakukan melalui elemen teratas stack.
