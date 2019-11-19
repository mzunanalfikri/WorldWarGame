#include <stdio.h>
#include "function.h"


/* **** SKILL **** */

/* ======================================
INTEGER DIPETAKAN KE SKILL :
1 --> Instant Upgrade
2 --> shield (BONUS)
3 --> Extra Turn , udah di cek nambah
4 --> Attack Up (BONUS)
5 --> Critical Hit (BONUS)
6 --> Instant Reinforcement, udah di cekk nambahh
7 --> Barrage, udah di cek nambahh
=========================================== */

// void NambahSkill(State *S){
//     if(Turn(Player1(*S))){
//         if(IsShield(*S)){
//             Add(&QSkill(Player1(*S)),2);
//         }
//         if(IsExtraTurn(*S)){
//             Add(&QSkill(Player1(*S)),3);
//         }
//         if(IsAttackUp(*S)){
//             Add(&QSkill(Player1(*S)),4);
//         }
//         if(IsCriticalHit(*S)){
//             Add(&QSkill(Player1(*S)),5);
//         }
//         if(IsIR(*S)){
//             Add(&QSkill(Player1(*S)),6);
//         }
//         if(IsBarrage(*S)){
//             Add(&QSkill(Player1(*S)),7);
//         }
//     }else if(Turn(Player2(*S))){
//         if(IsShield(*S)){
//             Add(&QSkill(Player2(*S)),2);
//         }
//         if(IsExtraTurn(*S)){
//             Add(&QSkill(Player2(*S)),3);
//         }
//         if(IsAttackUp(*S)){
//             Add(&QSkill(Player2(*S)),4);
//         }
//         if(IsCriticalHit(*S)){
//             Add(&QSkill(Player2(*S)),5);
//         }
//         if(IsIR(*S)){
//             Add(&QSkill(Player2(*S)),6);
//         }
//         if(IsBarrage(*S)){
//             Add(&QSkill(Player2(*S)),7);
//         }
//     }
// }
// void InstantUpgrade (State *S){
//     // addresslist P1,P2;
//     // if(Turn(Player1(*S))){
//     //     P1 = First(ListIdxBangunan(Player1(*S)));
//     //     while(P1 != NULL){
//     //         NaikLevel(ElmtTab(ArrayBangunan(*S),Info(P1));
//     //         P1=Next(ListIdxBangunan(Player1(*S)));
//     //     }
//     //     printf("Your Instant Upgrade Skill has been used\n");
//     //     printf("All of your building's level have been upgraded\n");
//     // }else i (Turn(Player2(*S))){
//     //     P2 = First(ListIdxBangunan(Player2(*S)));
//     //     while(P2 != NULL){
//     //         NaikLevel(ElmtTab(ArrayBangunan(*S),Info(P2));
//     //         P2=Next(ListIdxBangunan(Player2(*S)));
//     //     }
//     //     printf("Your Instant Upgrade Skill has been used\n");
//     //     printf("All of your building's level have been upgraded\n");
//     // }
// }
// /*Seluruh bangunan yang dimiliki pemain akan naik 1 level.
// Pemain tidak akan mendapat skill ini selain dari daftar skill awal.*/

// void Shield (State *S){ //bonus

// }
// /*
// Seluruh bangunan yang dimiliki oleh pemain akan memiliki pertahanan selama 2
// turn lawan. Apabila skill ini digunakan 2 kali berturut-turut, durasi tidak akan
// bertambah, namun menjadi nilai maksimum.
// */
// boolean IsShield (State S){

