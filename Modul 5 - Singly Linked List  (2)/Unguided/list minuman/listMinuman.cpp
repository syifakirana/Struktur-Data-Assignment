#include "listMinuman.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    return (List.first == Nil);
}

void createList(linkedlist &List) {
    List.first = Nil;
}

address alokasi(string nama, string ukuran, float harga) {
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.ukuran = ukuran;
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address bantu = List.first;
        while (bantu->next != Nil) {
            bantu = bantu->next;
        }
        bantu->next = nodeBaru;
    }
}

void delFirst(linkedlist &List) {
    if (!isEmpty(List)) {
        address hapus = List.first;
        List.first = hapus->next;
        dealokasi(hapus);
        cout << "Menu pertama berhasil dihapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List) {
    if (!isEmpty(List)) {
        address hapus = List.first, prev = Nil;
        while (hapus->next != Nil) {
            prev = hapus;
            hapus = hapus->next;
        }
        if (prev == Nil)
            List.first = Nil;
        else
            prev->next = Nil;
        dealokasi(hapus);
        cout << "Menu terakhir berhasil dihapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev) {
    if (!isEmpty(List) && nodePrev != Nil && nodePrev->next != Nil) {
        nodeHapus = nodePrev->next;
        nodePrev->next = nodeHapus->next;
        dealokasi(nodeHapus);
        cout << "Menu setelah " << nodePrev->isidata.nama << " berhasil dihapus!" << endl;
    } else {
        cout << "Tidak dapat menghapus node!" << endl;
    }
}

void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List menu kosong." << endl;
    } else {
        address bantu = List.first;
        while (bantu != Nil) {
            cout << "Nama Minuman: " << bantu->isidata.nama
                 << ", Ukuran: " << bantu->isidata.ukuran
                 << ", Harga: Rp" << bantu->isidata.harga << endl;
            bantu = bantu->next;
        }
    }
}

int nbList(linkedlist List) {
    int count = 0;
    address bantu = List.first;
    while (bantu != Nil) {
        count++;
        bantu = bantu->next;
    }
    return count;
}

void deleteList(linkedlist &List) {
    address bantu = List.first, hapus;
    while (bantu != Nil) {
        hapus = bantu;
        bantu = bantu->next;
        dealokasi(hapus);
    }
    List.first = Nil;
    cout << "Semua menu berhasil dihapus!" << endl;
}

// update
void updateFirst(linkedlist List) {
    if (isEmpty(List))
        cout << "List kosong!" << endl;
    else {
        cout << "Update menu pertama:\n";
        cout << "Nama Minuman: ";
        cin >> List.first->isidata.nama;
        cout << "Ukuran: ";
        cin >> List.first->isidata.ukuran;
        cout << "Harga: ";
        cin >> List.first->isidata.harga;
    }
}

void updateLast(linkedlist List) {
    if (isEmpty(List))
        cout << "List kosong!" << endl;
    else {
        address bantu = List.first;
        while (bantu->next != Nil)
            bantu = bantu->next;
        cout << "Update menu terakhir:\n";
        cout << "Nama Minuman: ";
        cin >> bantu->isidata.nama;
        cout << "Ukuran: ";
        cin >> bantu->isidata.ukuran;
        cout << "Harga: ";
        cin >> bantu->isidata.harga;
    }
}

void updateAfter(linkedlist List, address prev) {
    if (isEmpty(List))
        cout << "List kosong!" << endl;
    else if (prev != Nil && prev->next != Nil) {
        address target = prev->next;
        cout << "Update menu setelah " << prev->isidata.nama << ":\n";
        cout << "Nama Minuman: ";
        cin >> target->isidata.nama;
        cout << "Ukuran: ";
        cin >> target->isidata.ukuran;
        cout << "Harga: ";
        cin >> target->isidata.harga;
    } else
        cout << "Node tidak valid!" << endl;
}

// searching berdasarkan data
void FindNodeByData(linkedlist List, string data) {
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
        return;
    }
    address bantu = List.first;
    int pos = 0;
    bool found = false;
    while (bantu != Nil) {
        pos++;
        if (bantu->isidata.nama == data) {
            cout << "Menu \"" << data << "\" ditemukan pada posisi ke-" << pos << endl;
            cout << "Ukuran: " << bantu->isidata.ukuran << ", Harga: Rp" << bantu->isidata.harga << endl;
            found = true;
            break;
        }
        bantu = bantu->next;
    }
    if (!found)
        cout << "Menu " << data << " tidak ditemukan!" << endl;
}
// berdasarkan alamat
void FindNodeByAddress(linkedlist List, address node) {
    address bantu = List.first;
    int pos = 0;
    while (bantu != Nil) {
        pos++;
        if (bantu == node) {
            cout << "Node ditemukan di posisi ke-" << pos << endl;
            cout << "Nama Minuman: " << bantu->isidata.nama << endl;
            return;
        }
        bantu = bantu->next;
    }
    cout << "Node tidak ditemukan!" << endl;
}
// berdasarkan range harga
void FindNodeByRange(linkedlist List, float min, float max) {
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
        return;
    }
    address bantu = List.first;
    bool found = false;
    cout << "--- Menu dengan harga antara Rp" << min << " - Rp" << max << " ---" << endl;
    while (bantu != Nil) {
        if (bantu->isidata.harga >= min && bantu->isidata.harga <= max) {
            cout << bantu->isidata.nama << " (" << bantu->isidata.ukuran << ") - Rp" << bantu->isidata.harga << endl;
            found = true;
        }
        bantu = bantu->next;
    }
    if (!found)
        cout << "Tidak ada menu dalam range harga tersebut." << endl;
}
