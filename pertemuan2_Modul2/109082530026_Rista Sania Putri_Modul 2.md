# <h1 align="center">Laporan Praktikum Modul 2 - Codeblocks IDE & Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Rista Sania Putri - 109082530026</p>

## Dasar Teori

### A. Array<br/>
Array merupakan kumpulan data dengan nama yang sama dan setiap elemennya bertipe data sama. Elemen-elemen array diakses berdasarkan indeksnya, dan di C++ indeks dimulai dari 0 sehingga array dengan 5 elemen memiliki indeks 0 sampai 4 [1]. Data array disimpan pada lokasi memori yang berurutan [1].

#### 1. Array Satu Dimensi
Array satu dimensi hanya terdiri dari satu larik data. Bentuk deklarasinya adalah `tipe_data nama_var[ukuran]`, misalnya `int nilai[10];` yang berarti array `nilai` memiliki 10 elemen bertipe integer [1].

#### 2. Array Dua Dimensi
Array dua dimensi menyerupai tabel yang terdiri dari baris dan kolom. Cara akses, deklarasi, dan inisialisasinya sama dengan array satu dimensi, hanya saja menggunakan dua indeks, misalnya `int data_nilai[4][3];` [1].

#### 3. Array Berdimensi Banyak
Array berdimensi banyak adalah array dengan lebih dari dua indeks, dengan bentuk deklarasi `tipe_data nama_var[ukuran1][ukuran2]...[ukuran-N];` [1]. Contohnya `int data_rumit[4][6][6];`.

### B. Pointer dan Alamat Memori<br/>
Semua data yang digunakan program disimpan di dalam memori (RAM). Memori dapat digambarkan sebagai array satu dimensi berukuran sangat besar, di mana setiap cell memiliki alamat (*address*) yang unik [1].

#### 1. Alamat Memori (Address)
Untuk mengetahui alamat memori tempat sebuah variabel disimpan, digunakan operator `&` yang diletakkan di depan nama variabel [1].

#### 2. Pointer
Pointer adalah variabel yang menyimpan alamat memori variabel lain, sehingga nilai variabel yang ditunjuk dapat diakses melalui pointer tersebut. Deklarasinya `type *nama_variabel;`, sedangkan untuk mengambil nilai yang ditunjuk digunakan tanda `*` di depan nama pointer [1]. Pointer juga merupakan variabel sehingga memiliki alamat memorinya sendiri [1].

#### 3. Pointer dan Array
Array dan pointer memiliki hubungan yang kuat. Jika `pa = &a[0];` maka `pa + i` adalah alamat dari `a[i]` dan `*(pa + i)` berisi nilai dari `a[i]` [1].

### C. Fungsi dan Prosedur<br/>
Fungsi adalah blok kode yang dirancang untuk melakukan tugas tertentu agar program lebih terstruktur dan mengurangi duplikasi kode [1]. Fungsi mengembalikan sebuah nilai balik, dengan bentuk umum `tipe_keluaran nama_fungsi(daftar_parameter) { ... }` [1].

Prosedur adalah fungsi yang tidak mengembalikan nilai. Di C++ prosedur dikenal sebagai fungsi `void` [1].

### D. Parameter Fungsi<br/>
Parameter formal adalah variabel yang ada pada daftar parameter saat fungsi didefinisikan, sedangkan parameter aktual adalah nilai atau variabel yang dipakai saat fungsi dipanggil [1]. Terdapat tiga cara melewatkan parameter [1]:

#### 1. Call by Value
Nilai parameter aktual disalin ke parameter formal, sehingga perubahan di dalam fungsi tidak memengaruhi variabel aslinya.

#### 2. Call by Pointer
Yang dilewatkan adalah alamat variabel (`&a`), sehingga fungsi dapat mengubah nilai variabel aslinya melalui pointer (`*x`).

#### 3. Call by Reference
Parameter dideklarasikan dengan `&` (misalnya `int &x`) sehingga variabel asli dapat diubah tanpa perlu menuliskan `&` atau `*` saat pemanggilan.

## Guided 

### 1. Array Satu Dimensi

```C++
#include <iostream>
using namespace std;

int main() {
    int nilai[5];

    nilai[0] = 80;
    nilai[1] = 75;
    nilai[2] = 90;
    nilai[3] = 85;
    nilai[4] = 95;

    for (int i = 0; i < 5; i++) {
        cout << "Nilai ke-" << i + 1 << " = " << nilai[i] << endl;
    }

    return 0;
}
```
Program mendeklarasikan array `nilai` berisi 5 elemen integer, mengisinya satu per satu berdasarkan indeks (0 sampai 4), lalu menampilkannya dengan perulangan `for`. Output berupa "Nilai ke-1 = 80" sampai "Nilai ke-5 = 95".

### 2. Array Dua Dimensi

