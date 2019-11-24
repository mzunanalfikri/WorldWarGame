#include "bangunan.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


Bangunan MakeBangunanLv1 (char type, POINT P)
/* I.S. Sembarang */
/* F.S. Membuat sebuah bangunan default level 1 (digunakan pada awal load file) */
{
    Bangunan B;
    Level(B) = 1;
    Serang(B) = false;
    Pertahanan(B) = false;
    Type(B) = type;
    Posisi(B) = P;
    Move(B) = false;
    //percabangan untuk masing masing tipe
    if (type == 'C'){
        Pasukan(B) = 40;
        A(B) = 10;
        M(B) = 40;
    } else if (type == 'T') {
        Pasukan(B) = 30;
        A(B) = 5;
        M(B) = 20;
        Pertahanan(B) = true;
    } else if (type == 'F') {
        Pasukan(B) = 80;
        A(B) = 10;
        M(B) = 20;
    } else if (type == 'V'){
        Pasukan(B) = 20;
        A(B) = 5;
        M(B) = 20;
    }
    return B;
}

boolean IsNaikLevel (Bangunan B)
/* Mengirim True jika bangunan siap naik level */
{
    //cek apakah bisa naik level atau enggak
    return (Pasukan(B) >= M(B)/2 && Level(B)<4);
}

void NaikLevel (Bangunan *B)
/* I.S Sembarang */
/* F.S Bangunan naik 1 level dengan pertambahan 
        pasukan sesuai dengan levelnya */
{
    //cek bisa naik level, kalau bisa, naik level sesuai dengan tipenya
    if (IsNaikLevel(*B)){
        if (Type(*B) == 'C'){
            if (Level(*B) == 1) {
                Pasukan(*B) = Pasukan(*B) - M(*B)/2;
                A(*B) = 15;
                M(*B) = 60;
            } else if (Level(*B) == 2) {
                Pasukan(*B) = Pasukan(*B) - M(*B)/2;
                A(*B) = 20;
                M(*B) = 80;
            } else if (Level(*B) == 3) {
                Pasukan(*B) = Pasukan(*B) - M(*B)/2;
                A(*B) = 25;
                M(*B) = 100;
            }
        } else if (Type(*B) == 'T'){
            if (Level(*B) == 1) {
                Pasukan(*B) = Pasukan(*B) - M(*B)/2;
                A(*B) = 10;
                M(*B) = 30;
            } else if (Level(*B) == 2) {
                Pasukan(*B) = Pasukan(*B) - M(*B)/2;
                A(*B) = 20;
                M(*B) = 40;
            } else if (Level(*B) == 3) {
                Pasukan(*B) = Pasukan(*B) - M(*B)/2;
                A(*B) = 30;
                M(*B) = 50;
            }
        } else if (Type(*B) == 'F'){
            if (Level(*B) == 1) {
                Pasukan(*B) = Pasukan(*B) - M(*B)/2;
                A(*B) = 20;
                M(*B) = 40;
            } else if (Level(*B) == 2) {
                Pasukan(*B) = Pasukan(*B) - M(*B)/2;
                A(*B) = 30;
                M(*B) = 60;
                Pertahanan(*B) = true;
            } else if (Level(*B) == 3) {
                Pasukan(*B) = Pasukan(*B) - M(*B)/2;
                A(*B) = 40;
                M(*B) = 80;
            }
        } else if (Type(*B) == 'V'){
            if (Level(*B) == 1) {
                Pasukan(*B) = Pasukan(*B) - M(*B)/2;
                A(*B) = 10;
                M(*B) = 30;
            } else if (Level(*B) == 2) {
                Pasukan(*B) = Pasukan(*B) - M(*B)/2;
                A(*B) = 15;
                M(*B) = 40;
            } else if (Level(*B) == 3) {
                Pasukan(*B) = Pasukan(*B) - M(*B)/2;
                A(*B) = 20;
                M(*B) = 50;
            }
        }
        Level(*B)+=1;
        printf("Level ");
        PrintTipeBangunan(Type(*B));
        printf("-mu meningkat menjadi %d !\n", Level(*B));
    } else if (Level(*B) == 4){
        printf("Level ");
        PrintTipeBangunan(Type(*B));
        printf(" sudah maksimal !\n");
    } else {
        printf("Jumlah Pasukkan ");
        PrintTipeBangunan(Type(*B));
        printf(" tidak cukup untuk naik level.\n");
    }
}

void AddNextTurn (Bangunan * B)
/* I.S Bangunan terdefinisi */
/* F.S Bangunan betambah pasukannya sesuai level seteah turn */
{
    //penambahan pasukan setiap turn baru
    if (Pasukan(*B) < M(*B)){
        Pasukan(*B) += A(*B);
    }
}

