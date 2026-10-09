#include <iostream>
#include "data_mhs.h"

using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "Nama   = ";
    cin >> m.nama;
    cout << "NIM    = ";
    cin >> m.nim;
    cout << "uts    = ";
    cin >> m.uts;
    cout << "uas    = ";
    cin >> m.uas;
    cout << "tugas  = ";
    cin >> m.tugas;
    m.nilaiAkhir = hitungNilaiAkhir(m);
}

float hitungNilaiAkhir(mahasiswa m) {
    return 0.3 * m.uts + 0.4 * m.uas + 0.3 * m.tugas;
}

void tampilMhs(mahasiswa m) {
    cout << "Nama        : " << m.nama << endl;
    cout << "NIM         : " << m.nim << endl;
    cout << "UTS         : " << m.uts << endl;
    cout << "UAS         : " << m.uas << endl;
    cout << "Tugas       : " << m.tugas << endl;
    cout << "Nilai Akhir : " << m.nilaiAkhir << endl;
}