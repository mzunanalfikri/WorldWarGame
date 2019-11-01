/* File: mesinkar.c */
/* Realisasi Mesin Karakter */

#include "mesinkar.h"
#include <stdio.h>

char CC;
boolean EndPita;

static FILE * pita;
static int retval;

void START(char NamaFile[]) {
/* Mesin siap dioperasikan. Pita dengan nama file 'NamaFile' disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : 'NamaFile' terdefinisi dan ada filenya
   F.S. : Membuka file 'NamaFile'. CC adalah karakter pertama pada pita.
          Apabila pita langsung sampai terakhir, maka EndPita=true; selainnya
          EndPita=false*/

    /* Algoritma */
    pita = fopen(NamaFile,"r");
    EndPita=false;
    ADV();
}

void ADV() {
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = CC
   F.S. : CC adalah karakter berikutnya dari CC yang lama. Apabila pita telah sampai 
          akhir, EndPita=true */
    /* Algoritma */
    retval = fscanf(pita,"%c",&CC);
    if (retval==-1){
        EndPita=true;
        FINISH();
    }
}

void FINISH(){
/* Menutup pita dengan nama file 'NamaFile'
   I.S. : Pita 'NamaFile' telah dibuka
   F.S. : Pita 'NamaFile' ditutup */
    fclose(pita);
}