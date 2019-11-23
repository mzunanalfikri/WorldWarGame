/* File: mesinkar.c */
/* Realisasi Mesin Karakter */

#include "mesinkar.h"
#include <stdio.h>

char CC;
boolean EOP;

static FILE * pita;
static int retval;

void START() {
/* Mesin siap dioperasikan. Pita dengan nama file 'NamaFile' disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : 'NamaFile' terdefinisi dan ada filenya
   F.S. : Membuka file 'NamaFile'. CC adalah karakter pertama pada pita.
          Apabila pita langsung sampai terakhir, maka EndPita=true; selainnya
          EndPita=false*/

    /* Algoritma */
    pita = fopen("datatest1.txt", "r");
    EOP=false;
    ADV();
}

void STARTcmd() {
    /* Algoritma */
    pita = stdin;
    EOP=false;
    ADV();
}

void STARTload(char save_file[]) {
    /* Algoritma */
    pita = fopen(save_file, "r");
    EOP=false;
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
        EOP=true;
        FINISH();
    }
}

void FINISH(){
/* Menutup pita dengan nama file 'NamaFile'
   I.S. : Pita 'NamaFile' telah dibuka
   F.S. : Pita 'NamaFile' ditutup */
    fclose(pita);
}
