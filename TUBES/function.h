#ifndef H_Function_H
#define H_Function_H

#include "arraydin.h"
#include "bangunan.h"
#include "graph.h"
#include "listlinier.h"
#include "matriks.h"
#include "player.h"
#include "point.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "queue.h"
#include "readfile.h"
#include "stackt.h"
#include "state.h"
#include "pcolor.h"
#include<stdio.h>
#include<stdlib.h>


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

void InstantUpgrade (State *S);
/*Seluruh bangunan yang dimiliki pemain akan naik 1 level.
Pemain tidak akan mendapat skill ini selain dari daftar skill awal.*/

void Shield (State *S); //bonus
/*Seluruh bangunan yang dimiliki oleh pemain akan memiliki pertahanan selama 2
turn lawan. Apabila skill ini digunakan 2 kali berturut-turut, durasi tidak akan
bertambah, namun menjadi nilai maksimum.
Pemain mendapat skill ini jika setelah sebuah lawan menyerang, bangunan pemain
berkurang 1 menjadi sisa 2.*/

void EndTurn (State *S);
/* kondisi P1 saat ini : P2 turn true, setiap bangunan di P2 bertambah pasukannya */
/* kondisi P2 saat ini : P1 trun true, setiap bangunan di P1 bertambah pasukannya */


void ExtraTurn (State *S);
/*Setelah giliran pengaktifan skill ini berakhir, pemain selanjutnya tetap pemain
yang sama.
Pemain mendapat skill ini jika Fort pemain tersebut direbut lawan.
*/

boolean IsExtraTurn (State S);
void AttackUp (State *S); //bonus
/*Pada giliran ini, setelah skill ini diaktifkan, pertahanan bangunan musuh (termasuk
Shield) tidak akan mempengaruhi penyerangan.
Pemain mendapat skill ini jika pemain baru saja menyerang Tower lawan dan
jumlah towernya menjadi 3.*/

boolean IsAttackUp (State S);

void CriticalHit (State *S);
/*Pada giliran ini, setelah skill diaktifkan, jumlah pasukan pada bangunan yang
melakukan serangan tepat selanjutnya (hanya berlaku 1 serangan) hanya
efektif sebanyak 2 kali lipat pasukan. Skill ini
akan menonaktifkan Shield maupun pertahanan bangunan, seperti Attack Up.
Pemain mendapat skill ini jika lawan baru saja mengaktifkan skill Extra Turn.
*/

void InstantReinforcement (State *S);
/*Seluruh bangunan mendapatkan tambahan 5 pasukan.
Pemain mendapat skill ini di akhir gilirannya bila semua bangunan yang ia miliki
memiliki level 4.*/
boolean IsIR (State S);

void Barrage (State *S);
/*Jumlah pasukan pada seluruh bangunan musuh akan berkurang sebanyak 10
pasukan.
Pemain mendapat skill ini jika lawan baru saja bertambah bangunannya menjadi
10 bangunan.*/

boolean IsBarrage (State SMusuh);


void StatusPlayer(State S, MATRIKS Map);
/* prosedur untuk menampilkan status player (map, bangunan, skill) */

// Fungsi untuk cetak matriks dengan warna
void CetakMatiksWarna(MATRIKS M, State S);
/* Mencetak di layar matriks dengan warnanya */

void EnterCommad(State S);
/* prosedur untuk mencetak warna enter command sesuai playar */

/************/
/* LEVEL UP */
/************/
void ChooseBangunanPlayer(State S, int *x);
/* F.S. X menjadi indeks bangunan yang dipilih pemain */

void LevelUp(State * S);
/* Procedure untuk level up */

/************/
/*   MOVE   */
/************/
#endif