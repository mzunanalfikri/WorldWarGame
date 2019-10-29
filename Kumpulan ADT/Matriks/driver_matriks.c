#include "matriks.h"
#include <stdio.h>

int main ()
{
    /* KAMUS */
    MATRIKS M1,M2,MH;
    indeks i,j;
    ElType x;

    /* ALGORITMA */
    printf("Input M1 :\n");
    scanf("%d %d",&i,&j);
    //BacaMATRIKS(&M1,i,j);
    //printf("Input M2 :\n");
    //scanf("%d %d",&i,&j);
    //BacaMATRIKS(&M2,i,j);

    MakeMATRIKS(i, j, &M1);
    printf("M1 :\n");
    TulisMATRIKS(M1);
    printf("\n");
    Elmt(M1, 1, 1) = 'V';
    Elmt(M1, 1, 2) = 'V';
    Elmt(M1, 1, 3) = 'V';
    //printf("M2 :\n");
    //TulisMATRIKS(M2);
    //printf("\n");

    return 0;
}
