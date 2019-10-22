#include "array.h"
#include <stdio.h>

void MakeEmpty (TabInt *t) {
    t->Neff = 0;
}

int NbElmt (TabInt t) {
    return t.Neff;  
}

int MaxNbEl (TabInt t) {
    return IdxMax-IdxMin+1;
}

IdxType GetFirstIdx (TabInt t) {
    return IdxMin;
}

IdxType GetLastIdx (TabInt t) {
    return IdxMin+t.Neff-1;
}

boolean IsIdxValid (TabInt t, IdxType i) {
    return IdxMin <= i && i <= IdxMax;
}

boolean IsIdxEff (TabInt t, IdxType i) {
    return GetFirstIdx(t) <= i && i <= GetLastIdx(t);
}

boolean IsEmpty (TabInt t) {
    return t.Neff == 0;
}

boolean IsFull (TabInt t) {
    return t.Neff == IdxMax-IdxMin+1;
}

void BacaIsi (TabInt *t) {
    while (1) {
        scanf("%d", &(t->Neff));
        if (0 <= t->Neff && t->Neff <= MaxNbEl(*t))
            break;
    }
    int i = IdxMin;
    while (i < IdxMin+t->Neff)
        scanf("%d", &(t->TI[i++]));
}

void BacaIsiTab (TabInt *t) {
    MakeEmpty(t);
    int read, i = IdxMin;
    while (i <= IdxMax) {
        scanf("%d", &read);
        if (read == -9999)
            break;
        t->TI[i++] = read;
        ++(t->Neff);
    }
}

void TulisIsi (TabInt t) {
    if (t.Neff == 0) {
        printf("Tabel kosong\n");
        return;
    }
    for (int i = IdxMin; i < IdxMin+t.Neff; i++)
        printf("[%d]%d\n", i, t.TI[i]);
}

void TulisIsiTab (TabInt t) {
    printf("[");
    for (int i = IdxMin; i < IdxMin+t.Neff; i++) {
        printf("%d", t.TI[i]);
        if (i+1 < IdxMin+t.Neff)
            printf(",");
    }
    printf("]\n");
}

TabInt PlusTab (TabInt t1, TabInt t2) {
    TabInt t;
    MakeEmpty(&t);
    t.Neff = t1.Neff;
    for (int i = IdxMin; i < IdxMin+t.Neff; i++)
        t.TI[i] = t1.TI[i] + t2.TI[i];
    return t;
}

TabInt MinusTab (TabInt t1, TabInt t2) {
    TabInt t;
    MakeEmpty(&t);
    t.Neff = t1.Neff;
    for (int i = IdxMin; i < IdxMin+t.Neff; i++)
        t.TI[i] = t1.TI[i] - t2.TI[i];
    return t;
}

TabInt KaliTab (TabInt t1, TabInt t2) {
    TabInt t;
    MakeEmpty(&t);
    t.Neff = t1.Neff;
    for (int i = IdxMin; i < IdxMin+t.Neff; i++)
        t.TI[i] = t1.TI[i]*t2.TI[i];
    return t;
}

TabInt KaliKons (TabInt tin, ElType c) {
    TabInt t;
    t.Neff = tin.Neff;
    for (int i = IdxMin; i < IdxMin+tin.Neff; i++)
        t.TI[i] = tin.TI[i]*c;
    return t;
}

boolean IsEQ (TabInt t1, TabInt t2) {
    if (t1.Neff != t2.Neff)
        return false;
    for (int i = IdxMin; i < IdxMin+t1.Neff; i++)
        if (t1.TI[i] != t2.TI[i])
            return false;
    return true;
}

// NOTE: Potential error!
boolean IsLess (TabInt t1, TabInt t2) {
    for (int i = IdxMin; i < IdxMin+t1.Neff; i++) {
        if (t1.TI[i] == t2.TI[i])
            continue;
        return t1.TI[i] < t2.TI[i];
    }
    return NbElmt(t1) < NbElmt(t2);
}

IdxType Search1 (TabInt t, ElType x) {
    for (int i = IdxMin; i < IdxMin+t.Neff; i++)
        if (t.TI[i] == x)
            return i;
    return IdxUndef;
}

IdxType Search2 (TabInt t, ElType x) {
    int i = IdxMin;
    boolean found = false;
    while (!found && i < IdxMin+t.Neff)
        found = t.TI[i++] == x;
    if (found)
        return i-1;
    return IdxUndef;
}

boolean SearchB (TabInt t, ElType x) {
    boolean found = false;
    int i = IdxMin;
    while (!found && i < IdxMin+t.Neff)
        found = t.TI[i++] == x;
    return found;
}

