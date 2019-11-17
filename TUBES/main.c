#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "arraydin.h"
#include "bangunan.h"
#include "listlinier.h"
#include "matriks.h"
#include "player.h"
#include "point.h"
#include "queue.h"
#include "stackt.h"
#include "state.h"
#include "graph.h"
#include "pcolor.h"
#include "function.h"

int main() {
    // DEKLARASI ADT YANG DIGUNAKAN
    State S;
    MATRIKS Map;
    Graph G;

    ReadKonfigurasiFile(&S, &Map, &G);
    TulisMATRIKS(Map);
    PrintAllBangunan(ArrayBangunan(S));
    PrintInfoGraph(G);
    printf("done");
    return 0;
}