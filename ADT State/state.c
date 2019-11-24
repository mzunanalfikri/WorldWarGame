/* Realisasi ADT State */

#include "state.h"
#include<stdio.h>
#include<stdlib.h>

void MakeState(State *S, int JumlahBangunan)
/* I.S. State S Sembarang */
/* F.S State S telah siap diisi */
{
    MakeEmptyArray(&ArrayBangunan(*S), JumlahBangunan);
    MakePlayer(&Player1(*S));
    MakePlayer(&Player2(*S));
    CritHit(*S) = false;
}

void CopyState(State Sin, State * Sout)
/* I.S. State Sout sembarang */
/* F.S. State Sout terisi salinan state Sin */
{
    CopyTab(ArrayBangunan(Sin),&ArrayBangunan(*Sout));
    CopyPlayer(Player1(Sin),&Player1(*Sout));
    CopyPlayer(Player2(Sin),&Player2(*Sout));
    CritHit(*Sout) = CritHit(Sin); 
}



void PrintState(State S)
/* I.S State S terdefinisi */
/* F.S tercetak info state S ke layar */
{
    PrintAllBangunan(ArrayBangunan(S));
    PrintPlayer(Player1(S));
    PrintPlayer(Player2(S));
}

void DealokState(State *S)
// I.S. State S terdefinisi
// F.S. Memori yang digunakan State S dikembalikan ke sistem
 {
    DealokasiArray(&ArrayBangunan(*S));
    DealokasiPlayer(&Player1(*S));
    DealokasiPlayer(&Player2(*S));
}