```C++
#include <iostream>
using namespace std;

int main() {
    int nilai[3][3] = {
        {80, 75, 90},
        {85, 90, 88},
        {70, 80, 85},
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << nilai[i][j] << " ";
        }

        cout << endl;
     }
     cout << endl;
     cout << nilai[1][2] << endl; //88
     return 0;
}
```
Program membuat array 3x3 yang langsung diinisialisasi. Perulangan bersarang digunakan untuk menampilkan isi array per baris dan kolom. Baris terakhir menampilkan elemen pada baris indeks 1 dan kolom indeks 2, yaitu `88`.

### 3. Array Tiga Dimensi

```C++
#include <iostream>
using namespace std;

int main() {
    int data[2][2][3] = {
        {
            {10, 20, 30},
            {40, 50, 60},
        },
        {
            {70, 80, 90},
            {100, 110, 120},
        }
    };

    cout << data[0][1][2] << endl;
    return 0;
}
```
Array `data` terdiri dari 2 blok, masing-masing berisi 2 baris dan 3 kolom. Elemen `data[0][1][2]` berarti blok ke-0, baris ke-1, kolom ke-2, sehingga outputnya adalah `60`.

### 4. Address (Alamat Memori)

```C++
#include <iostream>
using namespace std;

int main() {
    int angka = 100;

    cout << "Nilai angka : " << angka << endl;
    cout << "Alamat angka : " << &angka << endl;

    return 0;
}
```
Program menampilkan nilai variabel `angka` (100) dan alamat memorinya menggunakan operator `&`. Alamat yang tampil berformat heksadesimal dan nilainya dapat berbeda pada setiap komputer atau setiap kali program dijalankan.

### 5. Pointer Array

```C++
#include <iostream>
using namespace std;

int main() {
    char arr[6];

    arr[0] = 'a';
    arr[1] = 'b';
    arr[2] = 'c';
    arr[3] = 'b';
    arr[4] = 'd';
    arr[5] = 'e';

    cout << arr[3] << endl; //value
    cout << &(arr[4]) << endl; //alamat memory atau address

    return 0;
}
```
Program mengisi array karakter `arr` dengan 6 elemen. `arr[3]` menampilkan nilai elemen, yaitu `b`. Sementara `&(arr[4])` dimaksudkan untuk menampilkan alamat elemen ke-4. Perlu diperhatikan bahwa pada tipe `char`, `cout` memperlakukan `char*` sebagai string, sehingga yang tercetak adalah karakter mulai dari `arr[4]` ("de") dan bukan alamat memorinya. Untuk menampilkan alamat sebenarnya dapat digunakan `cout << (void*)&arr[4];`.

### 6. Pointer

```C++
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
```
Variabel `pointer` diisi dengan alamat `angka` melalui `pointer = &angka;`. Hasilnya, isi `pointer` sama dengan alamat `angka`, dan `*pointer` menghasilkan nilai yang ditunjuk, yaitu `100`.

### 7. Function

```C++
#include <iostream>
using namespace std;

int maks3(int a, int b, int c) {
    int temp_max = a;

    
    if (b > temp_max) 
        temp_max = b;

    if (c > temp_max) 
        temp_max = c;

    return temp_max;
}

int main() {
    int x, y, z;

    cout << "Masukkan nilai 1: ";
    cin >> x;

    cout << "Masukkan nilai 2: ";
    cin >> y;

    cout << "Masukkan nilai 3: ";
    cin >> z;

    cout << "Nilai maksimum = " << maks3(x, y, z);

    return 0;
}
```
Fungsi `maks3` menerima tiga bilangan integer, membandingkannya dengan variabel lokal `temp_max`, lalu mengembalikan (`return`) nilai terbesar. Fungsi ini dipanggil di `main` dengan tiga nilai masukan pengguna.

### 8. Procedure

```C++
#include <iostream>
using namespace std;

void sapa() {
    cout << "Selamat datang di Praktikum Struktur data" << endl;
}

int main() {
    sapa();
    return 0;
}
```
`sapa()` adalah prosedur (fungsi `void`) yang hanya menampilkan teks dan tidak mengembalikan nilai. Prosedur dipanggil dari `main` sehingga tampil "Selamat datang di Praktikum Struktur data".

### 9. Call by Value, Call by Pointer, dan Call by Reference

#### a. Call by Value

```C++
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
```
Fungsi `tukar` hanya menerima salinan nilai `a` dan `b`. Penukaran terjadi pada salinan di dalam fungsi, sehingga nilai `a` dan `b` di `main` tidak berubah (tetap `a = 4` dan `b = 6`).

#### b. Call by Pointer

```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;

    temp = *x;
    *x = *y;
    *y =  temp;
}

int main() {
    int a = 4;
    int b = 6;

    cout << "Sebelum ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    tukar(&a, &b);

    cout << "\nSetelah ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}
```
Fungsi menerima alamat `a` dan `b` (`&a`, `&b`) dan mengubah nilainya lewat pointer `*x` dan `*y`. Karena yang diubah adalah variabel aslinya, hasilnya `a = 6` dan `b = 4`.

