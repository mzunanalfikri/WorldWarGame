/* driver read konfig file */

#include "readfile.h"
#include <stdio.h>

int main() {
    // KAMUS
    State S;
    MATRIKS PETAKS;
    Graph HUB;

    // ALGORITMA
    ReadKonfigurasiFile(&S, &PETAKS, &HUB);

    return 0;
}