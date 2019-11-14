//realisasi function

#include<stdio.h>
#include<stdlib.h>
#include "function.h"


// Fungsi untuk cetak matriks dengan warna
void CetakMatiksWarna(MATRIKS M, State S)
/* Mencetak di layar matriks dengan warnanya */
{
    for(int i=1;i<=NKolEff(M)+2;i++){
        printf("*");
    }
    printf("\n");
    for(indeks j=GetFirstIdxBrs(M);j<=NBrsEff(M);j++){
        printf("*");
        for(indeks k=GetFirstIdxKol(M);k<=(NKolEff(M));k++){
            if (SearchB(ListIdxBangunan(Player1(S)), Id(ElmtMatriks(M, j, k)))){
                //print bangunan player 1
                //printf("%c1", Tipe(ElmtMatriks(M, j, k)));
                print_red(Tipe(ElmtMatriks(M, j, k)));
            } else if (SearchB(ListIdxBangunan(Player2(S)), Id(ElmtMatriks(M, j, k)))){
                //print bangunan player 2
                //printf("%c2", Tipe(ElmtMatriks(M, j, k)));
                print_blue(Tipe(ElmtMatriks(M, j, k)));
            } else {
                printf("%c", Tipe(ElmtMatriks(M, j, k)));
            }
            //printf("%c", Tipe(ElmtMatriks(M, j, k)));
        }
        printf("*\n");
    }
    //printf("\n");
    for(int l=1;l<=NKolEff(M)+2;l++){
        printf("*");
    }
}
