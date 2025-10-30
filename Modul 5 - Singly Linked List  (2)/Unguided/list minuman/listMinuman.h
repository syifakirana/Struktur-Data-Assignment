#ifndef LISTMINUMAN_H
#define LISTMINUMAN_H
#define Nil NULL

#include <iostream>
using namespace std;

// menyimpan informasi menu minuman
struct minuman {
    string nama;
    string ukuran;
    float harga;
};

typedef minuman dataMinuman;
typedef struct node *address;

struct node {
    dataMinuman isidata;
    address next;
};

struct linkedlist {
    address first;
};

// deklarasi fungsi dan prosedur
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string ukuran, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

// update data
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

// searching
void FindNodeByData(linkedlist List, string data);
void FindNodeByAddress(linkedlist List, address node);
void FindNodeByRange(linkedlist List, float hargaAwal, float hargaAkhir);

#endif