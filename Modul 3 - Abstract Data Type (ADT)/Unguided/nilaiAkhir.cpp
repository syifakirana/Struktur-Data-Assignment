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
