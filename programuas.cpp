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
