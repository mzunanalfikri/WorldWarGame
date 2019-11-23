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

void BacaGraf(Graph * G, int jumlah_bangunan);

#endif
