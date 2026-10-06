#include <iostream>
using namespace std;

const int UKURAN = 10;

int cariMinimum(int arr[], int n);
int cariMaksimum(int arr[], int n);
void hitungRataRata(int arr[], int n);
void tampilArray(int arr[], int n);

int main() {
    int arrA[UKURAN] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int pilihan;

    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata-rata" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            tampilArray(arrA, UKURAN);
        } else if (pilihan == 2) {
            cout << "Nilai maksimum = " << cariMaksimum(arrA, UKURAN) << endl;
        } else if (pilihan == 3) {
            cout << "Nilai minimum = " << cariMinimum(arrA, UKURAN) << endl;
        } else if (pilihan == 4) {
            hitungRataRata(arrA, UKURAN);
        } else if (pilihan == 0) {
            cout << "Program selesai." << endl;
        } else {
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}

int cariMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int cariMaksimum(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void hitungRataRata(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    float rata = (float)total / n;
    cout << "Nilai rata-rata = " << rata << endl;
}

void tampilArray(int arr[], int n) {
    cout << "Isi array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}