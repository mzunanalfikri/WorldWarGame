#include "matriks.h"
#include <stdio.h>
#include<stdlib.h>
#include "listlinier.h"
#include "state.h"
#include "pcolor.h"
#include "function.h"

// void CetakMatiksWarna(MATRIKS M, State S){
//     for(int i=1;i<=NKolEff(M)+2;i++){
//         printf("*");
//     }
//     printf("\n");
//     for(indeks j=GetFirstIdxBrs(M);j<=NBrsEff(M);j++){
//         printf("*");
//         for(indeks k=GetFirstIdxKol(M);k<=(NKolEff(M));k++){
//             if (SearchB(ListIdxBangunan(Player1(S)), Id(ElmtMatriks(M, j, k)))){
//                 //print bangunan player 1
//                 printf("%c1", Tipe(ElmtMatriks(M, j, k)));
//             } else if (SearchB(ListIdxBangunan(Player2(S)), Id(ElmtMatriks(M, j, k)))){
//                 //print bangunan player 2
//                 printf("%c2", Tipe(ElmtMatriks(M, j, k)));
//             } else {
//                 printf("%c", Tipe(ElmtMatriks(M, j, k)));
//             }
//             //printf("%c", Tipe(ElmtMatriks(M, j, k)));
//         }
//         printf("*\n");
//     }
//     //printf("\n");
//     for(int l=1;l<=NKolEff(M)+2;l++){
//         printf("*");
//     }
// }

int main ()
{
    /* KAMUS */
    MATRIKS M1,M2,MH;
    indeks i,j;
    State S;

    MakeState(&S, 10);
    /* ALGORITMA */
    printf("Input M1 :\n");
    scanf("%d %d",&i,&j);
    //BacaMATRIKS(&M1,i,j);
    //printf("Input M2 :\n");
    //scanf("%d %d",&i,&j);
    //BacaMATRIKS(&M2,i,j);
    
    printf("M1 :\n");
    MakeMATRIKS(i,j,&M1);
    Tipe(ElmtMatriks(M1, 1, 1)) = 'V';
    Id(ElmtMatriks(M1, 1, 1)) = 1;

    Tipe(ElmtMatriks(M1, 2, 2)) = 'F';
    Id(ElmtMatriks(M1, 2, 2)) = 2;

    Tipe(ElmtMatriks(M1, 3, 3)) = 'T';
    InsVFirst(&ListIdxBangunan(Player1(S)), 1);
    InsVFirst(&ListIdxBangunan(Player2(S)), 2);  
    CetakMatiksWarna(M1, S);
    printf("finish\n");
    
    //printf("M2 :\n");
    //TulisMATRIKS(M2);
    //printf("\n");

    return 0;
}
