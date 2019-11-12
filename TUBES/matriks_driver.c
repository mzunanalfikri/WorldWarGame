#include "matriks.h"
#include <stdio.h>
#include "listlinier.h"
#include "state.h"

void CetakMatiksWarna(MATRIKS M, State S){

}

int main ()
{
    /* KAMUS */
    MATRIKS M1,M2,MH;
    indeks i,j;

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
    Tipe(ElmtMatriks(M1, 1, 2)) = 'F';
    TulisMATRIKS(M1);
    printf("finish\n");
    
    //printf("M2 :\n");
    //TulisMATRIKS(M2);
    //printf("\n");

    return 0;
}
