#include "stackt.h"
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
    // KAMUS
    State NeoState;

    // ALGORITMA
    MakeState(&NeoState, MaxElArray(ArrayBangunan(X)));
    CopyState(X, &NeoState);
    Top(*S)++;
    InfoTop(*S) = NeoState;
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
    /* Membuat copy dari Sin pada *Sout
    I.S. Sin terdefisi, *Sout sembarang
    F.S. StackState *Sout berisi salinan Sin */
    StackState Temp;
    State X,Y;
    CreateEmptyStackState(Sout);
    CreateEmptyStackState(&Temp);
    while(!IsEmptyStackState(Sin)){
        PopState(&Sin,&X);
        PushState(&Temp,X);
    }
    while(!IsEmptyStackState(Temp)){
        PopState(&Temp,&Y);
        PushState(Sout,Y);
    }
}

void EndTurnState(StackState* Sin){
    /* Menghapus semua state pada StackState Sin kecuali state paling atas
    I.S. Sin tidak kosong
    F.S. Sin hanya berisi State paling atas-nya saja */
    //StackState X;
    State Final = InfoTop(*Sin);
    State Final_Copy;
    State Temp;

    MakeState(&Final_Copy, MaxElArray(ArrayBangunan(Final)));
    CopyState(Final, &Final_Copy);
    //CreateEmptyStackState(&X);
    //PushState(&X,Final);
    while(!IsEmptyStackState(*Sin)){
        PopState(Sin,&Temp);
        DealokState(&Temp);
    }
    PushState(Sin,Final_Copy);
}

void Undo(StackState *S){
    /* Melakukan Undo (Mengahpus state teratas pada stack jika stack tidak menjadi kosong)
    I.S. Stack S tidak kosong
    F.S. State teratas Stack S dihapus jika jumlah elemen Stack S > 1, jika tidak maka Stack S tetap */
    State XTemp;
    PopState(S, &XTemp);


    if (IsEmptyStackState(*S)) {
        PushState(S, XTemp);
        printf("Anda tidak dapat membatalkan (Undo) hingga sebelum giliran Anda dimulai, atau hingga sebelum dunia berubah karena kekuatan Skill Anda.\n");
    } else {
        DealokState(&XTemp);
        printf("Aksi Anda yang sebelumnya telah dibatalkan (Undo).\n");
    }
}