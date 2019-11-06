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
    PrintQueue(Q);
    CopyQueue(Q,&Qc);
    PrintQueue(Qc);
    PrintQueue(Q);
}