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