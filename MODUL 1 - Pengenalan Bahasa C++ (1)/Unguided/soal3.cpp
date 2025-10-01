#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan angka: ";
    cin >> n;

    for (int i = n; i >= 1; i--) {
        // cetak spasi di depan
        for (int s = 0; s < (n - i); s++) {
            cout << "  "; // 2 spasi biar rapi
        }

        // kiri menurun
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        // bintang
        cout << "* ";

        // kanan menaik
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        cout << endl;
    }

    // baris terakhir spasi terus bintang
    for (int s = 0; s < n; s++) {
        cout << "  ";
    }
    cout << "*";

    return 0;
}
