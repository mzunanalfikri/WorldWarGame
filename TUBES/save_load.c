
#include "save_load.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* ask_file_name() {
    // KAMUS
    char* file_path;

    // ALGORITMA
    scanf("%s", &file_path);

    return file_path;
}


void save(StackState StackS, MATRIKS M, Graph G, boolean extraTurn, boolean attackUp, Kata player1, Kata player2)
// I.S. StackS, M, G, extraTurn, attackUp, filepath terdefinisi
// F.S. Data pada StackS, M, G, extraTurn, attackUp disimpan pada file yang ada pada filepath
    {
        // KAMUS
        FILE * save_file;
        char* filepath;
        Kata fpath;
        char save_file_path[260];
        char* currCWD, neoPath;
        int i, j, num_of_banguns, tempInt;
        addressParent bangunode;
        addresslist bangbung;
        addresslist Pbangun;

        // ALGORITMA
        //neoPath = strcat(currCWD, "\\");
        //neoPath = strcat(neoPath, filepath);
        //printf("Filepath is : %s\n", filepath);
        printf("File path lokasi save file : ");

        filepath = "D:\\github\\TubesAlstrukdat1\\TUBES\\s.txt"; // Need to make this dynamic but don't know how

        scanf("%s", save_file_path);

        //ReadCmd();

        //CopyKata(&fpath, CKata);
        
        printf("Save file akan di simpan di ");
        printf("%s\n", save_file_path);
        //TulisCKata(fpath);
        //printf("\n");

        save_file = fopen(save_file_path, "w");

        if (save_file == NULL) {
            printf("Tidak bisa membuat dan membuka file.\n");
            return;
        }

        // D:\\github\\TubesAlstrukdat1\\TUBES\\s.txt
        fprintf(save_file, "AVATARWORLDWARSAVE\n"); // Basically a header

        fprintf(save_file, "%d %d\n", M.NBrsEff, M.NKolEff); // Saves map size

        num_of_banguns = MaxElArray(ArrayBangunan(InfoTop(StackS)));

        fprintf(save_file, "%d\n", num_of_banguns);

        for (i = 1; i <= num_of_banguns; ++i) { // saves bangunans
            fprintf(save_file, "%c %d %d\n",
                Type(ElmtTab(ArrayBangunan(InfoTop(StackS)), i)),
                Absis(Posisi(ElmtTab(ArrayBangunan(InfoTop(StackS)), i))),
                Ordinat(Posisi(ElmtTab(ArrayBangunan(InfoTop(StackS)), i)))
            );
        }

        // saving the graph
        bangunode = FirstParent(G);
        while (bangunode != NULL) {
            bangbung = First(Child(bangunode));
            j = 1;
            while ( bangbung != NULL ) {
                while (Info(bangbung) > j) {
                    fprintf(save_file, "0 ");
                    ++j;
                }
                if (j == num_of_banguns) {
                    fprintf(save_file, "1\n");
                } else {
                    fprintf(save_file, "1 ");
                }
                ++j;
                bangbung = Next(bangbung);
            }
            while (j <= num_of_banguns) {
                if (j == num_of_banguns) {
                    fprintf(save_file, "0\n");
                } else {
                    fprintf(save_file, "0 ");
                }
                ++j;
            }
            bangunode = NextParent(bangunode);
        }
        //c

        // Saving the current game config is done, time to save the states

        // Saves things that last the whole turn first

        fprintf(save_file, "%s\n", (Turn(Player1(InfoTop(StackS))) ? "1" : (Turn(Player2(InfoTop(StackS))) ? "2" : "0"))); // Saves current turn marker
        fprintf(save_file, "%s\n", (attackUp ? "aUy" : "aUn")); // Saves attackUp state
        fprintf(save_file, "%s\n", (extraTurn ? "eTy" : "eTn")); // Saves extraTurn state

        // saves player names
        for (i = 1; i <= player1.Length; ++i) {
            fprintf(save_file, "%c", player1.TabKata[i]);
        }
        fprintf(save_file, "\n", player1.TabKata[i]);
        for (i = 1; i <= player2.Length; ++i) {
            fprintf(save_file, "%c", player2.TabKata[i]);
        }
        fprintf(save_file, "\n", player1.TabKata[i]);
        

        // Now, on to saving the actual game states (in the stack)

        fprintf(save_file, "%s\n", (CritHit(InfoTop(StackS)) ? "cHy" : "cHn")); // Saves critical hit state
        
        // Saves bangunans (Level, pasukan, Serang, Move)
        for (i = 1; i <= num_of_banguns; ++i) {
            fprintf(save_file, "%d %d %s %s\n",
                Level(ElmtTab(ArrayBangunan(InfoTop(StackS)), i)),
                Pasukan(ElmtTab(ArrayBangunan(InfoTop(StackS)), i)),
                (Serang(ElmtTab(ArrayBangunan(InfoTop(StackS)), i)) ? "batdy" : "batdn"),
                (Move(ElmtTab(ArrayBangunan(InfoTop(StackS)), i)) ? "bmtdy" : "bmtdn")
            );
        }

        // Saves player stuffs (idx, skill, shield)
        // Player 1
        Pbangun = First(ListIdxBangunan(Player1(InfoTop(StackS))));
        while (Pbangun != NULL) {
            fprintf(save_file, "%d ", Info(Pbangun));
            Pbangun = Next(Pbangun);
        }
        fprintf(save_file, "\np1s\n");

        while (!IsEmpty(QSkill(Player1(InfoTop(StackS))))) {
            Del(&QSkill(Player1(InfoTop(StackS))), &tempInt);
            fprintf(save_file, "%d ", tempInt);
        }
        //fprintf(save_file, "\n");

        fprintf(save_file, "\np1bs%d\n", ShieldPlayer(Player1(InfoTop(StackS))));

        // Player 2
        Pbangun = First(ListIdxBangunan(Player2(InfoTop(StackS))));
        while (Pbangun != NULL) {
            fprintf(save_file, "%d ", Info(Pbangun));
            Pbangun = Next(Pbangun);
        }
        fprintf(save_file, "\np2s\n");

        while (!IsEmpty(QSkill(Player2(InfoTop(StackS))))) {
            Del(&QSkill(Player2(InfoTop(StackS))), &tempInt);
            fprintf(save_file, "%d ", tempInt);
        }
        //fprintf(save_file, "\n");

        fprintf(save_file, "\np2bs%d\n", ShieldPlayer(Player2(InfoTop(StackS))));

        fprintf(save_file, "_AVATARWORLDWARSAVE_");

        printf("Save selesai.\n");

        fclose(save_file);
    }

