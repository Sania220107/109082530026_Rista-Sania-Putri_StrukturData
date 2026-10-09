#ifndef ARRAY_PTR_H_INCLUDED
#define ARRAY_PTR_H_INCLUDED

// menampilkan isi sebuah array integer 2D 3x3
void tampilArray(int arr[3][3]);

// menukarkan isi array A dan B pada posisi (baris, kolom) tertentu
void tukarArray(int A[3][3], int B[3][3], int baris, int kolom);

// menukarkan isi variabel yang ditunjuk oleh 2 pointer
void tukarPointer(int *p1, int *p2);

#endif // ARRAY_PTR_H_INCLUDED