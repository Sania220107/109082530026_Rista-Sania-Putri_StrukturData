# <h1 align="center">Laporan Praktikum Modul 6 - DOUBLY LINKED LIST (BAGIAN PERTAMA)</h1>
<p align="center">Rista Sania Putri - 109082530026</p>

## Dasar Teori
Linked list atau yang disebut juga senarai berantai adalah salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas[1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer. Pada praktikum ini dibahas pengembangan dari linked list, yaitu doubly linked list.

### A. Doubly Linked List<br/>
Doubly linked list adalah linked list yang setiap elemennya memiliki dua successor, yaitu pointer yang menunjuk ke elemen sebelumnya (prev) dan pointer yang menunjuk ke elemen sesudahnya (next)[3]. Dengan dua pointer tersebut, penelusuran data dapat dilakukan maju (dari first ke last) maupun mundur (dari last ke first), sehingga akses elemen menjadi lebih mudah dibandingkan singly linked list[3].
#### 1. Komponen
Komponen dalam doubly linked list adalah[3]:

<ol>
<li>pointer pada list yang menunjuk elemen pertama.</li>
<li>pointer pada list yang menunjuk elemen terakhir.</li>
<li>pointer pada elemen yang menunjuk elemen di depannya.</li>
<li>pointer pada elemen yang menunjuk elemen di belakangnya.</li>
</ol>

List dikatakan kosong jika L.first = Nil.
#### 2. Struktur Data
Struktur data doubly linked list terdiri dari record elemen (info, prev, next) dan record list (first, last)[3].

struct elmlist {
    infotype info;
    address prev;
    address next;
};

struct list {
    address first, last;
};
#### 3. Alokasi dan Dealokasi
Alokasi membuat elemen baru di memori dengan new lalu mengisi info, serta mengatur next dan prev menjadi Nil. Dealokasi membebaskan memori elemen dengan delete[2].

### B. Operasi pada Doubly Linked List<br/>
Operasi dasar pada doubly linked list terdiri dari insert dan delete yang dapat dilakukan di awal, di akhir, maupun di tengah list[3].

#### 1. Insert
<ul>
<li>Insert First: elemen baru disisipkan di awal list. P->next = L.first, (L.first)->prev = P, lalu L.first = P.</li>
<li>Insert Last: elemen baru disisipkan di akhir list. P->prev = L.last, (L.last)->next = P, lalu L.last = P.</li>
<li>Insert After / Insert Before: elemen baru disisipkan tepat setelah atau sebelum elemen R. Keduanya serupa, bedanya hanya pada elemen yang dijadikan acuan[3].</li>
</ul>

#### 2. Delete
<ul>
<li>Delete First: elemen pertama diambil, L.first dipindah ke elemen berikutnya, lalu prev elemen pertama yang baru diisi Nil.</li>
<li>Delete Last: elemen terakhir diambil, L.last dipindah ke elemen sebelumnya, lalu next elemen terakhir yang baru diisi Nil.</li>
<li>Delete After / Delete Before: menghapus elemen tepat setelah atau sebelum elemen acuan dengan menyambungkan kembali pointer next dan prev elemen di sekitarnya[3].</li>

</ul>

#### 3. Update, View, dan Searching
Proses pencarian, update, dan view data pada dasarnya sama dengan singly linked list, hanya saja pada doubly linked list iterasi dapat dilakukan maju dan mundur[3].

## Guided 

### 1. DoublyList

#### DoublyList.h

```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#include <string>
using namespace std;

struct barang {
    string kode;
    string nama;
    int tahun;
};

using infotype = barang;
struct elmlist;
using address = elmlist*;
struct elmlist {
    infotype info;
    address prev;
    address next;
};

struct list {
    address first;
    address last;
};

void CreateList(list &L);
address alokasi(const infotype &x);
void dealokasi(address &P);
void insertFirst(list &L, address P);
void insertLast(list &L, address P);
void insertAfter(list &L, address R, address P);
void insertBefore(list &L, address R, address P);
void printInfo(const list &L);
address findElm(const list &L, const string &kode);
void deleteFirst(list &L, address &P);
void deleteLast(list &L, address &P);
void deleteAfter(list &L, address prec, address &P);
void deleteBefore(list &L,address succ, address &P);
#endif
```


#### DoublyList.cpp

```C++
#include <iostream>
#include <iomanip>
#include "DoublyList.h"
using namespace std;

void CreateList(list &L) { L.first = nullptr; L.last = nullptr; }

address alokasi(const infotype &x) {
    address P = new elmlist;
    P->info = x;
    P->prev = nullptr; P->next = nullptr;
    return P;
}
void dealokasi(address &P) {
    if (P != nullptr) { delete P; P = nullptr; }
}
void insertFirst(list &L, address P) {
    if (!P) return;
    P->prev = nullptr; P->next = L.first;
    if (L.first) L.first->prev = P;
    else L.last = P;
    L.first = P;
}
void insertLast(list &L, address P) {
    if (!P) return;
    P->next = nullptr; P->prev = L.last;
    if (L.last) L.last->next = P;
    else L.first = P;
    L.last = P;
}

// Menyisipkan P tepat setelah R.
void insertAfter(list &L, address R, address P) {
    if (!R || !P) return;
    P->prev = R;
    P->next = R->next;
    if (R->next) R->next->prev = P;
    else L.last = P;
    R->next = P;
}

// Menyisipkan P tepat sebelum R.
void insertBefore(list &L, address R, address P) {
    if (!R || !P) return;
    P->next = R;
    P->prev = R->prev;
    if (R->prev) R->prev->next = P;
    else L.first = P;
    R->prev = P;
}
void printInfo(const list &L) {
    address P = L.first;
    if (!P) {
        cout << "List kosong.\n";
        return;
    }

    cout << "+--------+------------+-------+\n";
    cout << "| Kode   | Nama       | Tahun |\n";
    cout << "+--------+------------+-------+\n";
    while (P) {
        cout << "| " << left << setw(6) << P->info.kode
             << " | " << setw(10) << P->info.nama
             << " | " << setw(5) << P->info.tahun << " |\n";
        P = P->next;
    }
    cout << "+--------+------------+-------+\n";
}
address findElm(const list &L, const string &kode) {
    address P = L.first;
    while (P) {
        if (P->info.kode == kode) return P;
        P = P->next;
    }
    return nullptr;
}
void deleteFirst(list &L, address &P) {
    if (!L.first) { P = nullptr; return; }
    P = L.first; L.first = P->next;
    if (L.first) L.first->prev = nullptr;
    else L.last = nullptr;
    P->prev = P->next = nullptr;
}
void deleteLast(list &L, address &P) {
    if (!L.last) { P = nullptr; return; }
    P = L.last; L.last = P->prev;
    if (L.last) L.last->next = nullptr;
    else L.first = nullptr;
    P->prev = P->next = nullptr;
}
// Menghapus node tepat setelah prec.
void deleteAfter(list &L, address prec, address &P) {
    P = nullptr;
    if (!prec || !prec->next) return;
    P = prec->next; prec->next = P->next;
    if (P->next) P->next->prev = prec;
    else L.last = prec;
    P->prev = P->next = nullptr;
}
// Menghapus node tepat sebelum succ.
void deleteBefore(list &L, address succ, address &P) {
    P = nullptr;
    if (!succ || !succ->prev) return;
    P = succ->prev; succ->prev = P->prev;
    if (P->prev) P->prev->next = succ;
    else L.first = succ;
    P->prev = P->next = nullptr;
}
```


#### main.cpp

```C++
#include <iostream>
#include "DoublyList.h"
using namespace std;

void tampilkanJudul(const string &judul) {
    cout << "\n========================================\n";
    cout << judul << '\n';
    cout << "========================================\n";
}

int main() {
    list L;
    CreateList(L);

    infotype barang1 = {"B001", "Laptop", 2020};
    infotype barang2 = {"B002", "Monitor", 2022};
    infotype barang3 = {"B003", "Keyboard", 2023};
    infotype barang4 = {"B004", "Mouse", 2024};

    address P = nullptr;
    address posisi = nullptr;

    cout << "DEMONSTRASI OPERASI DOUBLY LINKED LIST\n";
    cout << "Data yang digunakan: B001, B002, B003, dan B004\n";

    tampilkanJudul("[1] INSERT FIRST");
    cout << "Menambahkan B002 di awal list.\n";
    insertFirst(L, alokasi(barang2));
    printInfo(L);

    tampilkanJudul("[2] INSERT LAST");
    cout << "Menambahkan B004 di akhir list.\n";
    insertLast(L, alokasi(barang4));
    printInfo(L);

    tampilkanJudul("[3] INSERT AFTER");
    cout << "Menambahkan B003 setelah B002.\n";
    posisi = findElm(L, "B002");
    if (posisi != nullptr) {
        insertAfter(L, posisi, alokasi(barang3));
    }
    printInfo(L);

    tampilkanJudul("[4] INSERT BEFORE");
    cout << "Menambahkan B001 sebelum B002.\n";
    posisi = findElm(L, "B002");
    if (posisi != nullptr) {
        insertBefore(L, posisi, alokasi(barang1));
    }
    printInfo(L);

    tampilkanJudul("[5] FIND ELEMENT");
    cout << "Mencari barang dengan kode B003.\n";
    posisi = findElm(L, "B003");
    if (posisi != nullptr) {
        cout << "Data ditemukan:\n";
        cout << "  Kode  : " << posisi->info.kode << '\n';
        cout << "  Nama  : " << posisi->info.nama << '\n';
        cout << "  Tahun : " << posisi->info.tahun << '\n';
    } else {
        cout << "Data tidak ditemukan.\n";
    }

    tampilkanJudul("[6] DELETE AFTER");
    cout << "Menghapus node setelah B002 (B003).\n";
    posisi = findElm(L, "B002");
    deleteAfter(L, posisi, P);
    if (P != nullptr) {
        cout << "Node yang dihapus: " << P->info.kode << '\n';
        dealokasi(P);
    } else {
        cout << "Tidak ada node yang dapat dihapus.\n";
    }
    printInfo(L);

    tampilkanJudul("[7] DELETE BEFORE");
    cout << "Menghapus node sebelum B004 (B002).\n";
    posisi = findElm(L, "B004");
    deleteBefore(L, posisi, P);
    if (P != nullptr) {
        cout << "Node yang dihapus: " << P->info.kode << '\n';
        dealokasi(P);
    } else {
        cout << "Tidak ada node yang dapat dihapus.\n";
    }
    printInfo(L);

    tampilkanJudul("[8] DELETE FIRST");
    cout << "Menghapus node pertama.\n";
    deleteFirst(L, P);
    if (P != nullptr) {
        cout << "Node yang dihapus: " << P->info.kode << '\n';
        dealokasi(P);
    } else {
        cout << "List kosong, tidak ada node yang dapat dihapus.\n";
    }
    printInfo(L);

    tampilkanJudul("[9] DELETE LAST");
    cout << "Menghapus node terakhir.\n";
    deleteLast(L, P);
    if (P != nullptr) {
        cout << "Node yang dihapus: " << P->info.kode << '\n';
        dealokasi(P);
    } else {
        cout << "List kosong, tidak ada node yang dapat dihapus.\n";
    }
    printInfo(L);

    tampilkanJudul("SELESAI");
    cout << "Kondisi list: "
         << (L.first == nullptr && L.last == nullptr ? "kosong.\n" : "masih berisi data.\n");

    return 0;
}
```
Program ini mencoba semua operasi dasar doubly linked list dengan data barang (kode, nama, tahun). Datanya ditambah pakai insertFirst, insertLast, insertAfter, dan insertBefore, dicari pakai findElm, lalu dihapus pakai deleteAfter, deleteBefore, deleteFirst, dan deleteLast sampai list kosong. Setiap selesai satu operasi, isi list ditampilkan pakai printInfo supaya perubahannya kelihatan.

## Unguided 

### 1. Buatlah ADT Doubly Linked list (kendaraan) pada file "Doublylist.h" dan implementasinya pada "Doublylist.cpp" (CreateList, alokasi, dealokasi, printInfo, insertLast), lalu coba pada "main.cpp". Nomor polisi tidak boleh sama.

#### Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
using namespace std;

#define Nil nullptr

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

typedef struct ElmList *address;
struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);

