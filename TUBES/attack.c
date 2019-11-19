#include "bangunan.h"
#include "graph.h"
#include "arraydin.h"
#include "player.h"
#include "listlinier.h"
#include "state.h"
#include <stdio.h>
#include <stdlib.h>





void Attack(State *S){
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
	printf("Daftar bangunan yang dapat diserang: \n");
	while (j<NbElmtTabArray(T1)) {
		if (ElmtTab(T1,j) == /* berhubungan dalam graph dengan bangunan X */) {
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
		InsVLast(&ListIdxBangunan(P1),array_target[Y]); 
		Level(BangunanDef) = 1;
		Pasukan(BangunanDef) = Pasukan(BangunanAtt) - pasukan_for_att;
		if (Pertahanan(BangunanDef)) {
			Pasukan(BangunanDef) = (0.75*pasukan_for_att)-pasukan_deff; }
		else {
			Pasukan(BangunanDef) = pasukan_for_att-pasukan_deff; } }
	else if (pasukan_for_att < Pasukan(BangunanDef)) {
		Pasukan(BangunanDef) = Pasukan(BangunanDef) - pasukan_for_att; } 
	


}




		
	
