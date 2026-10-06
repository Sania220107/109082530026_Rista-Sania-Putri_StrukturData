#include <iostream>
using namespace std;

int main() {
    int angka = 100;

    int *pointer;

    pointer = &angka;

    cout << "Nilai angka        : " << angka << endl; // 100
    cout << "Alamat angka       : " << &angka << endl; //address
    cout << "Isi pointer        : " << pointer << endl; // address angka
    cout << "Nilai dari pointer : " << *pointer << endl; // value angka (100)

    return 0;
}