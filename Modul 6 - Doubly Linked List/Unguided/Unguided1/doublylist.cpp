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