// }
void EndTurn (State *S, boolean * ExtraTurn)
/* kondisi P1 saat ini : P2 turn true, setiap bangunan di P2 bertambah pasukannya */
/* kondisi P2 saat ini : P1 trun true, setiap bangunan di P1 bertambah pasukannya */
 {
     addresslist P;
     boolean IR;
     IR = true;
     if (Turn(Player1(*S))){
         
         P = First(ListIdxBangunan(Player2(*S)));
         if (*ExtraTurn) {
             P = First(ListIdxBangunan(Player1(*S)));
             (*ExtraTurn) = false;
         } else {
            Turn(Player1(*S)) = false;
            Turn(Player2(*S)) = true;
         }
         while (P != NULL){
             AddNextTurn(&ElmtTab(ArrayBangunan(*S), Info(P)));
             P = Next(P);
             Serang(ElmtTab(ArrayBangunan(*S), Info(P))) = false;
             Move(ElmtTab(ArrayBangunan(*S), Info(P))) = false;
             //cek penambahan instant reinforcement
             if (Level(ElmtTab(ArrayBangunan(*S), Info(P))) != 4){
                 IR = false;
             }
         }
         //menambahkan instant reinforcement
         if (IR){
             Add(&QSkill(Player1(*S)), 6);
         }
         //ingetin update nge false in serang di bangunannya
         //sama move juga
        if (*ExtraTurn){
            printf("Extra Turn Activated, Player 1's Turn!\n ");
        } else {
            printf("\n");
            printf("===================================\n");
            printf("======== Player 2's Turn ! ========\n");
            printf("===================================\n");
            printf("\n");
        }
     } else if (Turn(Player2(*S))) {
         
         P = First(ListIdxBangunan(Player1(*S)));
         if (*ExtraTurn){
             P = First(ListIdxBangunan(Player2(*S)));
             (*ExtraTurn) = false;
         } else {
            Turn(Player2(*S)) = false;
            Turn(Player1(*S)) = true;
         }
         while (P != NULL){
             AddNextTurn(&ElmtTab(ArrayBangunan(*S), Info(P)));
             P = Next(P);
             Serang(ElmtTab(ArrayBangunan(*S), Info(P))) = false;
             Move(ElmtTab(ArrayBangunan(*S), Info(P))) = false;
             //cek penambahan instant reinforcement
             if (Level(ElmtTab(ArrayBangunan(*S), Info(P))) != 4){
                 IR = false;
             }
         }
         //menambahkan instant reinforcement
         if (IR){
             Add(&QSkill(Player2(*S)), 6);
         }
         if (*ExtraTurn){
            printf("Extra Turn Activated, Player 2's Turn!\n ");
        } else {
            printf("\n");
            printf("===================================\n");
            printf("======== Player 1's Turn ! ========\n");
            printf("===================================\n");
            printf("\n");
        }
     } 
 }

// void ExtraTurn (State *S){

// }
// /*Setelah giliran pengaktifan skill ini berakhir, pemain selanjutnya tetap pemain
// yang sama.
// */
// boolean IsExtraTurn (State S){

// }
// /*
// Pemain mendapat skill ini jika Fort pemain tersebut direbut lawan.
// */

// void AttackUp (State *S){ //bonus

// } 
// /*Pada giliran ini, setelah skill ini diaktifkan, pertahanan bangunan musuh (termasuk
// Shield) tidak akan mempengaruhi penyerangan.
// Pemain mendapat skill ini jika pemain baru saja menyerang Tower lawan dan
// jumlah towernya menjadi 3.*/

// boolean IsAttackUp (State S){

// }

// void CriticalHit (State *S){ //bonus

// }
// /*Pada giliran ini, setelah skill diaktifkan, jumlah pasukan pada bangunan yang
// melakukan serangan tepat selanjutnya (hanya berlaku 1 serangan) hanya
// efektif sebanyak 2 kali lipat pasukan. Skill ini
// akan menonaktifkan Shield maupun pertahanan bangunan, seperti Attack Up.
// Pemain mendapat skill ini jika lawan baru saja mengaktifkan skill Extra Turn.
// */
// boolean IsCriticalHit (State S){

// }
// void InstantReinforcement (State *S){
//     addresslist P1,P2;
//     if(Turn(Player1(*S))){
//         P1 = First(ListIdxBangunan(Player1(*S)));
//         while(P1 != NULL){
//             Pasukan(ElmtTab(ArrayBangunan(*S),Info(P1)))+=5;
//             P1=Next(P1);
//         }
//         printf("Your Instant Reinforcement Skill has been used\n");
//         printf("All of your building's army have been increased by 5\n");
//     }else i (Turn(Player2(*S))){
//         P2 = First(ListIdxBangunan(Player2(*S)));
//         while(P2 != NULL){
//             //Pasukan(ElmtTab(ArrayBangunan(*S),Info(P2))+=5;
//             P2=Next(ListIdxBangunan(Player2(*S)));
//         }
//         printf("Your Instant Reinforcement Skill has been used\n");
//         printf("All of your building's army have been increased by 5\n");
//     }
// }
// /*
// Seluruh bangunan mendapatkan tambahan 5 pasukan.
// */

