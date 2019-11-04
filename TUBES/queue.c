#include "queue.h"
#include "stdio.h"
#include "stdlib.h"

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return (Head(Q) == 0 && Tail(Q) == 0);
}
boolean IsFullQueue (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxElQueue */
{
    return ((Head(Q) - Tail(Q) + 1)% MaxElQueue(Q) == 0 );
}
int NBElmt (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    if (IsEmpty(Q))
    {
        return 0;
    }
    else // queue tidak kosaong
    {
        if (Head(Q) <= Tail(Q))
        {
            return (Tail(Q) - Head(Q) +1);
        }
        else // head leih besar dari tail
        {
            return (MaxElQueue(Q) - (Head(Q) - Tail(Q)) +1);
        }
    }
}

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxElQueue=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    // Alokasi queue kedalam memori
    (*Q).T = (infotype *) malloc ((Max+1) * sizeof(infotype));

    // Mengeset queue yang akan dibuat
    if ((*Q).T != NULL)
    {
        MaxElQueue(*Q) = Max;
        Head(*Q) = 0;
        Tail(*Q) = 0;
    }
    else // Jika alokasi gagal
    {
        MaxElQueue(*Q) = 0;
    }
}

/* *** Destruktor *** */
void DeAlokasi(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxElQueue(Q) diset 0 */
{
    MaxElQueue(*Q) = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
    // KAMUS LOKAL

    // ALGORITMA
    if (IsEmpty(*Q))
    {
        Head(*Q) = 1;
        Tail(*Q) = 1;
        InfoTail(*Q)=X;
    }
    else if (Tail(*Q) != MaxElQueue(*Q))
    {
        Tail(*Q)++;
        InfoTail(*Q)=X;

    }
    else // Tail = indeks akhir
    {
        Tail(*Q) = 1;
        InfoTail(*Q)=X;

    }
}
void Del (Queue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = 0ai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    *X = InfoHead(*Q);
    if (Head(*Q)== Tail(*Q))  /* Set mjd queue kosong */
    {
        Head(*Q)=0;
        Tail(*Q)=0;
    }
    else if (Head(*Q) != MaxElQueue(*Q))
    {
        Head(*Q)++;
    }
    else // Head sama dengan indeks terakhir
    {
        Head(*Q) = 1;
    }
}

void CopyQueue (Queue Q1 ,Queue *Q2){
    Queue Temp;
    infotype X,Y;
    CreateEmpty(&Temp,NBElmt(Q1));
    CreateEmpty(&Q2,NBElmt(Q1));
    while(!IsEmpty(Q1)){
        Del(&Q1,&X);
        Add(&Temp,X);
    }
    while(!IsEmpty(Temp)){
        Del(&Temp,&Y);
        Add(&Q2,Y);
    }
}


