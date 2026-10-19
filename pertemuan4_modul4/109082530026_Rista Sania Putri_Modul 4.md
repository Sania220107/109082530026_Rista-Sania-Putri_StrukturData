# <h1 align="center">Laporan Praktikum Modul 4 - SINGLY LINKED LIST (BAGIAN PERTAMA)</h1>
<p align="center">Rista Sania Putri - 109082530026</p>

## Dasar Teori

Linked list (senarai berantai) adalah salah satu bentuk struktur data berupa serangkaian elemen data yang saling berkait (berhubungan) dan bersifat fleksibel karena dapat tumbuh dan mengerut sesuai kebutuhan [1]. Data yang disimpan dalam linked list dapat berupa data tunggal (misalnya satu variabel bertipe string) atau data majemuk berupa *record* yang terdiri dari beberapa tipe data, misalnya data mahasiswa yang berisi nama, NIM, dan umur [1].

### A. Linked List dan Singly Linked List<br/>
Linked list dapat diimplementasikan menggunakan array maupun pointer. Pada praktikum ini digunakan pointer karena sifatnya yang dinamis, sedangkan array bersifat statis dan lebih cocok untuk kumpulan data yang jumlah elemen maksimumnya sudah diketahui sejak awal [1]. Selain itu, bentuk data pada linked list yang saling bergandengan lebih mudah ditangani dengan pointer [1]. Pada implementasinya, elemen yang diacu oleh pointer dapat diakses menggunakan operator panah (`->`) atau tanda titik (`.`) [1].

#### 1. Pengertian Singly Linked List
Singly linked list merupakan model ADT linked list yang hanya memiliki satu arah pointer [1]. Setiap elemen (node) terdiri dari dua bagian, yaitu data sebagai informasi utama yang tersimpan dan *successor* (`next`) sebagai penghubung ke elemen berikutnya [1].

#### 2. Istilah dalam Singly Linked List
- `first`/`head` : pointer pada list yang menunjuk alamat elemen pertama list [1].
- `next` : pointer pada elemen yang berfungsi sebagai *successor* atau penunjuk alamat elemen di depannya [1].
- `Nil`/`NULL` : tidak memiliki nilai, tidak mengacu ke mana pun, atau kosong [1].
- *Node*/simpul/elemen : tempat penyimpanan data pada suatu memori tertentu [1].

#### 3. Sifat Singly Linked List
Singly linked list hanya memerlukan satu buah pointer, node terakhir menunjuk ke `Nil` (kecuali pada list circular), hanya dapat melakukan pembacaan maju, dan pencarian dilakukan secara sekuensial jika data tidak terurut. Penyisipan atau penghapusan di tengah list juga lebih mudah dilakukan [1].

### B. Operasi pada Singly Linked List<br/>
Operasi dasar yang umum pada linked list adalah penciptaan list (*create list*), penyisipan elemen (*insert*), penghapusan elemen (*delete*), penelusuran dan penampilan elemen (*view*), pencarian elemen (*searching*), dan pengubahan isi elemen (*update*) [1].

#### 1. Pembentukan List dan Manajemen Memori
Pembentukan list dilakukan dengan fungsi `createList()` yang mengatur nilai awal `first` menjadi `Nil` [1]. Alokasi memori untuk setiap elemen dilakukan dengan fungsi `alokasi()`; pada C++ digunakan `new` (pada C digunakan `malloc`). Dealokasi memori dilakukan dengan `dealokasi()`; pada C++ digunakan `delete` (pada C digunakan `free`) [1]. Pengecekan list kosong atau tidak dilakukan dengan fungsi `isEmpty()` yang mengembalikan `true` jika list kosong [1].

