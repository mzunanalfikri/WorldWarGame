#include "bangunan.h"
#include "graph.h"
#include "arraydin.h"
#include "player.h"
#include "listlinier.h"
#include "state.h"
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

boolean IsPunyaHubungan(Graph G1,int Bangunan1,TabBangunan T2) {
	int j = 1;
	while(j <= NbElmtTabArray(T2)){
		if (IsTerhubung(G1,Bangunan1,j)) {
			return true; }
		else {
			j++; } } 
	if (j > NbElmtTabArray(T2)) {
		return false; }
}
		
void Attack(State *S,Graph G){
	int i = 1;
	int j = 1;
	int k = 1;
	int l = 1;
	int m = 1;
	int X,Y,jml_pasukan;
	int array_target[100];
	int arrayAtt[100];
	int pasukan_for_att;
	int pasukan_deff;
	addresslist P;
	Player P1;
	TabBangunan T1;
	Bangunan BangunanAtt,BangunanDef;
	pasukan_deff = Pasukan(BangunanDef);
	
	
	/* DAFTAR BANGUNAN PLAYER */
	
	printf("Daftar bangunan: \n");
	P = First(ListIdxBangunan(P1));
	while(P != NULL){
		if (Serang(ElmtTab(T1,Info(P))) == false) {
			printf("%d. ",l );
			PrintBangunan(ElmtTab(T1,Info(P)));
			arrayAtt[m] = Info(P);
			printf("\n");
			P = Next(P);
			l++;
			m++; } 
		else {
			P = Next(P); } }
		
	
	/* PRE - ATTACK */ 
		
	printf("Bangunan yang digunakan untuk menyerang: ");
	scanf("%d",&X);
	BangunanAtt = ElmtTab(T1,arrayAtt[X]);
	if (IsPunyaHubungan(G,arrayAtt[X],T1)) {
		printf("Daftar bangunan yang dapat diserang: \n");
		while (j < NbElmtTabArray(T1)) {
			if (IsTerhubung(G,arrayAtt[X],j)) {
				printf("%d. ",i);
				PrintBangunan(ElmtTab(T1,j));
				array_target[k] = j;
				printf("\n"); 
				i++; 
				j++;
				k++;	}
			else {
				j++; } }
		printf("Bangunan yang diserang: ");
		scanf("%d",&Y);
		BangunanDef = ElmtTab(T1,array_target[Y]);
		printf("Jumlah pasukan : ");
		scanf("%d",&jml_pasukan);
		pasukan_for_att = jml_pasukan; 
		
		/* PROCESS SELAMA ATTACK BERLANGSUNG */
		
		if (pasukan_for_att >= Pasukan(BangunanDef)) {
			Level(BangunanDef) = 1;
			InsVLast(&ListIdxBangunan(P1),array_target[Y]); /* Berganti Kepemilikan */
			Pasukan(BangunanAtt) = Pasukan(BangunanAtt) - pasukan_for_att;
			Serang(BangunanAtt) = true;
			if (Pertahanan(BangunanDef)) {
				Pasukan(BangunanDef) = (0.75*pasukan_for_att)-pasukan_deff; }
			else {
				Pasukan(BangunanDef) = pasukan_for_att-pasukan_deff; } 
				printf("Bangunan menjadi milikmu! "); }
		else if ((pasukan_for_att) < Pasukan(BangunanDef)) {
			Serang(BangunanAtt) = true;
			Pasukan(BangunanDef) = Pasukan(BangunanDef) - pasukan_for_att; 
			printf("Bangunan gagal direbut. "); } 
		}
			
	/* Apabila BangunanAtt tidak memiliki keterhubungan sama sekali dengan bangunan lain */		
	else {
		printf("Tidak ada bangunan yang dapat diserang"); }

	

}




		
	
