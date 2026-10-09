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