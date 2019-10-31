
#ifndef PLAYER_H
#define PLAYER_H

#include "boolean.h"
#include "queue.h"
#include "listlinier.h"

typedef struct{
    List ListIdxBangunan;
    Queue QSkill;
    boolean Turn;
} PLAYER;

/* *** Selektor *** */
#define ListIdxBangunan(Player) (Player).ListIdxBangunan
#define QSkill(Player) (Player).QSkill
#define Turn(Player) (Player).Turn

void MakePlayer(PLAYER *P);
/* Membentuk Player Kosong yang siap diisi */



#endif