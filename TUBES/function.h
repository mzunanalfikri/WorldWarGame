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

state InstantUpgrade (State *S);

state Shield (State *S); //bonus

state ExtraTurn (State *S);

state AttackUp (State *S); //bonus

state CriticalHit (State *S);

state InstantReinforcement (State *S);

state Barrage (State *S);