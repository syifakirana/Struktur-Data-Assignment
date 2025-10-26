#include "SinglyList.h"

void createList(List &L) {
    L.first = NULL;
}

address alokasi(infotype x) {
    address P = new ElmtList;
    P->info = x;
    P->next = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void printInfo(List L) {
    address P = L.first;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

// tambahan
// Menghapus elemen pertama
void deleteFirst(List &L, address &P) {
    if (L.first != NULL) {
        P = L.first;
        L.first = P->next;
        dealokasi(P);
    }
}

// Menghapus elemen terakhir
void deleteLast(List &L, address &P) {
    if (L.first != NULL) {
        if (L.first->next == NULL) {
            P = L.first;
            L.first = NULL;
            dealokasi(P);
        } else {
            address Q = L.first;
            while (Q->next->next != NULL) {
                Q = Q->next;
            }
            P = Q->next;
            Q->next = NULL;
            dealokasi(P);
        }
    }
}

// Menghapus setelah node tertentu
void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != NULL && Prec->next != NULL) {
        P = Prec->next;
        Prec->next = P->next;
        dealokasi(P);
    }
}

// Menghitung jumlah node
int nbList(List L) {
    int n = 0;
    address P = L.first;
    while (P != NULL) {
        n++;
        P = P->next;
    }
    return n;
}

// Menghapus seluruh list
void deleteList(List &L) {
    address P;
    while (L.first != NULL) {
        deleteFirst(L, P);
    }
}