void CopyBangunan (Bangunan BIn, Bangunan * BHsl)
/*Melakukan assignment MHsl dgn MIn */
{
    //untuk melakukan copy (memudahkan saat push state)
    Type(*BHsl) = Type(BIn);
    Pasukan(*BHsl) = Pasukan(BIn);
    Level(*BHsl) = Level(BIn);
    A(*BHsl) = A(BIn);
    M(*BHsl) = M(BIn);
    Pertahanan(*BHsl) = Pertahanan(BIn);
    Absis(Posisi(*BHsl)) = Absis(Posisi(BIn));
    Ordinat(Posisi(*BHsl)) = Ordinat(Posisi(BIn));
    Serang(*BHsl) = Serang(BIn);
}

void PrintBangunan (Bangunan B)
/* I.S Sembarang */
/* F.S Tercetak di layar info bangunannya */
{
    //mencetak bangunan sesuai dengan tipenya
    if (Type(B) == 'C' ) {
        printf("Castle (%d,%d) %d lv. %d\n", Absis(Posisi(B)), Ordinat(Posisi(B)), Pasukan(B), Level(B));
    } else if (Type(B) == 'T') {
        printf("Tower (%d,%d) %d lv. %d\n", Absis(Posisi(B)), Ordinat(Posisi(B)), Pasukan(B), Level(B));
    } else if (Type(B) == 'F') {
        printf("Fort (%d,%d) %d lv. %d\n", Absis(Posisi(B)), Ordinat(Posisi(B)), Pasukan(B), Level(B));
    } else if (Type(B) == 'V') {
        printf("Village (%d,%d) %d lv. %d\n", Absis(Posisi(B)), Ordinat(Posisi(B)), Pasukan(B), Level(B));
    }
}

void PrintTipeBangunan (char C)
/* I.S. Sembarang */
/* F.S. Tercetak bangunan sesuai TIpenya */
{   
    //mencetak hanya tipe bangunannya saja
    if (C == 'C'){
        printf("Castle");
    } else if (C == 'V') {
        printf("Village");
    } else if (C == 'F') {
        printf("Fort");
    } else if (C == 'T'){
        printf("Tower");
    }
}

void IU(Bangunan *B)
/* I.S. Sembarang */
/* F.S. Bangunan naik level secara instant */
{
    //percabangan untuk instant upgrade masing2 tipe,
    //level naik 1 tetapi pasukan tidak berkurang
    if (Level(*B)<4){
        if (Type(*B) == 'C'){
            if (Level(*B) == 1) {
                A(*B) = 15;
                M(*B) = 60;
            } else if (Level(*B) == 2) {
                A(*B) = 20;
                M(*B) = 80;
            } else if (Level(*B) == 3) {
                A(*B) = 25;
                M(*B) = 100;
            }
        } else if (Type(*B) == 'T'){
            if (Level(*B) == 1) {
                A(*B) = 10;
                M(*B) = 30;
            } else if (Level(*B) == 2) {
                A(*B) = 20;
                M(*B) = 40;
            } else if (Level(*B) == 3) {
                A(*B) = 30;
                M(*B) = 50;
            }
        } else if (Type(*B) == 'F'){
            if (Level(*B) == 1) {
                A(*B) = 20;
                M(*B) = 40;
            } else if (Level(*B) == 2) {
                A(*B) = 30;
                M(*B) = 60;
                Pertahanan(*B) = true;
            } else if (Level(*B) == 3) {
                A(*B) = 40;
                M(*B) = 80;
            }
        } else if (Type(*B) == 'V'){
            if (Level(*B) == 1) {
                A(*B) = 10;
                M(*B) = 30;
            } else if (Level(*B) == 2) {
                A(*B) = 15;
                M(*B) = 40;
            } else if (Level(*B) == 3) {
                A(*B) = 20;
                M(*B) = 50;
            }
        }
        Level(*B)+=1;
    }
}

void BackToLv1(Bangunan *B)
/* I.S. Sembarang */
/* F.S. Bangunan kembali ke level 1 dengan jumlah bangunan tetap*/
{
    //prosedur ini digunakan saat musuh berhasil mengakuisisi bangunan lawan
    Level(*B) = 1;
    Serang(*B) = false;
    Pertahanan(*B) = false;
    Move(*B) = false;
    //percabangan level satu sesuai tipenya
    if (Type(*B) == 'C'){
        A(*B) = 10;
        M(*B) = 40;
    } else if (Type(*B) == 'T') {
        A(*B) = 5;
        M(*B) = 20;
        Pertahanan(*B) = true;
    } else if (Type(*B) == 'F') {
        A(*B) = 10;
        M(*B) = 20;
    } else if (Type(*B) == 'V'){
        A(*B) = 5;
        M(*B) = 20;
    }
}
