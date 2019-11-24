#ifndef H_Function_H
#define H_Function_H

//#include "../Aarraydin.h"
//#include "bangunan.h"
#include "../ADT Graph/graph.h"
//#include "listlinier.h"
#include "../ADT Matriks/matriks.h"
//#include "player.h"
//#include "point.h"
#include "../ADT Mesin Kata/mesinkar.h"
#include "../ADT Mesin Kata/mesinkata.h"
//#include "queue.h"
#include "../Modul Read File/readfile.h"
#include "../ADT Stack/stackt.h"
#include "../ADT State/state.h"
#include "../Modul Pcolor/pcolor.h"
#include<stdio.h>
#include<stdlib.h>
#include "welcome.h"


/* **** SKILL **** */

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

void Skill(State *S, boolean * ExtraTurn, boolean * AttackUP);
/* Untuk memanggil skill skill */

void InstantUpgrade (State *S);
/*Seluruh bangunan yang dimiliki pemain akan naik 1 level.
Pemain tidak akan mendapat skill ini selain dari daftar skill awal.*/

void Shield (State *S); //bonus
/*Seluruh bangunan yang dimiliki oleh pemain akan memiliki pertahanan selama 2
turn lawan. Apabila skill ini digunakan 2 kali berturut-turut, durasi tidak akan
bertambah, namun menjadi nilai maksimum.
Pemain mendapat skill ini jika setelah sebuah lawan menyerang, bangunan pemain
berkurang 1 menjadi sisa 2.*/

void EndTurn (State *S, boolean *ExtraTurn, boolean *attackUP,Kata player1, Kata player2);
/* kondisi P1 saat ini : P2 turn true, setiap bangunan di P2 bertambah pasukannya */
/* kondisi P2 saat ini : P1 trun true, setiap bangunan di P1 bertambah pasukannya */


void ExtraTurnSkill (State *S, boolean *ExtraTurn);
/*Setelah giliran pengaktifan skill ini berakhir, pemain selanjutnya tetap pemain
yang sama.
Pemain mendapat skill ini jika Fort pemain tersebut direbut lawan.
*/

void AttackUp (boolean *AttackUp); //bonus
/*Pada giliran ini, setelah skill ini diaktifkan, pertahanan bangunan musuh (termasuk
Shield) tidak akan mempengaruhi penyerangan.
Pemain mendapat skill ini jika pemain baru saja menyerang Tower lawan dan
jumlah towernya menjadi 3.*/


void CriticalHit (State *S);
/*Pada giliran ini, setelah skill diaktifkan, jumlah pasukan pada bangunan yang
melakukan serangan tepat selanjutnya (hanya berlaku 1 serangan) hanya
efektif sebanyak 2 kali lipat pasukan. Skill ini
akan menonaktifkan Shield maupun pertahanan bangunan, seperti Attack Up.
Pemain mendapat skill ini jika lawan baru saja mengaktifkan skill Extra Turn.
*/

void AddIR (State *S);
/* Procedur untuk pengecekan penambahan skill Instant Reinforcement */

void InstantReinforcement (State *S);
/*Seluruh bangunan mendapatkan tambahan 5 pasukan.
Pemain mendapat skill ini di akhir gilirannya bila semua bangunan yang ia miliki
memiliki level 4.*/

void Barrage (State *S);
/*Jumlah pasukan pada seluruh bangunan musuh akan berkurang sebanyak 10
pasukan.
Pemain mendapat skill ini jika lawan baru saja bertambah bangunannya menjadi
10 bangunan.*/

/*************************/
/* MENAMPILKAN GAME PLAY */
/*************************/
void StatusPlayer(State S, MATRIKS Map,Kata player1, Kata player2);
/* prosedur untuk menampilkan status player (map, bangunan, skill) */

// Fungsi untuk cetak matriks dengan warna
void CetakMatiksWarna(MATRIKS M, State S);
/* Mencetak di layar matriks dengan warnanya */

void EnterCommad(State S);
/* prosedur untuk mencetak warna enter command sesuai playar */

/************/
/* LEVEL UP */
/************/
void ChooseBangunanPlayerLevelUp(State S, int *x, boolean player1);
/* F.S. X menjadi indeks bangunan yang dipilih pemain */

void LevelUp(State * S);
/* Procedure untuk level up */

/************/
/*   MOVE   */
/************/
void ChooseBangunanPlayerMove(State S, Graph G, int *pendonor, int *penerima, boolean player1);
/* F.S. pendonor menjadi indeks bangunan yang mengirim, penerima menjadi bangunan yang 
        dipilih */
void MovePasukaB1B2(State *S, int pendonor, int penerima);
/* Fungsi transisi untuk move pasukan */

void MovePasukan(State *S, Graph G);
/* Procedure untuk memindahkan pasukan dari bangunan satu ke lainnya */

/**************/
/*   ATTACK   */
/**************/
void ChooseBangunanPlayerAttack(State S, Graph G, int *serang, int *defend, boolean player1);
/* F.S. serang menjadi indeks bangunan penyerang, defend menjadi indeks bangunan
        yang bertahan */

void PreAttack(State *S, int serang, int defend, boolean *attackUP);
/* prosedur transisi untuk attack */

void Attack(State *S, Graph G, boolean * attackUP);
/* Procedure untuk memindahkan pasukan dari bangunan satu ke lainnya */

int NBElmtTower(List L, TabBangunan B);
/* Mengembalikan banyaknya element tower dari sebuah list */

void GameEnd(State S, boolean *endgame);
/* Kondisi game berakhir */

void Help();
/* I.S. Sembarang */
/* F.S. Mencetak list command di layar */

void CetakWarnaRed(Kata CKata);
/* Untuk Mencetak warna merah CKata */

void CetakWarnaBlue(Kata CKata);
/* Untuk Mencetak warna merah CKata */

#endif