# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahasa C++ (Bagian Pertama)</h1>
<p align="center">Rista Sania Putri - 109082530026</p>

## Dasar Teori

Bahasa C++ merupakan bahasa pemrograman yang dikembangkan oleh Bjarne Stroustrup sebagai ekstensi dari bahasa C sehingga pada awalnya sering disebut "C with Classes". Perbedaan utamanya dengan bahasa C adalah dukungan terhadap pemrograman berorientasi objek (*Object-Oriented Programming*/OOP) [1]. C++ termasuk bahasa tingkat tinggi, yaitu bahasa yang mudah dipahami manusia [1]. Karena komputer hanya memahami bahasa mesin, kode program perlu diterjemahkan oleh *compiler* sebelum dapat dijalankan [2]. Materi dasar yang umum dipelajari dalam C++ mencakup struktur program, variabel dan konstanta, input dan output, operasi aritmatika, percabangan, dan perulangan [3]. Untuk menulis dan menjalankan program, digunakan *Integrated Development Environment* (IDE) seperti Code::Blocks yang menyatukan text editor, compiler, dan debugger dalam satu aplikasi.

### A. Komponen Utama Struktur Kode C++
Struktur program merupakan salah satu materi dasar yang harus dipahami dalam belajar C++ [3]. Program C++ sederhana tersusun atas tiga komponen berikut.
#### 1. Preprocessor Directive
Baris yang diawali tanda `#`, seperti `#include <iostream>`, digunakan untuk menyertakan pustaka standar ke dalam program sebelum proses kompilasi dilakukan.
#### 2. Namespace
Deklarasi `using namespace std;` memungkinkan elemen pustaka standar seperti `cin` dan `cout` dipanggil langsung tanpa awalan `std::`.
#### 3. Fungsi Utama (Main Function)
Fungsi `int main()` adalah titik awal program (*entry point*). Semua instruksi di dalam tanda kurung kurawal `{}` dieksekusi mulai dari fungsi ini.

### B. Tipe Data, Variabel, dan Operasi Input/Output
Variabel, konstanta, serta input dan output termasuk elemen dasar pemrograman dalam C++ [3].
#### 1. Tipe Data
Tipe data menentukan jenis nilai yang dapat disimpan dalam variabel, misalnya `int` untuk bilangan bulat, `float` atau `double` untuk bilangan pecahan, dan `char` untuk satu karakter.
#### 2. Variabel dan Konstanta
Variabel adalah tempat penyimpanan nilai yang dapat berubah selama program berjalan, sedangkan konstanta bernilai tetap selama program dijalankan [3].
#### 3. Input dan Output
Input dibaca menggunakan `cin` dengan operator ekstraksi `>>`, sedangkan output ditampilkan menggunakan `cout` dengan operator penyisipan `<<`.

## Unguided 

### 1. Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
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
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Sania220107/109082530026_Rista-Sania-Putri_Struktur-Data/blob/main/Pertemuan1_Modul%201/output_1.jpeg?raw=true)

**Penjelasan Alur Program:**
Program ini menerima dua bilangan pecahan dari pengguna, lalu menampilkan hasil penjumlahan, pengurangan, perkalian, dan pembagiannya. Kedua bilangan disimpan dalam variabel `angka1` dan `angka2` bertipe `float` supaya bisa menampung angka desimal. Nilainya dibaca dengan `cin`, kemudian keempat operasi (`+`, `-`, `*`, `/`) dihitung langsung di dalam perintah `cout` dan hasilnya ditampilkan ke layar.

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100. Contoh: 79 : tujuh puluh Sembilan.

```C++
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
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Sania220107/109082530026_Rista-Sania-Putri_Struktur-Data/blob/main/Pertemuan1_Modul%201/output_2.jpeg?raw=true)

**Penjelasan Alur Program:**
Program ini mengubah angka 0 sampai 100 yang diinput pengguna menjadi tulisan bahasa Indonesia. Kata dasar "satu" sampai "sebelas" disimpan dalam array `satuan`, sehingga angka bisa langsung diambil sebagai indeksnya. Program memakai `if-else` bertingkat untuk memeriksa angka: di luar rentang akan muncul pesan kesalahan, angka 0 dan 100 dicetak sebagai "Nol" dan "Seratus", angka 1 sampai 11 diambil langsung dari array, angka 12 sampai 19 dibentuk dari `angka % 10` ditambah kata "belas", dan angka 20 sampai 99 dibentuk dari `angka / 10` (puluhan) ditambah `angka % 10` (satuan). Contohnya, angka 79 menghasilkan "tujuh puluh sembilan".


### 3. Buatlah program yang dapat memberikan input dan output sbb. (Pola Mirror Piramida Angka dengan tanda *).

Contoh input dan output:

```
input: 3
output:
321*123
 21*12
  1*1
   *
