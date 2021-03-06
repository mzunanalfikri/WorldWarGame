/* Realisasi ADT Player */


#include "player.h"
#include <stdio.h>
#include <stdlib.h>


void MakePlayer(Player *P)
/* I.S Sembarang */
/* F.S. Membentuk Player Kosong yang siap diisi */
{
    CreateEmptyList(&ListIdxBangunan(*P));
    CreateEmpty(&QSkill(*P), 10);
    Add(&QSkill(*P),1);
    Turn(*P) = false;
    ShieldPlayer(*P) = 0;
}

void PrintPlayer(Player P)
/* Procedure untuk mencetak info player ke layar */
{
    PrintInfo(ListIdxBangunan(P));
    PrintQSkill((QSkill(P)));
    //printf("Is player's turn? %s\n", (Turn(P)) ? "Yes" : "No");
}

void CopyPlayer(Player Pin, Player *Phsl)
/*I.S. Pin terdefinisi, Phsl sembarang */
/* F.S PHsl berisi sesuai dengan Pin */
{
    MakePlayer(Phsl);
    CopyList(ListIdxBangunan(Pin), &ListIdxBangunan(*Phsl));
    CopyQueue(QSkill(Pin), &QSkill(*Phsl));
    Turn(*Phsl) = Turn(Pin); 
    ShieldPlayer(*Phsl) = ShieldPlayer(Pin);
}

void DealokasiPlayer(Player *P)
// I.S. Player P terdefinisi
// F.S. Memori yang digunakan player P dikembalikan ke sistem
    {
        DealokasiAllList(ListIdxBangunan(*P));
        DeAlokasi(&QSkill(*P));
    }