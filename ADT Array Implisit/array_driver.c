#include <stdio.h>
#include "boolean.h"
#include "array.c"

int main(){
  TabInt T1,T2,T3;
  int input;
  int temp;

  printf("Tester\n");
  printf("----------\n");
  while(true){
    printf("0 = index\n1 = I/O\n2 = Is2\n3 = operasi\n4 = search\n5 = Nilai ekstrem\n6 = sort\ncode : ");
    scanf("%d",&input);
    switch(input){
      case 0:
        printf("Index = ");
        scanf("%d",&input);
        printf("IsIdxValid(T1,i) = %d\n",IsIdxValid(T1,input));
        printf("IsIdxEff(T1,i) = %d\n",IsIdxEff(T1,input));
        break;
      case 1:
        printf("Input 1\n");
        BacaIsi(&T1);

        printf("Input 2\n");
        BacaIsiTab(&T2);

        printf("[T1] \n");
        TulisIsi(T1);
        printf("\n");

        printf("[T2] \n");
        TulisIsiTab(T2);
        printf("\n");
        break;
      case 2:
        printf("IsEmpty(T1) = %d\n",IsEmpty(T1));
        printf("IsFull(T1) = %d\n",IsFull(T1));
        printf("NbElmt(T1) = %d\n",NbElmt(T1));
        printf("MaxNbEl(T1) = %d\n",MaxNbEl(T1));
        printf("GetFirstIdx(T1) = %d\n",GetFirstIdx(T1));
        printf("GetLastIdx(T1) = %d\n",GetLastIdx(T1));

        printf("IsSimetris(T1) = %d\n",IsSimetris(T1));

        printf("IsEQ(T1,T2) = %d\n",IsEQ(T1,T2));
        printf("IsLess(T1,T2) = %d\n",IsLess(T1,T2));
        break;
      case 3:
        printf("1 = plus\n2 = minus\n3 = kali\n4 = kali kons(3)\n5 = inverse\n6 = copy\nInput = ");
        scanf("%d",&input);
        if(input == 1){
          T3 = PlusTab(T1,T2);
        }else if(input==2){
          T3 = MinusTab(T1,T2);
        }else if(input==3){
          T3 = KaliTab(T1,T2);
        }else if(input ==4){
          T3 = KaliKons(T1,3);
        }else if(input ==5){
          T3 = InverseTab(T1);
        }else if(input == 6){
          CopyTab(T1,&T3);
        }

        printf("[T1] \n");
        TulisIsi(T1);
        printf("\n");

        printf("[T2] \n");
        TulisIsiTab(T2);
        printf("\n");

        printf("Hasil\n");
        TulisIsi(T3);
        printf("\n");

        break;
      case 4:
        printf("[T1] \n");
        TulisIsi(T1);
        printf("\n");

        printf("Search = ");
        scanf("%d",&input);

        printf("Search1\n");
        temp = Search1(T1,input);
        printf("Hasil = %d\n",temp);

        printf("Search2\n");
        temp = Search2(T1,input);
        printf("Hasil = %d\n",temp);

        printf("SearchB\n");
        printf("Hasil = %d\n",SearchB(T1,input));

        printf("SearchSentinel\n");
        printf("Hasil = %d\n",SearchSentinel(T1,input));
        break;
      case 5:
        printf("ValMax(T1) = %d\n",ValMax(T1));
        printf("Valmin(T1) = %d\n",ValMin(T1));

        printf("IdxMaxTab(T1) = %d\n",IdxMaxTab(T1));
        printf("IdxMinTab(T1) = %d\n",IdxMinTab(T1));
        break;
      case 6:
        printf("[T1] \n");
        TulisIsi(T1);
        printf("\nSORTING MaxSortDesc\n");

        MaxSortDesc(&T1);
        printf("[T1] \n");
        TulisIsi(T1);

        printf("\nSORTING InsSortAsc\n");

        InsSortAsc(&T2);
        printf("[T2] \n");
        TulisIsi(T2);
        break;
      case 7:
        printf("[T1] \n");
        TulisIsi(T1);
        printf("\n");
        printf("1 = addlast\n2 = addeli\n3 = dellast\n4 = deleli\n 5 = addelunik\ncode : ");
        scanf("%d",&input);
        switch(input){
          case 1:
            scanf("%d",&input);
            AddAsLastEl(&T1,input);
            break;
          case 2:
            scanf("%d",&input);
            scanf("%d",&temp);
            AddEli(&T1,input,temp);
            break;
          case 3:
            DelLastEl(&T1,&input);
            printf("deleted = %d\n",input);
            break;
          case 4:
            scanf("%d",&temp);
            DelEli(&T1,temp,&input);
            printf("deleted = %d\n",input);
            break;
          case 5:
            scanf("%d",&input);
            AddElUnik(&T1,input);
            break;

        }
        printf("[T1] \n");
        TulisIsi(T1);
        printf("\n");

        break;

        case 8:
          InsSortAsc(&T1);
          printf("[T1] \n");
          TulisIsi(T1);
          printf("\n");

          printf("Search = ");
          scanf("%d",&input);

          printf("index temu = %d\n",SearchUrut(T1,input));
          printf("max = %d\n",MaxUrut(T1));
          printf("min = %d\n",MinUrut(T1));

          printf("[T1] \n");
          TulisIsi(T1);
          printf("\n");

          printf("Add = ");
          scanf("%d",&input);
          Add1Urut(&T1,input);

          printf("[T1] \n");
          TulisIsi(T1);
          printf("\n");

          Del1Urut(&T1,input);

          printf("[T1] \n");
          TulisIsi(T1);
          printf("\n");



          break;





    }
  }

  return 0;
}
