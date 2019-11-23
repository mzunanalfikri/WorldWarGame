#include<stdio.h>
#include<stdlib.h>
#include "graph.h"

int main() {
    Graph G;
    CreateEmptyGraph(&G);
    InsVFirstParent(&G, 3);
    InsVFirst(&Child(FirstParent(G)),1 );
    InsVFirst(&Child(FirstParent(G)),2 );
    InsVFirst(&Child(FirstParent(G)),3 );
    //PrintInfoGraph(G);
    InsVLastParent(&G, 10);
    InsVFirst(&Child(NextParent(FirstParent(G))),1 );
    InsVLast(&Child(NextParent(FirstParent(G))),10 );
    InsVLast(&Child(NextParent(FirstParent(G))),19 );

    InsVLastParent(&G, 1000);
    InsVLastParent(&G, 12);
    PrintInfoGraph(G);
    // printf("%d\n",InfoParent(FirstParent(G)));
    // PrintInfo(Child(FirstParent(G)));


    return 0;
}