// NOTE: error!
boolean SearchSentinel (TabInt t, ElType x) {
    int i = IdxMin+t.Neff-1;
    while (i >= IdxMin) {
        if (t.TI[i] == x)
            break;
        i--;
    }
    return i >= IdxMin;
}

ElType ValMax (TabInt t) {
    int max = t.TI[IdxMin];
    for (int i = IdxMin+1; i < IdxMin+t.Neff; i++)
        max = t.TI[i] > max ? t.TI[i] : max;
    return max;
}

ElType ValMin (TabInt t) {
    int min = t.TI[IdxMin];
    for (int i = IdxMin+1; i < IdxMin+t.Neff; i++)
        min = t.TI[i] < min ? t.TI[i] : min;
    return min;
}

IdxType IdxMaxTab (TabInt t) {
    int max = IdxMin;
    for (int i = IdxMin+1; i < IdxMin+t.Neff; i++)
        max = t.TI[i] > t.TI[max] ? i : max;
    return max;
}

IdxType IdxMinTab (TabInt t) {
    int min = IdxMin;
    for (int i = IdxMin+1; i < IdxMin+t.Neff; i++)
        min = t.TI[i] < t.TI[min] ? i : min;
    return min;
}

void CopyTab (TabInt tin, TabInt *tout) {
    tout->Neff = tin.Neff;
    for (int i = IdxMin; i < IdxMin+tin.Neff; i++)
        tout->TI[i] = tin.TI[i];
}

// NOTE: Potential error!
TabInt InverseTab (TabInt t) {
    for (int i = 0; i < t.Neff/2; i++) {
        ElType temp = t.TI[IdxMin+i];
        t.TI[IdxMin+i] = t.TI[IdxMin+t.Neff-i-1];
        t.TI[IdxMin+t.Neff-i-1] = temp;
    }
    return t;
}

// NOTE: Potential error!
boolean IsSimetris (TabInt t) {
    for (int i = 0; i < t.Neff/2; i++)
        if (t.TI[IdxMin+i] != t.TI[IdxMin+t.Neff-i-1])
            return false;
    return true;
}

void MaxSortDesc (TabInt *t) {
    int ind = IdxMin, n = t->Neff;
    while (ind < IdxMin+t->Neff) {
        int index = ind;
        for (int i = ind+1; i < IdxMin+t->Neff; i++)
            index = t->TI[i] > t->TI[index] ? i : index;
        int temp = t->TI[index];
        t->TI[index] = t->TI[ind];
        t->TI[ind++] = temp;
    }
}

void InsSortAsc (TabInt *t) {
    int i = IdxMin;
    while (i < IdxMin+t->Neff) {
        int min = t->TI[i], minIndex = i;
        for (int j = i+1; j < IdxMin+t->Neff; j++)
            if (t->TI[j] < min) {
                min = t->TI[j];
                minIndex = j;
            }
        int temp = t->TI[minIndex];
        t->TI[minIndex] = t->TI[i];
        t->TI[i] = temp;
        ++i;
    }
}

void AddAsLastEl (TabInt *t, ElType x) {
    if (IsFull(*t))
        return;
    t->TI[IdxMin+t->Neff] = x;
    ++(t->Neff);
}

// NOTE: Potential error!
void AddEli (TabInt *t, ElType x, IdxType i) {
    if (IsFull(*t))
        return;
    int j = IdxMin+(t->Neff)++-1;
    while (j >= i) {
        t->TI[j+1] = t->TI[j];
        --j;
    }
    t->TI[i] = x;
}

void DelLastEl (TabInt *t, ElType *x) {
    *x = t->TI[IdxMin+t->Neff-1];
    --(t->Neff);
}

void DelEli (TabInt *t, IdxType i, ElType *x) {
    *x = t->TI[i];
    for (; i < IdxMin+t->Neff; i++)
        t->TI[i] = t->TI[i+1];
    --(t->Neff);
}

void AddElUnik (TabInt *t, ElType x) {
    if (SearchB(*t, x))
        printf("nilai sudah ada\n"); // Fixed correct
    else
        AddAsLastEl(t, x);
}

IdxType SearchUrut (TabInt t, ElType x) {
    return Search1(t, x);
}

ElType MaxUrut (TabInt t) {
    return t.TI[IdxMin+t.Neff-1];
}

ElType MinUrut (TabInt t) {
    return t.TI[IdxMin];
}

void MaxMinUrut (TabInt t, ElType * Max, ElType * Min) {
    *Max = MaxUrut(t);
    *Min = MinUrut(t);
}

void Add1Urut (TabInt *t, ElType x) {
    if (IsFull(*t))
        return;
    for (int i = IdxMin; i < IdxMin+t->Neff; i++)
        if (t->TI[i] > x) {
            AddEli(t, x, i);
            return;
        }
    AddEli(t, x, IdxMin+t->Neff);
}

