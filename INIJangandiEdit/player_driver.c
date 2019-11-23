#include<stdlib.h>
#include<stdio.h>
#include "player.h"

int main(){
    Player P, P2;
    MakePlayer(&P);
    InsVFirst(&ListIdxBangunan(P), 10);
    InsVFirst(&ListIdxBangunan(P), 110);
    Add(&QSkill(P), 88);
    Add(&QSkill(P), 99);
    PrintPlayer(P);

    printf("hasil copy : \n");
    CopyPlayer(P, &P2);
    PrintPlayer(P2);

    InsVFirst(&ListIdxBangunan(P2), 109);
    InsVFirst(&ListIdxBangunan(P2), 1100);
    PrintPlayer(P);
    PrintPlayer(P2);

    return 0;
}