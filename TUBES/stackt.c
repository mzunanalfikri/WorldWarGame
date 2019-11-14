#include "stackt.h"
#include "state.h"
#include "stdio.h"
#include "stdlib.h"


/* *** Konstruktor/Kreator *** */
void CreateEmptyStackState (StackState *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElStack */
/* jadi indeksnya antara 1.. MaxElStack+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
{
    Top(*S) = 0;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStackState (StackState S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return (Top(S) == 0);
}

boolean IsFullStackState (StackState S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return (Top(S) == MaxState);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushState (StackState * S, State X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
        Top(*S)++;
        InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void PopState (StackState * S, State* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    *X = InfoTop(*S);
    Top(*S)--;
}

void CopyStackState(StackState Sin, StackState *Sout){
    State Temp;
    State X,Y;
    CreateEmptyStack(Sout);
    CreateEmptyStack(&Temp);
    while(!IsEmptyStack(Sin)){
        Pop(&Sin,&X);
        Push(&Temp,X);
    }
    while(!IsEmptyStack(Temp)){
        Pop(&Temp,&Y);
        Push(Sout,Y);
    }
}
