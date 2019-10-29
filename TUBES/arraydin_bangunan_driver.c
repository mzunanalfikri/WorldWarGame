#include "arraydin.h"
#include "point.h"
#include "bangunan.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    TabInt T;
    TabInt T2, T3, T4;
    MakeEmptyArray(&T, 10);
    POINT P;
    printf("lalala");
    Elmt(T,1) = MakeBangunan('V', MakePOINT(96,15));
    PrintBangunan(Elmt(T,1));
    AddAsLastEl(&T, MakeBangunan('V', MakePOINT(90,15)));
    AddAsLastEl(&T, MakeBangunan( 'C', MakePOINT(3,54)));
    AddAsLastEl(&T, MakeBangunan( 'T', MakePOINT(6,1)));
    AddAsLastEl(&T, MakeBangunan( 'F', MakePOINT(7,0)));
    for (int i = GetFirstIdx(T) ; i<= GetLastIdx(T) ; i++) {
        PrintBangunan(Elmt(T,i));
    }
    printf("lalalalala\n");
    T2 = T;

    for (int i = GetFirstIdx(T) ; i<= GetLastIdx(T) ; i++) {
        PrintBangunan(Elmt(T2,i));
    }
    printf("lalala");
    T3 = T;
    for (int i = GetFirstIdx(T) ; i<= GetLastIdx(T) ; i++) {
        PrintBangunan(Elmt(T3,i));
    }
    T4 = T;
    for (int i = GetFirstIdx(T) ; i<= GetLastIdx(T) ; i++) {
        PrintBangunan(Elmt(T4,i));
    }
    printf("%d %d %d %d", Neff(T), Neff(T2), Neff(T3), Neff(T4));
    return 0;
}