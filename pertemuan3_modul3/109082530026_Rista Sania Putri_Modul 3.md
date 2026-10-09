# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT)</h1>
<p align="center">Rista Sania Putri - 109082530026</p>

## Dasar Teori

Abstract Data Type (ADT) adalah sebuah TYPE beserta sekumpulan PRIMITIF (operasi dasar) yang berlaku terhadap TYPE tersebut. Pada ADT yang lengkap, turut disertakan definisi invarian dari TYPE dan aksioma yang berlaku, dan ADT merupakan definisi yang bersifat statis [1]. Dalam bahasa C++, TYPE diterjemahkan menjadi `struct`, sedangkan PRIMITIF diterjemahkan menjadi fungsi atau prosedur.

### A. Abstract Data Type (ADT)<br/>
ADT memisahkan definisi tipe data dari realisasi operasinya, sehingga program menjadi lebih terstruktur, mudah dipahami, dan mudah dikelola [1].

#### 1. Primitif pada ADT
Primitif dikelompokkan menjadi beberapa jenis, yaitu konstruktor/kreator (pembentuk nilai type, biasanya diawali `Make` atau `create`), selector (mengakses komponen, biasanya diawali `Get`), prosedur pengubah nilai komponen, validator komponen, destruktor/dealokator, baca/tulis (interface input/output), operator relasional, aritmatika, dan konversi tipe [1].

#### 2. Pemisahan File pada ADT
ADT diimplementasikan menjadi dua modul utama dan satu modul driver [1]:
- **File header (`.h`)** berisi spesifikasi type dan deklarasi primitif (header fungsi/prosedur).
- **File body (`.cpp`)** berisi realisasi dari primitif yang dideklarasikan di file header.
- **File driver (`main.cpp`)** berisi program utama yang memanggil primitif dari ADT.

#### 3. Include Guard
Agar file header tidak ter-include berulang kali, digunakan include guard berupa `#ifndef`, `#define`, dan `#endif`.

### B. Array 2D dan Pointer<br/>
Soal ketiga menggunakan array dua dimensi dan pointer.

#### 1. Array 2D
Array 2D adalah array yang elemennya diakses dengan dua indeks, yaitu baris dan kolom, misalnya `int A[3][3]`. Array yang dikirim ke fungsi selalu diteruskan sebagai alamatnya, sehingga perubahan isi array di dalam fungsi ikut mengubah array aslinya.

#### 2. Pointer
Pointer adalah variabel yang menyimpan alamat memori dari variabel lain. Operator `&` digunakan untuk mengambil alamat suatu variabel, dan operator `*` digunakan untuk mengakses nilai yang ditunjuk oleh pointer.

#### 3. Menukar Nilai Lewat Pointer
Dengan mengirim pointer ke sebuah fungsi, fungsi dapat menukar nilai dari dua variabel yang ditunjuk oleh pointer tersebut dengan bantuan variabel sementara (`temp`).

## Guided

Pada guided dibuat ADT `mahasiswa` yang terdiri dari tiga file, yaitu `mahasiswa.h`, `mahasiswa.cpp`, dan `main.cpp`.

### 1. mahasiswa.h

```C++
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs (mahasiswa &m);
float rata2 (mahasiswa m);
#endif // MAHASISWA_H_INCLUDED
```
File `mahasiswa.h` berisi definisi type `mahasiswa` (nim, nilai1, dan nilai2) serta header fungsi `inputMhs` dan `rata2`. Include guard digunakan agar header tidak ter-include ganda.

### 2. mahasiswa.cpp

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "input nim = ";
    cin >> (m).nim;
    cout << "input nilai 1 = ";
    cin >> (m).nilai1;
    cout << "input nilai 2 = ";
    cin >> (m).nilai2;
};

float rata2(mahasiswa m) {
    return float(m.nilai1 + m.nilai2)/2;
}
```
File `mahasiswa.cpp` berisi realisasi dari primitif. Prosedur `inputMhs` menerima parameter secara referensi (`&m`) agar data yang diinput tersimpan ke variabel asal, sedangkan fungsi `rata2` menghitung rata-rata dari dua nilai.

### 3. main.cpp

```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main() {
    mahasiswa mhs;
    inputMhs (mhs);
    cout << "rata-rata = " << rata2 (mhs);
    return 0;
}
```
File `main.cpp` adalah driver yang membuat variabel bertipe `mahasiswa`, memanggil `inputMhs` untuk mengisi data, lalu menampilkan hasil `rata2`.

## Unguided

### 1. Program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.

**data_mhs.h**
```C++
#ifndef DATA_MHS_H_INCLUDED
#define DATA_MHS_H_INCLUDED

struct mahasiswa {
    char nama[50];
    char nim[13];
    float uts, uas, tugas;
    float nilaiAkhir;
};

void inputMhs(mahasiswa &m);
float hitungNilaiAkhir(mahasiswa m);
void tampilMhs(mahasiswa m);

#endif // DATA_MHS_H_INCLUDED
```

**data_mhs.cpp**
```C++
#include <iostream>
#include "data_mhs.h"

