#include <stdlib.h>
#include <stdio.h>
#include "arraydin.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyArray(TabBangunan *T, int maxel)
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
{
    Neff(*T) = maxel;
    MaxElArray(*T) = maxel; 
    TI(*T) = (ElTypeArr *) malloc ((maxel+1) * sizeof(ElTypeArr));
}

void DealokasiArray(TabBangunan *T)
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
{
    free(TI(*T));
    MaxElArray(*T) = 0;
    Neff(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtTabArray(TabBangunan T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
    return Neff(T);
}

int MaxElement(TabBangunan T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
{
    return MaxElArray(T);
}

IdxType GetFirstIdx(TabBangunan T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
    return IdxMin;
}

IdxType GetLastIdx(TabBangunan T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
    return(IdxMin + Neff(T) - 1);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidArray(TabBangunan T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return (i>= IdxMin && i<=MaxElArray(T));
}
boolean IsIdxEffArray(TabBangunan T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    return (i>=GetFirstIdx(T) && i<=GetLastIdx(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArray(TabBangunan T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
{
    return (Neff(T) == 0);
}
boolean IsFullArray(TabBangunan T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return (Neff(T) == MaxElArray(T));
}



/* ********** OPERASI LAIN ********** */
void CopyTab(TabBangunan Tin, TabBangunan *Tout)
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */
{
    MakeEmptyArray(Tout, MaxElArray(Tin));
    printf("lalala\n");
    Neff(*Tout) = Neff(Tin);
    IdxType i = GetFirstIdx(Tin);
    //PrintBangunan(ElmtTab(Tin, 1));
    for (i ; i <= GetLastIdx(Tin) ; i++){
        //ElmtTab(*Tout, i) = ElmtTab(Tin, i);
        //PrintBangunan(ElmtTab(Tin, i));
        CopyBangunan(ElmtTab(Tin, i), &ElmtTab(*Tout,i));
    }
}


/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabBangunan *T, ElTypeArr X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
    if (IsEmptyArray(*T)) {
        ElmtTab(*T, GetFirstIdx(*T)) = X;  
    } else {
        ElmtTab(*T, GetLastIdx(*T)+1) = X;
    }
    Neff(*T) += 1;
}

void PrintAllBangunan(TabBangunan B)
{
    int pertahanan;
    int serang;
    int netral;
    int move;
    
    for (int i = 1 ; i <= GetLastIdx(B) ; i++){
        if (Pertahanan(ElmtTab(B, i))){
            pertahanan = 1;
        } else { pertahanan = 0; }
        if (Serang(ElmtTab(B, i))){
            serang = 1;
        } else { serang = 0; }
        if (Netral(ElmtTab(B, i))){
            netral = 1;
        } else { netral = 0; }
        if (Move(ElmtTab(B, i))){
            move = 1;
        } else { move = 0; }
        printf("%d. %c | (%d,%d) | Pasukan : %d | Level : %d | A : %d | M : %d | Pertahanan : %d | Serang : %d | Netral : %d | Move : %d \n", 
        i, Type(ElmtTab(B, i)), Absis(Posisi(ElmtTab(B, i))), Ordinat(Posisi(ElmtTab(B, i))), Pasukan(ElmtTab(B, i)), Level(ElmtTab(B, i)),
        A(ElmtTab(B, i)), M(ElmtTab(B, i)), pertahanan, serang, netral, move);
    }

}


