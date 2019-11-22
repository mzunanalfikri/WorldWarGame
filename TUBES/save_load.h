/* File: save_load.h */
#ifndef __SAVELOAD_H__
#define __SAVELOAD_H__


#include "mesinkar.h"
#include "mesinkata.h"
#include "matriks.h"
#include "bangunan.h"
#include "state.h"
#include "graph.h"
#include "stackt.h"
#include "readfile.h"



char* ask_file_name();

void save(StackState StackS, MATRIKS M, Graph G, boolean extraTurn, boolean attackUp, char* filepath);
// I.S. StackS, M, G, extraTurn, attackUp, filepath terdefinisi
// F.S. Data pada StackS, M, G, extraTurn, attackUp disimpan pada file yang ada pada filepath

void load(StackState *StackS, MATRIKS *M, Graph *G, boolean *extraTurn, boolean *attackUp, char* filepath);
// I.S. StackS, M, G, extraTurn, attackUp sembarang; filepath terdefinisi
// F.S. Data pada StackS, M, G, extraTurn, attackUp sesuai data yang ada pada file yang ada pada filepath


#endif