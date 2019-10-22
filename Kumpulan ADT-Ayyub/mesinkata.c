#include "mesinkata.h"
#include <stdio.h>

boolean EndKata;
Kata CKata;

/* State Mesin Kata */

void IgnoreBlank(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
    while ((CC == BLANK) && (CC != MARK)) {
        ADV();
    }
}

void STARTKATA(){
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
    START();
    IgnoreBlank();
    if (CC == MARK) {
        EndKata = true;
    } else /* CC != MARK */ {
        EndKata = false;
        SalinKata();
    }
}

void ADVKATA(){
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
    if (CC == MARK) {
        EndKata = true;
    } else /* CC != MARK */ {
        SalinKata();
        IgnoreBlank();
    }
}

void SalinKata(){
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
          int i = 1; /* inisialisasi */
    /* Algoritma*/
    while ((CC != MARK) && (CC != BLANK) && (i <= NMax)) {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    } /* CC = MARK or CC = BLANK */
    CKata.Length = i-1;
}
