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

void SetSkill(State *S){
    infotype X;
    Queue Q = QSkill(Player1(*S));
    while(!IsEmpty(Q)){
        Del(&Q,&X);
    }
    EnterCommad(*S);
    ReadCmd();
    if (IsEQCKataString("Instant Upgrade")){
        Add(&Q,1);
    } else if (IsEQCKataString("Shield")){
        Add(&Q,2);
    } else if (IsEQCKataString("ExtraTurn")){
        Add(&Q,3);
    } else if (IsEQCKataString("Attack Up ")) {
        Add(&Q,4);
    } else if (IsEQCKataString("Critical Hit")){
        Add(&Q,5);
    } else if (IsEQCKataString("Instant Reinforcement")){
        Add(&Q,6);
    } else if (IsEQCKataString("Barrage")){
        Add(&Q,7);
    }
    PrintQSkill(Q);
}

void SetBangunan (Bangunan *B)
/* I.S. Sembarang */
/* F.S. Membuat sebuah bangunan default level 1 (digunakan pada awal load file) */
{
    int lv,serang,pertahanan,netral,move,pasukan,A,M;
    char type;
    scanf("%d",&lv);
    Level(*B) = lv;
    scanf("%d",&serang);
    Serang(*B) = serang;
    scanf("%d",&pertahanan);
    Pertahanan(*B) = pertahanan;
    scanf(" %c",&type);
    Type(*B) = type;
    scanf("%d",&netral);
    Netral(*B) = netral;
    scanf("%d",&move);
    Move(*B) = move;
    scanf("%d",&pasukan);
    Pasukan(*B) = pasukan;
    scanf("%d",&A);
    A(*B) = A;
    scanf("%d",&M);
    M(*B) = M;
}

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
    CreateEmptyStackState(&SStacks);
    PushState(&SStacks, S);
    StatusPlayer(S, Map);

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
        } else if (IsEQCKataString("SET_SKILL")){
            //manggil fungsi skill
            SetSkill(&S); 
        } else if (IsEQCKataString("UNDO")) {
            printf("Undo \n");
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
        }
        //cek juga ada yang kalah atau enggak
    }
    return 0;
}