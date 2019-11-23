
#include "listlinier.h"
#include<stdio.h>
#include<stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList (List L)
/* Mengirim true jika list kosong */
{
    return (First(L)==NULL);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    First(*L) = NULL;
}

/****************** Manajemen Memori ******************/
addresslist Alokasi (infotype X)
/* Mengirimkan addresslist hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addresslist tidak NULL, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
{
    addresslist P;
    P = (addresslist) malloc (sizeof(ElmtList));
    if (P != NULL)
    {
        Info(P) = X;
        Next(P) = NULL;
        return P;
    }
    else
    {
        return NULL;
    }
}

void DealokasiList (addresslist P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addresslist P */
{
    free(P);
}

void DealokasiAllList (List ListP)
// I.S. ListP terdifinisi
// F.S. Seluruh element di list ListP dikembalikan ke sistem
    {
        // KAMUS
        addresslist P, PNext;

        // ALGORITMA
        P = First(ListP);
        PNext = Next(P);

        while (P != NULL) {
            DealokasiList(P);
            P = PNext;
            if (PNext != NULL) {
                PNext = Next(PNext);
            }
        }
        
    }

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addresslist Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan addresslist elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */
{
    // KAMUS LOKAL
    addresslist P;
    boolean Found;

    // ALGORITMA
    P = First(L);
    Found = false;

    while ((P != NULL) && (!Found))
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

boolean SearchB (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan true. */
/* Jika tidak ada, mengirimkan false */
{
     // KAMUS LOKAL
    addresslist P;
    boolean Found;

    // ALGORITMA
    P = First(L);
    Found = false;

    while ((P != NULL) && (!Found))
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
    return Found;
}

/****************** PRIMITIF BERDASARKAN NULLAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan NULLai X jika alokasi berhasil */
{
    addresslist P;
    P = Alokasi(X);
    //printf("\nlalala33");
    if (P != NULL)
    {
        Next(P) = First(*L);
        First(*L) = P;
    }
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* berNULLai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    addresslist P,Last;

    P = Alokasi(X);
    if (P != NULL)
    {
        if (IsEmptyList(*L))
        {
            Next(P) = First(*L);
            First(*L) = P;
        }
        else
        {
            Last = First(*L);
            while (Next(Last) != NULL)
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
/* F.S. Elemen pertama list dihapus: NULLai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    addresslist P;

    P = First(*L);
    First(*L) = Next(P);
    Next(P) = NULL;
    *X = Info(P);

    DealokasiList(P);
}

void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: NULLai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    addresslist Prec,Last;

    Prec = NULL;
    Last = First(*L);

    while (Next(Last) != NULL)
    {
        Prec = Last;
        Last = Next(Last);
    }
    *X = Info(Last);

    if (Prec == NULL)
    {
        First(*L) = NULL;
    }
    else
    {
        Next(Prec) = NULL;
    }
    DealokasiList(Last);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, addresslist P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addresslist P sebagai elemen pertama */
{
    Next(P) = First(*L);
    First(*L) = P;
}


void InsertAfter (List *L, addresslist P, addresslist Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (List *L, addresslist P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    addresslist Last;

    if (IsEmptyList(*L))
    {
		InsertFirst(L,P);
	}
	else
    {
        Last = First(*L);
        while (Next(Last) != NULL)
        {
            Last = Next(Last);
        }
        Next(P) = NULL;
        Next(Last) = P;
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, addresslist *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L);
    if (Next(*P) == NULL)
    {
        First(*L) = NULL;
    }
    else
    {
        First(*L) = Next(First(*L));
    }
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddresslist P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info berNULLai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    addresslist P,Prec;

    P = Search(*L,X);
    if (P != NULL)
    {
        if(P == First(*L))
        {
            DelFirst(L,&P);
            P = NULL;
        }
        else
        {
            Prec = First(*L);
            while (Next(Prec) != P)
            {
                Prec = Next(Prec);
            }
            Next(Prec) = Next(P);
            P = NULL;
        }

        DealokasiList(P);
    }
}

void DelLast (List *L, addresslist *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    addresslist Prec,Last;

    Prec = NULL;
    Last = First(*L);

    while(Next(Last) != NULL)
    {
        Prec = Last;
        Last = Next(Last);
    }

    *P = Last;
    if (Prec == NULL)
    {
        First(*L) = NULL;
    }
    else
    {
        Next(Prec) = NULL;
    }
}

void DelAfter (List *L, addresslist *Pdel, addresslist Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = NULL;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen berNULLai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    addresslist P;

    printf("[");

    if (!IsEmptyList(L))
    {
        P = First(L);
        while (Next(P) != NULL)
        {
            printf("%d,",Info(P));
            P = Next(P);
        }
        printf("%d",Info(P));
    }

    printf("]");
    printf("\n");
}

int NbElmtList (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    addresslist P;
    int Count;

    // ALGORITMA
    P = First(L);
    Count = 0;
    while (P != NULL)
    {
        Count++;
        P = Next(P);
    }

    return Count;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan NULLai Info(P) yang maksimum */
{
    addresslist P;
    infotype max;

    P = Next(First(L));
    max = Info(First(L));
    while (P != NULL)
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
    addresslist P;

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

void CopyList(List Lin, List * Lout)
/* I.S. Lout sembarang */
/* F.S Terbentuk salinan Lin di Lout */
{
    addresslist P;
    infotype temp;
    CreateEmptyList(Lout);
    P = First(Lin);
    while(P!=NULL){
        InsVLast(Lout, Info(P));
        P=Next(P);
    }

    // while(!IsEmptyList(Lin)){
    //     DelVFirst(&Lin, &temp);
    //     InsVLast(Lout, temp);
    //     //DelFirst(&Lin,&P);
	// 	//InsertLast(Lout,P);
    // }
}
