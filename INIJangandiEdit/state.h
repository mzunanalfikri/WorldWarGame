/* ADT STATE dalam permainan, dan untuk push di stack untuk save state */

#ifndef STATE_H
#define STATE_H
#include "arraydin.h"
#include "player.h"

typedef struct {
    TabBangunan ArrayBangunan;
    Player Player1;
    Player Player2;
    boolean CritHit;    
} State;

/* *** Selektor *** */
#define ArrayBangunan(S) (S).ArrayBangunan
#define Player1(S) (S).Player1
#define Player2(S) (S).Player2
#define CritHit(S) (S).CritHit

void MakeState(State *S, int JumlahBangunan);
/* I.S. State S Sembarang */
/* F.S State S telah siap diisi */

void CopyState(State Sin, State * Sout);
/* I.S. State Sout sembarang */
/* F.S. State Sout terisi salinan state Sin */

//pop

//push

void PrintState(State S);

void DealokState(State *S);

#endif