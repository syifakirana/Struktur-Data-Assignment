#include <iostream>
using namespace std;

// Fungsi menukar 3 variabel menggunakan POINTER
void tukarPointer(int *x, int *y, int *z) {
    int temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

// Fungsi menukar 3 variabel menggunakan REFERENCE
void tukarReference(int &x, int &y, int &z) {
    int temp = x;
    x = y;
    y = z;
    z = temp;
}

int main() {
    int a = 10, b = 20, c = 30;

    cout << "=== Sebelum Ditukar ===" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    // Menukar dengan POINTER
    tukarPointer(&a, &b, &c);
    cout << "\n=== Setelah Tukar (Pointer) ===" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    // Menukar lagi dengan REFERENCE
    tukarReference(a, b, c);
    cout << "\n=== Setelah Tukar (Reference) ===" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    return 0;
}
