#include <stdio.h>
#include "function.h"


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


void InstantUpgrade (State *S){
    for(int i=1;i<=NbElmtTabArray(ArrayBangunan(*S));i++){
        NaikLevel(&ElmtTab((ArrayBangunan(*S)),i));
    }
}
/*Seluruh bangunan yang dimiliki pemain akan naik 1 level.
Pemain tidak akan mendapat skill ini selain dari daftar skill awal.*/

void Shield (State *S){ //bonus

}
/*Seluruh bangunan yang dimiliki oleh pemain akan memiliki pertahanan selama 2
turn lawan. Apabila skill ini digunakan 2 kali berturut-turut, durasi tidak akan
bertambah, namun menjadi nilai maksimum.
Pemain mendapat skill ini jika setelah sebuah lawan menyerang, bangunan pemain
berkurang 1 menjadi sisa 2.*/

void EndTurn (Player *P1, Player *P2){
    Turn(*P1) = false;
    Turn(*P2) = true;
    //teuinggg
}
/*I.S. : turn P1=true*/
/*F.S. : setelah end_turn, turn P2=true, P1=false*/

void ExtraTurn (State *S){

}
/*Setelah giliran pengaktifan skill ini berakhir, pemain selanjutnya tetap pemain
yang sama.
Pemain mendapat skill ini jika Fort pemain tersebut direbut lawan.
*/
boolean IsExtraTurn (State S){

}

void AttackUp (State *S){ //bonus

} 
/*Pada giliran ini, setelah skill ini diaktifkan, pertahanan bangunan musuh (termasuk
Shield) tidak akan mempengaruhi penyerangan.
Pemain mendapat skill ini jika pemain baru saja menyerang Tower lawan dan
jumlah towernya menjadi 3.*/

boolean IsAttackUp (State S){

}

void CriticalHit (State *S){ //bonus

}
/*Pada giliran ini, setelah skill diaktifkan, jumlah pasukan pada bangunan yang
melakukan serangan tepat selanjutnya (hanya berlaku 1 serangan) hanya
efektif sebanyak 2 kali lipat pasukan. Skill ini
akan menonaktifkan Shield maupun pertahanan bangunan, seperti Attack Up.
Pemain mendapat skill ini jika lawan baru saja mengaktifkan skill Extra Turn.
*/

void InstantReinforcement (State *S){
    for(int i=1;i<=NbElmtTabArray(ArrayBangunan(*S));i++){
        Pasukan(ElmtTab((ArrayBangunan(*S)),i))+=5;
    }
}
/*Seluruh bangunan mendapatkan tambahan 5 pasukan.
Pemain mendapat skill ini di akhir gilirannya bila semua bangunan yang ia miliki
memiliki level 4.*/

boolean IsIR (State S){
    boolean four = true;
    for(int i=1;i<=NbElmtTabArray(ArrayBangunan(S));i++){
        if(Level(ElmtTab((ArrayBangunan(S)),i))!=4){
            four = false;
            break;
        }
    }
    if(four){
        return true;
    }else{
        return false;
    }
}

void Barrage (State *SMusuh){
    for(int i=1;i<=NbElmtTabArray(ArrayBangunan(*SMusuh));i++){
        Pasukan(ElmtTab((ArrayBangunan(*SMusuh)),i))-=10;
    }
}
/*Jumlah pasukan pada seluruh bangunan musuh akan berkurang sebanyak 10
pasukan.
Pemain mendapat skill ini jika lawan baru saja bertambah bangunannya menjadi
10 bangunan.*/

boolean IsBarrage (State SMusuh){
    if(NbElmtTabArray(ArrayBangunan(SMusuh))==10){
        return true;
    }else{
        return false;
    }
}
/* **** ATTACK MECHANISM *** */

