
#include "listlinier.h"
#include<stdio.h>
#include<stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList (List L)
/* Mengirim true jika list kosong */
{
    return (First(L)==Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    address P;
    P = (address) malloc (sizeof(ElmtList));
    if (P != Nil)
    {
        Info(P) = X;
        Next(P) = Nil;
        return P;
    }
    else
    {
        return Nil;
    }
}

void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    // KAMUS LOKAL
    address P;
    boolean Found;

    // ALGORITMA
    P = First(L);
    Found = false;

    while ((P != Nil) && (!Found))
    {
        if (Info(P) == X)
        {
            Found = true;
        }
        else
        {
            P = Next(P);
        }
    }

    return P;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address P;

    P = Alokasi(X);
    if (P != Nil)
    {
        Next(P) = First(*L);
        First(*L) = P;
    }
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address P,Last;

    P = Alokasi(X);
    if (P != Nil)
    {
        if (IsEmptyList(*L))
        {
            Next(P) = First(*L);
            First(*L) = P;
        }
        else
        {
            Last = First(*L);
            while (Next(Last) != Nil)
            {
                Last = Next(Last);
            }
            Next(Last) = P;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address P;

    P = First(*L);
    First(*L) = Next(P);
    Next(P) = Nil;
    *X = Info(P);

    Dealokasi(&P);
}

void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address Prec,Last;

    Prec = Nil;
    Last = First(*L);

    while (Next(Last) != Nil)
    {
        Prec = Last;
        Last = Next(Last);
    }
    *X = Info(Last);

    if (Prec == Nil)
    {
        First(*L) = Nil;
    }
    else
    {
        Next(Prec) = Nil;
    }
    Dealokasi(&Last);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    Next(P) = First(*L);
    First(*L) = P;
}


void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    address Last;

    if (IsEmptyList(*L))
    {
		InsertFirst(L,P);
	}
	else
    {
        Last = First(*L);
        while (Next(Last) != Nil)
        {
            Last = Next(Last);
        }
        Next(P) = Nil;
        Next(Last) = P;
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L);
    if (Next(*P) == Nil)
    {
        First(*L) = Nil;
    }
    else
    {
        First(*L) = Next(First(*L));
    }
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address P,Prec;

    P = Search(*L,X);
    if (P != Nil)
    {
        if(P == First(*L))
        {
            DelFirst(L,&P);
            P = Nil;
        }
        else
        {
            Prec = First(*L);
            while (Next(Prec) != P)
            {
                Prec = Next(Prec);
            }
            Next(Prec) = Next(P);
            P = Nil;
        }

        Dealokasi(&P);
    }
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    address Prec,Last;

    Prec = Nil;
    Last = First(*L);

    while(Next(Last) != Nil)
    {
        Prec = Last;
        Last = Next(Last);
    }

    *P = Last;
    if (Prec == Nil)
    {
        First(*L) = Nil;
    }
    else
    {
        Next(Prec) = Nil;
    }
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    address P;

    printf("[");

    if (!IsEmptyList(L))
    {
        P = First(L);
        while (Next(P) != Nil)
        {
            printf("%d,",Info(P));
            P = Next(P);
        }
        printf("%d",Info(P));
    }

    printf("]");
}

int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    address P;
    int Count;

    // ALGORITMA
    P = First(L);
    Count = 0;
    while (P != Nil)
    {
        Count++;
        P = Next(P);
    }

    return Count;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
    address P;
    infotype max;

    P = Next(First(L));
    max = Info(First(L));
    while (P != Nil)
    {
        if (max < Info(P))
        {
            max = Info(P);
        }
        P = Next(P);
    }

    return max;
}

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    address P;

    CreateEmptyList(L3);

    while (!IsEmptyList(*L1))
    {
		DelFirst(L1,&P);
		InsertLast(L3,P);
	}
	while (!IsEmptyList(*L2))
	{
		DelFirst(L2,&P);
		InsertLast(L3,P);
	}
}