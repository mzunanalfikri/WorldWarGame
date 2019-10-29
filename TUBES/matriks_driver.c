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
    Elmt(M1, 1, 1) = 'V';
    Elmt(M1, 1, 2) = 'F';
    printf("M1 :\n");
    MakeMATRIKS(i,j,&M1);
    TulisMATRIKS(M1);
    printf("\n");
    printf("%c", Elmt(M1, 1, 1));
    printf("lalala\n");
    printf("%c", 'X');
    //printf("M2 :\n");
    //TulisMATRIKS(M2);
    //printf("\n");

    return 0;
}
