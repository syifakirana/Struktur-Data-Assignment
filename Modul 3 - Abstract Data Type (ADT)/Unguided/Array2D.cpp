#include <iostream>
using namespace std;
// menampilkan isi array 3x3
void tampilArray(int arr[3][3], string nama) {
    cout << nama << ":" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
// menukar elemen pada posisi tertentu antar dua array
void tukarElemen(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}
// menukar dua variabel lewat pointer
void tukarPointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    // dua array 3x3 langsung diisi 
    int array1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int array2[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    // dua variabel untuk pointer
    int x = 10, y = 20;
    int *p1 = &x;
    int *p2 = &y;

    // tampilkan array sebelum ditukar
    cout << "=== SEBELUM DITUKAR ===" << endl;
    tampilArray(array1, "Array 1");
    tampilArray(array2, "Array 2");
    // tukar posisi [0][0] biar kelihatan jelas
    tukarElemen(array1, array2, 0, 0);

    cout << "=== SETELAH TUKAR POSISI [0][0] ===" << endl;
    tampilArray(array1, "Array 1");
    tampilArray(array2, "Array 2");
    // tukar variabel lewat pointer
    tukarPointer(p1, p2);
    cout << "=== SETELAH TUKAR POINTER ===" << endl;
    cout << "x = " << x << ", y = " << y << endl;
    return 0;
}
