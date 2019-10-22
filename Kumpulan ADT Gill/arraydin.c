/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori tabel dinamik */

#include "arraydin.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel){
    MaxEl(*T)=maxel;
    TI(*T) = (int*)malloc((MaxEl(*T)+1)*sizeof(int));
    Neff(*T) = 0;
    
}
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */

void Dealokasi(TabInt *T){
    MaxEl(*T)=0;
    Neff(*T)=0;
    free(TI(*T));
}
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T){
    return(Neff(T));
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxElement(TabInt T){
    return(MaxEl(T));
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T){
    return(IdxMin);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx(TabInt T){
    return(Neff(T));
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i){
    return((i>=IdxMin)&&(i<=MaxEl(T)));
}
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff(TabInt T, IdxType i){
    return((i>=GetFirstIdx(T))&&(i<=GetLastIdx(T)));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T){
    return(Neff(T)==0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull(TabInt T){
    return(Neff(T)==MaxEl(T));
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T){
    int N,i,isi;
    do{
        scanf("%d",&N);
    }while(!((N>=0)&&(N<=MaxEl(*T))));
    if(N!=0){
        Neff(*T)=N;
        for(i=IdxMin;i<N;i++){
            scanf("%d\n",&isi);
            Elmt(*T,i) = isi;
        }
        scanf("%d",&isi);
        Elmt(*T,Neff(*T)) = isi;
    }else{
        MakeEmpty(&T,MaxEl(*T));
    }    
}
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
void TulisIsiTab(TabInt T){
    int i;
    if(Neff(T)!=0){
        printf("[");
        for(i=IdxMin;i<Neff(T);i++){
            printf("%d,",Elmt(T,i));
        }
        printf("%d]",Elmt(T,Neff(T)));
    }else{
        printf("[]");
    }    
}
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus){
    int i;
    TabInt T3,T4;
    MakeEmpty(&T3,MaxEl(T1));
    MakeEmpty(&T4,MaxEl(T1));
    if(plus){
        for(i=GetFirstIdx(T1);i<=Neff(T1);i++){
            Elmt(T3,i)=Elmt(T1,i)+Elmt(T2,i);
        }
        Neff(T3)=Neff(T1);
        return(T3);
    }else{
        for(i=IdxMin;i<=Neff(T1);i++){
            Elmt(T4,i)=Elmt(T1,i)-Elmt(T2,i);
        }
        Neff(T4)=Neff(T1);
        return(T4);
    }
}
/* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2){
    int i;
    _Bool foundsama;
    i=IdxMin;
    foundsama=true;
    if(Neff(T1)==Neff(T2)){
        for(i=IdxMin;i<=Neff(T1);i++){
            if(Elmt(T1,i)!=Elmt(T2,i)){
                foundsama=false;
                break;
            }
        }return(foundsama);
    }else{
        return(false);
    }   
}
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X){
    int indeks,i;
    indeks=IdxUndef;
    if(Neff(T)==0){
        return(indeks);
    }else{
        for(i=IdxMin;i<=Neff(T);i++){
            if(Elmt(T,i)==X){
                indeks=i;
                break;
            }
        }return (indeks);
    }    
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
boolean SearchB(TabInt T, ElType X){
    int indeks,i;
    boolean found;
    found=false;
    if(IsEmpty(T)){
        return(false);
    }else{
        for(i=IdxMin;i<=Neff(T);i++){
            if(Elmt(T,i)==X){
                found=true;
                break;
            }
        }return (found);
    }    
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min){
    int i,max,min;
    max=-1;
    for (i=IdxMin;i<=Neff(T);i++){
        if(Elmt(T,i)>max){
            max=Elmt(T,i);
        }
    }*Max=max;
    min=max;
    for (i=IdxMin;i<=Neff(T);i++){
        if(Elmt(T,i)<min){
            min=Elmt(T,i);
        }
    }*Min=min;
}
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */

/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout){
    int i;
    TI(*Tout) = (int *) malloc((MaxEl(Tin)+1) * sizeof(int));  
    Neff(*Tout)=Neff(Tin);
    for(i=IdxMin;i<=Neff(Tin);i++){
        Elmt(*Tout,i)=Elmt(Tin,i);
    }    
}
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */
ElType SumTab(TabInt T){
    int jum,i;
    jum=0;
    if(Neff(T)!=0){
        for(i=IdxMin;i<=Neff(T);i++){
            jum += Elmt(T,i);
        }
    }
    return(jum);
}
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
int CountX(TabInt T, ElType X){
    int count,i;
    count = 0;
    if(Neff(T)!=0){
        for(i=IdxMin;i<=Neff(T);i++){
            if(Elmt(T,i)==X){
                count+=1;
            }
        }
    }
    return(count);
}
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
boolean IsAllGenap(TabInt T){
    int i;
    _Bool foundgenap = true;
    if(Neff(T)==0){
        return false;
    }else{
        for(i=IdxMin;i<=Neff(T);i++){
            if(Elmt(T,i)%2==1){
                foundgenap = false;
                break;
            }
        }return(foundgenap);
    }
}
/* Menghailkan true jika semua elemen T genap. T boleh kosong */

/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc){
    int i,x,j,temp;
    if(asc){
        if (Neff(*T) > 1){
            for (i = IdxMin+1; (i <= Neff(*T)); i++){
                x = Elmt(*T,i);
                j = i-1;
                while ((j >= IdxMin) && (Elmt(*T,j) > x))
                {
                    Elmt(*T,j+1) = Elmt(*T,j);
                    j = j-1;
                }
                Elmt(*T,j+1) = x;
            }
        }
    }else{
        if (!(IsEmpty(*T))){
            for (i = IdxMin; (i <= (Neff(*T)-1)); i++)
            {
                x = i;
                for (j = i+1; j <= Neff(*T); j++){
                if ((Elmt(*T,j)) > (Elmt(*T,x))){
                    x = j;
                    }
                }
                temp = Elmt(*T,x);
                Elmt(*T,x) = Elmt(*T, i);
                Elmt(*T, i) = temp;
            }
        }
    }
}
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X){
    Neff(*T)+=1;
    Elmt(*T,Neff(*T))=X;
        
}
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X){
    *X=Elmt(*T,GetLastIdx(*T));
    Neff(*T)-=1;
}
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num){
    TI(*T) = (int*) realloc(TI(*T),(MaxEl(*T)+num)*sizeof(int));
    MaxEl(*T) += num;
}
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */

void ShrinkTab(TabInt *T, int num){
   
    MaxEl(*T) -= num;
    if(Neff(*T)>MaxEl(*T)){
        Neff(*T)=MaxEl(*T);
    }
}
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */

void CompactTab(TabInt *T){
    
    MaxEl(*T)=Neff(*T);
}
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */
