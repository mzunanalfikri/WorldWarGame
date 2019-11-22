#include<stdio.h>
#include<stdlib.h>
#include<time.h>
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
void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds) 
        ; 
} 
void welcome(){
   
    
    printf("                                                           \n");
    printf("                                                           \n");                               
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                                                           \n");
    printf("      + + +         // - ` . .                             \n");
    printf("                     ` ` - : o +o + o +     / / / /        \n");
    printf("         + oo o o : : : + = - . o s s o o o                \n");
    printf("             ` ` - + +s s s- -- +o - o+ :- / s o+ / --     \n");
    printf("          `  o  `` ` s ss s s  o o                         \n");
    printf("                    s  o o` `    a   os o o  /         \n");
    printf("            -  : :  o : s                                  \n");
    printf("                   + o o oo . ` ` + o = +  s s s o         \n");
    printf("               - o + ` / s s                               \n");
    printf("                              / .. + . / s ss              \n");
    printf("                         s.   o s                          \n");
    printf("                                       `:`                 \n");
    printf("                                                           \n");  
    //delay(1); system("cls");
    delay(1);
    system("cls");

    printf("                                                           \n");
    printf("                                                           \n");                               
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                .:+++       //-`..                         \n");
    printf("                           ``-:o+o+o+  /////o+/:..         \n");
    printf("             ``-+oooo:::+=-.ossooo++=:                     \n");
    printf("                         ``-++sss---+o-o+:-/so+/--         \n");
    printf("             ``-+ooo```sssssssooo++-`                      \n");
    printf("                          `.:+soo```oo0a``osoo/`           \n");
    printf("              -+ooo:::==o:ssssss                           \n");
    printf("                             +oooo.``+o=+ssso              \n");
    printf("                  yyyo--o+`/ss                             \n");
    printf("                                 /..+./sss                 \n");
    printf("                       s. os                               \n");
    printf("                                    `:`                    \n");
    printf("                                                           \n");  
    //delay(1); system("cls");
    delay(1);
    system("cls");

    printf("                                                           \n");
    printf("                                                           \n");                               
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                 .:+++       //-`..                        \n");
    printf("                          ``-:o+o+o+  /////o+/:..          \n");
    printf("              ``-+oooo:::+=-.ossooo++=:                    \n");
    printf("                        ``-++sss---+o-o+:-/so+/--          \n");
    printf("              ``-+ooo```sssssssooo++-`                     \n");
    printf("                         `.:+soo```oo0a``osoo/`            \n");
    printf("               -+ooo:::==o:ssssss                          \n");
    printf("                            +oooo.``+o=+ssso               \n");
    printf("                    yyyo--o+`/ss                           \n");
    printf("                                /..+./sss                  \n");
    printf("                        s. os                              \n");
    printf("                                   `:`                     \n");
    printf("                                                           \n");  
    printf("                             W  E  L                       \n");
    //delay(1); system("cls");
    delay(1);
    system("cls");

    printf("                                                           \n");
    printf("                                                           \n");                               
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                  .:+++       //-`..                       \n");
    printf("                         ``-:o+o+o+  /////o+/:..           \n");
    printf("               ``-+oooo:::+=-.ossooo++=:                   \n");
    printf("                       ``-++sss---+o-o+:-/so+/--           \n");
    printf("               ``-+ooo```sssssssooo++-`                    \n");
    printf("                        `.:+soo```oo0a``osoo/`             \n");
    printf("                -+ooo:::==o:ssssss                         \n");
    printf("                           +oooo.``+o=+ssso                \n");
    printf("                     yyyo--o+`/ss                          \n");
    printf("                               /..+./sss                   \n");
    printf("                         s. os                             \n");
    printf("                                  `:`                      \n");
    printf("                                                           \n");  
    printf("                      W  E  L  C  O  M  E                  \n");
    //delay(1); system("cls");
    delay(1);
    system("cls");

    printf("                                                           \n");
    printf("                                                           \n");                               
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                    .:+++       //-`..                     \n");
    printf("                       ``-:o+o+o+  /////o+/:..             \n");
    printf("                 ``-+oooo:::+=-.ossooo++=:                 \n");
    printf("                     ``-++sss---+o-o+:-/so+/--             \n");
    printf("                 ``-+ooo```sssssssooo++-`                  \n");
    printf("                      `.:+soo```oo0a``osoo/`               \n");
    printf("                  -+ooo:::==o:ssssss                       \n");
    printf("                         +oooo.``+o=+ssso                  \n");
    printf("                       yyyo--o+`/ss                        \n");
    printf("                             /..+./sss                     \n");
    printf("                           s. os                           \n");
    printf("                                `:`                        \n");
    printf("                                                           \n");  
    printf("                 W  E  L  C  O  M  E                       \n");
    //delay(1); system("cls");
    delay(1);
    system("cls");
    
    printf("                                                           \n");
    printf("                                                           \n");                               
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                                                           \n");
    printf("                      .:+++       //-`..                   \n");
    printf("                    ``-:o+o+o+  /////o+/:..                \n");
    printf("                   ``-+oooo:::+=-.ossooo++=:               \n");
    printf("                   ``-++sss---+o-o+:-/so+/--               \n");
    printf("                   ``-+ooo```sssssssooo++-`                \n");
    printf("                    `.:+soo```oo0a``osoo/`                 \n");
    printf("                      -+ooo:::==o:ssssss                   \n");
    printf("                       +oooo.``+o=+ssso                    \n");
    printf("                         yyyo--o+`/ss                      \n");
    printf("                           /..+./sss                       \n");
    printf("                             s. os                         \n");
    printf("                              `:`                          \n");
    printf("                                                           \n");  
    printf("                 W  E  L  C  O  M  E    T  O               \n");
    //delay(1); system("cls");
    delay(1);
    system("cls");
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
    
    extraTurn = false;
    attackUp = false;
    endgame = false;
    ReadKonfigurasiFile(&S, &Map, &G);
    Turn(Player1(S)) = true;
    //welcome();
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
            //cek dapet instant reinforcement
            AddIR(&S);
            //fungsi end turn
            EndTurn(&S, &extraTurn, &attackUp);
            //print status player
            StatusPlayer(S,Map);
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
            StatusPlayer(S, Map);
        } else if (IsEQCKataString("HELP")){
            Help();
        } else if (IsEQCKataString("PRINT_GRAPH")) {
            PrintInfoGraph(G);
        } else if (IsEQCKataString("SAVE")) {
            save(SStacks, Map, G, extraTurn, attackUp, "p.txt");
        } else if (IsEQCKataString("LOAD")) {
            load(&SStacks, &Map, &G, &extraTurn, &attackUp, "p.txt");
            CopyState(InfoTop(SStacks), &S);
        } else{
            printf("COMMAND yang anda masukkan tidak tersedia, coba lagi!\n");
        }
        //Cek Kondisi Game Over
        GameEnd(S, &endgame);
    }

    return 0;
}