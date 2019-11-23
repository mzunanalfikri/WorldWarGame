/* realisasi dari graph */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "graph.h"


boolean IsEmptyGraph (Graph G)
/* Mengirim true jika graph kosong */
{
    return (FirstParent(G) == NULL);
}

void CreateEmptyGraph(Graph *G)
/* I.S. sembarang */
/* F.S. terbentuk graph kosong */
{
    FirstParent(*G) = NULL;
}

addressParent AlokasiParent (infotype X)
/* Mengirimkan addressParent hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addresslist tidak nil, dan misalnya */
/* menghasilkan P, maka InfoParent(P)=X, NextParent(P)=Nil, CreateEmptyList(Child(P)) */
/* Jika alokasi gagal, mengirimkan Nil */
{
    addressParent P;
    P = (addressParent) malloc (sizeof(ElmtParent));
    if (P != NULL){
        InfoParent(P) = X;
        NextParent(P) = NULL;
        CreateEmptyList(&Child(P));
        return P;
    } else {
        return NULL;
    }
}

void DealokasiGraph (addressParent *G)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addresslist P */
{
    free(*G);
}

addressParent SearchParent (Graph G, infotype X)
/* Mencari apakah ada elemen Parent graph dengan InfoParent(G)= X */
/* Jika ada, mengirimkan addressParent elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    // KAMUS LOKAL
    addressParent P;
    boolean Found;

    // ALGORITMA
    P = FirstParent(G);
    Found = false;

    while ((P != NULL) && (!Found))
    {
        if (InfoParent(P) == X)
        {
            Found = true;
        }
        else
        {
            P = NextParent(P);
        }
    }

    return P;
}

void InsVFirstParent (Graph *G, infotype X)
/* I.S. G mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    addressParent P;

    P = AlokasiParent(X);
    if (P != NULL)
    {
        NextParent(P) = FirstParent(*G);
        FirstParent(*G) = P;
    }
}

void InsVLastParent (Graph *G, infotype X)
/* I.S. G mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    addressParent P,Last;

    P = AlokasiParent(X);
    if (P != NULL)
    {
        if (IsEmptyGraph(*G))
        {
            NextParent(P) = FirstParent(*G);
            FirstParent(*G) = P;
        }
        else
        {
            Last = FirstParent(*G);
            while (NextParent(Last) != NULL)
            {
                Last = NextParent(Last);
            }
            NextParent(Last) = P;
        }
    }
}

void InsertFirstParent (Graph *G, addressParent P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressParent P sebagai elemen pertama */
{
    NextParent(P) = FirstParent(*G);
    FirstParent(*G) = P;
}

void InsertLastParent (Graph *G, addressParent P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    addressParent Last;

    if (IsEmptyGraph(*G))
    {
		InsertFirstParent(G,P);
	}
	else
    {
        Last = FirstParent(*G);
        while (NextParent(Last) != NULL)
        {
            Last = NextParent(Last);
        }
        NextParent(P) = NULL;
        NextParent(Last) = P;
    }
}

void PrintInfoGraph (Graph G)
/* I.S. graph mungkin kosong */
/* F.S. Jika list tidak kosong, isi graph dicetak dgn format: infoparent : [child] */
/* Jika list kosong : menulis [] */
{
    addressParent P;
    P = FirstParent(G);
    if (!IsEmptyGraph(G)){
        while (P != NULL) {
            printf("indeks bangunan %d terhubung dengan : ", InfoParent(P));
            PrintInfo(Child(P));
            P = NextParent(P);
        }
    } else {
        printf("graph kosong");
    }
}

boolean IsTerhubung (Graph G, int Bangunan1, int Bangunan2)
/* Mengembalikan true jika bangunan 1 dan bangunan 2 terhubung */
{
    addressParent P;
    List L;

    P = SearchParent(G, Bangunan1);
    L = Child(P);
    return (SearchB(L, Bangunan2));    
}