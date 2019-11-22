
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
	return CKata.TabKata[1]; }


void TulisCKata() {
    int i;

    printf("Ckata : ");

    for (i = 1; i <= CKata.Length; i++)
    {
        printf("%c", CKata.TabKata[i]);
    }

	//printf("\nEnd Ckata|||");

    printf("\n");
}

boolean IsEQCKataString(char kata[20])
/* mengembalikan true jika kata sama dengan CKata */
{
    int count;
    count = 0;
    for (int i = 1 ; i <= CKata.Length ; i++){
        if (CKata.TabKata[i] == kata[i-1]){
            count++;
            //return false;
        }
    }
    //return true;
    return (count == CKata.Length);
}

boolean IsEQCKataInt(int X)
/* mengembalikan true jika X sama dengan CKATA */
{
    int y = KataToInt(CKata);
    return (y == X);
}