#include <stdio.h>
#include "mesinkata.c"
#include <conio.h>
#include <string.h>

int main()
{
    int i,hasil;
    Kata Papan;
    char StateNow[10] = "**x******";

    STARTKATA();
    while (!EndKata) {
    for (i=1;i<=CKata.Length;i++) {
        Papan.TabKata[i] = CKata.TabKata[i];
    }
    ADVKATA();
    }

    Papan.Length = CKata.Length;
    for (i=1;i<=Papan.Length;i++) {
        if (Papan.TabKata[i] == '*')
        {
            if ((i == 3) || (i == 6) || (i == 9))
            {
                printf("\n");
            }
            else // masih di baris yang sama
            {
                printf(" ");
            }

        }
        else if (Papan.TabKata[i] == 'x')
        {
            if ((i == 3) || (i == 6) || (i == 9))
            {
                printf("%c\n",Papan.TabKata[i]);
            }
            else // masih di baris yang sama
            {
                printf("%c ",Papan.TabKata[i]);
            }
        }
    }
    printf("\n");

    hasil = strcmp(Papan.TabKata,StateNow);
    printf("%d\n",hasil);
    return 0;
}

