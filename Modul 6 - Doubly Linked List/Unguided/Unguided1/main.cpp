#include <iostream>
#include "Doublylist.h"
using namespace std;

int main() {
    List L;
    CreateList(L);

    const int JUMLAH_INPUT = 4; 
    for (int i = 0; i < JUMLAH_INPUT; ++i) {
        infotipe x;

        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;

        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;

        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        cout << endl;

        // cek duplikat
        bool exists = false;
        for (address Q = L.First; Q != nullptr; Q = Q->next) {
            if (Q->info.nopol == x.nopol) {
                exists = true;
                break;
            }
        }

        if (exists) {
            cout << "nomor polisi sudah terdaftar" << endl;
            cout << endl;
        } else {
            address P = alokasi(x);
            insertLast(L, P);
        }
    }

    printInfo(L);

    address curr = L.First;
    while (curr != nullptr) {
        address toDel = curr;
        curr = curr->next;
        dealokasi(toDel);
    }
    L.First = L.Last = nullptr;

    return 0;
}