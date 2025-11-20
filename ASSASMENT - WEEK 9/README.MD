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

