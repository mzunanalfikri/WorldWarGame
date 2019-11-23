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
    if (Turn(Player1(*S))){
        EnterCommad(*S);
        ReadCmd();
        if (IsEQCKataString("Instant Upgrade")){
            Add(&QSkill(Player1(*S)),1);
        } else if (IsEQCKataString("Shield")){
            Add(&QSkill(Player1(*S)),2);
        } else if (IsEQCKataString("ExtraTurn")){
            Add(&QSkill(Player1(*S)),3);
        } else if (IsEQCKataString("Attack Up ")) {
            Add(&QSkill(Player1(*S)),4);
        } else if (IsEQCKataString("Critical Hit")){
            Add(&QSkill(Player1(*S)),5);
        } else if (IsEQCKataString("IR")){
            Add(&QSkill(Player1(*S)),6);
        } else if (IsEQCKataString("Barrage")){
            Add(&QSkill(Player1(*S)),7);
        }
        PrintQSkill(QSkill(Player1(*S)));
    } else if (Turn(Player2(*S))) {
        EnterCommad(*S);
        ReadCmd();
        if (IsEQCKataString("Instant Upgrade")){
            Add(&QSkill(Player2(*S)),1);
        } else if (IsEQCKataString("Shield")){
            Add(&QSkill(Player2(*S)),2);
        } else if (IsEQCKataString("ExtraTurn")){
            Add(&QSkill(Player2(*S)),3);
        } else if (IsEQCKataString("Attack Up ")) {
            Add(&QSkill(Player2(*S)),4);
        } else if (IsEQCKataString("Critical Hit")){
            Add(&QSkill(Player2(*S)),5);
        } else if (IsEQCKataString("IR")){
            Add(&QSkill(Player2(*S)),6);
        } else if (IsEQCKataString("Barrage")){
            Add(&QSkill(Player2(*S)),7);
        }
        PrintQSkill(QSkill(Player2(*S)));
    }
}

 void SetBangunan (Bangunan *B)
{
    int lv,serang,pertahanan,move,pasukan,A,M;
    char type;
    printf("level: ");
    scanf("%d",&lv);
    Level(*B) = lv;
    printf("serang?(1/0): ");
    scanf("%d",&serang);
    Serang(*B) = serang;
    printf("pertahanan?(1/0): ");
    scanf("%d",&pertahanan);
    Pertahanan(*B) = pertahanan;
    printf("Tipe bangunan? :");
    scanf(" %c",&type);
    Type(*B) = type;
    printf("Move( 1/0)? :");
    scanf("%d",&move);
    Move(*B) = move;
    printf("pasukan? ");
    scanf("%d",&pasukan);
    Pasukan(*B) = pasukan;
    printf("A? :");
    scanf("%d",&A);
    A(*B) = A;
    printf("M? :");
    scanf("%d",&M);
    M(*B) = M;
}

void PrintPlayerBangunan(State S, int *manipulate, boolean player1){
    int list[31];
    int temp;
    addresslist P;
    int count;

    printf("Daftar Bangunan : \n");
    P = First(ListIdxBangunan(Player2(S)));
    if (player1){
        P = First(ListIdxBangunan(Player1(S)));
    }
    count = 1;
    while (P != NULL){
        printf("%d. ", count);
        PrintBangunan(ElmtTab(ArrayBangunan(S), Info(P)));
        list[count] = Info(P);
        count++;
        P = Next(P);
    }
    if (count == 1){
        printf("Tidak ada bangunan yang kamu punya!. \n");
        *manipulate = 0;
    } else {
        printf("Bangunan yang ingin dimanipulasi : ");
        //scanf("%d", &temp);
        ReadCmd();
        temp = KataToInt(CKata);
        while (temp >= count || temp <= 0){
            printf ("Masukan salah!\nBangunan yang digunakan untuk dimanipulasi :");
            //scanf("%d", &temp);
            ReadCmd();
            temp = KataToInt(CKata);
        }
        *manipulate = list[temp];
    }
}

void SetPlayersBangunan(State *S){
    int n;
    infotype i;
    int x;
    if (Turn(Player1(*S))){
        while (!IsEmptyList(ListIdxBangunan(Player1(*S)))){
            DelVFirst(&ListIdxBangunan(Player1(*S)), &i);
        }
    } else if (Turn(Player2(*S))) {
        while (!IsEmptyList(ListIdxBangunan(Player2(*S)))){
            DelVFirst(&ListIdxBangunan(Player2(*S)), &i);
        }
    }
    printf("Mau berapa bangunan? ");
    scanf("%d",&n);
    
    while (n > 0){
        printf("masukkan indeks bangunan: ");
        scanf("%d",&x);
        if (Turn(Player1(*S))){
            InsVLast(&ListIdxBangunan(Player1(*S)), x);
            if (SearchB(ListIdxBangunan(Player2(*S)),x)){
                DelP(&ListIdxBangunan(Player2(*S)), x);
            }
        } else if (Turn(Player2(*S))) {
            InsVLast(&ListIdxBangunan(Player2(*S)), x);
            if (SearchB(ListIdxBangunan(Player1(*S)),x)){
                DelP(&ListIdxBangunan(Player1(*S)), x);
            }
        }
        n--;
    }
}

void SetLvBangunanTo4(State *S){
    InstantUpgrade(S);
    InstantUpgrade(S);
    InstantUpgrade(S);
}

int main() {
    // DEKLARASI ADT YANG DIGUNAKAN
    State S;
    StackState SStacks;
    MATRIKS Map;
    Graph G;
    
    int X;
    boolean endgame;
    boolean extraTurn;
    boolean attackUp;
    
    extraTurn = false;
    attackUp = false;
    endgame = false;
    Kata player1, player2;

    welcome();
    //tampilin rule game jugaa


    printf("Masukkan Nama Player 1 : ");
    ReadCmd();
    CopyKata(&player1, CKata);
    printf("Masukkan Nama Player 2 : ");
    ReadCmd();
    CopyKata(&player2, CKata);

    printf("=======================================\n");
    printf("          Player 1 (RED): ");
    CetakWarnaRed(player1); 
    printf("          Player 2 (BLUE): ");
    CetakWarnaBlue(player2); 
    printf("=======================================\n"); 

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
    Help();
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
        } else if (IsEQCKataString("SET_SKILL")){
            //manggil fungsi skill
            SetSkill(&S);
        } else if (IsEQCKataString("SET_BANGUNAN")){
            //manggil fungsi skill
            PrintPlayerBangunan(S,&X,Turn(Player1(S)));
            SetBangunan(&(ElmtTab(ArrayBangunan(S),X)));
        } else if (IsEQCKataString("SET_PLAYERS_BANGUNAN")){
            //manggil fungsi skill
            PrintAllBangunan(ArrayBangunan(S));
            SetPlayersBangunan(&S);
        } else if (IsEQCKataString("SET_BANGUNAN_LV4")){
            //manggil fungsi skill
            SetLvBangunanTo4(&S);  
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
            //save(SStacks, Map, G, extraTurn, attackUp, "p.txt");
        } else if (IsEQCKataString("LOAD")) {
            //load(&SStacks, &Map, &G, &extraTurn, &attackUp, "p.txt");
            CopyState(InfoTop(SStacks), &S);
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