
#include "mesinkata.h"
#include <stdio.h>
#include <stdlib.h>

boolean EndKata = false;
Kata CKata;
extern char CC;


void IgnoreBlank(){
	 while ((CC == BLANK) && (!EOP)) {
	   ADV();
	   } }
	   
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK */

void STARTKATA(char NamaFile[]);
/* I.S. : CC sembarang, 'NamaFile' terdefinisi dan ada filenya
   F.S. : CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA(){
	if (EOP) {
		EndKata = true; }
	else {
		SalinKata();
		IgnoreBlank(); } }

/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata(){
	int i;

	i = 1;
	for (;;) {
		CKata.TabKata[i] = CC;
		ADV();
		if (EOP ||  i == NMax || CC == BLANK ) {
			break; }
		else {
			i++; }
		}
	if (i == NMax) {
		while(CC != BLANK && !EOP) {
			ADV();
		}
	}
	CKata.Length = i; }
	
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau EndPita = true;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

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
	for (i = 1; i<= angka ; i++) {
		nilai = nilai * 10 + (DefKata.TabKata[i] - '0'); }
	return nilai; }

char CommandToChar(Kata CKata) {
	int i;
	i = CKata.Length;
	return CKata.TabKata[i]; }
