#include <iostream>
using namespace std;

const int N = 3;

void inputMatriks(int m[N][N], char nama) {
    cout << "Masukkan elemen matriks " << nama << " (3x3):" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << nama << "[" << i << "][" << j << "] = ";
            cin >> m[i][j];
        }
    }
}

void tampilMatriks(int m[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
}

void tambah(int a[N][N], int b[N][N], int hasil[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            hasil[i][j] = a[i][j] + b[i][j];
}

void kurang(int a[N][N], int b[N][N], int hasil[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            hasil[i][j] = a[i][j] - b[i][j];
}

void kali(int a[N][N], int b[N][N], int hasil[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            hasil[i][j] = 0;
            for (int k = 0; k < N; k++) {
                hasil[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int A[N][N], B[N][N], hasil[N][N];
    int pilihan;

    inputMatriks(A, 'A');
    inputMatriks(B, 'B');

    do {
        cout << "\n--- Menu Operasi Matriks 3x3 ---" << endl;
        cout << "1. Penjumlahan (A + B)" << endl;
        cout << "2. Pengurangan (A - B)" << endl;
        cout << "3. Perkalian   (A x B)" << endl;
        cout << "4. Tampilkan matriks A dan B" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            tambah(A, B, hasil);
            cout << "\nHasil A + B:" << endl;
            tampilMatriks(hasil);
        } else if (pilihan == 2) {
            kurang(A, B, hasil);
            cout << "\nHasil A - B:" << endl;
            tampilMatriks(hasil);
        } else if (pilihan == 3) {
            kali(A, B, hasil);
            cout << "\nHasil A x B:" << endl;
            tampilMatriks(hasil);
        } else if (pilihan == 4) {
            cout << "\nMatriks A:" << endl;
            tampilMatriks(A);
            cout << "\nMatriks B:" << endl;
            tampilMatriks(B);
        } else if (pilihan == 0) {
            cout << "Program selesai." << endl;
        } else {
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}