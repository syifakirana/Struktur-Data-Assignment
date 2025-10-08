# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (2)</h1>
<p align="center">Syifa Kirana Putri Surya</p>


## Dasar Teori
1. Array

Array adalah kumpulan data dengan tipe yang sama yang disimpan dalam satu variabel. Setiap elemen array dapat diakses menggunakan indeks, sehingga memudahkan pengolahan dan pengelolaan data secara efisien. Array bisa berupa satu dimensi, dua dimensi, atau multidimensi, tergantung kebutuhan program. Penggunaan array sangat berguna untuk menyimpan banyak data sekaligus dan melakukan operasi seperti penjumlahan, pencarian nilai maksimum/minimum, dan perhitungan rata-rata.

2. Pointer

Pointer adalah variabel yang menyimpan alamat memori dari variabel lain. Dengan pointer, program dapat mengakses dan mengubah nilai variabel secara langsung melalui alamatnya. Pointer juga memungkinkan pertukaran nilai antar variabel melalui function, sehingga proses menjadi lebih efisien dan fleksibel.

3. Reference

Reference adalah alias dari variabel yang sudah ada, artinya reference menunjuk langsung ke variabel asli. Perubahan yang dilakukan melalui reference akan mempengaruhi variabel aslinya. Reference memudahkan pengelolaan data dan sering digunakan untuk menukar nilai antar variabel tanpa memerlukan pointer.

4. Function dan Prosedur

Function adalah blok kode yang melakukan tugas tertentu dan biasanya mengembalikan nilai. Function membantu membuat program lebih modular, rapi, dan mudah dipahami. Contohnya, function dapat digunakan untuk mencari nilai minimum atau maksimum dalam array. Prosedur atau void function adalah function yang tidak mengembalikan nilai, digunakan untuk menjalankan proses tertentu, seperti menghitung dan menampilkan nilai rata-rata.

5. Percabangan

Percabangan digunakan untuk menentukan jalannya program berdasarkan kondisi tertentu. Struktur percabangan memungkinkan program mengeksekusi kode tertentu hanya jika kondisi terpenuhi. Percabangan sangat berguna untuk membandingkan elemen array saat mencari nilai minimum atau maksimum, atau saat membuat logika menu interaktif.

6. Perulangan

Perulangan digunakan untuk mengeksekusi perintah secara berulang hingga kondisi tertentu terpenuhi. Dalam program array, perulangan digunakan untuk menelusuri semua elemen, menghitung jumlah total, menampilkan isi array, dan menemukan nilai minimum atau maksimum.

7. Switch-Case

Switch-case adalah bentuk percabangan yang digunakan untuk memilih jalannya program berdasarkan nilai variabel tertentu. Struktur ini membuat menu program menjadi interaktif dan mudah digunakan. Dalam praktikum ini, switch-case digunakan untuk memungkinkan pengguna memilih aksi seperti menampilkan array, mencari nilai maksimum/minimum, atau menghitung rata-rata.

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

## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3

```cpp
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

```
### Output:
<img width="585" height="344" alt="Image" src="https://github.com/user-attachments/assets/c3fe043b-1092-4dbd-b204-e94a0d1f1fa1" />

Program di atas bertujuan untuk melakukan operasi penjumlahan, pengurangan, dan perkalian pada dua matriks 3x3. Matriks A dan B langsung didefinisikan di dalam program, kemudian program membuat matriks C sebagai tempat menyimpan hasil operasi.
Penjumlahan: setiap elemen C[i][j] diisi dengan A[i][j] + B[i][j].
Pengurangan: setiap elemen C[i][j] diisi dengan A[i][j] - B[i][j].
Perkalian: setiap elemen C[i][j] dihitung dengan menjumlahkan hasil perkalian elemen baris A[i][k] dengan elemen kolom B[k][j] untuk k dari 0 sampai 2.
Hasil dari setiap operasi ditampilkan ke layar menggunakan cout.

