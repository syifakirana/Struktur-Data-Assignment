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
void getInputStream(Stack &S) {
    char c;
    while (true) {
        cin.get(c);       // baca 1 karakter dari input
        if (c == '\n')    // ENTER -> selesai
            break;
        Push(S, c - '0'); // asumsikan input digit
    }
}
