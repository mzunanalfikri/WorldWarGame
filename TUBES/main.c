#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
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
#include "welcome.h"
#include "save_load.h"
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
// #include "readfile.c"'


int main() {
    // DEKLARASI ADT YANG DIGUNAKAN
    State S;
    StackState SStacks;
    MATRIKS Map;
    Graph G;
    
    boolean endgame;
    boolean extraTurn;
    boolean attackUp;
    
    extraTurn = false;
    attackUp = false;
    endgame = false;
    Kata player1, player2;

    welcome();
    //tampilin rule game jugaa


    printf("Masukkan Nama Komandan Negara Api (Player 1) : ");
    ReadCmd();
    CopyKata(&player1, CKata);
    printf("Masukkan Nama Komandan Negara Air (Player 2) : ");
    ReadCmd();
    CopyKata(&player2, CKata);

    

    printf("=======================================\n");
    printf("          Player 1 (RED): ");
    CetakWarnaRed(player1); 
    printf("          Player 2 (BLUE): ");
    CetakWarnaBlue(player2); 
    printf("=======================================\n"); 

    printf("\n");
    RuleGame();
    printf("\n");
    
    printf("Apakah KAMU SIAPPPP ? Tulis SIAPP untuk memulai permainan!\n");
    ReadCmd();
    while (!(IsEQCKataString("SIAPP"))){
        ReadCmd();
    }
    printf("Mari bersiap. Kita akan memulai sesuatu yang panjang!!");
    printf(".");
    delay(1);
    printf(".");
    delay(1);
    printf(".");
    delay(1);
    system("cls");
    //dikasih asci simple disini sabii

    ReadKonfigurasiFile(&S, &Map, &G);
    Turn(Player1(S)) = true;
    printf("\n");
    printf("===================================\n");
    printf("======== Giliran Player 1! ========\n");
    printf("===================================\n");
    printf("\n");
    CreateEmptyStackState(&SStacks);
    PushState(&SStacks, S);
    StatusPlayer(S, Map,player1,player2);
    while (!endgame){
        printf("\n");
        EnterCommad(S);
        ReadCmd();
        if (IsEQCKataString("ATTACK")){
            //memanggil fungsi attack
            Attack(&S, G, &attackUp);
            //push ke stack
            PushState(&SStacks, S);
        } else if (IsEQCKataString("LEVEL_UP")){
            //panggil fungsi levelup
            LevelUp(&S);
            PushState(&SStacks, S);
        } else if (IsEQCKataString("SKILL")){
            //manggil fungsi skill
            Skill(&S, &extraTurn, &attackUp); 
            //push ke stack
            PushState(&SStacks, S);
            EndTurnState(&SStacks);
        } else if (IsEQCKataString("UNDO")) {
            //printf("Undo \n");
            Undo(&SStacks);
            CopyState(InfoTop(SStacks), &S);
        } else if (IsEQCKataString("END_TURN")){
            system("cls");
            //cek dapet instant reinforcement
            AddIR(&S);
            //fungsi end turn
            EndTurn(&S, &extraTurn, &attackUp,player1,player2);
            //print status player
            StatusPlayer(S,Map,player1,player2);
            //push ke stack
            PushState(&SStacks, S);
            EndTurnState(&SStacks);
            
        } else if (IsEQCKataString("MOVE")){
            //funsi pasukan
            MovePasukan(&S, G);
            //push ke stack
            PushState(&SStacks, S);
        } else if (IsEQCKataString("EXIT")){
            endgame = true;
        } else if (IsEQCKataString("MAP")){
            CetakMatiksWarna(Map, S);
        } else if(IsEQCKataString("PRINT_ALL_BANGUNAN")){
            PrintAllBangunan(ArrayBangunan(S));
        } else if (IsEQCKataString("STATUS")) {
            StatusPlayer(S, Map,player1,player2);
        } else if (IsEQCKataString("HELP")){
            Help();
        } else if (IsEQCKataString("PRINT_GRAPH")) {
            PrintInfoGraph(G);
        } else if (IsEQCKataString("SAVE")) {
            save(SStacks, Map, G, extraTurn, attackUp, player1, player2);
        } else if (IsEQCKataString("LOAD")) {
            load(&SStacks, &Map, &G, &extraTurn, &attackUp, &player1, &player2);
            CopyState(InfoTop(SStacks), &S);
            StatusPlayer(S, Map,player1,player2);
            //save(SStacks, Map, G, extraTurn, attackUp, "p.txt");
        } else{
            printf("COMMAND yang anda masukkan tidak tersedia, coba lagi!\n");
        }
        //delay(1);
        //system("cls");
        //Cek Kondisi Game Over
        GameEnd(S, &endgame);
    }

    return 0;
}