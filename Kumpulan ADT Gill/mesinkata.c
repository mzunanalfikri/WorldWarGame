/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */


#include "mesinkata.h"
#include <stdio.h>

/* State Mesin Kata */
boolean EndKata;
Kata CKata;

void IgnoreBlank(){
    while((CC==BLANK)&&(CC!=MARK)){
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTKATA(){
    EndKata = false;
    START();
    IgnoreBlank();
    ADVKATA();
}
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA(){
    IgnoreBlank();
    if(CC==MARK){
        EndKata = true;
    }else{
        SalinKata();
        IgnoreBlank();
    }
}
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata(){
    boolean jalan;
    int i;

    i=1;
    jalan = true;

    while((jalan) && (i<=NMax)){
        if(CC==MARK || CC==BLANK){
            jalan=false;
        }else{
            CKata.TabKata[i]=CC;
            ADV();
            i++;            
        }
    }
    CKata.Length = i-1;

}
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

