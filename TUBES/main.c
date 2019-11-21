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
    boolean attackUp;
    boolean criticalHit;

    criticalHit = false;
    extraTurn = false;
    attackUp = false;
    endgame = false;
    ReadKonfigurasiFile(&S, &Map, &G);
    Turn(Player1(S)) = true;
    printf("\n");
    printf("===================================\n");
    printf("======== Player 1's Turn ! ========\n");
    printf("===================================\n");
    printf("\n");
    CreateEmptyStackState(&SStacks);
    PushState(&SStacks, S);
    StatusPlayer(S, Map);
    printf("Command yang tersedia: \n");
    printf("- ATTACK\n");
    printf("- LEVEL_UP\n");
    printf("- SKILL\n");
    printf("- UNDO\n");
    printf("- END_TURN\n");
    printf("- MOVE\n");
    printf("- EXIT\n");
    while (!endgame){
        EnterCommad(S);
        ReadCmd();
        if (IsEQCKataString("ATTACK")){
            //memanggil fungsi attack
            Attack(&S, G, &attackUp, &criticalHit);
            //
            PushState(&SStacks, S);
        } else if (IsEQCKataString("LEVEL_UP")){
            //panggil fungsi levelup
            LevelUp(&S);
            PushState(&SStacks, S);
        } else if (IsEQCKataString("SKILL")){
            //manggil fungsi skill
            
            Skill(&S, &extraTurn, &attackUp, &criticalHit); 
            //
            PushState(&SStacks, S);
            EndTurnState(&SStacks);
        } else if (IsEQCKataString("UNDO")) {
            //printf("Undo \n");
            Undo(&SStacks);
            CopyState(InfoTop(SStacks), &S);
        } else if (IsEQCKataString("END_TURN")){
            //cek dapet instant reinforcement
            AddIR(&S);
            //fungsi end turn
            EndTurn(&S, &extraTurn, &attackUp);
            //print status player
            StatusPlayer(S,Map);
            //
            PushState(&SStacks, S);
            EndTurnState(&SStacks);
        } else if (IsEQCKataString("MOVE")){
            //funsi pasukan
            MovePasukan(&S, G);
            //
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
        } else{
            printf("COMMAND yang anda masukkan tidak tersedia, coba lagi!\n");
        }
        
        //cek juga ada yang kalah atau enggak
        GameEnd(S, &endgame);
    }

    return 0;
}