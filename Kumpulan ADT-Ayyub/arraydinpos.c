#include "arraydinpos.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel){
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
    TI(*T) = (ElType *) malloc ((maxel+1) * sizeof(ElType));
    if (TI(*T) != NULL) {
        MaxEl(*T) = maxel;
        for (int i = IdxMin; i <= T->MaxEl; i++){
			T->TI[i] = ValUndef;
		}
    }
}

void Dealokasi(TabInt *T){
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
    free(TI(*T));
    MaxEl(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T){
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
    int count = 0;
	for (int i = IdxMin; i <= T.MaxEl; i++){
			if (T.TI[i] != ValUndef){
				count += 1;
			}
		}
	return count;
}

int MaxElement(TabInt T){
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
    return T.MaxEl;
}

IdxType GetFirstIdx(TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
    return IdxMin;
}

IdxType GetLastIdx(TabInt T){
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
    return NbElmt(T);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i){
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
    return IdxMin <= i && i <= T.MaxEl;
}

boolean IsIdxEff(TabInt T, IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
    return GetFirstIdx(T) <= i && i <= GetLastIdx(T);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T){
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
    return (NbElmt(T) == 0);
}
/* *** Test tabel penuh *** */
boolean IsFull(TabInt T){
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
    return (NbElmt(T) == T.MaxEl);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T){
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
	int N;
    while (1) {
        scanf("%d", &N);
        if (0 <= N && N <= MaxElement(*T))
            break;
    }
    int i = IdxMin;
    while (i < IdxMin+N)
        scanf("%d", &(T->TI[i++]));
}


void TulisIsiTab(TabInt T){
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
   int i;
	if (IsEmpty(T)){
		printf("[]");
	}
	else {
		printf("[");
		for (i = IdxMin; i < GetLastIdx(T); i++){
			printf("%d,",T.TI[i]);
		}
		printf("%d]",T.TI[GetLastIdx(T)]);
	}
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus){
/* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
    TabInt T;
    MakeEmpty(&T,MaxEl(T1));
    for (int i = IdxMin; i < IdxMin+NbElmt(T1); i++)
        if (plus) {
            T.TI[i] = T1.TI[i] + T2.TI[i];
        } else {
            T.TI[i] = T1.TI[i] - T2.TI[i];
        }
    return T;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2){
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */
    if (NbElmt(T1) != NbElmt(T2))
        return false;
    for (int i = IdxMin; i < IdxMin+NbElmt(T1); i++)
        if (T1.TI[i] != T2.TI[i])
            return false;
    return true;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X){
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
    for (int i = IdxMin; i < IdxMin+NbElmt(T); i++)
        if (T.TI[i] == X)
            return i;
    return IdxUndef;
}

boolean SearchB(TabInt T, ElType X){
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
    boolean found = false;
    int i = IdxMin;
    while (!found && i < IdxMin+NbElmt(T))
        found = T.TI[i++] == X;
    return found;
}

/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min){
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
    int max = T.TI[IdxMin];
    for (int i = IdxMin+1; i < IdxMin+NbElmt(T); i++)
        max = T.TI[i] > max ? T.TI[i] : max;
    *Max = max;
    int min = T.TI[IdxMin];
    for (int i = IdxMin+1; i < IdxMin+NbElmt(T); i++)
        min = T.TI[i] < min ? T.TI[i] : min;
    *Min = min;
}

/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout){
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */
    MakeEmpty((&(*Tout)),Tin.MaxEl);
    for (int i = IdxMin; i < IdxMin+NbElmt(Tin); i++)
        Tout->TI[i] = Tin.TI[i];
}

ElType SumTab(TabInt T){
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
    int Sum = 0;
    for (int i = IdxMin; i < IdxMin+NbElmt(T); i++)
        Sum += T.TI[i];
    return Sum;
}

int CountX(TabInt T, ElType X){
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
    int count = 0;
    int i;
	for (i = IdxMin; i <= NbElmt(T); i++){
		if (T.TI[i] == X) {
			count += 1;
		}
	}
    return count;
}

boolean IsAllGenap(TabInt T){
/* Menghailkan true jika semua elemen T genap. T boleh kosong */
    int Genap = 1;
    int i;
    Genap = (NbElmt(T) != 0);
	for (i = IdxMin; i <= NbElmt(T); i++){
		if (T.TI[i] % 2 == 1) {
			Genap = 0;
		}
	}
    return Genap;
}

/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc){
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
   int N = 0;
   for (int i = IdxMin; i <= T->MaxEl; i++){
			if (T->TI[i] != ValUndef){
				N += 1;
			}
		}
   if (!asc){
    int ind = IdxMin;
        while (ind < IdxMin+N) {
            int index = ind;
            for (int i = ind+1; i < IdxMin+N; i++)
                index = T->TI[i] > T->TI[index] ? i : index;
            int temp = T->TI[index];
            T->TI[index] = T->TI[ind];
            T->TI[ind++] = temp;
        }
   } else {
      int i = IdxMin;
        while (i < IdxMin+N) {
        int min = T->TI[i], minIndex = i;
        for (int j = i+1; j < IdxMin+N; j++)
            if (T->TI[j] < min) {
                min = T->TI[j];
                minIndex = j;
            }
        int temp = T->TI[minIndex];
        T->TI[minIndex] = T->TI[i];
        T->TI[i] = temp;
        ++i;
    } 
   }
}


/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X){
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
    if (IsFull(*T))
        return;
    int N = 0;
	for (int i = IdxMin; i <= T->MaxEl; i++){
			if (T->TI[i] != ValUndef){
				N += 1;
			}
		}
    T->TI[IdxMin+N] = X;
}
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X){
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
	int N = 0;
	for (int i = IdxMin; i <= T->MaxEl; i++){
			if (T->TI[i] != ValUndef){
				N += 1;
			}
		}
    *X = T->TI[IdxMin+N-1];
    T->TI[IdxMin+N-1] = ValUndef;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num){
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */
    TI(*T) = (ElType*)realloc(TI(*T), (T->MaxEl+num-IdxMin+1)*sizeof(ElType));
    if (TI(*T) == NULL) {
        printf("Alokasi memori gagal.\n");
    } else { // else berhasil
        MaxEl(*T) += num;
    }
}
void ShrinkTab(TabInt *T, int num){
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */
    TI(*T) = (ElType*)realloc(TI(*T), (T->MaxEl-num-IdxMin+1)*sizeof(ElType));
    if (TI(*T) == NULL) {
        printf("Alokasi memori gagal.\n");
    } else { // else berhasil
        MaxEl(*T) -= num;
    }
}

void CompactTab(TabInt *T){
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */
	int N = 0;
    if (TI(*T) == NULL) {
        printf("Alokasi memori gagal.\n");
    } else { // else berhasil
		for (int i = IdxMin; i <= T->MaxEl; i++){
			if (T->TI[i] != ValUndef){
				N += 1;
			}
		}
        MaxEl(*T) = N;
    }
    TI(*T) = (ElType*)realloc(TI(*T), (N+1)*sizeof(ElType));
}
