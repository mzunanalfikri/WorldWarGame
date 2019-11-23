#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    // KAMUS
    Queue Q1, Q2, Q3;
    infotype X1, X2, X3;

    // ALGORITMA
    CreateEmpty(&Q1, 5);
    printf("Q1 is empty ??? %s\n", IsEmpty(Q1) ? "YES" : "NO");
    printf("Q1 is Full ??? %s\n", IsFullQueue(Q1) ? "YES" : "NO");

    Add(&Q1, 10);
    Add(&Q1, 5);
    Add(&Q1, 2);
    Add(&Q1, 8);
    Add(&Q1, 99);
    printf("Q1 is Full ??? %s\n", IsFullQueue(Q1) ? "YES" : "NO");

    printf("Q1 isinya : \n");
    PrintQueue(Q1);

    return 0;
}