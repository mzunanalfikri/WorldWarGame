    #include <stdio.h>
    #include "jam.c"

    int main()
    {
        /* KAMUS */
        JAM J1,J2,J;
        int N;
        long selisih;
        /* ALGORITMA */

        /* Mengetes IsJAMValid,MakeJAM,BacaJAM,dan TulisJAM */
        /* Fungsi IsJAMValid dan MakeJAM termasuk kedalam BacaJAM */
        //Input Jam Awal
        printf("Masukkan jam awal = ");
        BacaJAM(&J1);
        //Input Jam Akhir
        printf("Masukkan jam akhir = ");
        BacaJAM(&J2);

        printf("\n");

        /* Mengetes JEQ,JNEQ,JLT,dan JGT */
        printf("*Tes JEQ*\n");
        if (JEQ(J1,J2))
        {
            printf("Jam awal sama dengan jam akhir\n");
        }
        else // bukan JEQ
        {
            printf("No\n");
        }
        printf("\n");

        printf("*Tes JNEQ*\n");
        if(JNEQ(J1,J2))
        {
            printf("Jam awal tidak sama dengan jam akhir\n");
        }
        else //bukan JNEQ
        {
            printf("No\n");
        }
        printf("\n");

        printf("*Tes JLT*\n");
        if(JLT(J1,J2))
        {
            printf("Jam awal kurang dari jam akhir\n");
        }
        else //bukan JLT
        {
            printf("No\n");
        }
        printf("\n");

        printf("*Tes JGT*\n");
        if(JGT(J1,J2))
        {
            printf("Jam awal lebih besar dari jam akhir\n");
        }
        else //bukan JGT
        {
            printf("No\n");
        }
        printf("\n");

        /* Mengetes JAMToDetik,DetikToJAM,NextDetik,NextNDetik,PrevDetik,PrevNDetik,dan Durasi */
        /* Fungsi JAMToDetik dan DetikToJAM termasuk kedalam fungsi Next dan Prev */
        printf("*Tes NextDetik*\n");
        printf("Waktu akhir bertambah 1 detik.\n");
        J2 = NextDetik(J2);
        printf("Jam akhir menjadi = ");
        TulisJAM(J2); printf("\n");

        printf("\n");

        printf("*Tes PrevDetik*\n");
        printf("Waktu awal berkurang 1 detik.\n");
        J1 = PrevDetik(J1);
        printf("Jam Awal menjadi = ");
        TulisJAM(J1); printf("\n");

        printf("\n");

        printf("*Tes NextNDetik*\n");
        printf("Waktu akhir akan ditambah N detik = ");
        scanf("%d",&N);
        J2 = NextNDetik(J2,N);
        printf("Jam akhir menjadi = ");
        TulisJAM(J2); printf("\n");

        printf("\n");

        printf("*Tes PrevNDetik*\n");
        printf("Waktu awal akan dikurangi N detik = ");
        scanf("%d",&N);
        J1 = PrevNDetik(J1,N);
        printf("Jam awal menjadi = ");
        TulisJAM(J1); printf("\n");

        printf("\n");

        printf("*Tes Durasi*\n");
        selisih = Durasi(J1,J2);
        printf("Selisih jam akhir dan jam awal adalah %ld detik.\n",selisih);

        return 0;
}
