#include<stdio.h>
#include "point.h"
#include "boolean.h"
#include<math.h>
#define PI 3.14159265

int main () {
    POINT P1,P2;
    P1 = MakePOINT(9,1); //test membuat point
    BacaPOINT(&P2); //test membaca point dari layar
    printf("\n");
    TulisPOINT(P1); //test Menulis point ke layar
    printf("\n");
    TulisPOINT(P2);
    printf("\n");
    //test EQ
    if (EQ(P1, P2)) {printf("EQ true, P1 P2 sama"); }
    else {printf("EQ False, P1 P2 Tidak sama"); }
    printf("\n");
    //Test NEQ
    if (NEQ(P1, P2)) {printf("NEQ true, P1 P2 tidak sama");}
    else {printf("NEQ false, P1 P2 sama");}
    printf("\n");
    //test is origin
    if (IsOrigin(P1)) {
        printf("is origin true, titik di 0,0\n");
    } else
    {
        printf("isorigin FAlse, tidakk di 0,0\n");
    }
    //test isonSbY and isOnsbX
    if (IsOnSbY(P1)){
        printf("titik ada di sumbu y\n");
    } else if (IsOnSbX(P1)) {
        printf("titik ada di sumbu X\n");
    } else {
        printf("tidak di sumbu apa apa\n");
    }

    printf("P1 ada di kuadran %d .\n", Kuadran(P1));
    printf("P2 ada di kuadran %d .\n", Kuadran(P2));
    printf("next X :\n");
    TulisPOINT(NextX(P1));
    printf("\n");
    printf("nextY : \n");
    TulisPOINT(NextY(P2));
    printf("\n");
    printf("Plus delta 10 10\n");
    TulisPOINT(PlusDelta(P1, 10, 10));
    printf("\n");
    printf("carmin sumbu X: \n");
    TulisPOINT(MirrorOf(P1,true));
    printf("\n");
    printf("cermin sumbu Y : \n");
    TulisPOINT(MirrorOf(P1,false));
    printf("\n");

    TulisPOINT(P1);
    printf("\n");
    printf("jarak P1 dari origin %f .\n", Jarak0(P1));
    printf("jarak P2 dari origin %f .\n", Jarak0(P2));
    printf("jarak P1 dan P2 adalah %f .\n", Panjang(P1,P2));

    //geser
    Geser(&P2, 13, 13);
    printf("P2 setelah digeser 13 13 : ");
    TulisPOINT(P2);
    printf("\n");

    GeserKeSbX(&P1);
    printf("P1 setelah digeser sb x : ");
    TulisPOINT(P1);
    printf("\n");

    GeserKeSbY(&P2);
    printf("P2 setelah digeser sb y : ");
    TulisPOINT(P2);
    printf("\n");

    Mirror(&P2, true);
    printf("P2 setelah dicerminkan sbx : ");
    TulisPOINT(P2);
    printf("\n");
    Mirror(&P2, false);
    printf("P2 setelah dicerminkan sby : ");
    TulisPOINT(P2);
    printf("\n");

    Putar(&P1, 90);
    printf("P1 setelah diputar 90 derajat : ");
    TulisPOINT(P1);
    printf("\n");
}