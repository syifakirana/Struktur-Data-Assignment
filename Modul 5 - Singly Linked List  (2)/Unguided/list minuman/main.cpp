#include "listMinuman.h"
#include <iostream>
using namespace std;

int main() {
    linkedlist List;
    address A, B, C, D, E = Nil;
    createList(List);

    A = alokasi("Milkshake", "Small", 18000);
    B = alokasi("Cappuccino", "Medium", 25000);
    C = alokasi("Latte", "Large", 28000);
    D = alokasi("Matcha", "Medium", 27000);
    E = alokasi("Juice", "Large", 23000);

    insertFirst(List, A);
    insertLast(List, B);
    insertAfter(List, C, A);
    insertAfter(List, D, C);
    insertLast(List, E);

    cout << "--- MENU SETELAH INSERT ---" << endl;
    printList(List);
    cout << "Total menu: " << nbList(List) << endl << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, D);

    cout << "--- MENU SETELAH UPDATE ---" << endl;
    printList(List);
    cout << endl;

    FindNodeByData(List, "Latte");
    FindNodeByAddress(List, C);
    FindNodeByRange(List, 20000, 27000);

    delFirst(List);
    delLast(List);
    delAfter(List, D, C);

    cout << "--- MENU SETELAH DELETE ---" << endl;
    printList(List);
    cout << endl;

    deleteList(List);
    cout << "--- MENU SETELAH DIHAPUS SEMUA ---" << endl;
    printList(List);

    return 0;
}
