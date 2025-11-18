#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World!" << endl;

    Queue Q;
    createQueue(Q);

    cout << "----------------------------" << endl;
    cout << "H  -  T    | Queue Info" << endl;
    cout << "----------------------------" << endl;

    printInfo(Q);

    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    enqueue(Q, 6); printInfo(Q);   // penuh terakhir

    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    enqueue(Q, 9); printInfo(Q);   // harus berputar
    enqueue(Q, 8); printInfo(Q);   // putaran lagi

    return 0;
}
