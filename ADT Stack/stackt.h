/* File : stackt.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackt_H
#define stackt_H

#include "boolean.h"
#include "../ADT State/state.h"

#define MaxState 100
/* Nil adalah stack dengan elemen kosong . */
/* Karena indeks dalam bhs C dimulai 0 maka tabel dg indeks 0 tidak dipakai */

typedef int address;   /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct {
	State T[MaxState +1]; /* tabel penyimpan elemen */
	address TOP;  /* alamat TOP: elemen puncak */
} StackState;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai State T[1]..T[MaxState] */
/* Jika S adalah StackState maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStackState (StackState *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElStackState */
/* jadi indeksnya antara 1.. MaxElStackState+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStackState (StackState S);
/* Mengirim true jika StackState kosong: lihat definisi di atas */

boolean IsFullStackState (StackState S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke StackState ************ */
void PushState (StackState * S, State X);
/* Menambahkan X sebagai elemen StackState S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen StackState ************ */
void PopState (StackState * S, State* X);
/* Menghapus X dari StackState S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void CopyStackState(StackState Sin, StackState *Sout);
/* Membuat copy dari Sin pada *Sout
    I.S. Sin terdefisi, *Sout sembarang
    F.S. StackState *Sout berisi salinan Sin */

void EndTurnState(StackState* Sin);
/* Menghapus semua state pada StackState Sin kecuali state paling atas
    I.S. Sin tidak kosong
    F.S. Sin hanya berisi State paling atas-nya saja */

void Undo(StackState *S);
/* Melakukan Undo (Mengahpus state teratas pada stack jika stack tidak menjadi kosong)
    I.S. Stack S tidak kosong
    F.S. State teratas Stack S dihapus jika jumlah elemen Stack S > 1, jika tidak maka Stack S tetap */

#endif
