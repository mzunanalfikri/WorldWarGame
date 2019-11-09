#include "listlinier.h"
#include "stdio.h"
#include "stdlib.h"
int main (){
    List L,L2;
    CreateEmptyList(&L);
    // InsVFirst(&L,1);
    // InsVLast(&L,2);
    // InsVLast(&L,3);
    // InsVLast(&L,4);
    // InsVLast(&L,5);

    PrintInfo(L);
    printf("\n");
    CopyList(L,&L2);

    InsVLast(&L2,100);
    PrintInfo(L2);
    printf("\n");
    PrintInfo(L);

}