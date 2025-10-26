#include "SinglyList.h"

int main() {
    List L;
    address P, Prec;

    createList(L);

    insertFirst(L, alokasi(2));
    insertFirst(L, alokasi(0));
    insertFirst(L, alokasi(8));
    insertFirst(L, alokasi(12));
    insertFirst(L, alokasi(9));

    // Hapus node 9 
    deleteFirst(L, P);

    // Hapus node 2 
    deleteLast(L, P);

    // Cari node sebelum 8 (yaitu 12), lalu hapus setelahnya (node 8)
    Prec = L.first; // 12
    deleteAfter(L, Prec, P);

    // Tampilkan hasil
    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    // Hapus seluruh list
    deleteList(L);
    cout << endl << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}