```

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "input: ";
    cin >> n;
    cout << "output:" << endl;
    
    for (int i = n; i >= 1; i--) { 
        
        for (int j = 0; j < n - i; j++) {
            cout << " ";
        }
        
        for (int j = i; j >= 1; j--) {
            cout << j;
        }
        
        cout << "*";
        
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        
        cout << endl; 
    }
    
    for (int j = 0; j < n; j++) {
        cout << " ";
    }
    cout << "*" << endl;
    
    return 0;
}

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Sania220107/109082530026_Rista-Sania-Putri_Struktur-Data/blob/main/Pertemuan1_Modul%201/output_3.jpeg?raw=true)

**Penjelasan Alur Program:**
Program ini menampilkan pola piramida angka yang simetris dengan tanda `*` di tengahnya, berdasarkan nilai `n` yang diinput pengguna. Perulangan `for` terluar berjalan dari `n` turun ke 1 dan mengatur jumlah baris. Di setiap baris, perulangan pertama mencetak spasi agar polanya bergeser ke kanan, perulangan kedua mencetak angka menurun dari `i` ke 1, lalu dicetak tanda `*`, dan perulangan terakhir mencetak angka menaik dari 1 ke `i`. Setelah semua baris selesai, program mencetak `n` spasi dan satu tanda `*` sebagai baris terakhir yang menjadi ujung piramida.


## Kesimpulan
Berdasarkan praktikum Modul 1, struktur dasar program C++ terdiri dari `#include`, `using namespace std;`, dan fungsi `main()`, dengan tipe data, variabel, serta `cin` dan `cout` untuk pengolahan input dan output. Pada soal 1, tipe data `float` memungkinkan program menghitung penjumlahan, pengurangan, perkalian, dan pembagian bilangan pecahan. Pada soal 2, array string dan percabangan `if-else` bertingkat, ditambah operator `%` dan `/`, digunakan untuk mengubah angka 0 sampai 100 menjadi tulisan. Pada soal 3, perulangan `for` bersarang digunakan untuk membentuk pola angka simetris dengan tanda `*`. Selain itu, Code::Blocks membantu proses menulis, mengompilasi, dan menjalankan program C++ dalam satu aplikasi.


## Referensi
[1] Effendi, Q. M. F. Z., Zuhura, T. R., Amrulloh, M. S. A. F., Arafat, F. Y., Haris, M., Wahyudi, N. R., Putra, I. M., & Ramadhan, K. (2024). "Penggunaan Bahasa C++ dalam Perkuliahan Jurusan Teknik Elektro Fakultas Teknik". *Jurnal Majemuk*, 3(1), 143–151. Diakses pada 29 September 2026 melalui https://jurnalilmiah.org/journal/index.php/majemuk/article/view/664.

<br>[2] Ardana, F. M., Tiadah, M. N., Adinata, M. A., Zulkarnain, Z. Z., Sabela, A. T., & Fadhlullah, M. A. (2024). "Analisis Survei Perbandingan Penggunaan Tingkatan Bahasa Pemrograman bagi Mahasiswa Teknik Informatika Universitas Negeri Semarang". *Jurnal Angka*, 1(1), 69–82. Diakses pada 29 September 2026 melalui https://jurnalilmiah.org/journal/index.php/angka/article/view/728.

<br>[3] Dewi, L. J. E. (2012). "Media Pembelajaran Bahasa Pemrograman C++". *Jurnal Pendidikan Teknologi dan Kejuruan*, 7(1). Diakses pada 29 September 2026 melalui https://doi.org/10.23887/jptk-undiksha.v7i1.31.
