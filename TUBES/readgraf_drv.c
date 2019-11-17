/* driver read konfig file */

#include "readfile.h"
#include <stdio.h>

int main() {
    // KAMUS
    Graph G;
    STARTKATA();
    CreateEmptyGraph(&G);

    BacaGraf(&G, 4);
    PrintInfoGraph(G);
    
    printf("baca selesai");
    return 0;
}