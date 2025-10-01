# Laporan Praktikum Modul Pengenalan Bahasa C++ (1)

---

## Dasar Teori
Dasar teori modul ini mencakup berbagai konsep penting dalam pemrograman C++. Variabel berfungsi sebagai wadah untuk menyimpan data, sedangkan tipe data menentukan jenis nilai yang dapat disimpan, seperti int untuk bilangan bulat, float untuk bilangan desimal, dan string untuk teks. Input dan output (cin dan cout) memungkinkan program bisa berinteraksi dengan pengguna, sedangkan operator aritmatika (+, -, *, /) digunakan untuk perhitungan matematis, dan operator perbandingan (==, !=, <, >, <=, >=) digunakan untuk membandingkan dua nilai. Percabangan menggunakan if, else if, dan else memungkinkan program mengeksekusi kode tertentu berdasarkan kondisi yang diberikan, sedangkan perulangan dengan for, while, dan do-while membantu mengeksekusi perintah berulang kali sesuai kebutuhan. Array adalah struktur data yang menyimpan sekumpulan nilai sejenis dalam satu variabel sehingga memudahkan pengolahan dan pengelolaan data.

---

## Guided

### 1. Hello World

```cpp
#include <iostream>
using namespace std;

int main() {
    // Write C++ code here
   cout << "Hello world!";
    return 0;
}
```
Program di atas digunakan untuk menampilkan teks “Hello world!” ke layar dengan memanfaatkan fungsi cout untuk mengeksekusinya

### 2. Input Output

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    const float pi = 3.14;

    cout << "Masukkan angka: ";
    cin >> n;

    cout << "Angka dikeluarkan: " << n << endl;
    cout << "Nilai konstanta pi: " << pi << endl;
    return 0;
    
}
```
Program di atas digunakan untuk meminta input sebuah bilangan dari pengguna kemudian menampilkannya kembali ke layar. Selain itu, program juga menampilkan nilai konstanta π (3.14) yang sudah ditentukan dengan kata kunci const. Jadi, fungsinya adalah mendemonstrasikan penggunaan variabel input, konstanta, serta proses input-output dengan cin dan cout di C++.

### 3. Operator

```cpp
#include <iostream>
using namespace std;

int main() {
    int a;
    int b;

    cout << "Masukkan angka1: ";
    cin >> a;
    cout << "Masukkan angka2: ";
    cin >> b;

    //Operator aritmatika
    cout << "a + b = " << (a+b) << endl;
    cout << "a - b = " << (a-b) << endl;
    cout << "a * b = " << (a*b) << endl;
    cout << "a / b = " << (a/b) << endl;
    cout << "a % b = " << (a%b) << endl;

    cout << "a > b = " << (a>b) << endl;
    cout << "a < b = " << (a<b) << endl;
    cout << "a >= b = " << (a>=b) << endl;
    cout << "a <= b = " << (a<=b) << endl;
    cout << "a == b = " << (a==b) << endl;
    cout << "a != b = " << (a!=b) << endl;
    return 0;
}
```
Program di atas bertujuan untuk memperlihatkan implementasi operator aritmatika dan operator perbandingan. Pengguna diminta untuk memasukkan dua buah bilangan bulat yang disimpan dalam variabel a dan b. Selanjutnya, program akan menampilkan hasil dari berbagai operasi aritmatika seperti penjumlahan, pengurangan, perkalian, pembagian, dan modulus. Selain itu, program juga menampilkan hasil evaluasi dari operasi perbandingan, yaitu perbandingan antara kedua bilangan tersebut menggunakan operator lebih besar, lebih kecil, sama dengan, tidak sama dengan, serta operator lebih besar atau sama dengan dan lebih kecil atau sama dengan. Program ini berfungsi sebagai latihan dasar untuk memahami cara kerja operator aritmatika dan relasi dalam C++ serta bagaimana hasilnya ditampilkan sebagai keluaran.

### 4. Percabangan

```cpp
#include <iostream>
using namespace std;

int main() {
    int angka1 = 10;
    int angka2 = 20;

    if (angka1 > angka2) {
        cout << "Angka 1 lebih besar dari Angka 2" << endl;
    } else if (angka1 < angka2) {
        cout  << "Angka 1 lebih kecil dari Angka 2" << endl;
    } else {
        cout << "Angka 1 sama dengan Angka 2" << endl;
    }

    return 0;
    
}
```
Program di atas merupakan penggunaan sederhana dari struktur kontrol percabangan if, else if, dan else dalam bahasa C++. Pada program ini terdapat dua variabel, yaitu angka1 dengan nilai 10 dan angka2 dengan nilai 20. Program kemudian melakukan proses perbandingan antara kedua variabel tersebut. Jika nilai angka1 lebih besar daripada angka2, maka blok kode pada bagian if akan dijalankan, sehingga menampilkan pesan “Angka 1 lebih besar dari Angka 2”. Jika kondisi pertama salah tetapi angka1 lebih kecil daripada angka2, maka bagian else if akan dijalankan dengan menampilkan pesan “Angka 1 lebih kecil dari Angka 2”. Apabila kedua kondisi tersebut tidak terpenuhi, maka bagian else akan dijalankan untuk menampilkan pesan “Angka 1 sama dengan Angka 2”. Berdasarkan nilai yang diberikan dalam kode, yaitu angka1 = 10 dan angka2 = 20, hasil keluaran dari program adalah “Angka 1 lebih kecil dari Angka 2”.

### 5. Perulangan

```cpp
#include <iostream>
using namespace std;
int main() {
   int i ;
   int j = 0 ;

   for (int i = 0; i < 10; i++) {
         cout << i <<  "-";
      }
      cout << endl;

    do {
        cout << j << "-";
        j++;
    } while (j < 10);

    return 0;
   }
