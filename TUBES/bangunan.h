/*
Properti ADT Bangunan :
    Id
    Kepemilikan {tidak perllu, sudah ada di list}
2. Type
3. Jumlah Pasukan
4. Level
5. A (Nilai Penambahan Pasukan)
6. M (Maksimum Penambahan Pasukan)
7. P (Pertahanan)
     U (Pasukan Awal) {tidak perlu, karena hanya di awal}
8. Posisi
9. Serang (false jika belom menyerang, true jika sudah menyerang)
10. Netral (true jika bangunan tidak dimiliki siapapun)
*/

#ifndef BANGUNAN_H
#define BANGUNAN_H

#include "boolean.h"
#include "point.h"

typedef struct {
    char Type;
    int Pasukan;
    int Level;
    int A;
    int M;
    boolean Pertahanan;
    POINT Posisi;
    boolean Serang;
    boolean Netral;
} Bangunan;

/* Akses dengan Selektor */
#define Type(B) (B).Type
#define Pasukan(B) (B).Pasukan
#define Level(B) (B).Level
#define A(B) (B).A
#define M(B) (B).M
#define Pertahanan(B) (B).Pertahanan
#define Posisi(B) (B).Posisi
#define Serang(B) (B).Serang
#define Netral(B) (B).Netral

/* ************** Prototype ************** */
Bangunan MakeBangunanLv1 (char type, POINT P);
/* I.S. Sembarane */
/* F.S. Membuat sebuah bangunan default level 1 (digunakan pada awal load file) */

boolean IsNaikLevel (Bangunan B);
/* Mengirim True jika bangunan siap naik level */

void NaikLevel (Bangunan *B);
/* I.S Bangunan valid untuk naik level (bisa naik level) */
/* F.S Bangunan naik 1 level dengan pertambahan 
        pasukan sesuai dengan levelnya */

void AddNextTurn (Bangunan * B);
/* I.S Bangunan terdefinisi */
/* F.S Bangunan betambah pasukannya sesuai level seteah turn */

void CopyBangunan (Bangunan BIn, Bangunan * BHsl );
/*Melakukan assignment MHsl dgn MIn */

void PrintBangunan (Bangunan B);
/* I.S Sembarang */
/* F.S Tercetak di layar info bangunannya */

#endif