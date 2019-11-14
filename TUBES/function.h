#ifndef H_Function_H
#define H_Function_H

#include "arraydin.h"
#include "bangunan.h"
#include "graph.h"
#include "listlinier.h"
#include "matriks.h"
#include "player.h"
#include "point.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "queue.h"
#include "readfile.h"
#include "stackt.h"
#include "state.h"
#include "pcolor.h"
#include<stdio.h>
#include<stdlib.h>


// Fungsi untuk cetak matriks dengan warna
void CetakMatiksWarna(MATRIKS M, State S);
/* Mencetak di layar matriks dengan warnanya */

/* **** SKILL **** */
void InstantUpgrade (State *S);

void Shield (State *S); //bonus

void ExtraTurn (State *S);

void AttackUp (State *S); //bonus

void CriticalHit (State *S);

void InstantReinforcement (State *S);

void Barrage (State *S);

/* **** ATTACK MECHANISM *** */

#endif