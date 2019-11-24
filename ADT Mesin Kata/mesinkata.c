
#include "mesinkata.h"
#include <stdio.h>
#include <stdlib.h>

boolean EndKata = false;
Kata CKata;
extern char CC;


void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
   {
       while ((CC == BLANK || CC == ENTER) && (CC != MARK)) {
           ADV();
       }

       if (CC == MARK) {
           EndKata = true;
       }
       
   }

void STARTKATA()
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
    {
        START();
        IgnoreBlank();

        if (CC == MARK) {
            EndKata = true;
        } else {
            EndKata = false;
            SalinKata();
        }
    }

void ReadCmd(){
/* I.S. : Input dari user terdefinisi
   F.S. : Membaca masukan input dari user dan menyalinnya dalam CKata */
    STARTcmd();
        IgnoreBlank();

        if (CC == MARK) {
            EndKata = true;
        } else {
            EndKata = false;
            SalinKata();
        }
}

void LoadFile(char save_file[]){
/* I.S. : File yang ingin di Load terdefinisi
   F.S. : Membuka file dengan directory default  */
    STARTload(save_file);
        IgnoreBlank();

        if (CC == MARK) {
            EndKata = true;
        } else {
            EndKata = false;
            SalinKata();
        }
}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
    {
        IgnoreBlank();

        if (CC == MARK) {
            EndKata = true;
        } else {
            SalinKata();
            IgnoreBlank();
        }
    }

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    {
        // KAMUS
        int i;

        // ALGORITMA
        i = 1;
        
        while ((CC != MARK) && (CC != BLANK) && (i <= NMax) && (CC != ENTER)) {
            CKata.TabKata[i] = CC;
            ADV();
            i++;    
        };

        CKata.Length = i-1;
        //IgnoreBlank();

        //printf("CKata.Len is... %d\n", CKata.Length);
        

    }


void CopyKata(Kata* clone, Kata ori){
	/* Menyalin kata
   I.S. : clone sembarang, ori sebuah kata yang valid
   F.S. : ori merupakan kata dengan panjang yang sama dengan src
          dan tiap karakter clone sama dengan ori */
   (*clone).Length = ori.Length;
   for (int i = 1; i <= ori.Length; i++){
		(*clone).TabKata[i] = ori.TabKata[i];
   } }

/* Operasi Mesinkata */
	
int KataToInt(Kata DefKata) {
/* I.S. : DefKata terdefinisi
   F.S. : Mengubah nilai pada DefKata menjadi bentuk integer */
	int i;
	int nilai,angka;
	nilai = 0;
	angka = DefKata.Length;
	//printf("Defkat alen : %d\n", DefKata.Length);
	for (i = 1; i<= angka ; i++) {
		//printf("NIlai KataToInt now %d\n", nilai);
		nilai = nilai * 10 + ((DefKata.TabKata[i]) - '0'); }
	return nilai; }

char CommandToChar(Kata CKata) {
/* I.S. : CKata terdefinisi
   F.S. : Mengubah bentuk Kata pada CKata menjadi bentuk character */
	return CKata.TabKata[1]; }


void TulisCKata(Kata kataa) {
/* I.S. : kataa terdefinisi
   F.S. : Menulis kataa pada layar  */
    int i;

    for (i = 1; i <= kataa.Length; i++)
    {
        printf("%c", kataa.TabKata[i]);
    }

	//printf("\nEnd Ckata|||");

    // printf("\n");
}

boolean IsEQCKataString(char kata[20])
/* I.S. : kata terdefinisi
   F.S. : Mengembalikan true jika kata sama dengan CKata */
{
    int i = 1;
    while (kata[i-1] != NULL){
        if (CKata.TabKata[i] != kata[i-1]){
            return false;
        }
        i++;
    }
    // return true;
    return ((i-1) == CKata.Length);
}

boolean IsEQCKataInt(int X)
/* I.S. : kata terdefinisi
   F.S. : Mengembalikan true jika nilai integer dari CKata sama dengan X */
{
    int y = KataToInt(CKata);
    return (y == X);
}