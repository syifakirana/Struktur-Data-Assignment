# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
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
```
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
```
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

int main() {
    cout << "ini adalah file code unguided praktikan" << endl;
    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk menyimpan data maksimal 10 mahasiswa yang mencakup nama, NIM, nilai UTS, UAS, dan tugas. Program menggunakan fungsi hitungNilaiAkhir() untuk menghitung nilai akhir dengan rumus 0.3 * UTS + 0.4 * UAS + 0.3 * Tugas. Data mahasiswa disimpan dalam array dan ditampilkan dengan jarak antar mahasiswa agar hasilnya lebih rapi di layar.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)

### 2. Buatlah ADT pelajaran sebagai berikut di dalam file “pelajaran.h”:


Buatlah implementasi ADT pelajaran pada file “pelajaran.cpp”
Cobalah hasil implementasi ADT pada file “main.cpp”

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code unguided praktikan" << endl;
    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk menyimpan data maksimal 10 mahasiswa yang mencakup nama, NIM, nilai UTS, UAS, dan tugas. Program menggunakan fungsi hitungNilaiAkhir() untuk menghitung nilai akhir dengan rumus 0.3 * UTS + 0.4 * UAS + 0.3 * Tugas. Data mahasiswa disimpan dalam array dan ditampilkan dengan jarak antar mahasiswa agar hasilnya lebih rapi di layar.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)

## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
