
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


void save(StackState StackS, MATRIKS M, Graph G, boolean extraTurn, boolean attackUp, char* filepath)
// I.S. StackS, M, G, extraTurn, attackUp, filepath terdefinisi
// F.S. Data pada StackS, M, G, extraTurn, attackUp disimpan pada file yang ada pada filepath
    {
        // KAMUS
        FILE * save_file;
        char* currCWD, neoPath;
        int i, j, num_of_banguns, tempInt;
        addressParent bangunode;
        addresslist bangbung;
        addresslist Pbangun;

        // ALGORITMA
        //neoPath = strcat(currCWD, "\\");
        //neoPath = strcat(neoPath, filepath);
        //printf("Filepath is : %s\n", filepath);

        filepath = "D:\\github\\TubesAlstrukdat1\\TUBES\\s.txt"; // Need to make this dynamic but don't know how

        save_file = fopen(filepath, "w");

        if (save_file == NULL) {
            printf("Tidak bisa membuat dan membuka file.\n");
            return;
        }

        // D:\\github\\TubesAlstrukdat1\\TUBES\\s.txt

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

        // Now, on to saving the actual game states (in the stack)
        
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

        printf("Save done\n");

        fclose(save_file);
    }

void load(StackState *StackS, MATRIKS *M, Graph *G, boolean *extraTurn, boolean *attackUp, char* filepath)
// I.S. StackS, M, G, extraTurn, attackUp sembarang; filepath terdefinisi
// F.S. Data pada StackS, M, G, extraTurn, attackUp sesuai data yang ada pada file yang ada pada filepath
    {
        
    }