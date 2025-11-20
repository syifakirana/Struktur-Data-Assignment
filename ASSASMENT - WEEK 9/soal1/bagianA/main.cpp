#include "SLLInventory.h"

int main() {
    List L;
    createList(L);
    Product P;
    P = {"Pulpen", "A001", 20, 2500, 0};
    insertLast(L, P);

    P = {"Buku Tulis", "A002", 15, 5000, 10};
    insertLast(L, P);

    P = {"Penghapus", "A003", 30, 1500, 0};
    insertLast(L, P);

    viewList(L);
    Product del;
    deleteFirst(L, del);
    viewList(L);
    P = {"Stabilo", "A010", 40, 9000, 5};
    updateAtPosition(L, 2, P);

    viewList(L);
    searchByFinalPriceRange(L, 2000, 7000);
    return 0;
}