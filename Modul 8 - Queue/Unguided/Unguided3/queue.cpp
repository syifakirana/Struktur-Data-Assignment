#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmpty(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFull(Queue Q) {
    return ((Q.tail + 1) % MAKSIMAL == Q.head);
}

void enqueue(Queue &Q, int x) {
    if (isFull(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmpty(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % MAKSIMAL;
    }

    Q.info[Q.tail] = x;
}

int dequeue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    int nilai = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % MAKSIMAL;
    }

    return nilai;
}

void printInfo(Queue Q) {
    if (isEmpty(Q)) {
        cout << Q.head << "  -  " << Q.tail << "    | empty queue" << endl;
        return;
    }

    cout << Q.head << "  -  " << Q.tail << "    | ";

    int i = Q.head;
    while (true) {
        cout << Q.info[i];
        if (i == Q.tail) break;
        cout << " ";
        i = (i + 1) % MAKSIMAL;
    }
    cout << endl;
}