#### 2. Insert
Insert adalah penambahan node baru ke dalam list. Ada tiga jenis insert, yaitu *insert first* (di awal list), *insert last* (di akhir list), dan *insert after* (setelah node tertentu) [1]. Pada *insert first*, `next` node baru diarahkan ke `first` lalu `first` diarahkan ke node baru [1]. Pada *insert last*, list ditelusuri sampai node terakhir lalu `next` node terakhir diarahkan ke node baru [1]. Pada *insert after*, `next` node baru diarahkan ke `next` dari node sebelumnya, lalu `next` node sebelumnya diarahkan ke node baru [1].

#### 3. Delete
Delete adalah penghapusan node dari list, terdiri dari *delete first*, *delete last*, dan *delete after* [1]. Setelah node dilepas dari list, memori yang dipakai node tersebut dibebaskan dengan `dealokasi`, sedangkan penghapusan seluruh node dalam list dilakukan dengan fungsi `delAll`/`deleteList` sehingga list menjadi kosong [1].

#### 4. View dan Update
*View* adalah operasi menampilkan isi node dengan menelusuri list, yaitu mengunjungi setiap node lalu menampilkan data yang tersimpan [1]. *Update* adalah operasi mengubah data node yang ada di dalam list, dan biasanya diawali dengan proses pencarian terhadap data yang akan diubah [1].

## Guided

Pada guided dibuat ADT `linkedList` untuk data mahasiswa yang terdiri dari tiga file, yaitu `list.h`, `list.cpp`, dan `main.cpp`.

### 1. list.h

```C++
//header guard digunakan untuk mencegah file header yg sama
//di-include lebih dari sekali dalam 1 program
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
#include <string>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;  //memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //mendefinisikan alias address sebagai pointer ke struct node

struct node { //node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedList { //ini linked listnya
    address first;
};

//semua function & prosedure yang akan dipakai
bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &P);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address Prev);
void insertLast(linkedList &List, address nodeBaru);

void delFirst(linkedList &List);
void delLast(linkedList &List);
void delAfter(linkedList &List, address nodeHapus, address nodePrev);
int nbList(linkedList List);
void deleteList(linkedList &List);

#endif
```
File `list.h` berisi deklarasi struktur data dan prototype semua fungsi/prosedur yang dipakai. *Header guard* (`#ifndef`, `#define`, `#endif`) mencegah file header yang sama di-include lebih dari sekali. `struct mahasiswa` menyimpan data nama, NIM, dan umur, kemudian diberi alias `dataMahasiswa`. `struct node` adalah elemen list yang berisi `isidata` dan pointer `next`, `address` adalah alias pointer ke `node`, dan `struct linkedList` hanya menyimpan pointer `first` yang menunjuk ke node pertama.

### 2. list.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) {
    if(List.first == Nil){
        return true;
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) {
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedList &List){
    /* I.S. list tidak kosong
    F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List){
    /* I.S. list tidak kosong
    F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else {
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev){
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev->next, menghapus Prev->next dari list */
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedList List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedList List) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedList &List){
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List sudah terhapus!" << endl;
}
```
File `list.cpp` berisi implementasi semua prototype di `list.h`. `createList` mengatur `first` menjadi `Nil`, `isEmpty` mengecek apakah `first` bernilai `Nil`, `alokasi` membuat node baru dengan `new` lalu mengisi data dan `next = Nil`, dan `dealokasi` mengembalikan memori node dengan `delete`. Untuk insert, `insertFirst` menyisipkan node di awal list, `insertLast` menelusuri list sampai node terakhir lalu menyambungkan node baru, dan `insertAfter` menyisipkan node baru setelah node `Prev`. Untuk delete, `delFirst` menghapus node pertama, `delLast` menghapus node terakhir, dan `delAfter` menghapus node yang berada setelah `nodePrev`. `printList` menelusuri list dari `first` sampai `Nil` sambil menampilkan data, `nbList` menghitung jumlah node, dan `deleteList` menghapus seluruh node satu per satu lalu mengembalikan list menjadi kosong.

### 3. main.cpp

```C++
#include "list.h"

#include <iostream>
using namespace std;

