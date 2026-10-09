#include <iostream>
#include "arr_ptr.h"

using namespace std;

int main() {
    int A[3][3] = {{1, 2, 3},
                   {4, 5, 6},
                   {7, 8, 9}};
    int B[3][3] = {{9, 8, 7},
                   {6, 5, 4},
                   {3, 2, 1}};

    int x = 10, y = 20;
    int *p1 = &x;
    int *p2 = &y;

    cout << "=== Sebelum tukar array ===" << endl;
    cout << "Array A:" << endl;
    tampilArray(A);
    cout << "Array B:" << endl;
    tampilArray(B);

    int baris, kolom;
    cout << "\nMasukkan posisi yang ditukar (baris kolom, 0-2) = ";
    cin >> baris >> kolom;

    if (baris < 0 || baris > 2 || kolom < 0 || kolom > 2) {
        cout << "Posisi tidak valid!" << endl;
        return 1;
    }

    tukarArray(A, B, baris, kolom);

    cout << "\n=== Sesudah tukar array pada posisi [" << baris << "][" << kolom << "] ===" << endl;
    cout << "Array A:" << endl;
    tampilArray(A);
    cout << "Array B:" << endl;
    tampilArray(B);

    cout << "\n=== Tukar pointer ===" << endl;
    cout << "Sebelum : x = " << *p1 << ", y = " << *p2 << endl;
    tukarPointer(p1, p2);
    cout << "Sesudah : x = " << *p1 << ", y = " << *p2 << endl;

    return 0;
}