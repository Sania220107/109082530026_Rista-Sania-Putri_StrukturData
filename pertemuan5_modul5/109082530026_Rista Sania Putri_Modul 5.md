# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (Bagian Kedua)</h1>
<p align="center">Rista Sania Putri - 109082530026</p>

## Dasar Teori

### A. Singly Linked List<br/>
Linked list atau yang disebut juga senarai berantai adalah salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas[1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer. Di singly linked list, tiap node cuma punya satu pointer yaitu next yang menunjuk ke node setelahnya, dan node paling akhir menunjuk ke Nil (NULL) sebagai tanda list sudah habis. Memori linked list dialokasikan secara dinamis, jadi cocok dipakai untuk data yang sering berubah, misalnya sering ditambah, dihapus, dicari, atau ditampilkan[2][3].
#### 1. Struktur Node dan List
Satu node isinya ada dua: data (info) dan pointer next. Sedangkan list sendiri cuma menyimpan pointer first yang menunjuk ke node pertama. Kalau nilai first adalah Nil, berarti list masih kosong.
#### 2. Operasi Dasar
Operasi dasarnya ada membuat list kosong (createList), menambah node (insert first, insert after, insert last), menghapus node (delete first, delete after, delete last), dan menampilkan isi list (printList / printInfo).
#### 3. Manajemen Memori
Node dibuat dengan new di fungsi alokasi, lalu kalau sudah tidak dipakai dihapus dengan delete di prosedur dealokasi supaya memorinya dikembalikan.

### B. Update<br/>
Update artinya mengubah data di node yang sudah ada di dalam list. Caranya, cari dulu node yang mau diubah, lalu isi datanya diganti. Susunan pointer-nya tidak berubah.
#### 1. Update First
Mengubah data di node pertama. Node ini bisa langsung diakses lewat List.first.
#### 2. Update Last
Mengubah data di node terakhir. Untuk sampai ke sana, list ditelusuri dulu sampai next bernilai Nil.
#### 3. Update After
Mengubah data di node yang letaknya tepat setelah node tertentu (Prev->next).

### C. Searching<br/>
Searching adalah operasi mencari node tertentu di dalam list. Prosesnya mengunjungi node satu per satu dan berhenti begitu node yang dicari ketemu. Dengan adanya searching, operasi seperti insert after, delete after, dan update jadi lebih gampang dikerjakan[4]. Karena aksesnya berurutan, pencarian dilakukan dengan memeriksa node satu per satu dari awal, dengan kompleksitas O(n)[3].

#### 1. Searching Berdasarkan Data
List ditelusuri dari node pertama, lalu data tiap node dibandingkan dengan data yang dicari. Contohnya findElm dan FindNodeByData.
#### 2. Searching Berdasarkan Alamat
Membandingkan alamat setiap node dengan alamat yang dicari (FindNodeByAddress).
#### 3. Searching Berdasarkan Range
Menampilkan semua node yang datanya masuk dalam rentang tertentu, misalnya rentang harga (FindNodeByRange).

## Guided 

### 1. File listBuah.h

```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif
```
File ini isinya deklarasi saja. Ada struct buah untuk data (nama, jumlah, harga), struct node yang menyimpan data dan pointer next, struct linkedlist yang punya pointer first, dan daftar prototype semua fungsi dan prosedur. Di Modul 5 ditambah prototype untuk update (updateFirst, updateLast, updateAfter) dan searching (FindNodeByData, FindNodeByAddress, FindNodeByRange). #ifndef di bagian atas gunanya supaya file ini tidak ke-include dua kali.

### 2. File listBuah.cpp

```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
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
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
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
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - UPDATE -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - SEARCHING -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```
File ini isi dari semua fungsi dan prosedur yang sudah dideklarasikan di header. Insert, delete, dan print masih materi Modul 4. Yang baru di Modul 5 adalah update dan searching. Prosedur update minta input data baru dari pengguna, lalu data di node yang dituju (pertama, terakhir, atau setelah node tertentu) diganti. Prosedur searching menelusuri list pakai node bantu sambil menghitung posisinya, lalu menampilkan node yang ketemu, atau pesan "tidak ditemukan" kalau tidak ada yang cocok.

### 3. File main.cpp

```C++
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    printList(List);
    updateLast(List);
    printList(List);
    updateAfter(List, nodeD);
    printList(List);
    
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;
    
    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);
    
    delFirst(List);
    printList(List);
    delLast(List);
    printList(List);
    delAfter(List, nodeD, nodeC);
    printList(List);

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
Di main, list buah dibuat lalu diisi lima node (Jeruk, Apel, Pir, Semangka, Durian) lewat operasi insert. Setelah itu dicoba update, searching (berdasarkan data, alamat, dan range harga), delete, dan terakhir hapus seluruh list. Tiap tahap menampilkan isi list dan jumlah node-nya.

## Unguided 

### 2. Buatlah ADT Singly Linked List di dalam file "Singlylist.h", implementasinya pada "Singlylist.cpp", lalu cobalah pada "main.cpp" (isi list: 9, 12, 8, 0, 2)

### 1. SinglyList.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

//no. 2 (ADT Singly Linked List)
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

// no. 3 (searching)
address findElm(List L, infotype x);

// no. 4 (menghitung total info)
int sumInfo(List L);

#endif
```
### 2. SinglyList.cpp
```C++
#include "Singlylist.h"
#include <iostream>
using namespace std;

void createList(List &L) {
    L.first = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    P->next = Nil;
    delete P;
    P = Nil;
}

void printInfo(List L) {
    if (L.first == Nil) {
        cout << "List kosong." << endl;
    } else {
        address P = L.first;
        while (P != Nil) {
            cout << P->info << " ";
            P = P->next;
        }
        cout << endl;
    }
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

/*----- LATIHAN NO. 3 - SEARCHING -----*/
//function untuk mencari node berdasarkan info
//mengembalikan address node jika ketemu, dan Nil jika tidak ada
address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

/*----- LATIHAN NO. 4 - TOTAL INFO -----*/
//function untuk menjumlahkan info seluruh node di dalam list
int sumInfo(List L) {
    int total = 0;
    address P = L.first;
    while (P != Nil) {
        total = total + P->info;
        P = P->next;
    }
    return total;
}
```
### 3. File main.cpp
```C++
#include "Singlylist.h"

#include <iostream>
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    //no. 2 : membuat list dan menampilkan isinya
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
    cout << endl;

    //Latihan no. 3 : mencari elemen dengan info 8
    address hasil = findElm(L, 8);
    if (hasil != Nil) {
        cout << hasil->info << " ditemukan dalam list" << endl;
    } else {
        cout << "8 tidak ditemukan dalam list" << endl;
    }
    cout << endl;

    //Latihan no. 4 : menghitung total info seluruh elemen
    cout << "Total info dari kelima elemen adalah " << sumInfo(L) << endl;

    return 0;
}
```


### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Sania220107/109082530026_Rista-Sania-Putri_StrukturData/blob/main/pertemuan5_modul5/Output%202_1.png?raw=true)



Di soal ini dibuat ADT singly linked list dengan infotype berupa int. Fungsi alokasi membuat node baru pakai new, lalu insertFirst menaruh node itu di awal list. Karena setiap node ditaruh di depan, angka yang dimasukkan terakhir (9) jadi node pertama. Makanya printInfo menampilkan 9 12 8 0 2, urutannya terbalik dari urutan input (2, 0, 8, 12, 9). Kode ini juga sudah berisi findElm dan sumInfo yang dijelaskan di nomor berikutnya.

### 3. Carilah elemen dengan info 8 dengan membuat fungsi baru findElm(L : List, x : infotype) : address


```C++
address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Sania220107/109082530026_Rista-Sania-Putri_StrukturData/blob/main/pertemuan5_modul5/Output%203_1.png?raw=true)



findElm jalan dari L.first pakai pointer bantu P. Di setiap node, P->info dicek apakah sama dengan x. Kalau sama, alamat node itu langsung dikembalikan. Kalau sampai ujung list tidak ada yang cocok, yang dikembalikan Nil. Di main, hasilnya dicek: kalau bukan Nil, tampil "8 ditemukan dalam list".

### 4. Hitunglah jumlah total info seluruh elemen (9+12+8+0+2=31)

```C++
int sumInfo(List L) {
    int total = 0;
    address P = L.first;
    while (P != Nil) {
        total = total + P->info;
        P = P->next;
    }
    return total;
}
```
### Output Unguided 4 :

##### Output 1
![Screenshot Output Unguided 4_1](https://github.com/Sania220107/109082530026_Rista-Sania-Putri_StrukturData/blob/main/pertemuan5_modul5/Output%204_1.png?raw=true)



sumInfo menelusuri semua node dari L.first sampai Nil. Di tiap node, P->info ditambahkan ke variabel total. Setelah selesai, total dikembalikan sebagai hasil fungsi, yaitu 9 + 12 + 8 + 0 + 2 = 31.

## Kesimpulan
Di praktikum ini saya belajar dua operasi lanjutan di singly linked list, yaitu update dan searching. Update cuma mengganti isi node, pointer-nya tidak diubah. Searching dilakukan dengan memeriksa node satu per satu pakai pointer bantu sampai data yang dicari ketemu atau list habis. Di latihan, ADT singly linked list dibuat dalam tiga file (header, implementasi, dan main), lalu ditambah fungsi findElm untuk mencari elemen dan sumInfo untuk menghitung total info semua elemen.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Mbejo, M. T., Nopa, L. A., Putri, J. S., & Risky, M. (2025). Analisis Struktur Data Linked List Dalam Pengolahan Data Mahasiswa. Jurnal Sains Informatika Terapan (JSIT), 4(2), 441-444. https://doi.org/10.62357/jsit.v4i2.591 
<br>[3] Lukman SD, A., Arya S, G., Putra I, M., & Devega, A. T. (2025). Analisis Komparatif Struktur Data Array Dan Linked List; Evaluasi Performa Dan Implementasi Optimal. Jurnal Sains Informatika Terapan (JSIT), 4(3), 854-858. https://doi.org/10.62357/jsit.v4i3.631 
<br>[4] Modul 5 Struktur Data: Singly Linked List (Bagian Kedua). Praktikum Struktur Data, Informatics Lab, Telkom University.