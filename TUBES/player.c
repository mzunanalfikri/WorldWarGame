/* Realisasi ADT Player */


#include "player.h"
#include <stdio.h>
#include <stdlib.h>


void MakePlayer(Player *P)
/* Membentuk Player Kosong yang siap diisi */
{
    CreateEmptyList(&ListIdxBangunan(*P));
    CreateEmpty(&QSkill(*P), 10);
    Add(&QSkill(*P),1);
    Turn(*P) = false;
    ShieldPlayer(*P) = 0;
}

void PrintPlayer(Player P)
/* Untuk debugging */
{
    PrintInfo(ListIdxBangunan(P));
    PrintQSkill(QSkill(P));
    //printf("Is player's turn? %s\n", (Turn(P)) ? "Yes" : "No");
}

void CopyPlayer(Player Pin, Player *Phsl)
/* assign player Phsl dengan player Pin */
{
    MakePlayer(Phsl);
    CopyList(ListIdxBangunan(Pin), &ListIdxBangunan(*Phsl));
    CopyQueue(QSkill(Pin), &QSkill(*Phsl));
    Turn(*Phsl) = Turn(Pin); 
    ShieldPlayer(*Phsl) = ShieldPlayer(Pin);
}