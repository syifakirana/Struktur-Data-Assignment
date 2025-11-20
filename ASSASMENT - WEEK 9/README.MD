# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
<p align="center">Syifa Kirana Putri Surya</p>

## SOAL NO 1  
### bagian A  
File: SLLInventory.h
```cpp
#ifndef SLLINVENTORY_H
#define SLLINVENTORY_H
#include <iostream>
using namespace std;

typedef struct Product {
    string Nama;
    string SKU;
    int Jumlah;
    float HargaSatuan;
    float DiskonPersen;
}Product;

typedef struct Node *address;

typedef struct Node {
    Product info;
    address next;
} Node;

typedef struct {
    address head;
} List;

bool isEmpty(List L);
void createList(List &L);
address allocate(Product P);
void deallocate(address p);
void insertFirst(List &L, Product P);
void insertLast(List &L, Product P);
void insertAfter(List &L, address Q, Product P);
void deleteFirst(List &L, Product &P);
void deleteLast(List &L, Product &P);
void deleteAfter(List &L, address Q, Product &P);
void updateAtPosition(List &L, int posisi, Product dataBaru);
void viewList(List L);
void searchByFinalPriceRange(List L, float minPrice, float maxPrice);

#endif
```
File: SLLInventory.cpp
```cpp
#include "SLLInventory.h"

bool isEmpty(List L) {
    return L.head == NULL;
}

void createList(List &L) {
    L.head = NULL;
}

address allocate(Product P) {
    address p = new Node;
    p->info = P;
    p->next = NULL;
    return p;
}

void deallocate(address p) {
    delete p;
}

void insertFirst(List &L, Product P) {
    address p = allocate(P);
    p->next = L.head;
    L.head = p;
}

void insertLast(List &L, Product P) {
    address p = allocate(P);
    if (L.head == NULL) {
        L.head = p;
    } else {
        address q = L.head;
        while (q->next != NULL) q = q->next;
        q->next = p;
    }
}

void insertAfter(List &L, address Q, Product P) {
    if (Q != NULL) {
        address p = allocate(P);
        p->next = Q->next;
        Q->next = p;
    }
}

void deleteFirst(List &L, Product &P) {
    if (L.head != NULL) {
        address p = L.head;
        P = p->info;
        L.head = p->next;
        deallocate(p);
    }
}

void deleteLast(List &L, Product &P) {
    if (L.head != NULL) {
        address q = L.head;
        address prev = NULL;
        while (q->next != NULL) {
            prev = q;
            q = q->next;
        }
        P = q->info;
        if (prev == NULL) {
            L.head = NULL;
        } else {
            prev->next = NULL;
        }
        deallocate(q);
    }
}

void deleteAfter(List &L, address Q, Product &P) {
    if (Q != NULL && Q->next != NULL) {
        address p = Q->next;
        P = p->info;
        Q->next = p->next;
        deallocate(p);
    }
}

void updateAtPosition(List &L, int posisi, Product dataBaru) {
    address p = L.head;
    int i = 1;
    while (p != NULL && i < posisi) {
        p = p->next;
        i++;
    }
    if (p != NULL) {
        p->info = dataBaru;
    }
}

float finalPrice(Product P) {
    return P.HargaSatuan * (1 - P.DiskonPersen / 100);
}

void viewList(List L) {
    address p = L.head;
    int i = 1;
    while (p != NULL) {
        cout << i << ". "
             << p->info.Nama << "  "
             << p->info.SKU << "  "
             << p->info.Jumlah << "  "
             << p->info.HargaSatuan << "  "
             << p->info.DiskonPersen << "  "
             << finalPrice(p->info) << endl;
        p = p->next;
        i++;
    }
}

void searchByFinalPriceRange(List L, float minPrice, float maxPrice) {
    address p = L.head;
    int i = 1;
    while (p != NULL) {
        float h = finalPrice(p->info);
        if (h >= minPrice && h <= maxPrice) {
            cout << i << ". " << p->info.Nama << "  " << h << endl;
        }
        p = p->next;
        i++;
    }
}
```
File: main.cpp
```cpp
#include "SLLInventory.h"

int main() {
    List L;
    createList(L);
    Product P;
    P = {"Pulpen", "A001", 20, 2500, 0};
    insertLast(L, P);

    P = {"Buku Tulis", "A002", 15, 5000, 10};
    insertLast(L, P);

    P = {"Penghapus", "A003", 30, 1500, 0};
    insertLast(L, P);

    viewList(L);
    Product del;
    deleteFirst(L, del);
    viewList(L);
    P = {"Stabilo", "A010", 40, 9000, 5};
    updateAtPosition(L, 2, P);

    viewList(L);
    searchByFinalPriceRange(L, 2000, 7000);
    return 0;
}
```
### Output: 
<img width="557" height="234" alt="Image" src="https://github.com/user-attachments/assets/4e28884e-f76d-4934-a1d8-67eda83706a5" />

