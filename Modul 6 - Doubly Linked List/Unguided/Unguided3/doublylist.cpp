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
