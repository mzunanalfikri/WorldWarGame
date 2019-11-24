#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include "./Modul Read File/readfile.h"
#include "./Modul Function/function.h"
#include "./Modul Function/welcome.h"
#include "./Modul Save Load/save_load.h"


int main() {
    // DEKLARASI ADT YANG DIGUNAKAN
    State S;
    StackState SStacks;
    MATRIKS Map;
    Graph G;
    //Deklarasi Variabel Global
    boolean endgame;
    boolean extraTurn;
    boolean attackUp;
    
    /*** ALGORITMA ***/
    extraTurn = false;
    attackUp = false;
    endgame = false;
    Kata player1, player2;

    //tampilan awal
    //welcome();
    //read configurasi file dan inisiasi awal
    ReadKonfigurasiFile(&S, &Map, &G);
    Turn(Player1(S)) = true;
    CreateEmptyStackState(&SStacks);
    PushState(&SStacks, S);

    //opsi load game atau mulai
    printf("            Opsi Memulai permainan : \n");
    printf("            [MULAI] Mulai Game Baru\n");
    printf("            [LOAD]  Load Game\n");
    printf("\n");
    printf("            Pilih Opsi : ");
    ReadCmd();
    while (!IsEQCKataString("LOAD") && !IsEQCKataString("MULAI")) {
        printf("            Opsi salah, masukkan opsi yang benar : ");
        ReadCmd();
    }

    
    if (IsEQCKataString("LOAD")) {
        load(&SStacks, &Map, &G, &extraTurn, &attackUp, &player1, &player2);
        CopyState(InfoTop(SStacks), &S);
        system("cls");
    } else if (IsEQCKataString("MULAI")) {
        //memasukkan nama pemain jika mulai dari awal
        printf("\n");
        printf("            Masukkan Nama Komandan Negara Api (Player 1) : ");
        ReadCmd();
        CopyKata(&player1, CKata);
        printf("            Masukkan Nama Komandan Negara Air (Player 2) : ");
        ReadCmd();
        CopyKata(&player2, CKata);
        system("cls");
    }
    
    //menampilkan nama pemain
    printf("\n");
    printf("            =====================================================================\n");
    printf("                            Player 1 (RED): ");
    CetakWarnaRed(player1); 
    printf("                            Player 2 (BLUE): ");
    CetakWarnaBlue(player2); 
    printf("            =====================================================================\n"); 

    printf("\n");
    RuleGame();
    printf("\n");
    
    printf("            Apakah KAMU SIAPPPP ? Tulis SIAPP untuk memulai permainan!\n");
    printf("            ");
    ReadCmd();
    while (!(IsEQCKataString("SIAPP"))){
        printf("            coba lagi, sepertinya kamu kurang siapp...\n");
        printf("            ");
        ReadCmd();
    }
    printf("\n");
    printf("            Mari bersiap. Kita akan memulai sesuatu yang panjang!!");
    printf(".");
    delay(1);
    printf(".");
    delay(1);
    printf(".");
    delay(1);
    system("cls");
    
    //turn pemain saat memulai permainan
    if (Turn(Player1(S))){
        printf("\n");
        printf("===================================\n");
        printf("======== Giliran Player 1! ========\n");
        printf("===================================\n");
        printf("\n");
    } else if (Turn(Player2(S))){
        printf("\n");
        printf("===================================\n");
        printf("======== Giliran Player 2! ========\n");
        printf("===================================\n");
        printf("\n");
    }
    //menampilkan status game
    StatusPlayer(S, Map,player1,player2);

    //main loop game
    while (!endgame){
        printf("\n");
        EnterCommad(S);
        ReadCmd();
        if (IsEQCKataString("ATTACK")){
            //memanggil fungsi attack
            Attack(&S, G, &attackUp);
            //push ke stack
            PushState(&SStacks, S);
            delay(1);
            system("cls");
            printf("\n");
            StatusPlayer(S,Map,player1,player2);
        } else if (IsEQCKataString("LEVEL_UP")){
            //panggil fungsi levelup
            LevelUp(&S);
            PushState(&SStacks, S);
            delay(1);
            system("cls");
            printf("\n");
            StatusPlayer(S,Map,player1,player2);
        } else if (IsEQCKataString("SKILL")){
            //manggil fungsi skill
            Skill(&S, &extraTurn, &attackUp); 
            //push ke stack
            PushState(&SStacks, S);
            EndTurnState(&SStacks);
            delay(1);
            system("cls");
            printf("\n");
            StatusPlayer(S,Map,player1,player2);
        } else if (IsEQCKataString("UNDO")) {
            //printf("Undo \n");
            Undo(&SStacks);
            CopyState(InfoTop(SStacks), &S);
            delay(1);
            system("cls");
            printf("\n");
            StatusPlayer(S,Map,player1,player2);
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
            // delay(1);
            // system("cls");
            // printf("\n");
            // StatusPlayer(S,Map,player1,player2);
        } else if (IsEQCKataString("MOVE")){
            //funsi pasukan
            MovePasukan(&S, G);
            //push ke stack
            PushState(&SStacks, S);
            delay(1);
            system("cls");
            printf("\n");
            StatusPlayer(S,Map,player1,player2);
        } else if (IsEQCKataString("EXIT")){
            //tampilan untuk exit
            printf("Apakah anda ingin menyimpan permainan ? Y/N\n");
            ReadCmd();
            if(IsEQCKataString("Y")){
                save(SStacks, Map, G, extraTurn, attackUp, player1, player2);
                printf("saving");
                printf(".");
                delay(1);
                printf(".");
                delay(1);
                printf(".\n");
                delay(1);
                printf("Save selesai.\n");
                delay(1);
                tampilanExit();
                endgame = true;
            }else if (IsEQCKataString("N")){
                tampilanExit();
                endgame = true;
            }
        } else if (IsEQCKataString("MAP")){
            //fungsi untuk memudahkan testing
            CetakMatiksWarna(Map, S);
            delay(2);
            system("cls");
            printf("\n");
            StatusPlayer(S,Map,player1,player2);
        } else if(IsEQCKataString("PRINT_ALL_BANGUNAN")){
            //fungsi untuk memudahkan testing
            PrintAllBangunan(ArrayBangunan(S));
            delay(1);
            //system("cls");
            TulisMATRIKS(Map);
            printf("\n");
            StatusPlayer(S,Map,player1,player2);
        } else if (IsEQCKataString("STATUS")) {
            StatusPlayer(S, Map,player1,player2);
            delay(2);
            system("cls");
            printf("\n");
            StatusPlayer(S,Map,player1,player2);
        } else if (IsEQCKataString("HELP")){
            Help();
            delay(2);
            system("cls");
            printf("\n");
            StatusPlayer(S,Map,player1,player2);
        } else if (IsEQCKataString("PRINT_GRAPH")) {
            //fungsi untuk memudahkan testing
            PrintInfoGraph(G);
            delay(1);
            system("cls");
            printf("\n");
            StatusPlayer(S,Map,player1,player2);
        } else if (IsEQCKataString("SAVE")) {
            //save game
            save(SStacks, Map, G, extraTurn, attackUp, player1, player2);
            printf("saving");
            printf(".");
            delay(1);
            printf(".");
            delay(1);
            printf(".\n");
            delay(1);
            printf("Save selesai.\n");
            delay(1);
            system("cls");
            printf("\n");
            StatusPlayer(S,Map,player1,player2);
        } else{
            printf("COMMAND yang anda masukkan tidak tersedia, coba lagi!\n");
            delay(1);
            system("cls");
            printf("\n");
            StatusPlayer(S,Map,player1,player2);
        }
        
        //cek kondisi akhir game
        GameEnd(S, &endgame);
    }

    return 0;
}