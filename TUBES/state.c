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

void CopyState(State Sin, State * Sout){
    CopyTab(ArrayBangunan(Sin),&ArrayBangunan(*Sout));
    CopyPlayer(Player1(Sin),&Player1(*Sout));
    CopyPlayer(Player2(Sin),&Player2(*Sout));
}
/* I.S. State Sout sembarang */
/* F.S. State Sout terisi salinan state Sin */


void PrintState(State S){
    PrintAllBangunan(ArrayBangunan(S));
    PrintPlayer(Player1(S));
    PrintPlayer(Player2(S));
}

void DealokState(State *S) {
    DealokasiArray(&ArrayBangunan(*S));
    DealokasiPlayer(&Player1(*S));
    DealokasiPlayer(&Player2(*S));
}