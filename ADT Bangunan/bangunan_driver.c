#include <stdio.h>
#include <stdlib.h>
#include "bangunan.h"

int main() {
    Bangunan B, B1;
    B = MakeBangunanLv1('F', MakePOINT(5,6));
    PrintBangunan(B);
    NaikLevel(&B);
    PrintBangunan(B);
    AddNextTurn(&B);
    PrintBangunan(B);
    CopyBangunan(B, &B1);
    PrintBangunan(B1);
    PrintTipeBangunan(Type(B));
    IU(&B);
    PrintBangunan(B);
    BackToLv1(&B);
    PrintBangunan(B);

    return 0;
}