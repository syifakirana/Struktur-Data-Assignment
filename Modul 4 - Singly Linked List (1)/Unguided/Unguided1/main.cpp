#include "SinglyList.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    // Inisialisasi list kosong
    createList(L);

    // Menambahkan elemen ke list
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

    // Menampilkan isi list
    cout << "Isi Linked List: ";
    printInfo(L);

    return 0;
}