```
Program ini menampilkan penggunaan for loop dan do-while loop. Pada bagian pertama, perulangan for digunakan untuk mencetak angka dari 0 sampai 9 dengan tanda hubung setelah setiap angka. Setelah itu, program melanjutkan dengan perulangan do-while yang juga mencetak angka mulai dari 0 sampai 9 dengan pola serupa. Bedanya, perulangan for langsung mengecek kondisi di awal, sedangkan do-while akan menjalankan isi perulangan minimal satu kali sebelum memeriksa kondisi.

### 6. PerulanganDoWhile

```cpp
#include <iostream>
using namespace std;

int main() {
    int i = 0;
    int j = 20;

    while (i <= 10){
        cout << i << "-";
        i++;
    }

    cout << endl;

    do {
        cout << j << "-";
        j++;
    } while (j <= 10);

    return 0;
    
}
```
Program ini menampilkan penggunaan perulangan while dan do-while. Pada bagian pertama, perulangan while digunakan untuk mencetak angka dari 0 hingga 10 dengan tanda hubung setelah setiap angka. Setelah itu, program mengeksekusi perulangan do-while yang dimulai dengan nilai j = 20. Karena kondisi perulangan j <= 10 tidak terpenuhi, perulangan hanya berjalan satu kali dan tetap mencetak angka 20.

### 7. Struktur

```cpp
#include <iostream>
using namespace std;


struct Mahasiswa {
    string nama;
    int umur;
};

int main() {
    int jumlah;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlah;

    Mahasiswa mhs[jumlah];

    //input data menggunakan loop
    for (int i = 0; i < jumlah; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama: ";
        cin >> mhs[i].nama;
        cout << "Umur: ";
        cin >> mhs[i].umur;
    }

    //Tampilkan data
    cout << "\n=== Data Mahasiswa ===\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "Mahasiswa ke-" << i+1
            << " | Nama: " << mhs[i].nama
            << " | Umur: " << mhs[i].umur << endl;

    }
        return 0;
}
```
Program ini menggunakan struct untuk menyimpan data mahasiswa. Struct Mahasiswa mempunyai dua atribut, yaitu nama dan umur. Pertama, program meminta pengguna memasukkan jumlah mahasiswa yang ingin dicatat. Lalu dengan bantuan perulangan for, program meminta input nama dan umur dari setiap mahasiswa. Setelah semua data dimasukkan, program akan menampilkan kembali daftar mahasiswa dengan data yang sudah diberikan. Program ini menunjukkan cara sederhana menyimpan dan menampilkan kumpulan data menggunakan struct dan perulangan

## Unguided

### 1. Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

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

Program di atas bertujuan untuk memperlihatkan implementasi operator aritmatika dasar dalam C++. Pengguna diminta untuk memasukkan dua bilangan bertipe float yang disimpan dalam variabel a dan b. Selanjutnya, program akan menampilkan hasil dari operasi aritmatika seperti penjumlahan, pengurangan, perkalian, dan pembagian antara kedua bilangan tersebut. Program ini berfungsi sebagai latihan dasar untuk memahami cara kerja operator aritmatika dalam C++ serta bagaimana hasil perhitungannya ditampilkan sebagai keluaran menggunakan cout.

### Full Code Screenshot:
<img width="1913" height="1028" alt="Image" src="https://github.com/user-attachments/assets/d9656c1b-a2c0-4f81-91c5-ceec7868c327" />


### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100. Contoh: 79 : tujuh puluh sembilan

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

Program di atas bertujuan untuk mengubah angka dari 0 hingga 100 menjadi kata dalam bahasa Indonesia. Program ini menggunakan tiga array satuan, belasan, dan puluhan untuk menyimpan representasi kata dari angka 0–9, 10–19, dan kelipatan puluhan. Pengguna diminta memasukkan sebuah angka n, lalu program memeriksa nilainya: jika kurang dari 10, ditampilkan dari array satuan; jika antara 10–19, ditampilkan dari array belasan; jika 20–99, ditampilkan dari array puluhan dan, jika ada sisa, ditambahkan kata dari array satuan; jika 100, ditampilkan "seratus"; selain itu, program menampilkan pesan "di luar jangkauan".

### Full Code Screenshot:
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/f1096193-6b67-4107-89cc-c71d1c0962a5" />

### 3. Buatlah program yang dapat memberikan input dan output sbb.



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

Program di atas bertujuan untuk mencetak pola segitiga angka dengan simbol bintang di tengah berdasarkan input angka n. Program meminta pengguna memasukkan sebuah angka n, kemudian menggunakan loop for untuk mencetak setiap baris dari atas ke bawah. Pada setiap baris: pertama dicetak spasi agar pola rata tengah, lalu deretan angka menurun dari i ke 1 di sebelah kiri, diikuti simbol *, lalu deretan angka menaik dari 1 ke i di sebelah kanan. Setelah semua baris dicetak, program menambahkan baris terakhir yang hanya berisi spasi dan satu simbol * di tengah.

### Full Code Screenshot:



## Kesimpulan
Dari praktikum ini, yang saya dapatkan adalah pemahaman konsep dasar pemrograman seperti variabel, tipe data, input-output, operator aritmatika dan perbandingan, percabangan, perulangan, serta array sangat penting untuk membangun program yang efektif. Praktikum ini membantu memperkuat pemahaman teori melalui penerapan langsung, sehingga kita dapat melihat bagaimana setiap konsep bekerj. misalnya bagaimana percabangan mempengaruhi alur program, atau bagaimana loop mempermudah pengolahan data berulang.

