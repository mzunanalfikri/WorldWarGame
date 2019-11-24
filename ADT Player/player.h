/* ADT PLAYER UNTUK identitas player */


#ifndef PLAYER_H
#define PLAYER_H

#include "boolean.h"
#include "../ADT Queue/queue.h"
#include "../ADT List/listlinier.h"

typedef struct{
    List ListIdxBangunan;
    Queue QSkill;
    boolean Turn; //True if this player on turn
    int ShieldPlayer; //0 tidak punya shield, 1 punya shield dalam 1x turn, 2 dalam 2 turn
} Player;

/* *** Selektor *** */
#define ListIdxBangunan(P) (P).ListIdxBangunan
#define QSkill(P) (P).QSkill
#define Turn(P) (P).Turn
#define ShieldPlayer(P) (P).ShieldPlayer

void MakePlayer(Player *P);
/* I.S Sembarang */
/* F.S. Membentuk Player Kosong yang siap diisi */

void PrintPlayer(Player P);
/* Procedure untuk mencetak info player ke layar */

void CopyPlayer(Player Pin, Player *Phsl);
/*I.S. Pin terdefinisi, Phsl sembarang */
/* F.S PHsl berisi sesuai dengan Pin */

void DealokasiPlayer(Player *P);
// I.S. Player P terdefinisi
// F.S. Memori yang digunakan player P dikembalikan ke sistem



#endif