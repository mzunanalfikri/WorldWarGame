#include "arraydin.h"
#include "point.h"
#include "bangunan.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    /*
    Bangunan B1, B2;
    B1 = MakeBangunanLv1('V', MakePOINT(96,15));
    
    CopyBangunan(B1, &B2);
    B2 = MakeBangunanLv1('F', MakePOINT(96,15));
    PrintBangunan(B1);

    PrintBangunan(B2);
    */
    TabBangunan T, T1;
    printf("lalalalala\n");
    MakeEmptyArray(&T, 10);
    printf("lalalalala\n");
    MakeEmptyArray(&T1, 10);
    printf("lalalalala\n");
    AddAsLastEl(&T, MakeBangunanLv1('V', MakePOINT(90,15)));
    AddAsLastEl(&T, MakeBangunanLv1( 'C', MakePOINT(3,54)));
    AddAsLastEl(&T, MakeBangunanLv1( 'T', MakePOINT(6,1)));
    for (int i = GetFirstIdx(T) ; i<= GetLastIdx(T) ; i++) {
        PrintBangunan(ElmtTab(T,i));
    }
    CopyTab(T, &T1);
    for (int i = GetFirstIdx(T1) ; i<= GetLastIdx(T1) ; i++) {
        PrintBangunan(ElmtTab(T1,i));
    }
    printf("%d %d %d",GetFirstIdx(T), GetLastIdx(T), MaxElArray(T));
    printf("%d %d %d",GetFirstIdx(T1), GetLastIdx(T1), MaxElArray(T1));

   

    /*
    TabBangunan T, T2, T3, T4;
    MakeEmptyArray(&T, 10);
    POINT P;
    printf("lalala\n");
    ElmtTab(T,1) = MakeBangunanLv1('V', MakePOINT(96,15));
    PrintBangunan(ElmtTab(T,1));
    AddAsLastEl(&T, MakeBangunanLv1('V', MakePOINT(90,15)));
    AddAsLastEl(&T, MakeBangunanLv1( 'C', MakePOINT(3,54)));
    AddAsLastEl(&T, MakeBangunanLv1( 'T', MakePOINT(6,1)));
    AddAsLastEl(&T, MakeBangunanLv1( 'F', MakePOINT(7,0)));

    for (int i = GetFirstIdx(T) ; i<= GetLastIdx(T) ; i++) {
        PrintBangunan(ElmtTab(T,i));
    }
    printf("lalalalala\n");
    MakeEmptyArray(&T2, 10);
    printf("%d %d %d",GetFirstIdx(T), GetLastIdx(T), MaxElArray(T));
    CopyTab(T, &T2);
    */

    
    // for (int i = GetFirstIdx(T) ; i<= GetLastIdx(T) ; i++) {
    //     PrintBangunan(ElmtTab(T2,i));
    // }
    // printf("lalala");
    // T3 = T;
    // for (int i = GetFirstIdx(T) ; i<= GetLastIdx(T) ; i++) {
    //     PrintBangunan(ElmtTab(T3,i));
    // }
    // T4 = T;
    // for (int i = GetFirstIdx(T) ; i<= GetLastIdx(T) ; i++) {
    //     PrintBangunan(ElmtTab(T4,i));
    // }
    // printf("%d %d %d %d", Neff(T), Neff(T2), Neff(T3), Neff(T4));
    return 0;
}