// Soal 2
address findElm(List L, infotype x);

// Soal 3
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);

#endif
```
#### Doublylist.cpp
```C++
#include "Doublylist.h"

void CreateList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void printInfo(List L) {
    address P = L.last;
    while (P != Nil) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->prev;
    }
}

address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == x.nopol) return P;
        P = P->next;
    }
    return Nil;
}
```
#### main.cpp
```C++
#include "Doublylist.h"

int main() {
    List L;
    CreateList(L);

    infotype x;
    for (int i = 0; i < 4; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        if (findElm(L, x) != Nil) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            insertLast(L, alokasi(x));
        }
        cout << endl;
    }

    cout << "DATA LIST 1" << endl << endl;
    printInfo(L);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)


Program ini membuat doubly linked list untuk data kendaraan yang isinya nomor polisi, warna, dan tahun buat. Data ditambahkan lewat insertLast, jadi selalu masuk di belakang list. Sebelum data dimasukkan, program mengecek dulu pakai findElm. Kalau nomor polisinya sudah ada, data ditolak dan muncul tulisan “nomor polisi sudah terdaftar”. printInfo menampilkan data dari belakang ke depan lewat pointer prev, makanya urutan tampilannya terbalik dari urutan input.

### 2. Carilah elemen dengan nomor polisi D001 dengan membuat fungsi baru findElm(L : List, x : infotype) : address.

#### Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
using namespace std;

#define Nil nullptr

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

typedef struct ElmList *address;
struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
address findElm(List L, infotype x);

#endif
```
#### Doublylist.cpp
```C++
#include "Doublylist.h"

void CreateList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void printInfo(List L) {
    address P = L.last;
    while (P != Nil) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->prev;
    }
}

address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == x.nopol) return P;
        P = P->next;
    }
    return Nil;
}
```
#### main.cpp
```C++
#include "Doublylist.h"

int main() {
    List L;
    CreateList(L);

    infotype x;
    for (int i = 0; i < 4; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        if (findElm(L, x) != Nil) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            insertLast(L, alokasi(x));
        }
        cout << endl;
    }

    cout << "DATA LIST 1" << endl << endl;
    printInfo(L);

    // ---- Soal 2: cari nomor polisi ----
    cout << endl << "Masukkan Nomor Polisi yang dicari : ";
    cin >> x.nopol;
    address P = findElm(L, x);
    cout << endl;
    if (P != Nil) {
        cout << "Nomor Polisi   : " << P->info.nopol << endl;
        cout << "Warna          : " << P->info.warna << endl;
        cout << "Tahun          : " << P->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)




Di soal ini ditambah fungsi findElm untuk mencari data berdasarkan nomor polisi. Fungsi ini jalan dari elemen pertama sambil membandingkan nomor polisi tiap elemen. Kalau ketemu, yang dikembalikan adalah alamat elemennya, kalau tidak ketemu hasilnya Nil. Setelah itu program menampilkan nomor polisi, warna, dan tahun dari data yang dicari, yaitu D001.

