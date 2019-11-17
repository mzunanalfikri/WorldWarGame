/* driver read konfig file */

#include "readfile.h"
#include <stdio.h>

int main() {
    // KAMUS
    State S, S1;
    Player P;
    MATRIKS PETAKS;
    Graph HUB;
    
    MakePlayer(&P);
 
    printf("lalala\n");
    ReadKonfigurasiFile(&S, &PETAKS, &HUB);

    PrintAllBangunan(ArrayBangunan(S));
    return 0;
}