#include "stackt.h"
#include "stdio.h"
#include "stdlib.h"
int main (){
    Stack S,S2;
    CreateEmptyStack(&S);
    Push(&S,5);
    Push(&S,4);
    Push(&S,3);
    Push(&S,2);
    Push(&S,1);
    PrintStack(S);
    CopyStack(S,&S2);
    Push(&S2, 3);
    Push(&S2, 100);
    PrintStack(S2);
    PrintStack(S);

}