// boolean IsIR (State S){
//     addresslist P;
//     boolean four = true;
//     P = First(ListIdxBangunan(Player1(*S)));
//     while((P != NULL)&&(four==true)){
//         if(Level(ElmtTab(ArrayBangunan(*S),Info(P1))!=4){
//             four = false;
//         }
//         else{
//             P=Next(ListIdxBangunan(Player1(*S)));
//         }
//     }
//     if(four){
//         return true;
//     }else{
//         return false;
//     }
// }
/*
Pemain mendapat skill ini di akhir gilirannya bila semua bangunan yang ia miliki
memiliki level 4.
*/
void Barrage (State *SMusuh){
    
}
/*Jumlah pasukan pada seluruh bangunan musuh akan berkurang sebanyak 10
pasukan.
Pemain mendapat skill ini jika lawan baru saja bertambah bangunannya menjadi
10 bangunan.*/

boolean IsBarrage (State SMusuh){
    
}


void StatusPlayer(State S, MATRIKS Map)
/* prosedur untuk menampilkan status player (map, bangunan, skill) */
{
    if (Turn(Player1(S))){
        CetakMatiksWarna(Map, S);
        
        printf("%s%c", RED, 'P');
        printf("%s", NORMAL);
        printf("%s%c", RED, 'L');
        printf("%s", NORMAL);
        printf("%s%c", RED, 'A');
        printf("%s", NORMAL);
        printf("%s%c", RED, 'Y');
        printf("%s", NORMAL);
        printf("%s%c", RED, 'E');
        printf("%s", NORMAL);
        printf("%s%c", RED, 'R');
        printf("%s", NORMAL);
        printf("%s%c", RED, ' ');
        printf("%s", NORMAL);
        printf("%s%c", RED, '1');
        printf("%s", NORMAL);
        printf("\n");

        printf("Daftar Bangunan : \n");
        addresslist P;
        int count;
        P = First(ListIdxBangunan(Player1(S)));
        count = 1;
        while (P != NULL){
            printf("%d. ", count);
            PrintBangunan(ElmtTab(ArrayBangunan(S), Info(P)));
            P = Next(P);
            count++;
        }

        PrintQSkill(QSkill(Player1(S)));
    } else if (Turn(Player2(S))) {
        CetakMatiksWarna(Map, S);
        
        printf("%s%c", BLUE, 'P');
        printf("%s", NORMAL);
        printf("%s%c", BLUE, 'L');
        printf("%s", NORMAL);
        printf("%s%c", BLUE, 'A');
        printf("%s", NORMAL);
        printf("%s%c", BLUE, 'Y');
        printf("%s", NORMAL);
        printf("%s%c", BLUE, 'E');
        printf("%s", NORMAL);
        printf("%s%c", BLUE, 'R');
        printf("%s", NORMAL);
        printf("%s%c", BLUE, ' ');
        printf("%s", NORMAL);
        printf("%s%c", BLUE, '2');
        printf("%s", NORMAL);
        printf("\n");

        printf("Daftar Bangunan : \n");
        addresslist P;
        int count;
        P = First(ListIdxBangunan(Player2(S)));
        count = 1;
        while (P != NULL){
            printf("%d. ", count);
            PrintBangunan(ElmtTab(ArrayBangunan(S), Info(P)));
            P = Next(P);
            count++;
        }

        PrintQSkill(QSkill(Player2(S)));
    }
}
/* **** ATTACK MECHANISM *** */

// Fungsi untuk cetak matriks dengan warna
void CetakMatiksWarna(MATRIKS M, State S)
/* Mencetak di layar matriks dengan warnanya */
{
    for(int i=1;i<=NKolEff(M)+2;i++){
        printf("*");
    }
    printf("\n");
    for(indeks j=GetFirstIdxBrs(M);j<=NBrsEff(M);j++){
        printf("*");
        for(indeks k=GetFirstIdxKol(M);k<=(NKolEff(M));k++){
            if (SearchB(ListIdxBangunan(Player1(S)), Id(ElmtMatriks(M, j, k)))){
                //print bangunan player 1
                //printf("%c1", Tipe(ElmtMatriks(M, j, k)));
                print_red(Tipe(ElmtMatriks(M, j, k)));
            } else if (SearchB(ListIdxBangunan(Player2(S)), Id(ElmtMatriks(M, j, k)))){
                //print bangunan player 2
                //printf("%c2", Tipe(ElmtMatriks(M, j, k)));
                print_blue(Tipe(ElmtMatriks(M, j, k)));
            } else {
                printf("%c", Tipe(ElmtMatriks(M, j, k)));
            }
            //printf("%c", Tipe(ElmtMatriks(M, j, k)));
        }
        printf("*\n");
    }
    //printf("\n");
    for(int l=1;l<=NKolEff(M)+2;l++){
        printf("*");
    }
    printf("\n");
}

