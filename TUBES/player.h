/* ADT PLAYER UNTUK identitas player */


#ifndef PLAYER_H
#define PLAYER_H

#include "boolean.h"
#include "queue.h"
#include "listlinier.h"

typedef struct{
    List ListIdxBangunan;
    Queue QSkill;
    boolean Turn; //True if this player on turn
} Player;

/* *** Selektor *** */
#define ListIdxBangunan(P) (P).ListIdxBangunan
#define QSkill(P) (P).QSkill
#define Turn(P) (P).Turn

void MakePlayer(Player *P);
/* Membentuk Player Kosong yang siap diisi */

void PrintPlayer(Player P);
/* Untuk debugging */

void CopyPlayer(Player Pin, Player *Phsl);
/* assign player Phsl dengan player Pin */


#endif