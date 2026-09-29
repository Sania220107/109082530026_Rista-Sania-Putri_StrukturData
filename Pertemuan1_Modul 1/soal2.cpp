#include <iostream>
#include <string>
using namespace std;

int main() {
    int angka;

    cout << "Masukkan bilangan rentang 0 sampai 100: ";
    
    cin >> angka;

    string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas"};

    cout << "Output: " << endl;
    if(angka < 0 || angka > 100) {
        cout << "Angka yang anda masukkan diluar rentang yang sudah ditentukan";
    } else if (angka == 0) {
        cout << "Nol" << endl;
    } else if (angka <= 11) {
        cout << satuan[angka] << endl;
    } else if (angka < 20) {
        cout << satuan[angka % 10] << " belas" << endl;
    } else if (angka < 100) {
        cout << satuan[angka / 10] << " puluh";
        if (angka % 10 != 0) {
        cout << " " << satuan[angka % 10] << endl;
        }
    } else if(angka == 100) {
        cout << "Seratus" << endl;
    }
    
    return 0;
}