void load(StackState *StackS, MATRIKS *M, Graph *G, boolean *extraTurn, boolean *attackUp, Kata *player1, Kata *player2)
// I.S. StackS, M, G, extraTurn, attackUp sembarang; filepath terdefinisi
// F.S. Data pada StackS, M, G, extraTurn, attackUp sesuai data yang ada pada file yang ada pada filepath
    {
        // KAMUS
        FILE * save_file;
        char* filepath;
        char save_file_path[260];
        int i, j, Mat_x, Mat_y, num_of_banguns, tempInt;
        State baseState, tempState;
        Queue tempQ;
        addressParent bangunode;
        addresslist bangbung;
        addresslist Pbangun;

        // ALGORITMA
        filepath = "s.txt"; // Need to make this dynamic but don't know how

        printf("Lokasi save file : ");
        scanf("%s", save_file_path);

        LoadFile(save_file_path);

        // ** Basically reads the configuration file to create a base state

        if (IsEQCKataString("AVATARWORLDWARSAVE")) {
            printf("Save file dikenali. Memulai loading...\n");
            ADVKATA();
        } else {
            printf("Save file salah atau rusak.\n");
            return;
        }

        Mat_x = KataToInt(CKata);
        ADVKATA();
        //TulisCKata(CKata);
        Mat_y = KataToInt(CKata);

        MakeMATRIKS(Mat_x, Mat_y, M);

        ADVKATA();

        num_of_banguns = KataToInt(CKata);

        MakeState(&baseState, num_of_banguns);

        ADVKATA();

        baca_array_bangunan(&ArrayBangunan(baseState), num_of_banguns, M);

        /* MAKE GRAF */
        CreateEmptyGraph(G);

        /* MAKE GRAF END */
        BacaGraf(G,num_of_banguns);
        ADVKATA();

        // !! Configuration section ended, base state created

        // Gets whose turn it is
        if(IsEQCKataInt(1)) {
            Turn(Player1(baseState)) = true;
            Turn(Player2(baseState)) = false;
        } else if (IsEQCKataInt(2)) {
            Turn(Player1(baseState)) = false;
            Turn(Player2(baseState)) = true;
        } else {
            printf("Player turn state tidak dikenali.\n");
        }
        
        ADVKATA();

        // Gets attackUp state
        if (IsEQCKataString("aUy")) {
            *attackUp = true;
        } else if(IsEQCKataString("aUn")) {
            *attackUp = false;
        } else{
            printf("Attack up state tidak dikenali.\n");
        }

        ADVKATA();

        // Gets extraTurn state
        if (IsEQCKataString("eTy")) {
            *extraTurn = true;
        } else if(IsEQCKataString("eTn")) {
            *extraTurn = false;
        } else{
            printf("Extra turn state tidak dikenali.\n");
        }

        ADVKATA();

        // Gets player names
        CopyKata(player1, CKata);
        ADVKATA();
        CopyKata(player2, CKata);
        ADVKATA();

        // starts creating individual states
        MakeState(&tempState, num_of_banguns);
        CopyState(baseState, &tempState);

        // Gets critical hit state
        if (IsEQCKataString("cHy")) {
            CritHit(tempState) = true;
        } else if(IsEQCKataString("cHn")) {
            CritHit(tempState) = false;
        } else{
            printf("Ciritcal hit state tidak dikenali.\n");
        }

        ADVKATA();

        // Inserts bangunans
        for (i = 1; i <= num_of_banguns; ++i) {
            
            Pasukan(ElmtTab(ArrayBangunan(tempState), i)) = 999;
            tempInt = KataToInt(CKata);
            while (Level(ElmtTab(ArrayBangunan(tempState), i)) < tempInt && Level(ElmtTab(ArrayBangunan(tempState), i)) < 4) {
                NaikLevel(&ElmtTab(ArrayBangunan(tempState), i));
            };

            ADVKATA();

            Pasukan(ElmtTab(ArrayBangunan(tempState), i)) = KataToInt(CKata);
            ADVKATA();

            if (IsEQCKataString("batdy")) {
                Serang(ElmtTab(ArrayBangunan(tempState), i)) = true;
            } else if (IsEQCKataString("batdn")) {
                Serang(ElmtTab(ArrayBangunan(tempState), i)) = false;
            } else {
                printf("Building attack state tidak dikenali.\n");
            };

            ADVKATA();

            if(IsEQCKataString("bmtdy")) {
                Move(ElmtTab(ArrayBangunan(tempState), i)) = true;
            } else if (IsEQCKataString("bmtdn")) {
                Move(ElmtTab(ArrayBangunan(tempState), i)) = false;
            } else {
                printf("Building move state tidak dikenali.\n");
            }

            ADVKATA();
        }

        // Gets PLayer 1's bangunan list
        while (!IsEQCKataString("p1s")) {
            InsVLast(&ListIdxBangunan(Player1(tempState)), KataToInt(CKata));
            ADVKATA();
        }

        ADVKATA();

        // Gets player 1's skill queue
        CreateEmpty(&QSkill(Player1(tempState)), 10);
        while (!IsEQCKataString("p1bs0") && !IsEQCKataString("p1bs1") && !IsEQCKataString("p1bs2")) {
            Add(&QSkill(Player1(tempState)), KataToInt(CKata));
            ADVKATA();
        }

        // Gets player 1's shield state
        if (IsEQCKataString("p1bs0")) {
            ShieldPlayer(Player1(tempState)) = 0;
        } else if (IsEQCKataString("p1bs1")) {
            ShieldPlayer(Player1(tempState)) = 1;
        } else if (IsEQCKataString("p1bs2")) {
            ShieldPlayer(Player1(tempState)) = 2;
        } else {
            printf("Player 1 shield state tidak dikenali.\n");
        }

        ADVKATA();

        // Gets PLayer 2's bangunan list
        while (!IsEQCKataString("p2s")) {
            InsVLast(&ListIdxBangunan(Player2(tempState)), KataToInt(CKata));
            ADVKATA();
        }

        ADVKATA();
        
        CreateEmpty(&QSkill(Player2(tempState)), 10);
        while (!IsEQCKataString("p2bs0") && !IsEQCKataString("p2bs1") && !IsEQCKataString("p2bs2")) {
            Add(&QSkill(Player2(tempState)), KataToInt(CKata));
            ADVKATA();
        }

        // Gets player 2's shield state
        if (IsEQCKataString("p2bs0")) {
            ShieldPlayer(Player2(tempState)) = 0;
        } else if (IsEQCKataString("p2bs1")) {
            ShieldPlayer(Player2(tempState)) = 1;
        } else if (IsEQCKataString("p2bs2")) {
            ShieldPlayer(Player2(tempState)) = 2;
        } else {
            printf("Player 2 shield state tidak dikenali.\n");
        }

        //ADVKATA();

        printf("Loading selesai.\n");
        
        FINISH();

        PushState(StackS, tempState);

        EndTurnState(StackS);

    }