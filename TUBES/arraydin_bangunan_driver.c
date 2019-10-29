#include "arraydin.h"
#include "point.h"
#include "bangunan.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    TabInt T;
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
    return 0;
}