void EnterCommad(State S)
/* prosedur untuk mencetak warna enter command sesuai playar */
{
    if (Turn(Player1(S))){
        printf("%s%c", RED, 'E');
        printf("%s", NORMAL);
        printf("%s%c", RED, 'N');
        printf("%s", NORMAL);
        printf("%s%c", RED, 'T');
        printf("%s", NORMAL);
        printf("%s%c", RED, 'E');
        printf("%s", NORMAL);
        printf("%s%c", RED, 'R');
        printf("%s", NORMAL);
        printf(" ");
        printf("%s%c", RED, 'C');
        printf("%s", NORMAL);
        printf("%s%c", RED, 'O');
        printf("%s", NORMAL);
        printf("%s%c", RED, 'M');
        printf("%s", NORMAL);
        printf("%s%c", RED, 'M');
        printf("%s", NORMAL);
        printf("%s%c", RED, 'A');
        printf("%s", NORMAL);
        printf("%s%c", RED, 'N');
        printf("%s", NORMAL);
        printf("%s%c", RED, 'D');
        printf("%s", NORMAL);
        printf(" ");
        printf("%s%c", RED, ':');
        printf("%s", NORMAL);
        printf(" ");
    } else if (Turn(Player2(S))){
        printf("%s%c", BLUE, 'E');
        printf("%s", NORMAL);
        printf("%s%c", BLUE, 'N');
        printf("%s", NORMAL);
        printf("%s%c", BLUE, 'T');
        printf("%s", NORMAL);
        printf("%s%c", BLUE, 'E');
        printf("%s", NORMAL);
        printf("%s%c", BLUE, 'R');
        printf("%s", NORMAL);
        printf(" ");
        printf("%s%c", BLUE, 'C');
        printf("%s", NORMAL);
        printf("%s%c", BLUE, 'O');
        printf("%s", NORMAL);
        printf("%s%c", BLUE, 'M');
        printf("%s", NORMAL);
        printf("%s%c", BLUE, 'M');
        printf("%s", NORMAL);
        printf("%s%c", BLUE, 'A');
        printf("%s", NORMAL);
        printf("%s%c", BLUE, 'N');
        printf("%s", NORMAL);
        printf("%s%c", BLUE, 'D');
        printf("%s", NORMAL);
        printf(" ");
        printf("%s%c", BLUE, ':');
        printf("%s", NORMAL);
        printf(" ");
    }
}

/************/
/* LEVEL UP */
/************/
void ChooseBangunanPlayerLevelUp(State S, int * x, boolean player1)
/* F.S. X menjadi indeks bangunan yang dipilih pemain */
{
    int temp;
    int indeks[31];
    printf("Daftar Bangunan : \n");
    addresslist P;
    int count;

    P = First(ListIdxBangunan(Player2(S)));
    if (player1){
        P = First(ListIdxBangunan(Player1(S)));
    }
    count = 1;
    while (P != NULL){
        printf("%d. ", count);
        PrintBangunan(ElmtTab(ArrayBangunan(S), Info(P)));
        indeks[count] = Info(P);
        P = Next(P);
        count++;
    }
    printf("Bangunan yang akan dinaikkan levelnya : ");
    //scanf("%d", &temp);
    ReadCmd();
    temp = KataToInt(CKata);
    while (temp >= count){
        printf ("Masukan salah, Bangunan yang akan dinaikkan levelnya :");
        //scanf("%d", &temp);
        ReadCmd();
        temp = KataToInt(CKata);
    }
    *x = indeks[temp];
}



