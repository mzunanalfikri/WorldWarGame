//Muhammad Zunan Alfikri
//1 November 2019


#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return (Head(Q) == Nil && Tail(Q) == Nil);
}

boolean IsFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return ( Head(Q) - Tail(Q) == 1 | Tail(Q) - Head(Q) + 1 == MaxEl(Q));
}

int NBElmt (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    if (IsEmpty(Q)){
        return 0;
    }else if (Tail(Q) > Head(Q)){
        return (Tail(Q)-Head(Q)+1);
    } else if (Tail(Q) < Head(Q)){
        return(MaxEl(Q) - (Head(Q) - Tail(Q) - 1));
    }
}

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    MaxEl(*Q) = Max;
    (*Q).T = (infotype *) malloc ((Max+1) * sizeof(int));
}

/* *** Destruktor *** */
void DeAlokasi(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    MaxEl(*Q) = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
    if (IsEmpty(*Q)){
        Tail(*Q) = 1;
        Head(*Q) = 1;
        InfoTail(*Q) = X;
    } else if (Tail(*Q) == MaxEl(*Q)){
        Tail(*Q) = 1;
        InfoTail(*Q) = X;
    } else {
        Tail(*Q) += 1;
        InfoTail(*Q) = X;
    }
}

void Del (Queue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
{
    if (Tail(*Q) == Head(*Q)){
        *X = InfoHead(*Q);
        Tail(*Q) = Nil;
        Head(*Q) = Nil;
    } else if (Head(*Q) == MaxEl(*Q)){
        *X = InfoHead(*Q);
        Head(*Q) = 1;
    } else {
        *X = InfoHead(*Q);
        Head(*Q) += 1;
    }
}