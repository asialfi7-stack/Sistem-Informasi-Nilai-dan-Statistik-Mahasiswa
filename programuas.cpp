#include <iostream>
#include <string>
using namespace std;

const int MAKS = 100; // Maksimal data mahasiswa

struct Mahasiswa {
    string nama;
    string nim;
    float tugas, uts, uas, akhir;
};

void inputData(Mahasiswa mhs[], int &n) {
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "\nData Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama: ";
        cin.ignore();
        getline(cin, mhs[i].nama);
        cout << "NIM: ";
        cin >> mhs[i].nim;
        cout << "Nilai Tugas: ";
        cin >> mhs[i].tugas;
        cout << "Nilai UTS: ";
        cin >> mhs[i].uts;
        cout << "Nilai UAS: ";
        cin >> mhs[i].uas;

        // Hitung nilai akhir (bobot: tugas 30%, UTS 30%, UAS 40%)
        mhs[i].akhir = (mhs[i].tugas * 0.3) + (mhs[i].uts * 0.3) + (mhs[i].uas * 0.4);
    }
}
void tampilData(Mahasiswa mhs[], int n) {
    cout << "\n=== Daftar Nilai Mahasiswa ===\n";
    for (int i = 0; i < n; i++) {
        cout << "\nNama: " << mhs[i].nama
             << "\nNIM: " << mhs[i].nim
             << "\nNilai Akhir: " << mhs[i].akhir;
        if (mhs[i].akhir >= 60)
            cout << " (LULUS)\n";
        else
            cout << " (TIDAK LULUS)\n";
    }
}

void tampilStatistik(Mahasiswa mhs[], int n) {
    float total = 0, tertinggi = mhs[0].akhir, terendah = mhs[0].akhir;
    for (int i = 0; i < n; i++) {
        total += mhs[i].akhir;
        if (mhs[i].akhir > tertinggi) tertinggi = mhs[i].akhir;
        if (mhs[i].akhir < terendah) terendah = mhs[i].akhir;
    }
    cout << "\n=== Statistik Nilai ===";
    cout << "\nRata-rata: " << total / n;
    cout << "\nNilai Tertinggi: " << tertinggi;
    cout << "\nNilai Terendah: " << terendah << endl;
}
void cariMahasiswa(Mahasiswa mhs[], int n) {
    string cari;
    cout << "\nMasukkan NIM yang ingin dicari: ";
    cin >> cari;
    bool ketemu = false;
    for (int i = 0; i < n; i++) {
        if (mhs[i].nim == cari) {
            cout << "\nData ditemukan!\n";
            cout << "Nama: " << mhs[i].nama << endl;
            cout << "Nilai Akhir: " << mhs[i].akhir << endl;
            ketemu = true;
            break;
        }
    }
    if (!ketemu) cout << "Data dengan NIM tersebut tidak ditemukan.\n";
}

int main() {
    Mahasiswa mhs[MAKS];
    int n, pilihan;
    do {
        cout << "\n===== SISTEM INFORMASI NILAI MAHASISWA =====";
        cout << "\n1. Input Data Mahasiswa";
        cout << "\n2. Tampilkan Semua Data";
        cout << "\n3. Tampilkan Statistik Nilai";
        cout << "\n4. Cari Mahasiswa (berdasarkan NIM)";
        cout << "\n5. Keluar";
        cout << "\nPilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1: inputData(mhs, n); break;
        case 2: tampilData(mhs, n); break;
        case 3: tampilStatistik(mhs, n); break;
        case 4: cariMahasiswa(mhs, n); break;
        case 5: cout << "Keluar dari program.\n"; break;
        default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);

    return 0;
}
