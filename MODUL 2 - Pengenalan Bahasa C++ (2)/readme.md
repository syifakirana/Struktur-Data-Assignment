# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (2)</h1>
<p align="center">Syifa Kirana Putri Surya</p>


## Dasar Teori


---

## Guided

### 1. array

```cpp
#include <iostream>
using namespace std;

int main() {
    // Array  1 dimensi
    int arr1D[5] = {10, 20, 30, 40, 50};
    cout << "Array 1 dimensi:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "arr[" << i << ":] = " << arr1D[i] << endl;
    }
    cout << endl;

    // Array 2 dimensi
    int arr2D[3][4] = {
        {1, 2, 3},
        {4, 5, 6},
    };
    cout << "Array 2 dimensi:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "arr2D[" << i << "][" << j << "] = " << arr2D[i][j]
            << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Array Multi Dimensi (3D)
    int arr3D[2][2][3] = {
        { {1, 2, 3}, {4, 5, 6} },
        { {7, 8, 9}, {10, 11, 12} } 
    };
    cout << "Array 3 dimensi:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                cout << "arr3D[" << i << "][" << j << "]["
                << k << "] = "<< arr3D[i][j][k] << endl;
            }
        }
    }

    return 0;
}
```
Program di atas digunakan untuk menampilkan isi array 1 dimensi, 2 dimensi, dan 3 dimensi menggunakan perulangan for dan menggunakan fungsi cout untuk menampilkan nilai-nilai tersebut ke layar sesuai urutan indeksnya.

### 2. Function Procedure 

```cpp
#include <iostream>
using namespace std;

void tulis (int x) {
    for (int i = 0; i < x; i++){
        cout << "Baris ke -: " << i+1 << endl;
        }
}

int main() {
    int jum;
    cout << "Jumlah baris kata: ";
    cin >> jum;
    tulis(jum);
    return 0;
}
```
Program di atas digunakan untuk menampilkan sejumlah baris teks sesuai input pengguna dengan menggunakan fungsi tulis() dan perulangan for.

### 3. Pointer

```cpp
#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
} 

int main() {
    int a =20, b =30;
    int *ptr;

    ptr = &a;

    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Value stored in ptr (Address of a): " << ptr << endl;
    cout << "Value pointes to by ptr: " << *ptr << endl;

    tukar(&a, &b);
    cout << "After swapping, value of a = " << a << " and b = " << b << endl;

    return 0;
    
}
```
Program di atas digunakan untuk menukar nilai dua variabel menggunakan pointer. Pointer menyimpan alamat memori dari variabel lain sehingga nilai variabel bisa diubah secara tidak langsung melalui alamatnya. Program juga menampilkan nilai variabel, alamat memori, dan nilai yang ditunjuk oleh pointer sebelum serta sesudah proses pertukaran dengan fungsi tukar().

### 4. References

```cpp
#include <iostream>
using namespace std;

void tukar (int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 20, b = 30;
    int& ref = a;

    cout << "Nilai a: " << a << endl;
    cout << "Alamat a (&a): " << &a << endl;
    cout << "Nilai ref (alias a): " << ref << endl; 
    cout << "Alamat ref (&ref): " << &ref << endl; 

    //Mengubah nilai a lewat reference
    ref = 50;
    cout << "\nSetelah ref = 50;" << endl;
    cout << "Nilai a: " << a << endl;
    cout << "Nilai ref: " << ref << endl;

    tukar(a, b);
    cout << "After swapping, value of a=" << a << " and b=" << b << endl; 

    return 0;
}
```
Program di atas digunakan untuk menukar nilai dua variabel menggunakan reference dan menunjukkan bahwa reference merupakan alias dari variabel asli, sehingga perubahan pada reference juga mengubah nilai variabel tersebut.

## Unguided (BELUM)

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3

```cpp
#include <iostream>
using namespace std;

int main() {
     float a, b;

    cout << "Masukkan bilangan pertama: ";
    cin >> a;
    cout << "Masukkan bilangan kedua: ";
    cin >> b;

    //Operator aritmatika
    cout << "a + b = " << (a+b) << endl;
    cout << "a - b = " << (a-b) << endl;
    cout << "a * b = " << (a*b) << endl;
    cout << "a / b = " << (a/b) << endl;

    return 0;
}
```
### Output:
<img width="513" height="306" alt="Image" src="https://github.com/user-attachments/assets/820d5bb0-69d5-4c2d-9600-63f8594d1b98" />

Program di atas bertujuan untuk memperlihatkan

### Full Code Screenshot:
<img width="1913" height="1028" alt="Image" src="https://github.com/user-attachments/assets/d9656c1b-a2c0-4f81-91c5-ceec7868c327" />


### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel

```cpp
#include <iostream>
using namespace std;

int main() {
    string satuan[] = {"nol","satu","dua","tiga","empat","lima",
                       "enam","tujuh","delapan","sembilan"};
    string belasan[] = {"sepuluh","sebelas","dua belas","tiga belas","empat belas",
                        "lima belas","enam belas","tujuh belas","delapan belas","sembilan belas"};
    string puluhan[] = {"","sepuluh","dua puluh","tiga puluh","empat puluh",
                        "lima puluh","enam puluh","tujuh puluh","delapan puluh","sembilan puluh"};

    int n;
    cout << "Masukkan angka (0-100): ";
    cin >> n;

    if (n < 10) cout << satuan[n];
    else if (n < 20) cout << belasan[n - 10];
    else if (n < 100) {
        cout << puluhan[n/10];
        if (n % 10 != 0) cout << " " << satuan[n%10];
    }
    else if (n == 100) cout << "seratus";
    else cout << "di luar jangkauan";

    cout << endl;
    return 0;
}

```
### Output:
<img width="506" height="330" alt="Image" src="https://github.com/user-attachments/assets/76789aec-e9bf-4cb6-a24c-ca0cdcecd4fc" />

Program di atas bertujuan untuk

### Full Code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/f1096193-6b67-4107-89cc-c71d1c0962a5" />

### 3. Diketahui sebuah array 1 dimensi sebagai berikut : arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55}
Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan menu switch-case seperti berikut ini :
--- Menu Program Array ---
1. Tampilkan isi array
2. cari nilai maksimum
3. cari nilai minimum
4. Hitung nilai rata - rata


```cpp
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

```
### Output:
<img width="580" height="447" alt="Image" src="https://github.com/user-attachments/assets/27b301a3-0129-4a4b-a5d9-e5873750104f" /> 

Program di atas bertujuan untuk 

### Full Code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/d2a1cbda-901b-47e3-b430-8d8a1cd9cffd" />


## Kesimpulan
Dari praktikum ini, yang saya dapatkan adalah pemahaman konsep dasar pemrograman seperti variabel, tipe data, input-output, operator aritmatika dan perbandingan, percabangan, perulangan, serta array sangat penting untuk membangun program yang efektif. Praktikum ini membantu memperkuat pemahaman teori melalui penerapan langsung, sehingga kita dapat melihat bagaimana setiap konsep bekerj. misalnya bagaimana percabangan mempengaruhi alur program, atau bagaimana loop mempermudah pengolahan data berulang.
