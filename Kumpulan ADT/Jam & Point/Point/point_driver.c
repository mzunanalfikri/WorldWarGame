    #include <stdio.h>
	#include "point.c"

	int main()
	{
	    /* KAMUS */
        POINT P1, P2;
        float dx,dy,sudut;
        /* ALGORITMA */
        /* Mengetes MakePOINT yang termasuk kedalam BacaPOINT, serta TulisPOINT */
        printf("Masukkan titik awal = ");
        BacaPOINT(&P1);
        printf("Titik awal adalah ");
        TulisPOINT(P1);printf("\n");

        printf("Masukkan titik akhir = ");
        BacaPOINT(&P2);
        printf("Titik akhir adalah ");
        TulisPOINT(P2);printf("\n");

        printf("Masukkan delta x = ");
        scanf("%f",&dx);
        printf("Masukkan delta y = ");
        scanf("%f",&dy);

        printf("\n");

        /* Mengetes EQ */
        printf("*Tes EQ*\n");
        if (EQ(P1,P2))
        {
            printf("Kedua titik berada pada titik yang sama\n");
        }
        else // not EQ
        {
            printf("No\n");
        }

        /* Mengetes NEQ */
        printf("*Tes NEQ*\n");
        if (NEQ(P1,P2))
        {
            printf("Kedua titik tidak berada pada titik yang sama\n");
        }
        else // not EQ
        {
            printf("No\n");
        }

        /* Mengetes IsOrigin */
        printf("*Tes IsOrigin*\n");
        if (IsOrigin(P1))
        {
            printf("Titik awal berada pada titik (0,0)\n");
        }
        else // not EQ
        {
            printf("Titik awal tidak berada pada titik (0,0)\n");
        }

        printf("\n");

        /* Mengetes MirrorOf dan Mirror */
        printf("*Tes MirrorOf*\n");
        if (IsOrigin(P1))
        {
            printf("Titik awal dimirror menjadi ");
            TulisPOINT(P1); printf("\n");
        }
        else // kondisi dapat di mirror
        {
            P1 = MirrorOf(P1,true);
            printf("Titik awal dimirror menjadi ");
            TulisPOINT(P1); printf("\n");
        }
        printf("*Tes Mirror*\n");
        if (IsOrigin(P2))
        {
            printf("Titik akhir dimirror menjadi ");
            TulisPOINT(P2); printf("\n");
        }
        else // kondisi dapat di mirror
        {
            Mirror(&P2,false);
            printf("Titik akhir dimirror menjadi ");
            TulisPOINT(P2); printf("\n");
        }

        printf("\n");

        /* Mengetes Kuadran */
        printf("*Tes Kuadran*\n");
        if (IsOrigin(P1))
        {
            printf("Titik tidak berada dalam kuadran");
        }
        else // bukan ketiga kondisi diatas
        {
            printf("Titik awal berada di kuadran %d\n",Kuadran(P1));

        }
        if (IsOrigin(P2))
        {
            printf("Titik tidak berada dalam kuadran");
        }
        else // bukan ketiga kondisi diatas
        {
            printf("Titik akhir berada di kuadran %d\n",Kuadran(P2));
        }

        printf("\n");

        /* Mengetes IsOnSbX dan GeserKeSbX*/
        printf("*Tes GeserKeSbX*\n");
        GeserKeSbX(&P2);
        printf("Titik akhir menjadi ");
        TulisPOINT(P2); printf("\n");

        printf("*Tes IsOnSbX*\n");
        if (IsOnSbX(P2))
        {
            printf("Titik akhir berada pada sumbu x\n");
        }
        else // not EQ
        {
            printf("Titik akhir berada pada sumbu x\n");
        }

        printf("\n");

        /* Mengetes IsOnSbY dan GeserKeSbY */
        printf("*Tes GeserKeSbYY*\n");
        GeserKeSbY(&P1);
        printf("Titik awal menjadi ");
        TulisPOINT(P1); printf("\n");

        printf("*Tes IsOnSbY*\n");
        if (IsOnSbY(P1))
        {
            printf("Titik awal berada pada sumbu y\n");
        }
        else // not EQ
        {
            printf("Titik awal berada pada sumbu y\n");
        }

        printf("\n");

        /* Mengetes NextX */
        printf("*Tes NextX*\n");
        printf("Titik awal menjadi ");
        P1 = NextX(P1);
        TulisPOINT(P1); printf("\n");

        /* Mengetes NextY */
        printf("*Tes NextY*\n");
        printf("Titik akhir menjadi ");
        P2 = NextY(P2);
        TulisPOINT(P2); printf("\n");

        printf("\n");

        /* Mengetes PlusDelta*/
        printf("*Tes PlusDelta*\n");
        printf("Titik awal = ");
        TulisPOINT(P1);printf("\n");
        P1 = PlusDelta(P1,dx,dy);
        printf("Titik awal digeser sejauh x = %.2f dan y = %.2f menjadi ",dx,dy);
        TulisPOINT(P1); printf("\n");

        printf("\n");

        /* Mengetes Geser*/
        printf("*Tes Geser*\n");
        printf("Titik akhir = ");
        TulisPOINT(P2);printf("\n");
        printf("Titik akhir digeser sejauh x = %.2f dan y = %.2f menjadi ",dx,dy);
        Geser(&P2,dx,dy);
        TulisPOINT(P2); printf("\n");

        printf("\n");

        /* Mengetes Jarak0 */
        printf("*Tes Jarak0*\n");
        printf("Jarak titik ");
        TulisPOINT(P1); printf(" terhadap titik origin\n");
        printf("Jarak titik awal dengan titik (0,0) adalah %.2f\n",Jarak0(P1));

        /* Mengetes Panjang */
        printf("*Tes Panjang*\n");
        printf("Jarak titik ");
        TulisPOINT(P1); printf(" terhadap titik ");
        TulisPOINT(P2); printf("\n");
        printf("Jarak titik awal dengan titik akhir adalah %.2f\n",Panjang(P1,P2));

        printf("\n");

        /* Mengetes Putar */
        printf("*Tes Putar*\n");
        printf("Titik ");
        TulisPOINT(P1); printf("\n");
        printf("Masukkan sudut = ");
        scanf("%f",&sudut);
        Putar(&P1,sudut);
        printf("setelah diputar %.2f derajat menjadi ",sudut);
        TulisPOINT(P1); printf("\n");

        return 0;


	}
