/*
Muhammd Zunan Alfikri
13518019
10 September 2019
*/

#include <stdlib.h>
#include <stdio.h>
#include "arraydin.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel)
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
{
    Neff(*T) = 0;
    MaxEl(*T) = maxel; 
    TI(*T) = (ElType *) malloc ((maxel+1) * sizeof(int));
}

void Dealokasi(TabInt *T)
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
{
    free(TI(*T));
    MaxEl(*T) = 0;
    Neff(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
    return Neff(T);
}

int MaxElement(TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
{
    return MaxEl(T);
}

IdxType GetFirstIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
    return IdxMin;
}

IdxType GetLastIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
    return(IdxMin + Neff(T) - 1);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return (i>= IdxMin && i<=MaxEl(T));
}
boolean IsIdxEff(TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    return (i>=GetFirstIdx(T) && i<=GetLastIdx(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
{
    return (Neff(T) == 0);
}
boolean IsFull(TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return (Neff(T) == MaxEl(T));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T)
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
    //Kamus
    int i;
    IdxType k;
    
    //algoritma
    scanf("%d", &i);
    while (!(i >= 0 && i<= MaxElement(*T))){
        scanf("%d", &i);
    }
    Neff(*T) = i;
    if (i > 0) {
        for ( k = IdxMin ; k <= IdxMin+i-1 ; k++){
            scanf("%d", &Elmt(*T, k));
        }
    }
}

void TulisIsiTab(TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
    IdxType i = IdxMin;
    printf("[");
    if (Neff(T)>0){
        for (i ; i <= GetLastIdx(T) ; i++ ){
            printf("%d", Elmt(T, i));
            if (i != GetLastIdx(T)){
                printf(",");
            }
        }
    }
    printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus)
/* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
    TabInt T;
    IdxType i = IdxMin;
    MakeEmpty(&T, MaxEl(T));
    Neff(T) = Neff(T1);
    if (plus) {
        for (i ; i <= GetLastIdx(T1) ; i++) {
            Elmt(T, i) =  Elmt(T1, i) + Elmt(T2, i);
        }
    } else {
        for (i ; i <= GetLastIdx(T1) ; i++) {
            Elmt(T, i) =  Elmt(T1, i) - Elmt(T2, i);
        }
    }
    return T;
    Dealokasi(&T);
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */
{
    IdxType i;
    boolean found = true;
    if (Neff(T1) != Neff(T2)) {
        found = false;
    } else {
        for (i = GetFirstIdx(T1) ; i <= GetLastIdx(T1) ; i++){
            if (Elmt(T1,i) != Elmt(T2, i)){
                found = false;
            }
        }
    }
    return found;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
{
    IdxType i = IdxMin;
    while ((i<GetLastIdx(T)) && (Elmt(T,i) != X)) {
        i += 1;
    }
    if (Elmt(T, i ) == X) {
        return i;
    } else {
        return IdxUndef;
    }
}

boolean SearchB(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
{
    boolean found = false;
    IdxType i = IdxMin;
    while ((i <= GetLastIdx(T)) && !(found)) {
        if (Elmt(T,i) == X){
            found = true;
        } else {
            i += 1;
        }
    }
    return found;
}

/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min)
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
    ElType maks = Elmt(T, IdxMin);
    ElType mins = Elmt(T, IdxMin);
    IdxType i = IdxMin+1;
    for (i ; i <= GetLastIdx(T) ; i++){
        if (Elmt(T,i) > maks) {
            maks = Elmt(T, i);
        }
        if (Elmt(T,i) < mins) {
            mins = Elmt(T, i);
        }
    }
    *Max = maks;
    *Min = mins;
}

/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout)
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */
{
    MakeEmpty(Tout, MaxEl(Tin));
    Neff(*Tout) = Neff(Tin);
    IdxType i = GetFirstIdx(Tin);
    for (i ; i <= GetLastIdx(Tin) ; i++){
        Elmt(*Tout, i) = Elmt(Tin, i);
    }
}

ElType SumTab(TabInt T)
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
{
    if (IsEmpty(T)) {
        return 0;
    } else {
        ElType sum = 0;
        for (int i = IdxMin ; i<= GetLastIdx(T) ; i++){
            sum += Elmt(T,i);
        }
        return sum;
    }
}

int CountX(TabInt T, ElType X)
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
{
    IdxType i;
    int count;
    if (IsEmpty(T)) {
        return 0;
    } else {
        count = 0;
        for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
            if (Elmt(T, i) == X){
                count += 1;
            }
        }
        return count;
    }
}

boolean IsAllGenap(TabInt T)
/* Menghailkan true jika semua elemen T genap. T boleh kosong */
{
    boolean found = true;
    int i = IdxMin;
    if (IsEmpty(T)){
        found = false;
    }
    else {
    while (found && i < GetLastIdx(T)){
        if (Elmt(T, i) % 2 != 0){
            found = false;
        }
        i++;
    }
    }
    return found;
}

/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc)
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
{
    ElType temp; 
    if (asc) {
    for (int i = IdxMin ; i < GetLastIdx(*T) ; i++){
        for (int k = i+1 ; k <= GetLastIdx(*T) ; k++){
            if (Elmt(*T, i) > Elmt(*T, k)){
                temp = Elmt(*T,i);
                Elmt(*T, i) = Elmt(*T, k);
                Elmt(*T,k) = temp;
            }
        }
    }
    }
    else
    {
    for (int i = IdxMin ; i < GetLastIdx(*T) ; i++){
        for (int k = i+1 ; k <= GetLastIdx(*T) ; k++){
            if (Elmt(*T, i) < Elmt(*T, k)){
                temp = Elmt(*T,i);
                Elmt(*T, i) = Elmt(*T, k);
                Elmt(*T,k) = temp;
            }
        }
    }
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
    if (IsEmpty(*T)) {
        Elmt(*T, GetFirstIdx(*T)) = X;  
    } else {
        Elmt(*T, GetLastIdx(*T)+1) = X;
    }
    Neff(*T) += 1;
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
    (*X) = Elmt(*T, GetLastIdx(*T));
    Neff(*T)--;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num)
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */
{
    TI(*T) = (ElType *) realloc(TI(*T), (MaxEl(*T)+1+num) * sizeof(int));
    MaxEl(*T) = MaxEl(*T) + num;
}

void ShrinkTab(TabInt *T, int num)
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */
{
    TI(*T) = (ElType *) realloc(TI(*T), (MaxEl(*T)+1-num) * sizeof(int));
    MaxEl(*T) = MaxEl(*T) - num;
}

void CompactTab(TabInt *T)
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */
{
    TI(*T) = (ElType *) realloc(TI(*T), (Neff(*T)+1) * sizeof(int));
    MaxEl(*T) = Neff(*T);
}