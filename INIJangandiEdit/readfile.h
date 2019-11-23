/* File: readfile.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __READFILE_H__
#define __READFILE_H__

#include "mesinkar.h"
#include "mesinkata.h"
#include "matriks.h"
#include "bangunan.h"
#include "state.h"
#include "graph.h"


void ReadKonfigurasiFile(State* S, MATRIKS* M, Graph* G);
/* Membaca konfigurasi file yang terdefinisi
	I.S : Konfigurasi file terdefinisi
	F.S : Membaca konfigurasi file dan mencetak ke layar kondisi State Awal */

void baca_array_bangunan(TabBangunan *bangunans, int num_of_bangunan, MATRIKS *peta);

void BacaGraf(Graph * G, int jumlah_bangunan);

#endif
