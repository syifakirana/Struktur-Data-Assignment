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