using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "Nama   = ";
    cin >> m.nama;
    cout << "NIM    = ";
    cin >> m.nim;
    cout << "uts    = ";
    cin >> m.uts;
    cout << "uas    = ";
    cin >> m.uas;
    cout << "tugas  = ";
    cin >> m.tugas;
    m.nilaiAkhir = hitungNilaiAkhir(m);
}

float hitungNilaiAkhir(mahasiswa m) {
    return 0.3 * m.uts + 0.4 * m.uas + 0.3 * m.tugas;
}

void tampilMhs(mahasiswa m) {
    cout << "Nama        : " << m.nama << endl;
    cout << "NIM         : " << m.nim << endl;
    cout << "UTS         : " << m.uts << endl;
    cout << "UAS         : " << m.uas << endl;
    cout << "Tugas       : " << m.tugas << endl;
    cout << "Nilai Akhir : " << m.nilaiAkhir << endl;
}
```

**main.cpp**
```C++
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
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Sania220107/109082530026_Rista-Sania-Putri_StrukturData/blob/main/pertemuan3_modul3/output_1.1.jpeg?raw=true)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/Sania220107/109082530026_Rista-Sania-Putri_StrukturData/blob/main/pertemuan3_modul3/output_1.2.jpeg?raw=true)


Pada program ini dibuat ADT `mahasiswa` dengan field nama, nim, uts, uas, tugas, dan nilaiAkhir. Data disimpan dalam array `dataMhs` berukuran maksimal 10. Jumlah data diinput oleh pengguna dan dibatasi 1 sampai 10 dengan `do-while`. Nilai akhir dihitung oleh fungsi `hitungNilaiAkhir` dengan rumus `0.3*uts + 0.4*uas + 0.3*tugas`, lalu disimpan ke field `nilaiAkhir` saat proses input.

### 2. ADT pelajaran (pelajaran.h, pelajaran.cpp, main.cpp)

**pelajaran.h**
```C++
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

#include <string>

using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif // PELAJARAN_H_INCLUDED
```

**pelajaran.cpp**
```C++
#include <iostream>
#include "pelajaran.h"

using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```

**main.cpp**
```C++
#include <iostream>
#include "pelajaran.h"

using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2](https://github.com/Sania220107/109082530026_Rista-Sania-Putri_StrukturData/blob/main/pertemuan3_modul3/output_2.jpeg?raw=true)


Pada program ini dibuat ADT `pelajaran` dengan field `namaMapel` dan `kodeMapel`. Fungsi `create_pelajaran` berperan sebagai konstruktor yang membentuk nilai bertipe `pelajaran` dari nama dan kode yang diberikan, sedangkan prosedur `tampil_pelajaran` menampilkan isinya. Hasil output sesuai dengan contoh pada modul.

### 3. Program dengan 2 array 2D integer 3x3 dan 2 pointer integer, beserta fungsi menampilkan array, menukar isi array pada posisi tertentu, dan menukar isi variabel yang ditunjuk 2 pointer

**arr_ptr.h**
```C++
#ifndef ARRAY_PTR_H_INCLUDED
#define ARRAY_PTR_H_INCLUDED

void tampilArray(int arr[3][3]);

void tukarArray(int A[3][3], int B[3][3], int baris, int kolom);

void tukarPointer(int *p1, int *p2);

#endif // ARRAY_PTR_H_INCLUDED
```

**arr_ptr.cpp**
```C++
#include <iostream>
#include "arr_ptr.h"

using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarArray(int A[3][3], int B[3][3], int baris, int kolom) {
    int temp = A[baris][kolom];
    A[baris][kolom] = B[baris][kolom];
    B[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
```

**main.cpp**
```C++
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
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Sania220107/109082530026_Rista-Sania-Putri_StrukturData/blob/main/pertemuan3_modul3/output_3.1.jpeg?raw=true)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/Sania220107/109082530026_Rista-Sania-Putri_StrukturData/blob/main/pertemuan3_modul3/output_3.2.jpeg?raw=true)



Program ini memiliki dua array 2D integer 3x3 (`A` dan `B`) dan dua pointer integer (`p1` dan `p2`) yang menunjuk ke variabel `x` dan `y`. Fungsi `tampilArray` menampilkan isi array, fungsi `tukarArray` menukar elemen `A` dan `B` pada posisi baris dan kolom yang diinput pengguna, dan fungsi `tukarPointer` menukar nilai variabel yang ditunjuk oleh dua pointer melalui dereferensi (`*p1` dan `*p2`). Seluruh fungsi dipisah dalam ADT `arr_ptr` (file `.h` dan `.cpp`) agar sesuai dengan konsep ADT.

## Kesimpulan
Dari praktikum ini dapat disimpulkan bahwa Abstract Data Type (ADT) memisahkan program menjadi file header (`.h`) yang berisi definisi type dan deklarasi primitif, file body (`.cpp`) yang berisi realisasi fungsi dan prosedur, serta file driver (`main.cpp`) yang menjalankan program. Pemisahan ini membuat kode lebih rapi, mudah dipahami, dan dapat digunakan kembali. Penerapan ADT pada data mahasiswa, pelajaran, serta array 2D dan pointer menunjukkan bahwa konsep yang sama dapat dipakai untuk berbagai jenis permasalahan.

## Referensi
[1] Modul Praktikum Struktur Data, Modul 3 Abstract Data Type (ADT). Fakultas Informatika, Telkom University.