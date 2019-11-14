/* Pembacaan Konfigurasi File */

#include "readfile.h"
#include <stdio.h>


void baca_array_bangunan(TabBangunan *bangunans, int num_of_bangunan, MATRIKS *peta) {
	// KAMUS
	int i, bangunan_X, bangunan_Y;
	char tipe_bangunan;

	// ALGORITMA
	
	//MakeEmptyArray(bangunans, num_of_bangunan);
	for (i = 1; i <= num_of_bangunan; i++)
	{ // Posisi ckata mulai di tipe dari banungan pertama
		//ADVKATA();
		tipe_bangunan = CKata.TabKata[1];
		printf("TIpe bangunan : %c", tipe_bangunan);
		ADVKATA();
		bangunan_X = KataToInt(CKata);
		ADVKATA();
		bangunan_Y = KataToInt(CKata);

		TulisPOINT(MakePOINT(bangunan_X, bangunan_Y));

		ElmtTab(*bangunans, i) = MakeBangunanLv1(tipe_bangunan, MakePOINT(bangunan_X, bangunan_Y));

		Tipe(ElmtMatriks(*peta, bangunan_X, bangunan_Y)) = tipe_bangunan;
		Id(ElmtMatriks(*peta, bangunan_X, bangunan_Y)) = i;
		
		printf("Bangunan %d : ", i);
		PrintBangunan(ElmtTab(*bangunans, i));
		printf("\n");
		ADVKATA(); // BIKIN CORNER CASE KALO UDAH NYAMPE AKHIR EOF
	}
	
}


void ReadKonfigurasiFile(State *S, MATRIKS *M, Graph *G) {
	// KAMUS
	int Mat_x, Mat_y, jumlah_bangunan;
	TabBangunan bangunans;

	// ALGORITMA
	
	STARTKATA("konfigurasifile.txt");

	/* MAKE MAP MATRIX */
	printf("Kata to Int : %d\n",KataToInt(CKata));
	Mat_x = KataToInt(CKata);
	
	ADVKATA();
	TulisCKata();
	Mat_y = KataToInt(CKata);

	printf("X is %d, Y is %d\n", Mat_x, Mat_y);

	MakeMATRIKS(Mat_x, Mat_y, M);
	/* MAKE MAP MATRIX END */

	TulisMATRIKS(*M);

	/* MAKE BANGUNAN ARRAY */
	ADVKATA();

	jumlah_bangunan = KataToInt(CKata);

	MakeState(S, jumlah_bangunan);

	ADVKATA();

	baca_array_bangunan(&ArrayBangunan(*S), jumlah_bangunan, M);

	InsVFirst(&ListIdxBangunan(Player1(*S)), 1);
	InsVFirst(&ListIdxBangunan(Player2(*S)), 2);

	Netral(ElmtTab(ArrayBangunan(*S), 1)) = false;
	Netral(ElmtTab(ArrayBangunan(*S), 2)) = false;
	/* MAKE BANGUNAN ARRAY END */
	TulisMATRIKS(*M);

	/* MAKE GRAF */
	CreateEmptyGraph(G);

	/* MAKE GRAF END */





}
