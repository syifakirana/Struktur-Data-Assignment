#include <iostream>
using namespace std;

int main() {
    // Matriks A
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Matriks B
    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int C[3][3]; // hasil operasi

    // Penjumlahan matriks
    cout << "=== HASIL PENJUMLAHAN (A + B) ===" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] + B[i][j];
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }

    // Pengurangan matriks
    cout << "\n=== HASIL PENGURANGAN (A - B) ===" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] - B[i][j];
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }

    // Perkalian matriks
    cout << "\n=== HASIL PERKALIAN (A x B) ===" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            C[i][j] = 0;
            for(int k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
