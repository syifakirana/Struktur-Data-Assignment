#include <iostream>
#include "stack.h"
using namespace std;

void CreateStack(Stack &S) {
    S.top = -1;
}

void Push(Stack &S, infotype x) {
    if (S.top < 19) {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype Pop(Stack &S) {
    if (S.top >= 0) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    }
    return -1;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    CreateStack(temp);

    while (S.top >= 0) {
        Push(temp, Pop(S));
    }

    S = temp; // hanya 1 kali pembalikan
}

//tambahan
void pushAscending(Stack &S, infotype x) {
    Stack temp;
    CreateStack(temp);

    // pindahkan elemen yang lebih besar ke temp
    while (S.top >= 0 && S.info[S.top] > x) {
        Push(temp, Pop(S));
    }

    // push elemen baru
    Push(S, x);

    // kembalikan elemen dari temp
    while (temp.top >= 0) {
        Push(S, Pop(temp));
    }
}
