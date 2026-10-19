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