#include <stdio.h>
#include <stdlib.h>
#include "state.h"

int main() {
    State S, S1;
    MakeState(&S, 10);
    PrintState(S);
    CopyState(S,&S1);
    PrintState(S1);
    DealokState(&S);

    return 0;
}