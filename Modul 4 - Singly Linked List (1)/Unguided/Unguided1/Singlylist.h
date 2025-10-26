#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

// Deklarasi tipe data dasar
typedef int infotype;
typedef struct ElmtList *address;

// Struktur elemen list
struct ElmtList {
    infotype info;
    address next;
};

// Struktur list
struct List {
    address first;
};

// Deklarasi function dan procedure
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void printInfo(List L);

#endif // SINGLYLIST_H_INCLUDED