### Full Code Screenshot:
<img width="1331" height="1003" alt="Image" src="https://github.com/user-attachments/assets/962a3d8e-3679-4cf4-bfff-4e50212b5ed2" />


### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel

```cpp
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

```
### Output:
<img width="513" height="300" alt="Image" src="https://github.com/user-attachments/assets/8357e0ea-2c26-4271-8c7b-97ea5fc0c9de" />

Program ini bertujuan untuk menukar nilai tiga variabel (a, b, c) dengan dua cara, yaitu menggunakan pointer dan reference. Fungsi pointer memakai alamat variabel untuk mengubah nilainya, sedangkan reference langsung mengubah variabel aslinya. Di main(), program menampilkan nilai awal, menukar dengan pointer, menampilkan hasilnya, lalu menukar lagi dengan reference dan menampilkan hasil akhirnya. Program ini menunjukkan cara mengubah nilai variabel lewat fungsi dengan dua metode berbeda.

### Full Code Screenshot:
<img width="1357" height="875" alt="Image" src="https://github.com/user-attachments/assets/0b3c558a-1808-45c1-9037-b108d8d03c39" />

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

// Function untuk mencari nilai minimum
int cariMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Function untuk mencari nilai maksimum
int cariMaksimum(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Prosedur untuk menghitung rata-rata
void hitungRataRata(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    double rata = (double)total / n;
    cout << "Nilai rata-rata dari array adalah: " << rata << endl;
}

int main() {
    int arrA[] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int n = sizeof(arrA)/sizeof(arrA[0]);
    int pilihan;

    do {
        // Menampilkan menu
        cout << "\n--- Menu Program Array ---\n";
        cout << "1. Tampilkan isi array\n";
        cout << "2. Cari nilai maksimum\n";
        cout << "3. Cari nilai minimum\n";
        cout << "4. Hitung nilai rata-rata\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                cout << "Isi array: ";
                for (int i = 0; i < n; i++) {
                    cout << arrA[i] << " ";
                }
                cout << endl;
                break;
            case 2:
                cout << "Nilai maksimum dari array adalah: " << cariMaksimum(arrA, n) << endl;
                break;
            case 3:
                cout << "Nilai minimum dari array adalah: " << cariMinimum(arrA, n) << endl;
                break;
            case 4:
                hitungRataRata(arrA, n);
                break;
            case 5:
                cout << "Program selesai. Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 5);

    return 0;
}

```
### Output:
<img width="1141" height="758" alt="Image" src="https://github.com/user-attachments/assets/2aa86a38-7096-4577-a220-b1d41ef647ac" />

Program ini bertujuan untuk melakukan beberapa operasi pada array satu dimensi arrA, yaitu menampilkan isi array, mencari nilai maksimum, minimum, dan menghitung rata-rata. Function cariMinimum() digunakan untuk menemukan nilai terkecil, cariMaksimum() untuk nilai terbesar, dan prosedur hitungRataRata() untuk menghitung dan menampilkan rata-rata. Program menampilkan menu interaktif menggunakan switch-case, sehingga pengguna dapat memilih opsi yang diinginkan, dan setiap pilihan akan dijalankan sampai pengguna memilih keluar.
### Full Code Screenshot:
<img width="1364" height="1022" alt="Image" src="https://github.com/user-attachments/assets/85f33b1e-9610-4762-aa5e-b0f5a6a92998" />
<img width="1322" height="1033" alt="Image" src="https://github.com/user-attachments/assets/3f256afc-08c0-48e1-bd90-0c35957a61dd" />

## Kesimpulan
Dari praktikum ini, saya mendapatkan pemahaman tentang bagaimana menggunakan array, function, prosedur, pointer, reference, perulangan, dan percabangan untuk membangun program yang efektif. Praktikum ini membantu memperkuat konsep teori melalui penerapan langsung, sehingga kita bisa melihat bagaimana function dan prosedur mempermudah pengolahan data, bagaimana pointer dan reference memungkinkan pengubahan nilai variabel secara efisien, serta bagaimana switch-case dan loop mempermudah interaksi dan pengolahan data dalam program.