void Del1Urut (TabInt *t, ElType x) {
    if (SearchB(*t, x))
        DelEli(t, Search1(*t, x), &x);
}

// int main()
// {
//  /*kamus*/
//    int i,j,X;
//    TabInt T1,T2,T3;
//  /*algoritma*/
//     printf("data tabel pertama \n");
//    	BacaIsi(&T1);
//    	printf("\n");
//    	TulisIsi(T1);
//    	printf("\n");
//    	TulisIsiTab(T1);
//    	printf("\n");
//    	printf("data tabel kedua : \n");
//    	BacaIsi(&T2);
//    	printf("\n");
//    	TulisIsi(T2);
//    	printf("\n");
//    	TulisIsiTab(T2);
//    	printf("\n");

//    	/*seleksi ukuran elemen*/
//    	if(IsEQ(T1,T2))
//    	   printf("kedua tabel sama\n");
//    	 else
//    	   if(IsLess(T1,T2))
//    	      printf("T1 < T2\n");
//    	     else
//    	       printf("T1 > T2\n");
//     printf("\n");

//    	/*penjumlahan tabel*/
//    	printf("hasil T1 + T2 : ");
//    	TulisIsiTab(PlusTab(T1,T2));
//    	printf("\n");
//     printf("hasil T1 - T2 : ");
//    	TulisIsiTab(MinusTab(T1,T2));
//    	printf("\n");
//    	printf("hasil T1 * 2 : ");
//    	TulisIsiTab(KaliKons(T1,2));
//    	printf("\n");

   	
//     printf("isi T3\n");
//     BacaIsi(&T3);
//     printf("T3 : ");
//     TulisIsiTab(T3);
//     printf("\n");

//     /*algoritma searching*/
//     printf("//Searching angka 2 di T3//\n");
//     printf("Tanpa boolean\n");
//     printf("%d\n",Search1(T3,2));
//     printf("Dengan boolean Found\n");
//     printf("%d\n",Search2(T3,2));
//     printf("Dengan boolean\n");
//     printf("%d\n",SearchB(T3,2));
//     printf("Dengan sentinel\n");
//    	printf("%d\n",SearchSentinel(T3,2));
//     printf("\n");

//     /*nilai ekstrim*/
//     printf("//nilai ekstrim di T1//\n");
//     printf("nilai maksimum   : %d\n",ValMax(T1));
//     printf("ada di indeks ke : %d\n",IdxMaxTab(T1));
//     printf("nilai minimum    : %d\n",ValMin(T1));
//     printf("ada di indeks ke : %d\n",IdxMinTab(T1));
//     printf("\n");

//     /*operasi lain
//     printf("//operasi lain pada TabInt//\n");
//     SetTab(T3,&T1);
//     printf("nilai T1 yang berasal dari T3 lalu diinverse : ");
//     TulisIsiTab(InverseTab(T1));*/
//     if(IsSimetris(T1))
//       printf("T1 adalah tabel simetris\n");
//     else
//       printf("T1 bukan tabel simetris\n");
//     printf("\n");

//     /*sorting terhadap T2*/
//     printf("//sorting T2//\n");
//     printf("dengan menggunakan MaxSortDesc\n");
//     MaxSortDesc(&T2);
//     printf("T2 : ");
//     TulisIsiTab(T2);
//     printf("dengan menggunakan InsSortAsc\n");
//     InsSortAsc(&T2);
//     printf("T2 : ");
//     TulisIsiTab(T2);
//     printf("\n");

//     /*menambah dan menghapus elemen di T3*/
//     printf("//add & delete T3//\n");
//     printf("menambah elemen '3' di akhir T3 : ");
//     AddAsLastEl(&T3,3);
//     TulisIsiTab(T3);
//     printf("menambah elemen '3' di akhir T3 (unik) : ");
//     AddElUnik(&T3,3);
//     TulisIsiTab(T3);
//     printf("menghapus elemen terakhir T3 : ");
//     DelLastEl(&T3,&X);
//     TulisIsiTab(T3);
//     printf("\n");

//     /*T3 terurut*/
//     InsSortAsc(&T3);
//     printf("//T3 terurut//\n");
//     printf("mencari '4' pada T3\n");
//     printf("ada di indeks ke : %d\n",SearchUrut(T3,4));
//     printf("nilai max T3 : %d\n", ValMax(T3));
//     printf("nilai min T3 : %d\n", ValMin(T3));
//     printf("mengisi nilai '4' pada indeks ditemukan pertama : \n");
//     Add1Urut(&T3,4);
//     TulisIsiTab(T3);
//     printf("menghapus nilai '4' pada indeks ditemukan pertama : \n");
//     Del1Urut(&T3,4);
//     TulisIsiTab(T3);
//     return 0;
// }