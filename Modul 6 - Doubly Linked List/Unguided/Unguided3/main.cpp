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

        bool exists = false;
        for (address Q = L.First; Q != nullptr; Q = Q->next) {
            if (Q->info.nopol == x.nopol) {
                exists = true;
                break;
            }
        }

        if (exists) {
            cout << "nomor polisi sudah terdaftar" << endl << endl;
        } else {
            insertLast(L, alokasi(x));
        }
    }

    printInfo(L);

    string key;
    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> key;
    cout << endl;

    address target = findElm(L, key);

    if (target == nullptr) {
        cout << "Data dengan nomor polisi " << key << " tidak ditemukan" << endl;
    } else {
        address P = nullptr;

        if (target == L.First) {
            deleteFirst(L, P);
        } else if (target == L.Last) {
            deleteLast(L, P);
        } else {
            deleteAfter(target->prev, P);
            if (target->prev->next == nullptr) {
                L.Last = target->prev;
            }
        }

        if (P != nullptr) {
            cout << "Data dengan nomor polisi " << key << " berhasil dihapus." << endl << endl;
            dealokasi(P);
        } else {
            cout << "Gagal menghapus data." << endl << endl;
        }

        printInfo(L);
    }

    address cur = L.First;
    while (cur != nullptr) {
        address toDel = cur;
        cur = cur->next;
        dealokasi(toDel);
    }

    return 0;
}