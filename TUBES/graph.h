/* File : graph.h 
Representasi address dengan multi list,
analogi parent dan child (supaya mudah),
parent bangunannya, child (indeks bangunan yang terhubung)
*/

#ifndef H_Graph_H
#define H_Graph_H

#include "boolean.h"
#include "listlinier.h"


typedef struct tElmtParent  *addressParent;
typedef struct tElmtParent {
    infotype infoparent;
    addressParent nextparent;
    List Child;
} ElmtParent;

typedef struct {
    addressParent FirstParent;
} Graph;

/* Definisi graph :
Graph : firstParent  = NULL
elemtn terakhir Parent jika nextparent(Last) = NULL
setiap child dapat diakses dengan Child(P)
*/
#define InfoParent(G) (G)->infoparent
#define NextParent(G) (G)->nextparent
#define Child(G) (G)->Child
#define FirstParent(G) ((G).FirstParent)


boolean IsEmptyGraph (Graph G);
/* Mengirim true jika graph kosong */

void CreateEmptyGraph(Graph *G);
/* I.S. sembarang */
/* F.S. terbentuk graph kosong */

addressParent AlokasiParent (infotype X);
/* Mengirimkan addressParent hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addresslist tidak nil, dan misalnya */
/* menghasilkan P, maka InfoParent(P)=X, NextParent(P)=Nil, CreateEmptyList(Child(P)) */
/* Jika alokasi gagal, mengirimkan Nil */

void DealokasiGraph (addressParent *G);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addresslist P */

addressParent SearchParent (Graph G, infotype X);
/* Mencari apakah ada elemen Parent graph dengan InfoParent(G)= X */
/* Jika ada, mengirimkan addressParent elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

void InsVFirstParent (Graph *G, infotype X);
/* I.S. G mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

void InsVLastParent (Graph *G, infotype X);
/* I.S. G mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void InsertFirstParent (Graph *G, addressParent P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressParent P sebagai elemen pertama */

void InsertLastParent (Graph *G, addressParent P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

void PrintInfoGraph (Graph G);
/* I.S. graph mungkin kosong */
/* F.S. Jika list tidak kosong, isi graph dicetak dgn format: infoparent : [child] */
/* Jika list kosong : menulis [] */



#endif