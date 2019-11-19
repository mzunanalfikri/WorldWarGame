#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "arraydin.h"
#include "bangunan.h"
#include "listlinier.h"
#include "matriks.h"
#include "player.h"
#include "point.h"
#include "queue.h"
#include "stackt.h"
#include "state.h"
#include "graph.h"
#include "pcolor.h"
#include "function.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "readfile.h"
// #include "arraydin.c"
// #include "bangunan.c"
// #include "listlinier.c"
// #include "matriks.c"
// #include "player.c"
// #include "point.c"
// #include "queue.c"
// #include "stackt.c"
// #include "state.c"
// #include "graph.c"
// #include "pcolor.c"
// #include "function.c"
// #include "mesinkar.c"
// #include "mesinkata.c"
// #include "readfile.c"

int main() {
    // DEKLARASI ADT YANG DIGUNAKAN
    State S;
    StackState SStacks;
    MATRIKS Map;
    Graph G;
    
    boolean endgame;
    boolean extraTurn;

    extraTurn = false;
    endgame = false;
    ReadKonfigurasiFile(&S, &Map, &G);
    Turn(Player1(S)) = true;
    PushState(&SStacks, S);
    StatusPlayer(S, Map);

    while (!endgame){
        EnterCommad(S);
        ReadCmd();
        if (IsEQCKataString("ATTACK")){
            printf("menampilkan attack mechanism\n");
            Attack(&S, G);
            PushState(&SStacks, S);
        } else if (IsEQCKataString("LEVEL_UP")){
            LevelUp(&S);
            addIR(&S);
            PushState(&SStacks, S);
        } else if (IsEQCKataString("SKILL")){
            printf("skill \n");
            Skill(&S, &extraTurn);
            PushState(&SStacks, S);
        } else if (IsEQCKataString("UNDO")) {
            printf("Undo \n");
            Undo(&SStacks);
            CopyState(InfoTop(SStacks), &S);
        } else if (IsEQCKataString("END_TURN")){
            AddIR(&S);
            EndTurn(&S, &extraTurn);
            StatusPlayer(S,Map);
            EndTurnState(&SStacks);
        } else if (IsEQCKataString("MOVE")){
            MovePasukan(&S, G);
            PushState(&SStacks, S);
        } else if (IsEQCKataString("EXIT")){
            endgame = true;
        } else if (IsEQCKataString("MAP")){
            CetakMatiksWarna(Map, S);
        } else if(IsEQCKataString("PRINT_ALL_BANGUNAN")){
            PrintAllBangunan(ArrayBangunan(S));
        } else if (IsEQCKataString("STATUS")) {
            StatusPlayer(S, Map);
        } else if (IsEQCKataString("HELP")){
            printf("tampilin help");
        } else if (IsEQCKataString("PRINT_GRAPH")) {
            PrintInfoGraph(G);
        }
        // disini lakukan pengecekan skiil bertamah
        //cek juga ada yang kalah atau enggak
    }

    return 0;
}