void LevelUp(State * S)
/* Procedure untuk level up */
{
    int x;
    if (Turn(Player1(*S))) {
        ChooseBangunanPlayerLevelUp(*S, &x, true);
        //printf(" x : %d\n", x);
        NaikLevel(&ElmtTab(ArrayBangunan(*S), x));
    } else if (Turn(Player2(*S))) {
        ChooseBangunanPlayerLevelUp(*S, &x, false);
        NaikLevel(&ElmtTab(ArrayBangunan(*S), x));
    }
    
}

/************/
/*   MOVE   */
/************/
void ChooseBangunanPlayerMove(State S,Graph G, int *pendonor, int*penerima, boolean player1)
/* F.S. pendonor menjadi indeks bangunan yang mengirim, penerima menjadi bangunan yang 
        dipilih */
{
    int donor[31];
    int terima[31];
    int temp;

    //Pilih bangunan pendonor
    printf("Daftar Bangunan : \n");
    addresslist P;
    int count;

    P = First(ListIdxBangunan(Player2(S)));
    if (player1){
        P = First(ListIdxBangunan(Player1(S)));
    }
    count = 1;
    while (P != NULL){
        if (!Move(ElmtTab(ArrayBangunan(S), Info(P)))) {
            printf("%d. ", count);
            PrintBangunan(ElmtTab(ArrayBangunan(S), Info(P)));
            donor[count] = Info(P);
            count++;
        }
        P = Next(P);
    }
    if (count == 1){
        printf("Tidak ada pasukan yang bisa di move. \n");
        *pendonor = 0;
    } else {
        printf("Pilih bangunan : ");
        //scanf("%d", &temp);
        ReadCmd();
        temp = KataToInt(CKata);
        while (temp >= count || temp <= 0){
            printf ("Masukan salah, Bangunan yang akan dinaikkan levelnya :");
            //scanf("%d", &temp);
            ReadCmd();
            temp = KataToInt(CKata);
        }
        *pendonor = donor[temp];

        //Pilih bangunan penerima
        printf("Daftar bangunan terdekat : \n");
        P = First(ListIdxBangunan(Player2(S)));
        if (player1){
            P = First(ListIdxBangunan(Player1(S)));
        }
        count = 1;
        while (P != NULL){
            if (IsTerhubung(G, *pendonor, Info(P))) {
                printf("%d. ", count);
                PrintBangunan(ElmtTab(ArrayBangunan(S), Info(P)));
                terima[count] = Info(P);
                count++;
            }
            P = Next(P);
        }
        if (count == 1){
            printf("Tidak ada bangunan terdekat.\n");
            *penerima = 0;
        } else {
            printf("Bangunan yang akan menerima : ");
            //scanf("%d", &temp);
            ReadCmd();
            temp = KataToInt(CKata);
            while (temp >= count || temp <= 0){
                printf ("Masukan salah, Bangunan yang akan dinaikkan levelnya :");
                //scanf("%d", &temp);
                ReadCmd();
                temp = KataToInt(CKata);
            }
            *penerima = terima[temp];
        }
    }
    //cek list player, Terhubung(pendonor, bangunan yang ada di list), if true, tampilkan
}

void MovePasukaB1B2(State *S, int pendonor, int penerima)
/* Fungsi transisi untuk move pasukan */
{
    int x;
    printf("Jumlah pasukan : ");
    ReadCmd();
    x = KataToInt(CKata);
    while (Pasukan(ElmtTab(ArrayBangunan(*S), pendonor)) < x) {
        printf("Jumlah pasukan tidak valid, masukkan pasukan lagi : ");
        ReadCmd();
        x = KataToInt(CKata);
    }
    Move(ElmtTab(ArrayBangunan(*S), pendonor)) = true;
    Pasukan(ElmtTab(ArrayBangunan(*S), pendonor)) = Pasukan(ElmtTab(ArrayBangunan(*S), pendonor)) - x;
    Pasukan(ElmtTab(ArrayBangunan(*S), penerima)) = Pasukan(ElmtTab(ArrayBangunan(*S), penerima)) + x;
    printf("%d Pasukan dari ", x);
    PrintTipeBangunan(Type(ElmtTab(ArrayBangunan(*S), pendonor)));
    printf(" ");
    TulisPOINT(Posisi(ElmtTab(ArrayBangunan(*S), pendonor)));
    printf(" telah berpindah ke ");
    PrintTipeBangunan(Type(ElmtTab(ArrayBangunan(*S), penerima)));
    printf(" ");
    TulisPOINT(Posisi(ElmtTab(ArrayBangunan(*S), penerima)));
    printf("\n");
}

