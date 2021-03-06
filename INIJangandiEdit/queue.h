/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

#ifndef queue_H
#define queue_H

#include "boolean.h"
/* ======================================
INTEGER DIPETAKAN KE SKILL :
1 --> Instant Upgrade
2 --> shield (BONUS)
3 --> Extra Turn
4 --> Attack Up (BONUS)
5 --> Critical Hit (BONUS)
6 --> Instant Reinforcement
7 --> Barrage
=========================================== */
/* Konstanta untuk mendefinisikan addressQ tak terdefinisi */

/* Definisi elemen dan addressQ */
typedef int infotype;
typedef int addressQ;   /* indeks tabel */
/* Contoh deklarasi variabel bertype Queue : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct { infotype * T;   /* tabel penyimpan elemen */
                 addressQ HEAD;  /* alamat penghapusan */
                 addressQ TAIL;  /* alamat penambahan */
                 int MaxElQueue;     /* Max elemen queue */
               } Queue;
/* Definisi Queue kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika Q adalah Queue, maka akses elemen : */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxElQueue(Q) (Q).MaxElQueue

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFullQueue (Queue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxElQueue */
int NBElmt (Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxElQueue=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(Queue * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxElQueue(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X);
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
void Del (Queue * Q, infotype * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
void CopyQueue (Queue Q1 ,Queue *Q2);
/* Proses: Melakukan assignment Q1 ke Q2 */
/* I.S. Q sembarang */
/* F.S. Q2 merupakan queue hasil copy dari Q1 */
void PrintQSkill (Queue Q);
/* Proses: Menampilkan ke layar isi Q dengan aturan FIFO */
/* I.S. Q sembarang */
/* F.S. Semua isi Q ditampilkan ke layar dan dibatasi dengan "|" dengan aturan sebagai berikut: */
/* ======================================
INTEGER DIPETAKAN KE SKILL :
1 --> Instant Upgrade
2 --> shield 
3 --> Extra Turn
4 --> Attack Up 
5 --> Critical Hit 
6 --> Instant Reinforcement
7 --> Barrage
=========================================== */

void PrintTopQSkill (Queue Q);
/* Proses: Menampilkan ke layar head Q */
/* I.S. Q sembarang */
/* F.S. Head dari Q ditampilkan ke layar dengan aturan sebagai berikut: */
/* ======================================
INTEGER DIPETAKAN KE SKILL :
1 --> Instant Upgrade
2 --> shield 
3 --> Extra Turn
4 --> Attack Up 
5 --> Critical Hit 
6 --> Instant Reinforcement
7 --> Barrage
=========================================== */

#endif