int main() {
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2311102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Pada program utama dibuat list kosong, kemudian lima node dialokasikan (`nodeA` sampai `nodeE`) dengan data mahasiswa. Node dimasukkan dengan urutan: `nodeA` dengan `insertFirst`, `nodeB` dengan `insertLast`, `nodeC` setelah `nodeA`, `nodeD` setelah `nodeC`, dan `nodeE` dengan `insertLast`, sehingga urutan list menjadi Dhimas, Rizal, Satrio, Arvin, Joshua (5 node). Setelah itu dilakukan `delFirst` (menghapus Dhimas), `delLast` (menghapus Joshua), dan `delAfter` (menghapus node setelah `nodeC`, yaitu Satrio), sehingga tersisa Rizal dan Arvin (2 node). Terakhir `deleteList` menghapus seluruh node sehingga list kosong dan jumlah node menjadi 0.

## Unguided 

### 1. Membuat ADT Singly Linked List pada file `Singlylist.h`, implementasi procedure pada `Singlylist.cpp`, dan program utama pada `main.cpp`

**Singlylist.h**
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
#include <cstddef>
using namespace std;

typedef int infotype;            
typedef struct ElmList *address;

struct ElmList {                 
    infotype info;
    address next;
};

struct List {                    
    address First;
};

//procedure & function yang digunakan
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif
```

**Singlylist.cpp**
```C++
#include "Singlylist.h"

void CreateList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    if (P != Nil) {
        P->next = Nil;
        delete P;
        P = Nil;
    }
}


void printInfo(List L) {
    address P = L.First;
    if (P == Nil) {
        cout << "List kosong!" << endl;
    } else {
        while (P != Nil) {
            cout << P->info;
            if (P->next != Nil) {
                cout << " ";
            }
            P = P->next;
        }
        cout << endl;
    }
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}
```

**main.cpp**
```C++
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1](https://github.com/Sania220107/109082530026_Rista-Sania-Putri_StrukturData/blob/main/pertemuan4_modul4/output_1.png?raw=true)

Pada soal ini dibuat ADT singly linked list dengan tipe `infotype` berupa `int`, `address` sebagai pointer ke `ElmList`, dan `List` yang menyimpan pointer `First`. Procedure `CreateList` membuat list kosong, `alokasi` membuat node baru dengan `new`, `dealokasi` mengembalikan memori node, `printInfo` menampilkan isi list dari node pertama sampai terakhir, dan `insertFirst` menyisipkan node di awal list. Pada `main`, nilai 2, 0, 8, 12, dan 9 dialokasikan lalu dimasukkan satu per satu menggunakan `insertFirst`. Karena setiap node baru selalu ditempatkan di awal list, urutan list menjadi kebalikan dari urutan insert, yaitu `9 12 8 0 2`, sesuai output yang diharapkan.

### 2. Dari soal latihan pertama, menghapus node 9 dengan `deleteFirst()`, node 2 dengan `deleteLast()`, dan node 8 dengan `deleteAfter()`, lalu menampilkan jumlah node dengan `nbList()` dan menghapus seluruh node dengan `deleteList()`

**Singlylist.h**
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
#include <cstddef>
using namespace std;

typedef int infotype;           
typedef struct ElmList *address; 

struct ElmList {                 
    infotype info;
    address next;
};

struct List {                  
    address First;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);



void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
int nbList(List L);
void deleteList(List &L);

#endif
```

**Singlylist.cpp**
```C++
#include "Singlylist.h"
void CreateList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

//pengembalian memori node ke sistem
void dealokasi(address &P) {
    if (P != Nil) {
        P->next = Nil;
        delete P;
        P = Nil;
    }
}

//menampilkan seluruh isi list
void printInfo(List L) {
    address P = L.First;
    if (P == Nil) {
        cout << "List kosong!" << endl;
    } else {
        while (P != Nil) {
            cout << P->info;
            if (P->next != Nil) {
                cout << " ";
            }
            P = P->next;
        }
        cout << endl;
    }
}

//insert first
void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

//delete first
void deleteFirst(List &L, address &P) {
    if (L.First == Nil) {
        cout << "List kosong!" << endl;
        P = Nil;
    } else {
        P = L.First;
        L.First = P->next;
        P->next = Nil;
    }
}

//delete last
void deleteLast(List &L, address &P) {
    if (L.First == Nil) {
        cout << "List kosong!" << endl;
        P = Nil;
    } else if (L.First->next == Nil) { 
        P = L.First;
        L.First = Nil;
    } else {
        address Q = L.First;            
        while (Q->next->next != Nil) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = Nil;
    }
}

//delete after
void deleteAfter(List &L, address Prec, address &P) {
    if (L.First == Nil) {
        cout << "List kosong!" << endl;
        P = Nil;
    } else if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
    } else {
        cout << "Node sebelumnya (Prec) tidak valid!" << endl;
        P = Nil;
    }
}

