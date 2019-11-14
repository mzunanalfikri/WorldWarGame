/* Realisasi ADT State */

#include "state.h"
#include "bangunan.h"
#include<stdio.h>
#include<stdlib.h>

void MakeState(State *S, int JumlahBangunan)
/* I.S. State S Sembarang */
/* F.S State S telah siap diisi */
{
    MakeEmptyArray(&ArrayBangunan(*S), JumlahBangunan);
    MakePlayer(&Player1(*S));
    MakePlayer(&Player2(*S));
}

void CopyState(State Sin, State * Sout);
/* I.S. State Sout sembarang */
/* F.S. State Sout terisi salinan state Sin */
