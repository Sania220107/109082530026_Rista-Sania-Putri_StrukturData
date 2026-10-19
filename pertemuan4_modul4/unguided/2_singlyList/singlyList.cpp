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