void MovePasukan(State *S, Graph G)
/* Procedure untuk memindahkan pasukan dari bangunan satu ke lainnya */
{
    int pendonor;
    int penerima;
    if (Turn(Player1(*S))) {
        ChooseBangunanPlayerMove(*S, G, &pendonor, &penerima, true );
        printf("pendonor  : %d | penerima : %d \n", pendonor, penerima);
        if (pendonor == 0 || penerima == 0){
            printf("Move gagal.\n");
        } else {
            MovePasukaB1B2(S, pendonor, penerima);
        }
        //printf(" x : %d\n", x);
    } else if (Turn(Player2(*S))) {
        ChooseBangunanPlayerMove(*S, G, &pendonor, &penerima, false );
        if (pendonor == 0 || penerima == 0){
            printf("Move gagal.\n");
        } else {
            MovePasukaB1B2(S, pendonor, penerima);
        }
    }
}

/**************/
/*   ATTACK   */
/**************/
void ChooseBangunanPlayerAttack(State S, Graph G, int *serang, int *defend, boolean player1)
/* F.S. serang menjadi indeks bangunan penyerang, defend menjadi indeks bangunan
        yang bertahan */
{
    int att[31];
    int def[31];
    int temp;

    //Pilih bangunan pendonor
    printf("Daftar Bangunan : \n");
    addresslist P;
    int count;

    P = First(ListIdxBangunan(Player2(S)));
    if (player1){
        P = First(ListIdxBangunan(Player1(S)));
    }
    count = 1;
    while (P != NULL){
        if (!Serang(ElmtTab(ArrayBangunan(S), Info(P)))) {
            printf("%d. ", count);
            PrintBangunan(ElmtTab(ArrayBangunan(S), Info(P)));
            att[count] = Info(P);
            count++;
        }
        P = Next(P);
    }
    if (count == 1){
        printf("Tidak ada bangunan yang bisa Attack. \n");
        *serang = 0;
    } else {
        printf("Bangunan yang digunakan untuk menyerang : ");
        //scanf("%d", &temp);
        ReadCmd();
        temp = KataToInt(CKata);
        while (temp >= count || temp <= 0){
            printf ("Masukan salah, Bangunan yang digunakan untuk menyerang :");
            //scanf("%d", &temp);
            ReadCmd();
            temp = KataToInt(CKata);
        }
        *serang = att[temp];

        //Pilih bangunan penerima
        printf("Daftar bangunan yang dapat diserang : \n");
        List L;
        L = (ListIdxBangunan(Player2(S)));
        if (player1){
            L = (ListIdxBangunan(Player1(S)));
        }
        
        P = First(Child(SearchParent(G, *serang)));
        count = 1;
        while (P != NULL){
            if (!SearchB(L, Info(P))) {
                printf("%d. ", count);
                PrintBangunan(ElmtTab(ArrayBangunan(S), Info(P)));
                def[count] = Info(P);
                count++;
            }
            P = Next(P);
        }
        if (count == 1){
            printf("Tidak ada bangunan yang diserang.\n");
            *defend = 0;
        } else {
            printf("Bangunan yang diserang: ");
            //scanf("%d", &temp);
            ReadCmd();
            temp = KataToInt(CKata);
            while (temp >= count || temp <= 0){
                printf ("Masukan salah, Bangunan yang diserang: ");
                //scanf("%d", &temp);
                ReadCmd();
                temp = KataToInt(CKata);
            }
            *defend = def[temp];
        }
    }
}