#### c. Call by Reference

```C++
#include <iostream>
 using namespace std;

 void tukar(int &x, int &y) {
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

     tukar(a, b);

     cout << "\nSetelah ditukar: " << endl;
     cout << "a = " << a << endl;
     cout << "b = " << b << endl;
    
     return 0;
 }
```
Parameter `int &x` dan `int &y` menjadi referensi (nama lain) dari `a` dan `b`. Pemanggilan cukup `tukar(a, b)` tanpa `&`, dan hasilnya sama seperti call by pointer, yaitu `a = 6` dan `b = 4`.

## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3

```C++
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
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/Pertemuan2_Modul2/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/Pertemuan2_Modul2/Output-Unguided1-2.png)

Program meminta pengguna mengisi dua matriks 3x3 (A dan B) menggunakan array dua dimensi, lalu menyediakan menu operasi. Setiap operasi dipisahkan ke dalam prosedur/fungsi tersendiri: `inputMatriks` untuk input, `tampilMatriks` untuk menampilkan, `tambah` dan `kurang` untuk operasi elemen per elemen (`a[i][j] ± b[i][j]`), serta `kali` untuk perkalian matriks dengan tiga perulangan bersarang (`hasil[i][j] += a[i][k] * b[k][j]`). Menu diulang dengan `do-while` hingga pengguna memilih 0 untuk keluar.

### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel

```C++
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
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1]()

penjelasan unguided 2

Program memiliki dua fungsi `tukar` dengan nama sama tetapi tipe parameter berbeda (*function overloading*): satu menerima pointer (`int *`) dan satu menerima referensi (`int &`). Keduanya menggeser nilai: `a` menerima nilai `b`, `b` menerima nilai `c`, dan `c` menerima nilai `a` semula. Dengan nilai awal `a = 4`, `b = 6`, `c = 8`, hasil setelah penukaran adalah `a = 6`, `b = 8`, `c = 4` untuk kedua metode. Sebelum menguji call by reference, nilai variabel dikembalikan ke kondisi awal agar hasil kedua metode dapat dibandingkan.

### 3. Diketahui sebuah array 1 dimensi sebagai berikut: arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55}. Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata-rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata-rata! Buat program menggunakan menu switch-case seperti berikut ini: Tampilkan isi array, Cari nilai maksimum, Cari nilai minimum, Hitung nilai rata-rata.

```C++
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

        switch (pilihan) {
            case 1:
                tampilArray(arrA, UKURAN);
                break;
            case 2:
                cout << "Nilai maksimum = " << cariMaksimum(arrA, UKURAN) << endl;
                break;
            case 3:
                cout << "Nilai minimum = " << cariMinimum(arrA, UKURAN) << endl;
                break;
            case 4:
                hitungRataRata(arrA, UKURAN);
                break;
            case 0:
                cout << "Program selesai." << endl;
                break;
            default:
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
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/Pertemuan2_Modul2/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/Pertemuan2_Modul2/Output-Unguided3-2.png)

penjelasan unguided 3

Program menyimpan array `arrA` berisi 10 elemen dan menyediakan menu berbasis `switch-case` untuk memanggil empat fungsi/prosedur. Pilihan 0 ditambahkan sebagai opsi keluar agar perulangan `do-while` dapat berhenti. `cariMaksimum` dan `cariMinimum` memulai dengan elemen pertama sebagai pembanding, lalu menelusuri sisa elemen. `hitungRataRata` menjumlahkan seluruh elemen lalu membaginya dengan jumlah elemen (dengan *casting* ke `float` agar hasilnya desimal), dan `tampilArray` mencetak seluruh isi array. Hasilnya: isi array `11 8 5 7 12 26 3 54 33 55`, nilai maksimum `55`, nilai minimum `3`, dan rata-rata `21.4` (total 214 dibagi 10).

## Kesimpulan
Pada praktikum modul 2 ini dipelajari penggunaan array satu dimensi, dua dimensi, dan berdimensi banyak untuk menyimpan sekumpulan data bertipe sama yang diakses melalui indeks. Praktikum juga memperkenalkan konsep alamat memori dan pointer, di mana operator `&` digunakan untuk mengambil alamat variabel dan operator `*` untuk mengakses nilai yang ditunjuk pointer. Selain itu, fungsi dan prosedur membuat program lebih terstruktur dan mengurangi pengulangan kode. Tiga cara melewatkan parameter memiliki perbedaan yang jelas: call by value hanya menyalin nilai sehingga variabel asli tidak berubah, sedangkan call by pointer dan call by reference dapat mengubah variabel asli di luar fungsi, dengan call by reference memiliki penulisan yang lebih sederhana.

## Referensi
[1] Informatics Lab, Fakultas Informatika, Telkom University. (2026). "Modul 2: Pengenalan Bahasa C++ (Bagian Kedua)", Praktikum Struktur Data.