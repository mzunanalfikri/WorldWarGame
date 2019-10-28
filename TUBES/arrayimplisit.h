/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit, 
   memori tabel statik */

#ifndef ARRAYIMPLISIT_H
#define ARRAYIMPLISIT_H

#include "boolean.h"


/*  Kamus Umum */
#define IdxMax 100
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define IdxMin 1
/* Indeks minimum array */
#define IdxUndef -999 
/* Indeks tak terdefinisi*/
#define ValUndef 0
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;  /* type indeks */

typedef struct {
    int Id;
    char Type;
    int Pasukan;
    int Level;
    int A;
    int M;
    boolean P;
    POINT Posisi;
} Bangunan; //Type elemen tabel

typedef struct { 
	Bangunan TI[IdxMax+1]; /* memori tempat penyimpan elemen (container) */
} TabInt;
/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses: 
   T.TI    untuk mengakses seluruh nilai elemen tabel 
   T.TI[i] untuk mengakses elemen ke-i */
/* Definisi : 
  Tabel kosong: semua elemen bernilai ValUndef
  Definisi elemen pertama : T.TI[i] dengan i=1 
  Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */
  
/* ********** SELEKTOR ********** */
#define TI(T)     (T).TI
#define Elmt(T,i) (T).TI[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T);
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxNbEl (TabInt T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx (TabInt T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i);
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff (TabInt T, IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull (TabInt T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T);
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
void BacaIsiTab (TabInt * T);
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
/* Dibaca elemen satu per satu dan disimpan mulai dari IdxMin */
/* Pembacaan dihentikan jika pengguna memasukkan nilai -9999 */
/* Jika dari pertama dimasukkan nilai -9999 maka terbentuk T kosong */
void TulisIsi (TabInt T);
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
void TulisIsiTab (TabInt T);
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */

/* ********** NILAI EKSTREM ********** */
IdxType IdxMaxTab (TabInt T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai maksimum pada tabel */
IdxType IdxMinTab (TabInt T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai minimum pada tabel */

/* ********** OPERASI LAIN ********** */
void CopyTab (TabInt Tin, TabInt * Tout);
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, Bangunan B);
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
void AddEli (TabInt * T, Bangunan B, IdxType i);
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas 
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, Bangunan * B);
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
void DelEli (TabInt * T, IdxType i, Bangunan * B);
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */

/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */
void AddElUnik (TabInt * T, Bangunan B);
/* Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/*      dan semua elemennya bernilai unik, tidak terurut */
/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T, 
        jika belum ada elemen yang bernilai X. 
		Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S. 
		dan dituliskan pesan "nilai sudah ada" */
/* Proses : Cek keunikan dengan sequential search dengan sentinel */
/*          Kemudian tambahkan elemen jika belum ada */

#endif