### bagian B  
File: SLLInventory.h
```cpp
#ifndef SLLINVENTORY_H
#define SLLINVENTORY_H
#include <iostream>
using namespace std;

typedef struct Product {
    string Nama;
    string SKU;
    int Jumlah;
    float HargaSatuan;
    float DiskonPersen;
} Product;

typedef struct Node *address;

typedef struct Node {
    Product info;
    address next;
} Node;

typedef struct {
    address head;
} List;

bool isEmpty(List L);
void createList(List &L);
address allocate(Product P);
void deallocate(address p);
void insertLast(List &L, Product P);
float finalPrice(Product P);

void MaxHargaAkhir(List L); //tambahan
void viewList(List L);

#endif
```
File: SLLInventory.cpp
```cpp
#include "SLLInventory.h"

bool isEmpty(List L){
    return L.head==NULL;
}

void createList(List &L){
    L.head=NULL;
}

address allocate(Product P){
    address p=new Node;
    p->info=P;
    p->next=NULL;
    return p;
}

void deallocate(address p){
    delete p;
}

void insertLast(List &L, Product P){
    address p=allocate(P);
    if(L.head==NULL){
        L.head=p;
    } else {
        address q=L.head;
        while(q->next!=NULL) q=q->next;
        q->next=p;
    }
}

float finalPrice(Product P){
    return P.HargaSatuan * (1 - P.DiskonPersen/100);
}

void viewList(List L){
    address p=L.head;
    int i=1;
    while(p!=NULL){
        cout<<i<<". "<<p->info.Nama<<"  "<<finalPrice(p->info)<<endl;
        p=p->next;
        i++;
    }
}

void MaxHargaAkhir(List L){//tambahan
    if(L.head==NULL) return;

    float MAX=-1;
    address p=L.head;
    while(p!=NULL){
        float h=finalPrice(p->info);
        if(h>MAX) MAX=h;
        p=p->next;
    }

    cout<<"Harga Akhir terbesar: "<<MAX<<endl;

    p=L.head;
    int i=1;
    while(p!=NULL){
        if(finalPrice(p->info)==MAX){
            cout<<i<<". "<<p->info.Nama<<"  "<<MAX<<endl;
        }
        p=p->next;
        i++;
    }
}

```
File: main.cpp
```cpp
#include "SLLInventory.h"


int main(){
    List L;
    createList(L);
    Product P;
    P={"Pulpen","A001",20,2500,0};
    insertLast(L,P);

    P={"Buku Tulis","A002",15,5000,10};
    insertLast(L,P);

    P={"Penghapus","A003",30,1500,0};
    insertLast(L,P);

    viewList(L);
    MaxHargaAkhir(L);//tambahan
    return 0;
}
```
### Output: 
<img width="542" height="175" alt="Image" src="https://github.com/user-attachments/assets/cc8199f1-c905-4d90-9c04-192f501b2342" />

## SOAL NO 2  

