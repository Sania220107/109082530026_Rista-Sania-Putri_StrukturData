#include <iostream>
using namespace std;

void tukar(int *x, int *y, int *z) {
    int temp;

    temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

void tukar(int &x, int &y, int &z) {
    int temp;

    temp = x;
    x = y;
    y = z;
    z = temp;
}

int main() {
    int a = 4;
    int b = 6;
    int c = 8;

    //BY POINTER 
    cout << "=== BY POINTER ===" << endl;
    cout << "Sebelum ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    tukar(&a, &b, &c);

    cout << "\nSetelah ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    a = 4;
    b = 6;
    c = 8;

    // BY REFERENCE 
    cout << "\n=== BY REFERENCE ===" << endl;
    cout << "Sebelum ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    tukar(a, b, c);

    cout << "\nSetelah ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    return 0;
}