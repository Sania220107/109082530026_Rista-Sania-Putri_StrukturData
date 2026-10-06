#include <iostream>
 using namespace std;

 void tukar(int x, int y) {
     int temp;
     temp = x;
     x = y;
     y = temp;
 }
 int main() {
     int a = 4;
     int b = 6;

     cout << "Sebelum ditukar: " << endl;
     cout << "a = " << a << endl;
     cout << "b = " << b << endl;

     // Memanggil fungsi dengan mengirimkan nilainya saja
     tukar(a, b);

     // Hasil print di bawah ini angkanya akan tetap a = 4 dan b = 6
     cout << "\nSetelah ditukar: " << endl;
     cout << "a = " << a << endl;
     cout << "b = " << b << endl;
    
     return 0;
}