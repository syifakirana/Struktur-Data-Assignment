#ifndef QUEUE_H
#define QUEUE_H

const int MAKSIMAL = 5;

struct Queue {
    int info[MAKSIMAL];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
