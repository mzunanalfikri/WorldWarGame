//Nama  :Muhammad Zunan Alfikri
//NIM   :13518019
#include<stdio.h>
#include "point.h"
#include<math.h>
#define PI 3.141592654
#define square(X) ((X)*(X))

POINT MakePOINT (float X, float Y) {
    //Kamus
    POINT P;
    //Algoritma
    Absis(P) = X;
    Ordinat(P) = Y;
    return P;
}

void BacaPOINT (POINT *P) {
    //Membaca nilai absis dan ordinat
    //Kamus 
    float a, b;
    //Algoritma
    scanf("%f %f", &a, &b);
    *P = MakePOINT(a,b);
}

void TulisPOINT (POINT P) {
    //Manulis nilai point ke layar
    //Kamus

    //Algoritma
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

boolean EQ (POINT P1, POINT P2) {
    //mengembalikan true juka p1 = p2
    return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}

boolean NEQ (POINT P1, POINT P2) {
    //mengembalikan true jika p1 !=P2
    return ((Absis(P1) != Absis(P2)) || (Ordinat(P1) != Ordinat(P2)));
}

boolean IsOrigin (POINT P) {
    //mengembalikan true jika p titik origin
    return (Absis(P)==0 && Ordinat(P)==0);
}

boolean IsOnSbX (POINT P) {
    //Mengembalikan True jika P terletak pada sumbu x
    return (Ordinat(P) == 0);
}

boolean IsOnSbY (POINT P) {
    //mengembalikan True jika P terletak pada sumbu y
    return (Absis(P) == 0);
}

int Kuadran (POINT P) {
    //mengembalikan nilai kuadram dari suatu titik
    if (Absis(P) > 0 && Ordinat(P) > 0 ) {
        return 1;
    }
    else if (Absis(P) > 0 && Ordinat(P) < 0) {
        return 4;
    }
    else if (Absis(P) < 0 && Ordinat(P) < 0) {
        return 3;
    }
    else {
        return 2;
    }
}

POINT NextX (POINT P) {
    //mengirim salinan p dengan absis ditambah satu
    return MakePOINT((Absis(P)+1),Ordinat(P));
}

POINT NextY (POINT P) {
    //megiirm salinan p dengan ordinat ditambah satu
    return MakePOINT(Absis(P), (Ordinat(P) + 1));
}

POINT PlusDelta (POINT P, float deltaX, float deltaY) {
    return (MakePOINT((Absis(P) + deltaX), (Ordinat(P) + deltaY)));
}

POINT MirrorOf (POINT P, boolean SbX) {
    if (SbX == true) {
        return MakePOINT(Absis(P), (-1*(Ordinat(P))));
    } 
    else {
        return MakePOINT( (-1*(Absis(P))), Ordinat(P) );
    }
}

float Jarak0 (POINT P) {
    return sqrt((square(Absis(P)) + square(Ordinat(P))));
}

float Panjang (POINT P1, POINT P2) {
    //menghitung jarak antara 2 titik
    return sqrt(square(Absis(P1)-Absis(P2)) + square(Ordinat(P1)-Ordinat(P2)));
}

void Geser (POINT *P, float deltaX, float deltaY) {
    //digeser absisnya sebesar deltaX dan floatnya sebesat deltaY
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}

void GeserKeSbX (POINT *P) { 
    //di geser menjadi sumbu x 
    Ordinat(*P) = 0;
}

void GeserKeSbY (POINT *P) {
    //di geser menjadi sumbu y
    Absis(*P) = 0;
}

void Mirror (POINT *P, boolean SbX) {
    if (SbX == true) {
        Ordinat(*P) = -1*(Ordinat(*P));
    }
    else {
        Absis(*P) = (-1*(Absis(*P)));
    }   
}

void Putar (POINT *P, float Sudut) {
    // digeser sebesar sudut
    // Kamus
    float rad, a, b;
    // Algoritma
    rad = Sudut*PI/180;
    a = cos(rad)*Absis(*P) + sin(rad)*Ordinat(*P);
    b = (-1.0)*sin(rad)*Absis(*P) + cos(rad)*Ordinat(*P);   
    *P = MakePOINT(a,b);
}