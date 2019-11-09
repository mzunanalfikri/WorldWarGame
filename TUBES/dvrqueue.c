#include "queue.h"
#include "stdio.h"
#include "stdlib.h"
int main (){
    Queue Q,Qc;
    CreateEmpty(&Q,5);
    Add(&Q,1);
    Add(&Q,2);
    Add(&Q,3);
    Add(&Q,4);
    Add(&Q,5);
    printf("Q awal : \n");
    PrintQueue(Q);
    CopyQueue(Q,&Qc);
    // Add(&Qc, 44);
    Add(&Qc, 3);
    printf("Qc hasil : \n");
    PrintQueue(Qc);
    PrintQueue(Qc);
    printf("Q akhir : \n");
    PrintQueue(Q);
    // PrintQueue(Qc);
}