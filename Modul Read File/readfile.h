/* File: readfile.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __READFILE_H__
#define __READFILE_H__

#include "../ADT Mesin Kata/mesinkar.h"
#include "../ADT Mesin Kata/mesinkata.h"
#include "../ADT Matriks/matriks.h"
//#include "bangunan.h"
#include "../ADT State/state.h"
#include "../ADT Graph/graph.h"


void ReadKonfigurasiFile(State* S, MATRIKS* M, Graph* G);
/* Membaca konfigurasi file yang terdefinisi
	I.S : Konfigurasi file terdefinisi
	F.S : Membaca konfigurasi file dan mencetak ke layar kondisi State Awal */

void baca_array_bangunan(TabBangunan *bangunans, int num_of_bangunan, MATRIKS *peta);
/* Membaca array bangunan dari kofigurasi file
	I.S. : Konfigurasi file terdefinisi dan Ckata sedang di awal baris data bangunan pertama
	F.S. : Semua baris berisi data bangunan (sebanyak num_of_bangunan) dibaca dan dimasukkan ke dalam *bangunans, dan *peta. CKata sedang di awal baris setelah definisi bangunan terakhir */

void BacaGraf(Graph * G, int jumlah_bangunan);
/* Membaca graf keterhubungan bangunan dari kofigurasi file
	I.S. : Konfigurasi file terdefinisi dan Ckata sedang di awal baris data graf keterhubungan pertama
	F.S. : Semua baris berisi data graf (sebanyak jumlah_bangunan) dibaca dan dimasukkan ke dalam *G. CKata sedang di awal baris setelah definisi data graf terakhir (EOF) */

#endif