void PreAttack(State *S, int serang, int defend)
/* prosedur transisi untuk attack */
{
    boolean akuisisi;
    akuisisi = false;
    int x;
    printf("Jumlah pasukan : ");
    ReadCmd();
    x = KataToInt(CKata);
    while (Pasukan(ElmtTab(ArrayBangunan(*S), serang)) < x || x < 0) {
        printf("Jumlah pasukan tidak valid, masukkan pasukan lagi : ");
        ReadCmd();
        x = KataToInt(CKata);
    }
    if (Pertahanan(ElmtTab(ArrayBangunan(*S), defend))){
        printf("lawan ada pertahanan \n");
        if (x >= Pasukan(ElmtTab(ArrayBangunan(*S), defend))*4/3){
            Pasukan(ElmtTab(ArrayBangunan(*S), serang)) -= x;
            Pasukan(ElmtTab(ArrayBangunan(*S), defend)) = x - Pasukan(ElmtTab(ArrayBangunan(*S), defend))*4/3;
            Netral(ElmtTab(ArrayBangunan(*S), defend)) = false;
            if (Turn(Player1(*S))){
                DelP(&ListIdxBangunan(Player2(*S)), defend);
                InsVFirst(&ListIdxBangunan(Player1(*S)), defend);
            } else if (Turn(Player2(*S))) {
                DelP(&ListIdxBangunan(Player1(*S)), defend);
                InsVFirst(&ListIdxBangunan(Player2(*S)), defend);
            }
            akuisisi = true;
        } else {
            Pasukan(ElmtTab(ArrayBangunan(*S), serang)) -= x;
            Pasukan(ElmtTab(ArrayBangunan(*S), defend)) -= x*3/4;
            printf("Bangunan gagal direbut. \n");
        }
    } else {
        printf("lawan ngga ada pertahanan\n");
        if (x >= Pasukan(ElmtTab(ArrayBangunan(*S), defend))){
            Pasukan(ElmtTab(ArrayBangunan(*S), serang)) -= x;
            Pasukan(ElmtTab(ArrayBangunan(*S), defend)) = x - Pasukan(ElmtTab(ArrayBangunan(*S), defend));
            Netral(ElmtTab(ArrayBangunan(*S), defend)) = false;
            if (Turn(Player1(*S))){
                DelP(&ListIdxBangunan(Player2(*S)), defend);
                InsVFirst(&ListIdxBangunan(Player1(*S)), defend);
            } else if (Turn(Player2(*S))) {
                DelP(&ListIdxBangunan(Player1(*S)), defend);
                InsVFirst(&ListIdxBangunan(Player2(*S)), defend);
            }
            akuisisi = true;
        } else {
            Pasukan(ElmtTab(ArrayBangunan(*S), serang)) -= x;
            Pasukan(ElmtTab(ArrayBangunan(*S), defend)) -= x;
            printf("Bangunan gagal direbut. \n");
        }
    }
    Serang(ElmtTab(ArrayBangunan(*S), serang)) = true;
    //pengecekan penambahan skill
    if (akuisisi){
        if (Turn(Player1(*S))){
            //Cek dapet extra turn
            if (Type(ElmtTab(ArrayBangunan(*S), defend)) == 'F' ){
                Add(&QSkill(Player2(*S)), 3);
                printf("Player 2 mendapatkan Skill Extra Turn \n");
            }
            //cek dapet barrage
            if (NbElmtList(ListIdxBangunan(Player1(*S))) == 10){
                Add(&QSkill(Player2(*S)), 7);
                printf("Player 2 mendatapkan Skill Barrage \n");
            }
        } else if(Turn(Player2(*S))) {
            //Cek dapet extra turn
            if (Type(ElmtTab(ArrayBangunan(*S), defend)) == 'F' ){
                Add(&QSkill(Player1(*S)), 3);
                printf("Player 1 mendapatkan Skill Extra Turn \n");
            }
            //cek dapet barrage
            if (NbElmtList(ListIdxBangunan(Player2(*S))) == 10){
                Add(&QSkill(Player1(*S)), 7);
                printf("Player 1 mendatapkan Skill Barrage \n");
            }
        }
    }
}

void Attack(State *S, Graph G)
/* Procedure untuk memindahkan pasukan dari bangunan satu ke lainnya */
{
    int attack;
    int defend;
    if (Turn(Player1(*S))) {
        ChooseBangunanPlayerAttack(*S, G, &attack, &defend, true );
        printf("attack  : %d | defend : %d \n", attack, defend);
        if (attack == 0 || defend == 0){
            printf("Attack gagal.\n");
        } else {
            PreAttack(S, attack, defend);
        }
        //printf(" x : %d\n", x);
    } else if (Turn(Player2(*S))) {
        ChooseBangunanPlayerAttack(*S, G, &attack, &defend, false );
        printf("attack  : %d | defend : %d \n", attack, defend);
        if (attack == 0 || defend == 0){
            printf("Attack gagal.\n");
        } else {
           PreAttack(S, attack, defend);
        }
    }
}