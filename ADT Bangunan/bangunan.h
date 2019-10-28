/*
Properti ADT Bangunan :
1. Id
    Kepemilikan {tidak perllu, sudah ada di list}
2. Type
3. Jumlah Pasukan
4. Level
5. A (Nilai Penambahan Pasukan)
6. M (Maksimum Penambahan Pasukan)
7. P (Pertahanan)
     U (Pasukan Awal) {tidak perlu, karena hanya di awal}
8. Posisi
*/

#ifndef BANGUNAN_H
#define BANGUNAN_H

#include "boolean.h"
#include "point.h"

typedef struct {
    int Id;
    char Type;
    int Pasukan;
    int Level;
    int A;
    int M;
    boolean P;
    POINT Posisi;
} Bangunan;

/* Akses dengan Selektor */
#define Id(B)       (B).Id
#define Type(B)     (B).Type
#define Pasukan(B)  (B).Pasukan
#define Level(B)    (B).Level
#define A(B)        (B).A
#define M(B)        (B).M
#define P(B)        (B).P
#define Posisi(B)   (B).Posisi

void MakeBangunan (Bangunan * B, char type, POINT P);
boolean IsNaikLevel (Bangunan B);
void NaikLevel (Bangunan *B);
void AddNextTurn (Bangunan * B);
void PrintBangunan (Bangunan B);

#endif