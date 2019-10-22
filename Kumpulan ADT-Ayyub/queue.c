#include "boolean.h"
#include "queue.h"
#include <stdlib.h>

boolean IsEmpty (Queue Q){
    return ((Q.HEAD == Nil) && (Q.TAIL == Nil));
}
/* Mengirim true jika Q kosong: lihat definisi di atas */


boolean IsFull (Queue Q){
     return (Q.TAIL == Q.MaxEl);
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */

int NBElmt (Queue Q){
    if (Q.TAIL == Q.HEAD){
        return 0;
    } else if (Q.TAIL > Q.HEAD){
        return (Q.TAIL-Q.HEAD+1);
    } else {
        return (Q.MaxEl-(Q.HEAD-Q.TAIL)+1);
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max){
    Q -> T = (infotype *) malloc ((Max+1) * sizeof(infotype));
    if (Q -> T != NULL) {
        Q->HEAD = 0;
        Q->TAIL = 0;
        Q->MaxEl = Max;
    }
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(Queue * Q){
    free(Q->T);
    MaxEl(*Q) = 0;
    Head(*Q) = 0;
    Tail(*Q) = 0;
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X){
    if (!(IsFull(*Q))){
        if (IsEmpty(*Q)){
            Q -> HEAD = 1;
            Q -> TAIL = 1;
            Q ->T[Q->TAIL] = X;
        } else if (Q->TAIL == Q->MaxEl){
            Q -> TAIL = 1;
            Q ->T[Q -> TAIL] = X;
        } else {
            Q->TAIL += 1;
            Q->T[Q->TAIL] = X;
        }
    }
}
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
void Del (Queue * Q, infotype * X){
    *X = Q->T[Q->HEAD];
    if (Q->TAIL == Q->HEAD){
        Q -> HEAD = Nil;
        Q -> TAIL = Nil;
    } else if ((Q->HEAD) == Q->MaxEl){
        Q -> HEAD = 1;
    } else {
        Q -> HEAD += 1;
    }
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
