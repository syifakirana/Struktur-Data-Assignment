# <h1 align="center">Laporan Praktikum Modul Abstract Data Type (ADT)</h1>
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

<img width="722" height="125" alt="Image" src="https://github.com/user-attachments/assets/048b2ed8-33ad-4015-bc5a-813596a7348f" /><br>
Buatlah implementasi ADT pelajaran pada file “pelajaran.cpp”  
Cobalah hasil implementasi ADT pada file “main.cpp”  

<img width="834" height="188" alt="Image" src="https://github.com/user-attachments/assets/87456f69-bd6a-4bbc-8a19-3f30f77c125b" /><br>
Gambar 3-1 main.cpp pelajaran  
Contoh output hasil :  

<img width="356" height="58" alt="Image" src="https://github.com/user-attachments/assets/532a5d94-0163-4c5b-8704-0bb673ecf832" />  <br>
Gambar 3-2 output pelajaran

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

### 3. Buatlah program dengan ketentuan :
- 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
- fungsi/prosedur yang menampilkan isi sebuah array integer 2D
- fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu

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

Kode di atas digunakan untuk

#### Full code Screenshot:

## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

