#include "matriks.h"
#include <stdio.h>
#include <stdlib.h>

/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
    for(indeks i=BrsMin;i<=NBrsEff(*M);i++){
        for(indeks j=KolMin;j<=NKolEff(*M);j++){
            ElmtMatriks(*M,i,j) = ' ';
        }
    }
    
}
/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValidMatriks (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
    return ((i>=BrsMin) && (i<=BrsMax) && (j>=KolMin) && (j<=KolMax));
}
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
    return (BrsMin);
}
indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
    return (KolMin);
}
indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
    return (BrsMin + NBrsEff(M) - 1);
}
indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
    return (KolMin + NKolEff(M) - 1);
}
boolean IsIdxEffMatriks (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
    return ((i>0) && (j>0) && (i <= GetLastIdxBrs(M)) && (j <= GetLastIdxKol(M)));
}
ElTypeMatriks GetElmtMatriksDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
    return (ElmtMatriks(M,i,i));
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
    /* KAMUS LOKAL */
    indeks i,j;

    /* ALGORITMA */
    NBrsEff(*MHsl) = GetLastIdxBrs(MIn);
    NKolEff(*MHsl) = GetLastIdxKol(MIn);

    for (i=BrsMin;i<=NBrsEff(*MHsl);i++)
    {
        for (j=KolMin;j<=NKolEff(*MHsl);j++)
        {
            ElmtMatriks(*MHsl,i,j) = ElmtMatriks(MIn,i,j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK){
     /* KAMUS LOKAL */
    indeks i,j;
    ElTypeMatriks x;

    /* ALGORITMA */
    if (IsIdxValidMatriks(NB,NK))
    {
        MakeMATRIKS(NB,NK,M);
        for (i=BrsMin;i<=NB;i++)
        {
            for (j=KolMin;j<=NK;j++)
            {
                scanf("%c",&x);
                ElmtMatriks(*M,i,j) = x;
            }
        }
    }
}

void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    /* KAMUS LOKAL */
    for(int i=1;i<=NKolEff(M)+2;i++){
        printf("*");
    }
    printf("\n");
    for(indeks j=GetFirstIdxBrs(M);j<=NBrsEff(M);j++){
        printf("*");
        for(indeks k=GetFirstIdxKol(M);k<=(NKolEff(M));k++){
            printf("%c", ElmtMatriks(M, j, k));
        }
        printf("*\n");
    }
    //printf("\n");
    for(int l=1;l<=NKolEff(M)+2;l++){
        printf("*");
    }
}
