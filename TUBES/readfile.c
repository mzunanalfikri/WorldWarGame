/* Pembacaan Konfigurasi File */

#include "readfile.h"
#include "state.h"
#include <stdio.h>

void ReadKonfigurasiFile(State* S){
	
	
	Kata BrsBangunan,KolBangunan,TypeBangunan,JmlBangunan,height,width;
	/* Kata Status (Untuk keterhubungan bangunan) */
	MATRIKS Peta;
	Bangunan Castel,Tower,Fort,Village;
	char CharTypeBangunan;
	char C = '\0';
	char V = '\0';
	char T = '\0';
	char F = '\0';
	POINT KoordinatBangunan;
	int TinggiPeta,LebarPeta,JumlahBangunan;
	int i,k,l;
	/* int j,AttStatus; (Untuk keterhubungan bangunan */
	int idxBangunan;
	char konfigurasifile; /* Nama Konfigurasi File (dalam txt) */
	TabBangunan arrBangunan;
	
	idxBangunan = -1;
	STARTKATA(konfigurasifile);	/* Nama Konfigurasi File (dalam txt) */
	
	while (!EOP){
		CopyKata(&height, CKata);
		TinggiPeta = KataToInt(height);
		ADVKATA();
		CopyKata(&width, CKata);
		LebarPeta = KataToInt(width);
		MakeMATRIKS(TinggiPeta,LebarPeta,&Peta);
		for (k = 1; k<= LebarPeta; k++) {
			ElmtMatriks(Peta,1,k) = '*'; 
			ElmtMatriks(Peta,TinggiPeta,k) = '*'; }
		for (l = 1; l<= TinggiPeta; l++) {
			ElmtMatriks(Peta,l,1) = '*'; 
			ElmtMatriks(Peta,l,LebarPeta) = '*'; }
		ADVKATA();
		CopyKata(&JmlBangunan, CKata);
		JumlahBangunan = KataToInt(JmlBangunan);
		MakeEmptyArray(&arrBangunan, JumlahBangunan-1);
		ADVKATA();
		for (i = 1; i <= JumlahBangunan; i++) {
			CopyKata(&TypeBangunan, CKata);
			CharTypeBangunan = CommandToChar(TypeBangunan);
			ADVKATA();
			CopyKata(&BrsBangunan, CKata);
			Ordinat(KoordinatBangunan) = KataToInt(BrsBangunan);
			ADVKATA();
			CopyKata(&KolBangunan, CKata);
			Absis(KoordinatBangunan) = KataToInt(KolBangunan);
			if (CharTypeBangunan == 'C') {
				Castel = MakeBangunanLv1(C, KoordinatBangunan);
				idxBangunan++;
				ElmtTab(arrBangunan,idxBangunan) = Castel; }
			else if (CharTypeBangunan == 'V') {
				Village = MakeBangunanLv1(V, KoordinatBangunan); 
				idxBangunan++;
				ElmtTab(arrBangunan,idxBangunan) = Village; }
			else if (CharTypeBangunan == 'F') {
				Fort = MakeBangunanLv1(F, KoordinatBangunan); 
				idxBangunan++;
				ElmtTab(arrBangunan,idxBangunan) = Fort;}
			else if (CharTypeBangunan == 'T') {
				Tower = MakeBangunanLv1(T, KoordinatBangunan); 
				idxBangunan++;
				ElmtTab(arrBangunan,idxBangunan) = Tower; }
			ElmtMatriks(Peta,Absis(KoordinatBangunan),Ordinat(KoordinatBangunan)) = CharTypeBangunan;
			ADVKATA(); }
		
		/* Keterhubungan antar Peta 
		for (i = 1; i <= JumlahBangunan; i++) {
			for (j = 1; j <= JumlahBangunan; j++) {
				CopyKata(&Status, CKata);
				AttStatus = KataToInt(Status);
				if (AttOrNot == 0) {
					Tidak Terhubung(Gabisa nyerang)  } 
			else if (AttOrNot == 1) {
					 Terhubung(Bisa nyerang) } } 
			ADVKATA(); }			*/
	}
	TulisMATRIKS(Peta);

	}

