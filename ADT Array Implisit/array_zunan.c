//Muhammad Zunan Alfikri
//16518175

#include<stdio.h>
#include "boolean.h"
#include "array.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
    Neff(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
    return Neff(T);
}

/* *** Daya tampung container *** */
int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
    return(IdxMax-IdxMin+1);
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
    return IdxMin;
}

IdxType GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
    return (Neff(T)+IdxMin-1);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return(i>=IdxMin && i<=IdxMax);
}

boolean IsIdxEff (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    return(i>=GetFirstIdx(T) && i<=GetLastIdx(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    return (Neff(T) == 0);
}

/* *** Test tabel penuh *** */
boolean IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return (Neff(T) == MaxNbEl(T));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
    //Kamus
    int i;
    IdxType k;
    
    //algoritma
    scanf("%d", &i);
    while (!(i >= 0 && i<= MaxNbEl(*T))){
        scanf("%d", &i);
    }
    Neff(*T) = i;
    if (i > 0) {
        for ( k = IdxMin ; k <= IdxMin+i-1 ; k++){
            scanf("%d", &Elmt(*T, k));
        }
    }
}

void BacaIsiTab (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
/* Dibaca elemen satu per satu dan disimpan mulai dari IdxMin */
/* Pembacaan dihentikan jika pengguna memasukkan nilai -9999 */
/* Jika dari pertama dimasukkan nilai -9999 maka terbentuk T kosong */
{
    ElType n;
    int count = 0;
    IdxType index = IdxMin;

    scanf("%d", &n);
    while(n != -9999 && count<100){
        count += 1;
        Elmt(*T, index) = n;
        index += 1;
        scanf("%d", &n);
    }
    Neff(*T) = count;
}

void TulisIsi (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50
*/
{
    IdxType i = IdxMin;
    
    if (Neff(T)==0){
        printf("Tabel kosong\n");
    } else {
        for (i; i <= GetLastIdx(T) ; i++){
            printf("[%d]%d\n", i, Elmt(T,i) );
        }
    }
}

void TulisIsiTab (TabInt T)
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
TabInt PlusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
{
    TabInt T;
    IdxType i = IdxMin;
    Neff(T) = Neff(T1);
    for (i ; i <= GetLastIdx(T1) ; i++) {
        Elmt(T, i) =  Elmt(T1, i) + Elmt(T2, i);
    }
    return T;
}

TabInt MinusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
    TabInt T;
    IdxType i = IdxMin;
    Neff(T) = Neff(T1);
    for (i ; i <= GetLastIdx(T1) ; i++) {
        Elmt(T, i) =  Elmt(T1, i) - Elmt(T2, i);
    }
    return T;
}

TabInt KaliTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan */
{
    TabInt T;
    IdxType i = IdxMin;
    Neff(T) = Neff(T1);
    for (i ; i <= GetLastIdx(T1) ; i++) {
        Elmt(T, i) =  Elmt(T1, i) * Elmt(T2, i);
    }
    return T;
}

TabInt KaliKons (TabInt Tin, ElType c)
/* Prekondisi : Tin tidak kosong */
/* Mengirimkan tabel dengan setiap elemen Tin dikalikan c */
{
    TabInt T;
    IdxType i = IdxMin;
    Neff(T) = Neff(Tin);
    for (i ; i <= GetLastIdx(Tin) ; i++) {
        Elmt(T, i) =  Elmt(Tin, i)*c;
    }
    return T;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
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

boolean IsLess (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 < T2, */
/* yaitu : sesuai dg analogi 'Ali' < Badu'; maka [0, 1] < [2, 3] */
{
    IdxType min = GetLastIdx(T1);
    if (GetLastIdx(T2)< min) min = GetLastIdx(T2);
    for (int i = GetFirstIdx(T1) ; i <= min ; i++){
        if (Elmt(T1, i) < Elmt(T2, i)) return true;
        if (Elmt(T1, i) > Elmt(T2, i)) return false;
    }
    return (NbElmt(T1)<NbElmt(T2));
    // boolean isless = true;
    // IdxType i;
    // if (Neff(T1) > Neff(T2)){
    //     isless = false;
    // } else {
    //     for (i = GetFirstIdx(T1); i <= GetLastIdx(T1) ; i++){
    //         if (Elmt(T1, i) >= Elmt(T2, i)) {
    //             isless = false;
    //         }
    //     }
    // }
    // return isless;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
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

IdxType Search2 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
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
    if (found) {
        return i;
    } else {
        return IdxUndef;
    }
}

boolean SearchB (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */
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

boolean SearchSentinel (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* dengan metoda sequential search dengan sentinel */
/* Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C 
   yang tidak dipakai dalam definisi tabel */
{
    IdxType i = GetLastIdx(T);
    Elmt(T, 0) = X;
    while (Elmt(T, i) != X){
        i--;
    }
    if (i==0) {
        return false;
    } else {
        return true;
    }
}

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
{
    ElType maks = Elmt(T, IdxMin);
    IdxType i = IdxMin+1;
    for (i ; i <= GetLastIdx(T) ; i++){
        if (Elmt(T,i) > maks) {
            maks = Elmt(T, i);
        }
    }
    return maks;
}

ElType ValMin (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
{
    ElType mins = Elmt(T, IdxMin);
    IdxType i = IdxMin+1;
    for (i ; i <= IdxMin+Neff(T)-1 ; i++){
        if (Elmt(T,i) < mins) {
            mins = Elmt(T, i);
        }
    }
    return mins;
}

IdxType IdxMaxTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai maksimum pada tabel */
{
    ElType maks = ValMax(T);
    IdxType i = IdxMin;
    while (Elmt(T, i) != maks){
        i += 1;
    }
    return i;
}

IdxType IdxMinTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai minimum pada tabel */
{
    ElType mins = ValMin(T);
    IdxType i = IdxMin;
    while (Elmt(T, i) != mins){
        i += 1;
    }
    return i;
}

/* ********** OPERASI LAIN ********** */
void CopyTab (TabInt Tin, TabInt * Tout)
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
{
    Neff(*Tout) = Neff(Tin);
    IdxType i = GetFirstIdx(Tin);
    for (i ; i <= GetLastIdx(Tin) ; i++){
        Elmt(*Tout, i) = Elmt(Tin, i);
    }
}

TabInt InverseTab (TabInt T)
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
{
    TabInt T1;
    IdxType i = IdxMin;
    Neff(T1) = Neff(T);
    if (Neff(T) != 0) {
        for (i ; i <= GetLastIdx(T) ; i++){
            Elmt(T1, i) = Elmt (T, GetLastIdx(T)+1-i);
        }
    }
    return T1;
}

boolean IsSimetris (TabInt T)
/* Menghasilkan true jika tabel simetrik */
/* Tabel disebut simetrik jika: */
/*      elemen pertama = elemen terakhir, */
/*      elemen kedua = elemen sebelum terakhir, dan seterusnya */
/* Tabel kosong adalah tabel simetris */
{
    return (IsEQ(T, InverseTab(T)));
}

/* ********** SORTING ********** */
void MaxSortDesc (TabInt * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menurun dengan Maximum Sort */
/* Proses : mengurutkan T sehingga elemennya menurun/mengecil */
/*          tanpa menggunakan tabel kerja */
{
    InsSortAsc(T);
    (*T) = InverseTab(*T);
}

void InsSortAsc (TabInt * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menaik dengan Insertion Sort */
/* Proses : mengurutkan T sehingga elemennya menaik/membesar */
/*          tanpa menggunakan tabel kerja */
{
    IdxType pass = IdxMin+1;
    IdxType i;
    ElType temp;
    if (Neff(*T) > 1){
        for (pass ; pass <= GetLastIdx(*T) ; pass++){
            temp = Elmt(*T, pass);
            i = pass-1;
            while (temp < Elmt(*T,i) && i>IdxMin) {
                Elmt(*T, i+1) = Elmt(*T, i);
                i--;
            }
            if (temp >= Elmt(*T, i)){
                Elmt(*T, i+1) = temp;
            } else {
                Elmt(*T, i+1) = Elmt(*T, i);
                Elmt(*T, i) = temp;
            }
        }
    }
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
    Elmt(*T, GetLastIdx(*T)+1) = X;
    Neff(*T) += 1;
}

void AddEli (TabInt * T, ElType X, IdxType i)
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas 
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */
{
    IdxType k = GetLastIdx(*T);
    for (k ; k>= i ; k-- ){
        Elmt(*T, k+1) = Elmt(*T, k);
    }
    Elmt(*T,i) = X;
    Neff(*T) += 1;
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
    (*X) = Elmt(*T, GetLastIdx(*T));
    Neff(*T)--;
}

void DelEli (TabInt * T, IdxType i, ElType * X)
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
{
    *X = Elmt(*T, i);
    for (i ; i < GetLastIdx(*T) ; i++){
        Elmt(*T, i) = Elmt(*T, i+1);
    }
    Neff(*T)--;
}

/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */
void AddElUnik (TabInt * T, ElType X)
/* Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/*      dan semua elemennya bernilai unik, tidak terurut */
/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T, 
        jika belum ada elemen yang bernilai X. 
    Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S. 
    dan dituliskan pesan "nilai sudah ada" */
/* Proses : Cek keunikan dengan sequential search dengan sentinel */
/*          Kemudian tambahkan elemen jika belum ada */
{
    boolean found = SearchSentinel(*T, X);
    if (!found && !(IsFull(*T))){
        Elmt(*T, GetLastIdx(*T)+1) = X; 
        Neff(*T)+=1;
    } else if (found) {
        printf("nilai sudah ada\n");
    }
}

/* ********** TABEL DGN ELEMEN TERURUT MEMBESAR ********** */
IdxType SearchUrut (TabInt T, ElType X)
/* Prekondisi: Tabel T boleh kosong. Jika tidak kosong, elemen terurut membesar. */
/* Mengirimkan indeks di mana harga X dengan indeks terkecil diketemukan */
/* Mengirimkan IdxUndef jika tidak ada elemen tabel bernilai X */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel kosong */
{
    return Search2(T, X);
}

ElType MaxUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai maksimum pada tabel */
{
    return (Elmt(T, GetLastIdx(T)));
}

ElType MinUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai minimum pada tabel*/
{
    return (Elmt(T, GetFirstIdx(T)));
}

void MaxMinUrut (TabInt T, ElType * Max, ElType * Min)
/* I.S. Tabel T tidak kosong, elemen terurut membesar */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
    *Min = MinUrut(T);
    *Max = MaxUrut(T);
}

void Add1Urut (TabInt * T, ElType X)
/* Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel */
/* Nilai dalam tabel tidak harus unik. */
/* I.S. Tabel T boleh kosong, boleh penuh. */
/*      Jika tabel isi, elemennya terurut membesar. */
/* F.S. Jika tabel belum penuh, menambahkan X. */
/*      Jika tabel penuh, maka tabel tetap. */
/* Proses : Search tempat yang tepat sambil geser */
/*          Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan */
{
    IdxType i = IdxMin;
    if (!(IsFull(*T))){
        while (Elmt(*T, i)<X){
            i += 1;
        }
        AddEli(T, X, i);
    }
}

void Del1Urut (TabInt * T, ElType X)
/* Menghapus X yang pertama kali (pada indeks terkecil) yang ditemukan */
/* I.S. Tabel tidak kosong */
/* F.S. Jika ada elemen tabel bernilai X , */
/*      maka banyaknya elemen tabel berkurang satu. */
/*      Jika tidak ada yang bernilai X, tabel tetap. */
/*      Setelah penghapusan, elemen tabel tetap kontigu! */
/* Proses : Search indeks ke-i dengan elemen ke-i = X. */
/*          Delete jika ada. */
{
    IdxType i = Search1(*T, X);
    if (i != IdxUndef){
        for (i ; i < GetLastIdx(*T) ; i++){
            Elmt(*T, i) = Elmt(*T, i+1);
        }
        Neff(*T)--;
    }
}