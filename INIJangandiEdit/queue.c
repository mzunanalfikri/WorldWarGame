#include "queue.h"
#include "stdio.h"
#include "stdlib.h"

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return (Head(Q) == 0 && Tail(Q) == 0);
}
boolean IsFullQueue (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxElQueue */
{
    return ((Head(Q) - Tail(Q) + 1)% MaxElQueue(Q) == 0 );
}
int NBElmt (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    if (IsEmpty(Q))
    {
        return 0;
    }
    else // queue tidak kosong
    {
        if (Head(Q) <= Tail(Q))
        {
            return (Tail(Q) - Head(Q) +1);
        }
        else // head leih besar dari tail
        {
            return (MaxElQueue(Q) - (Head(Q) - Tail(Q)) +1);
        }
    }
}

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxElQueue=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    // Alokasi queue kedalam memori
    (*Q).T = (infotype *) malloc ((Max+1) * sizeof(infotype));

    // Mengeset queue yang akan dibuat
    if ((*Q).T != NULL)
    {
        MaxElQueue(*Q) = Max;
        Head(*Q) = 0;
        Tail(*Q) = 0;
    }
    else // Jika alokasi gagal
    {
        MaxElQueue(*Q) = 0;
    }
}

/* *** Destruktor *** */
void DeAlokasi(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxElQueue(Q) diset 0 */
{
    MaxElQueue(*Q) = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
    // KAMUS LOKAL

    // ALGORITMA
    if(NBElmt(*Q)>=10){
        printf("Kamu memiliki terlalu banyak Skill!\n");
    }else{
        if (IsEmpty(*Q))
        {
            Head(*Q) = 1;
            Tail(*Q) = 1;
            InfoTail(*Q)=X;
        }
        else if (Tail(*Q) != MaxElQueue(*Q))
        {
            Tail(*Q)++;
            InfoTail(*Q)=X;

        }
        else // Tail = indeks akhir
        {
            Tail(*Q) = 1;
            InfoTail(*Q)=X;

        }
    }
}
void Del (Queue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = 0ai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    *X = InfoHead(*Q);
    if (Head(*Q)== Tail(*Q))  /* Set mjd queue kosong */
    {
        Head(*Q)=0;
        Tail(*Q)=0;
    }
    else if (Head(*Q) != MaxElQueue(*Q))
    {
        Head(*Q)++;
    }
    else // Head sama dengan indeks terakhir
    {
        Head(*Q) = 1;
    }
}
void PrintQSkill (Queue Q)
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
{
    infotype X;
    printf("Skill Avaible | ");
    while (!IsEmpty(Q)){
        Del(&Q,&X);
        if (X == 1){
            printf("InstantUpgrade |");
        } else if (X == 2) {
            printf("Shield |");
        } else if (X == 3) {
            printf("Extra Turn |");
        } else if (X == 4){
            printf("AttackUp |");
        } else if (X == 5){
            printf ("CriticalHit |");
        } else if (X == 6) {
            printf("InstantReinforcement |");
        } else if (X == 7) {
            printf("Barrage |");
        }
    }
    printf("\n");
}


void CopyQueue (Queue Q1 ,Queue *Q2)
/* Proses: Melakukan assignment Q1 ke Q2 */
/* I.S. Q sembarang */
/* F.S. Q2 merupakan queue hasil copy dari Q1 */
{
    
    infotype X;
    CreateEmpty(Q2,10);
    while(!IsEmpty(Q1)){
        Del(&Q1,&X);
        Add(Q2,X);
    }
}

void PrintTopQSkill (Queue Q)
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
{
    infotype X;
    printf("Skill Avaible : ");
    
    if (!IsEmpty(Q)){
        Del(&Q,&X);
        if (X == 1){
            printf("InstantUpgrade ");
        } else if (X == 2) {
            printf("Shield ");
        } else if (X == 3) {
            printf("Extra Turn ");
        } else if (X == 4){
            printf("AttackUp ");
        } else if (X == 5){
            printf ("CriticalHit ");
        } else if (X == 6) {
            printf("InstantReinforcement ");
        } else if (X == 7) {
            printf("Barrage");
        }
    } else {
        printf("Kamu tidak mempunyai skill.");
    }
    printf("\n");
}