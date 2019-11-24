/* File: point.h */
/* Tanggal: 28 Agustus 2016 */
/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#ifndef POINT_H
#define POINT_H

#include "boolean.h"

typedef struct { 
	int X; /* absis   */
	int Y; /* ordinat */
} POINT;

/* *** Notasi Akses: Selektor POINT *** */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y
        
/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y);
/* I.S. : X dan Y terdefinisi
    F.S. : Membentuk sebuah POINT dari komponen-komponennya */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P); 
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
void TulisPOINT (POINT P);
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */                

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2);
/* I.S. : P1 dan P2 terdefinisi
F.S. : Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
boolean NEQ (POINT P1, POINT P2);
/* I.S. : P1 dan P2 terdefinisi
 F.S. : Mengirimkan true jika P1 tidak sama dengan P2 */
    
/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P);
/* I.S. : P1 dan P2 terdefinisi
F.S. : Menghasilkan true jika P adalah titik origin */

boolean IsOnSbX (POINT P);
/* I.S. : P1 dan P2 terdefinisi
F.S. : Menghasilkan true jika P terletak Pada sumbu X */

boolean IsOnSbY (POINT P);
/* I.S. : P1 dan P2 terdefinisi
 F.S. : Menghasilkan true jika P terletak Pada sumbu Y */
int Kuadran (POINT P);
/* I.S : P bukan titik origindan P tidak terletak di salah satu sumbu 
F.S. : Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextX (POINT P);
/* I.S : P terdefinisi 
 F.S. : Mengirim salinan P dengan absis ditambah satu */

POINT NextY (POINT P);
/* I.S : P terdefinisi 
F.S. : Mengirim salinan P dengan ordinat ditambah satu */

POINT PlusDelta (POINT P, int deltaX, int deltaY);
/* I.S : P terdefinisi 
F.S. : Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */

POINT MirrorOf (POINT P, boolean SbX);
/* I.S : P terdefinisi 
 F.S. : Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
    /* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
    /* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */

int Jarak0 (POINT P);
/* I.S : P terdefinisi 
F.S. : Menghitung jarak P ke (0,0) */

int Panjang (POINT P1, POINT P2);
/* I.S : P terdefinisi 
 F.S. : Menghitung panjang garis yang dibentuk P1 dan P2 */
    /* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
    /* Tuliskan spec fungsi yang lebih tepat. */

void Geser (POINT *P, int deltaX, int deltaY);
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
void GeserKeSbX (POINT *P);
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
void GeserKeSbY (POINT *P);
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
void Mirror (POINT *P, boolean SbX);
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
void Putar (POINT *P, int Sudut);
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */

#endif