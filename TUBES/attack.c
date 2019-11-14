#include "bangunan.h"
#include "graph.h"
#include "arraydin.h"
#include "player.h"
#include "listlinier.h"
#include "state.h"

void Attack(State *S) {
	TabBangunan T;
	Bangunan target_bangunan;	
	Bangunan BEnemy,BPlayer;	
	List ListBPlayer;
	Player P1;
	int i;
	int X,Y;
	int idx_target;
	Y = Pasukan(BEnemy);
	if (X >= Pasukan(BEnemy)) {
		InsVLast(ListIdxBangunan(P1),/* indeks bangunan BEnemy pada array bangunan */); 
		Level(BEnemy) = 1;
		Pasukan(BPlayer) = Pasukan(BPlayer) - X;
		if (Pertahanan(BEnemy)) {
			Pasukan(BEnemy) = (0,75*X)-Y; }
		else {
			Pasukan(BEnemy) = X-Y; } }
	else if (X < Pasukan(BEnemy)) {
		Pasukan(BEnemy) = Pasukan(BEnemy) - X; } 
	


}

void PrintBangunanPlayer(){
	TabBangunan T1;
	Player P1;
	addresslist P;
	List ListIdxBangunan;
	int i=1;
	int j=1;
	int arrayAtt[100];
	printf("Daftar bangunan: \n");
	P = First(ListIdxBangunan(P1));
	while(P != NULL){
		if (Serang(ElmtTab(T1,Info(P))) == false) {
			printf("%d",i, ".  ");
			PrintBangunan(ElmtTab(T1,Info(P)));
			arrayAtt[j] = Info(P);
			printf("\n");
			P = Next(P);
			i++;
			j++; } }
		else {
			P = Next(P); } 
}


void PrintTargetEnemy(int n){
	int i = 1;
	int j = 1;
	int X;
	TabBangunan T1;
	printf("Bangunan yang digunakan untuk menyerang: ");
	scanf("%d",&X);
	printf("Daftar bangunan yang dapat diserang: \n");
	while (j<NbElmtTabArray(T1)) {
		if (ElmtTab(T1,j) == /* berhubungan dalam graph dengan bangunan X */) {
			printf("%d",i, ".  ");
			PrintBangunan(ElmtTab(T1,j));
			printf("\n");
			i++; 
			j++;}
		else {
			j++; } }
}

		
	
