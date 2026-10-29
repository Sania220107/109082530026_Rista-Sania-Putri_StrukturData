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