//menghitung jumlah node
int nbList(List L) {
    int jumlah = 0;
    address P = L.First;
    while (P != Nil) {
        jumlah++;
        P = P->next;
    }
    return jumlah;
}

//menghapus seluruh node di dalam list
void deleteList(List &L) {
    address P = Nil;
    while (L.First != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
    }
}
```

**main.cpp**
```C++
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    address hapus = Nil;

    //hapus node 9 menggunakan deleteFirst()
    deleteFirst(L, hapus);
    dealokasi(hapus);

    //hapus node 2 menggunakan deleteLast()
    deleteLast(L, hapus);
    dealokasi(hapus);

    //hapus node 8 menggunakan deleteAfter() (node setelah node 12)
    deleteAfter(L, P4, hapus);
    dealokasi(hapus);

    //tampilkan isi list & jumlah node menggunakan nbList()
    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    cout << endl;

    //hapus seluruh node menggunakan deleteList()
    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2](https://github.com/Sania220107/109082530026_Rista-Sania-Putri_StrukturData/blob/main/pertemuan4_modul4/output_2.png?raw=true)

Soal ini melanjutkan soal pertama dengan menambahkan procedure `deleteFirst`, `deleteLast`, `deleteAfter`, `nbList`, dan `deleteList`. List awal `9 12 8 0 2` dibuat terlebih dahulu seperti pada soal pertama. Selanjutnya `deleteFirst` melepas node pertama (9) sehingga list menjadi `12 8 0 2`, `deleteLast` melepas node terakhir (2) sehingga list menjadi `12 8 0`, dan `deleteAfter` dengan `P4` (node 12) sebagai node sebelumnya melepas node 8 sehingga list menjadi `12 0`. Setiap node yang dilepas langsung dikembalikan memorinya dengan `dealokasi`. `printInfo` kemudian menampilkan `12 0` dan `nbList` menghitung jumlah node sebanyak 2. Terakhir `deleteList` menghapus seluruh node sehingga jumlah node menjadi 0, sesuai output yang diharapkan.

## Kesimpulan
Dari praktikum ini dapat disimpulkan bahwa singly linked list adalah struktur data dinamis yang tersusun dari node-node yang saling terhubung dengan satu arah pointer, sehingga ukurannya dapat bertambah dan berkurang sesuai kebutuhan. Operasi dasarnya meliputi pembuatan list, alokasi dan dealokasi memori, insert (first, last, after), delete (first, last, after), menampilkan isi list, menghitung jumlah node, dan menghapus seluruh list. Pengelolaan memori dengan `new` dan `delete` perlu dilakukan dengan benar agar tidak terjadi kebocoran memori maupun pointer yang menggantung. Dengan memisahkan ADT ke dalam file `.h` (deklarasi) dan `.cpp` (implementasi), program menjadi lebih terstruktur dan mudah digunakan kembali pada program utama.

## Referensi
[1] Modul Praktikum Struktur Data, Modul 4 Singly Linked List (Bagian Pertama). Fakultas Informatika, Telkom University.