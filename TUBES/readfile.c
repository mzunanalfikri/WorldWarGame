/* Pembacaan Konfigurasi File */

#include "mesinkar.h"
#include "mesinkata.h"
#include "matriks.h"
#include "bangunan.h"

int main(){
	
	
	Kata BrsBangunan,KolBangunan,TypeBangunan,JmlBangunan,Status,height,width;
	MATRIKS Peta;
	char CharTypeBangunan;
	char C,V,T,F;
	POINT KoordinatBangunan;
	int TinggiPeta,LebarPeta,JumlahBangunan;
	int i,j,k,l,AttStatus;
	
	
	STARTKATA();
	
	
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
			ElmtMatriks(Peta,Absis(KoordinatBangunan),Ordinat(KoordinatBangunan)) = CharTypeBangunan;
			ADVKATA();
			if (CharTypeBangunan == 'C') {
				MakeBangunanLv1(C, KoordinatBangunan); }
			else if (CharTypeBangunan == 'V') {
				MakeBangunanLv1(V, KoordinatBangunan); }
			else if (CharTypeBangunan == 'F') {
				MakeBangunanLv1(F, KoordinatBangunan); }
			else if (CharTypeBangunan == 'T') {
				MakeBangunanLv1(T, KoordinatBangunan); } }
		for (i = 1; i <= JumlahBangunan; i++) {
			for (j = 1; j <= JumlahBangunan; j++) {
				CopyKata(&Status, CKata);
				AttStatus = KataToInt(Status);
				if (AttOrNot == 0) {
					/* Tidak Terhubung(Gabisa nyerang) */ }
				else if (AttOrNot == 1) {
					/* Terhubung(Bisa nyerang) */ } } 
				ADVKATA(); }			
	}
	
	TulisMATRIKS(Peta);
	
	return 0;
	}