File: DLLPlaylist.h
```cpp
#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H
#include <iostream>
using namespace std;

struct Song {
    string Title;
    string Artist;
    int DurationSec;
    int PlayCount;
    float Rating;
};

struct Node {
    Song info;
    Node *prev;
    Node *next;
};

struct List {
    Node *head;
    Node *tail;
};

void createList(List &L);
bool isEmpty(List L);

Node* allocate(Song S);
void deallocate(Node *p);

void insertFirst(List &L, Song S);
void insertLast(List &L, Song S);
void insertAfter(List &L, Node *Q, Song S);
void insertBefore(List &L, Node *Q, Song S);

void deleteFirst(List &L, Song &S);
void deleteLast(List &L, Song &S);
void deleteAfter(List &L, Node *Q, Song &S);
void deleteBefore(List &L, Node *Q, Song &S);

void updateAtPosition(List &L, int pos, Song S);
void updateBefore(List &L, Node *Q, Song S);

float popScore(Song S);
void viewList(List L);

void searchByPopularityRange(List L, float minS, float maxS);

Node* nodeAt(List L, int pos);

#endif
```
File: DLLPlaylist.cpp
```cpp
#include "DLLPlaylist.h"

void createList(List &L){
    L.head = NULL;
    L.tail = NULL;
}

bool isEmpty(List L){
    return L.head==NULL;
}

Node* allocate(Song S){
    Node *p = new Node;
    p->info = S;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

void deallocate(Node *p){
    delete p;
}

void insertFirst(List &L, Song S){
    Node *p = allocate(S);
    if(isEmpty(L)){
        L.head = p; L.tail = p;
    } else {
        p->next = L.head;
        L.head->prev = p;
        L.head = p;
    }
}

void insertLast(List &L, Song S){
    Node *p = allocate(S);
    if(isEmpty(L)){
        L.head = p; L.tail = p;
    } else {
        p->prev = L.tail;
        L.tail->next = p;
        L.tail = p;
    }
}

void insertAfter(List &L, Node *Q, Song S){
    if(Q==NULL) return;
    Node *p = allocate(S);
    p->next = Q->next;
    p->prev = Q;
    if(Q->next!=NULL) Q->next->prev = p;
    else L.tail = p;
    Q->next = p;
}

void insertBefore(List &L, Node *Q, Song S){
    if(Q==NULL) return;
    Node *p = allocate(S);
    p->prev = Q->prev;
    p->next = Q;
    if(Q->prev!=NULL) Q->prev->next = p;
    else L.head = p;
    Q->prev = p;
}

void deleteFirst(List &L, Song &S){
    if(isEmpty(L)) return;
    Node *p = L.head;
    S = p->info;
    if(L.head==L.tail){
        L.head=L.tail=NULL;
    } else {
        L.head = p->next;
        L.head->prev = NULL;
    }
    deallocate(p);
}

void deleteLast(List &L, Song &S){
    if(isEmpty(L)) return;
    Node *p = L.tail;
    S = p->info;
    if(L.head==L.tail){
        L.head=L.tail=NULL;
    } else {
        L.tail = p->prev;
        L.tail->next = NULL;
    }
    deallocate(p);
}

void deleteAfter(List &L, Node *Q, Song &S){
    if(Q==NULL || Q->next==NULL) return;
    Node *p = Q->next;
    S = p->info;
    Q->next = p->next;
    if(p->next!=NULL) p->next->prev = Q;
    else L.tail = Q;
    deallocate(p);
}

void deleteBefore(List &L, Node *Q, Song &S){
    if(Q==NULL || Q->prev==NULL) return;
    Node *p = Q->prev;
    S = p->info;
    Q->prev = p->prev;
    if(p->prev!=NULL) p->prev->next = Q;
    else L.head = Q;
    deallocate(p);
}

Node* nodeAt(List L, int pos){
    Node *p=L.head;
    int i=1;
    while(p!=NULL && i<pos){
        p=p->next;
        i++;
    }
    return p;
}

void updateAtPosition(List &L, int pos, Song S){
    Node *p=nodeAt(L,pos);
    if(p!=NULL) p->info=S;
}

void updateBefore(List &L, Node *Q, Song S){
    if(Q==NULL || Q->prev==NULL) return;
    Q->prev->info = S;
}

float popScore(Song S){
    return 0.8 * S.PlayCount + 20.0 * S.Rating;
}

void viewList(List L){
    Node *p = L.head;
    int i = 1;
    while(p!=NULL){
        cout << i << ". "
             << p->info.Title << "  "
             << p->info.Artist << "  "
             << p->info.DurationSec << "  "
             << p->info.PlayCount << "  "
             << p->info.Rating << "  "
             << popScore(p->info)
             << endl;
        p = p->next;
        i++;
    }
}

void searchByPopularityRange(List L, float minS, float maxS){
    Node *p=L.head;
    int i=1;
    while(p!=NULL){
        float sc = popScore(p->info);
        if(sc>=minS && sc<=maxS){
            cout<<i<<". "<<p->info.Title<<"  "<<sc<<endl;
        }
        p=p->next;
        i++;
    }
}
```
File: main.cpp
```cpp
#include "DLLPlaylist.h"
using namespace std;

int main(){
    List L;
    createList(L);

    Song S, del;

    S = {"Senja di Kota", "Nona Band", 210, 150, 4.2};
    insertLast(L, S);

    S = {"Langkahmu", "Delta", 185, 320, 4.8};
    insertLast(L, S);

    S = {"Hujan Minggu", "Arka", 240, 90, 3.9};
    insertLast(L, S);

    viewList(L);
    cout << endl;
    deleteLast(L, del);
    S = {"Pelita", "Luna", 200, 260, 4.5};
    updateAtPosition(L, 2, S);
    viewList(L);
    cout << endl;
    Node *pos2 = nodeAt(L, 2);
    S = {"Senandung", "Mira", 175, 120, 4.0};
    insertBefore(L, pos2, S);

    viewList(L);
    cout << endl;

    S = {"Update Lagu", "ZZZ", 100, 222, 3.5};
    updateBefore(L, pos2, S);

    viewList(L);
    cout << endl;
    deleteBefore(L, nodeAt(L,3), del);
    viewList(L);
    cout << endl;
    searchByPopularityRange(L, 150.0, 300.0);

    return 0;
}
```
### Output: 

