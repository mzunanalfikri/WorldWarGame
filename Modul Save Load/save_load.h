/* File: save_load.h */
#ifndef __SAVELOAD_H__
#define __SAVELOAD_H__

#include "../ADT Mesin Kata/mesinkar.h"
#include "../ADT Mesin Kata/mesinkata.h"
#include "../ADT Matriks/matriks.h"
//#include "bangunan.h"
#include "../ADT State/state.h"
#include "../ADT Graph/graph.h"
#include "../ADT Stack/stackt.h"
#include "../Modul Read File/readfile.h"



char* ask_file_name();

void save(StackState StackS, MATRIKS M, Graph G, boolean extraTurn, boolean attackUp, Kata player1, Kata player2);
// I.S. StackS, M, G, extraTurn, attackUp, filepath terdefinisi
// F.S. Data pada StackS, M, G, extraTurn, attackUp disimpan pada file yang ada pada filepath

void load(StackState *StackS, MATRIKS *M, Graph *G, boolean *extraTurn, boolean *attackUp, Kata *player1, Kata *player2);
// I.S. StackS, M, G, extraTurn, attackUp sembarang; filepath terdefinisi
// F.S. Data pada StackS, M, G, extraTurn, attackUp sesuai data yang ada pada file yang ada pada filepath


#endif