#include <iostream>
using namespace std;

int main() {
    float angka1, angka2;

    cout << "Masukkan 2 bilangan pecahan" << endl;
    cout << "Masukkan bilangan pertama: ";
    cin >> angka1;
    cout << "Masukkan bilangan kedua: ";
    cin >> angka2;

    cout << "\n === HASIL OPERASI ===" << endl;
    cout << "Hasil Penjumlahan: " << angka1 + angka2 << endl;
    cout << "Hasil Pengurangan: " << angka1 - angka2 << endl;
    cout << "Hasil Perkalian: " << angka1 * angka2 << endl;
    cout << "Hasil Pembagian: " << angka1 / angka2 << endl;

    return 0;
}