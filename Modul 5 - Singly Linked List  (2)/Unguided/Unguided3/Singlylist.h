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