### 3. Hapus elemen dengan nomor polisi D003 dengan procedure deleteFirst, deleteLast, dan deleteAfter.

#### Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
using namespace std;

#define Nil nullptr

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

typedef struct ElmList *address;
struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
address findElm(List L, infotype x);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);

#endif
```
#### Doublylist.cpp
```C++
#include "Doublylist.h"

void CreateList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void printInfo(List L) {
    address P = L.last;
    while (P != Nil) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->prev;
    }
}

address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == x.nopol) return P;
        P = P->next;
    }
    return Nil;
}

void deleteFirst(List &L, address &P) {
    P = L.first;
    if (L.first == L.last) {       // hanya 1 elemen
        L.first = Nil;
        L.last = Nil;
    } else {
        L.first = P->next;
        L.first->prev = Nil;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    P = L.last;
    if (L.first == L.last) {       // hanya 1 elemen
        L.first = Nil;
        L.last = Nil;
    } else {
        L.last = P->prev;
        L.last->next = Nil;
        P->prev = Nil;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    P = Prec->next;
    Prec->next = P->next;
    if (P->next != Nil) P->next->prev = Prec;
    else L.last = Prec;
    P->next = Nil;
    P->prev = Nil;
}
```
#### main.cpp
```C++
#include "Doublylist.h"

int main() {
    List L;
    CreateList(L);

    infotype x;
    for (int i = 0; i < 4; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        if (findElm(L, x) != Nil) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            insertLast(L, alokasi(x));
        }
        cout << endl;
    }

    cout << "DATA LIST 1" << endl << endl;
    printInfo(L);

    // ---- Soal 2: cari nomor polisi ----
    cout << endl << "Masukkan Nomor Polisi yang dicari : ";
    cin >> x.nopol;
    address P = findElm(L, x);
    cout << endl;
    if (P != Nil) {
        cout << "Nomor Polisi   : " << P->info.nopol << endl;
        cout << "Warna          : " << P->info.warna << endl;
        cout << "Tahun          : " << P->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }

    // ---- Soal 3: hapus nomor polisi ----
    cout << endl << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> x.nopol;
    P = findElm(L, x);
    if (P == Nil) {
        cout << "Data tidak ditemukan" << endl;
    } else {
        address hapus;
        if (P == L.first)      deleteFirst(L, hapus);
        else if (P == L.last)  deleteLast(L, hapus);
        else                   deleteAfter(L, P->prev, hapus);

        dealokasi(hapus);
        cout << "Data dengan nomor polisi " << x.nopol << " berhasil dihapus." << endl;
    }

    cout << endl << "DATA LIST 1" << endl << endl;
    printInfo(L);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)



Di soal ini ditambah tiga prosedur hapus, yaitu deleteFirst, deleteLast, dan deleteAfter. Data yang mau dihapus dicari dulu pakai findElm, lalu cara hapusnya tergantung posisinya. Kalau di awal pakai deleteFirst, kalau di akhir pakai deleteLast, dan kalau di tengah pakai deleteAfter. Untuk deleteAfter, elemen sebelumnya langsung diambil dari P->prev, jadi tidak perlu dicari lagi. Pada contoh, D003 ada di tengah sehingga dihapus pakai deleteAfter. Setelah dilepas dari list, elemennya dihapus dari memori pakai dealokasi, lalu list ditampilkan lagi dan tersisa D004 dan D001.

## Kesimpulan
Doubly linked list adalah pengembangan dari singly linked list yang setiap elemennya memiliki pointer prev dan next, sehingga list dapat ditelusuri maju maupun mundur. Operasi insert dan delete di awal, akhir, maupun tengah list dapat dilakukan dengan mengatur ulang pointer first, last, prev, dan next, dan perlu diperhatikan kasus khusus seperti list kosong atau list dengan satu elemen. Keberadaan pointer prev juga mempermudah operasi seperti deleteAfter, karena elemen sebelumnya dapat langsung diakses tanpa pencarian ulang. Melalui praktikum ini, konsep ADT doubly linked list berhasil diimplementasikan dalam bahasa C++ menggunakan pointer.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4. 
<br>[3] Modul 6 Praktikum Struktur Data: Doubly Linked List (Bagian Pertama). Fakultas Informatika, Telkom University.
