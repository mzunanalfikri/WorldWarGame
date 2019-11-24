/* File: mesinkar.h */
/* Realisasi Mesin Karakter */


#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "boolean.h"

//#define MARK '.'
#define MARK EOF
/* State Mesin */
extern char CC;
extern boolean EOP;


void START();
/* Mesin siap dioperasikan. Pita dengan nama file 'Default' disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : 'Default' terdefinisi dan ada filenya
   F.S. : Membuka file 'Default'. CC adalah karakter pertama pada pita.
          Apabila pita langsung sampai terakhir, maka EOP=true; selainnya
          EOP=false*/

void STARTcmd();
/* I.S. : Input user terdefinisi
   F.S. : Memulai membaca input user pada layar */

void STARTload(char save_file[]);
/* I.S. : File yang ingin di load terdefinisi
   F.S. : Memulai load file pada file yang dipilih */


void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = CC
   F.S. : CC adalah karakter berikutnya dari CC yang lama. Apabila pita telah sampai 
          akhir, EOP=true */
 

void FINISH();
/* Menutup pita dengan nama file 'Default'
   I.S. : Pita 'Default' dibuka
   F.S. : Pita 'Default' ditutup */

#endif
