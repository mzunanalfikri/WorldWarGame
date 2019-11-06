#include "stackt.h"
#include "stdio.h"
#include "stdlib.h"


/* *** Konstruktor/Kreator *** */
void CreateEmptyStack (Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElStack */
/* jadi indeksnya antara 1.. MaxElStack+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
{
    Top(*S) = 0;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return (Top(S) == 0);
}
boolean IsFullStack (Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return (Top(S) == MaxElStack);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, infotype X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
        Top(*S)++;
        InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, infotype* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    *X = InfoTop(*S);
    Top(*S)--;
}
void PrintStack(Stack S){
    infotype X;
    while(!IsEmptyStack(S)){
        Pop(&S,&X);
        printf("%d " , X);
    }
    printf("\n");

}
void CopyStack(Stack Sin, Stack *Sout){
    Stack Temp;
    infotype X,Y;
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
