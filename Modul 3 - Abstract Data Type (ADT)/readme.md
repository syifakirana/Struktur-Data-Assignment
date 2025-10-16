<h1 align="center">Laporan Praktikum Modul Abstract Data Type (ADT)</h1>
<p align="center">Syifa Kirana Putri Surya</p>

## Dasar Teori

Berikan penjelasan teori terkait materi modul ini dengan bahasa anda sendiri serta susunan yang terstruktur per topiknya.

## Guided 

### 1. Program Menghitung Rata-Rata Nilai Mahasiswa (menggunakan multiple file)

File: mahasiswa.h
```C++
#ifndef MAHASISWA H INCLUDED
#define MAHASISWA_H_INCLUDED
struct mahasiswa{
char nim[10];
int nilail, nilai2;
};
void inputMhs (mahasiswa &m);
float rata2(mahasiswa m);
#endif // MAHASISWA_H_INCLUDED
```

File: mahasiswa.cpp
```C++
#include <iostream>
using namespace std;
#include "mahasiswa.h"
void inputMhs (mahasiswa &m) {
cout << "input nama = ";
cin >> (m).nim;
cout << "input nilai = ";
cin >> (m).nilail;
cout << "input nilai2 = ";
cin >> (m).nilai2;
}
float rata2(mahasiswa m){
return (m.nilail + m.nilai2) / 2.0;
}
```

File: main.cpp
```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;
int main() {
mahasiswa mhs;
inputMhs (mhs);
cout << "rata-rata = " << rata2(mhs);
return 0;
}
```

Program di atas digunakan untuk memasukkan dua nilai mahasiswa dan menampilkan hasil rata-ratanya di layar. Program dibagi menjadi tiga file agar lebih terstruktur: mahasiswa.h berisi data dan fungsi yang digunakan, mahasiswa.cpp berisi isi fungsi, dan main.cpp sebagai file utama untuk menjalankan program dan menampilkan hasilnya dengan cout.

## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.

```C++
#include <iostream>
using namespace std;

// untuk menghitung nilai akhir
float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main() {
    const int maks = 10;
    string nama[maks];
    string nim[maks];
    float uts[maks], uas[maks], tugas[maks], nilaiAkhir[maks];
    int jumlah;

    cout << "Masukkan jumlah mahasiswa (max. 10): ";
    cin >> jumlah;
    cout << endl;

    if (jumlah > maks) {
        cout << "Maksimal hanya bisa 10 mahasiswa!" << endl;
        return 0;
    }

    for (int i = 0; i < jumlah; i++) {
        cout << "Data Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama   : ";
        cin >> nama[i];
        cout << "NIM    : ";
        cin >> nim[i];
        cout << "UTS    : ";
        cin >> uts[i];
        cout << "UAS    : ";
        cin >> uas[i];
        cout << "Tugas  : ";
        cin >> tugas[i];

        nilaiAkhir[i] = hitungNilaiAkhir(uts[i], uas[i], tugas[i]);
        cout << endl;
    }

    cout << "Daftar Nilai Mahasiswa";
    for (int i = 0; i < jumlah; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama        : " << nama[i] << endl;
        cout << "NIM         : " << nim[i] << endl;
        cout << "UTS         : " << uts[i] << endl;
        cout << "UAS         : " << uas[i] << endl;
        cout << "Tugas       : " << tugas[i] << endl;
        cout << "Nilai Akhir : " << nilaiAkhir[i] << endl;
    }

    return 0;
}

```
#### Output:
<img width="1426" height="681" alt="Image" src="https://github.com/user-attachments/assets/d985f22f-0053-4c6c-adae-297099949bb5" />

Kode di atas digunakan untuk menghitung dan menampilkan nilai akhir mahasiswa berdasarkan nilai UTS, UAS, dan tugas dengan bobot masing-masing 30%, 40%, dan 30%. Data setiap mahasiswa disimpan menggunakan array dengan kapasitas maksimal sepuluh data. Fungsi hitungNilaiAkhir digunakan agar proses perhitungan nilai menjadi lebih terstruktur dan mudah dibaca. Pengguna akan diminta memasukkan nama, NIM, serta nilai-nilai yang diperlukan, lalu program secara otomatis menampilkan daftar mahasiswa beserta nilai akhirnya.

#### Full code Screenshot:
<img width="1919" height="1019" alt="Image" src="https://github.com/user-attachments/assets/747027a1-babb-4f62-b765-7b414b1a41b8" />

### 2. Buatlah ADT pelajaran sebagai berikut di dalam file “pelajaran.h”:  

<img width="722" height="125" alt="Image" src="https://github.com/user-attachments/assets/048b2ed8-33ad-4015-bc5a-813596a7348f" /><br>
Buatlah implementasi ADT pelajaran pada file “pelajaran.cpp”  
Cobalah hasil implementasi ADT pada file “main.cpp”  

<img width="834" height="188" alt="Image" src="https://github.com/user-attachments/assets/87456f69-bd6a-4bbc-8a19-3f30f77c125b" /><br>
Gambar 3-1 main.cpp pelajaran  
Contoh output hasil :  

<img width="356" height="58" alt="Image" src="https://github.com/user-attachments/assets/532a5d94-0163-4c5b-8704-0bb673ecf832" />  <br>
Gambar 3-2 output pelajaran

File : pelajaran.h
```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif
```

File : pelajaran.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```

File : main2.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```

#### Output:
<img width="503" height="236" alt="Image" src="https://github.com/user-attachments/assets/d679d261-5748-416f-889e-d4a2fcfc042c" />  

Program ini terdiri dari tiga file, yaitu pelajaran.h, pelajaran.cpp, dan main2.cpp, yang digunakan untuk menyimpan dan menampilkan data mata pelajaran. Di file pelajaran.h, dibuat struktur bernama pelajaran yang berisi dua data, yaitu nama mata pelajaran dan kode pelajaran. File ini juga berisi deklarasi dua fungsi, yaitu create_pelajaran() untuk membuat data pelajaran baru dan tampil_pelajaran() untuk menampilkannya. Di file pelajaran.cpp, kedua fungsi tersebut dijelaskan cara kerjanya — create_pelajaran() mengisi nama dan kode pelajaran lalu mengembalikannya, sedangkan tampil_pelajaran() menampilkan hasilnya ke layar. Terakhir, di file main2.cpp, program utama membuat satu data pelajaran dengan nama “Struktur Data” dan kode “STD”, lalu menampilkan hasilnya dengan memanggil fungsi yang sudah dibuat.

#### Full code Screenshot:
File : pelajaran.h
<img width="1131" height="661" alt="Image" src="https://github.com/user-attachments/assets/a032c586-183b-4f7d-b5ae-f806106b6833" />

File : pelajaran.cpp
<img width="999" height="648" alt="Image" src="https://github.com/user-attachments/assets/c9c2076d-a55d-475d-bea4-6b0fb6bde9c0" />

File : main2.cpp
<img width="931" height="563" alt="image" src="https://github.com/user-attachments/assets/16805382-8cbf-4bb0-bf71-a3231e99e624" />


### 3. Buatlah program dengan ketentuan :
- 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
- fungsi/prosedur yang menampilkan isi sebuah array integer 2D
- fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu

```C++
#include <iostream>
using namespace std;

// fungsi menampilkan isi array 3x3
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

// fungsi menukar elemen pada posisi tertentu antar dua array
void tukarElemen(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

// fungsi menukar dua variabel lewat pointer
void tukarPointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    // dua array 3x3 langsung diisi (tanpa input dari user)
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
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk

#### Full code Screenshot:

## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

