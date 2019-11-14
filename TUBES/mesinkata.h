/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "mesinkar.h"

#define NMax 50
#define BLANK ' '
#define ENTER '\n'

typedef struct {
  char TabKata[NMax+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
  int Length;
} Kata;

/* State Mesin Kata */
extern Kata CKata;

void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK */

void STARTKATA();
/* I.S. : CC sembarang, 'Default' terdefinisi dan ada filenya
   F.S. : CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void STARTKATAcmd();
/* membaca kata dari cmd */

void ADVKATA();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau EndPita = true;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void CopyKata(Kata* clone, Kata ori);
	/* Menyalin kata
   I.S. : clone sembarang, ori sebuah kata yang valid
   F.S. : clone merupakan kata dengan panjang yang sama dengan ori
          dan tiap karakter clone sama dengan ori */
  

/* Operasi Mesinkata */
	
int KataToInt(Kata DefKata);
	/* Mengubah kata yang ada dalam CKata menjadi sebuah nilai dalam integer
	 I.S : DefKata terdefinisi
	 F.S : Nilai DefKata sudah dalam bentuk integer dan terdefinisi */
	 
char CommandToChar(Kata CKata);

void TulisCKata();
/* Untuk Mencetak Ckata */

boolean IsEQCKata(char kata[20]);
/* mengembalikan true jika kata sama dengan CKata */

#endif
