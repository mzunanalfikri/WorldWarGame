#include "listrek.c"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,X;
    List L = Nil;
    List LHsl = Nil;
    //List LCon = Nil;
    //List LKons = Nil;

    for (i=1;i<=5;i++)
    {
        scanf("%d",&X);
        L = Konso(X,L);
    }
    printf("\n");
    if (Search(L,10) == true)
    {
        printf("KETEMU\n");
    }
    else
    {
        printf("GAK ADA\n");
    }

    LHsl = KonsB(L,99);
    PrintList(LHsl);


    return 0;
}
