#include <iostream>
#include "data_mhs.h"

using namespace std;

int main() {
    mahasiswa dataMhs[10];
    int n;

    do {
        cout << "Jumlah mahasiswa (max 10) = ";
        cin >> n;
    } while (n < 1 || n > 10);

    for (int i = 0; i < n; i++) {
        cout << "\n=== Data mahasiswa ke-" << i + 1 << " ===" << endl;
        inputMhs(dataMhs[i]);
    }

    cout << "\n===== DATA MAHASISWA =====" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\n--- Mahasiswa ke-" << i + 1 << " ---" << endl;
        tampilMhs(dataMhs[i]);
    }

    return 0;
}