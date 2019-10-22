/* File: jam_driver.c */
/* Tanggal: 28 Agustus 2016 */
/* Definisi ADT JAM */

#include <stdio.h>
#include "jam.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsJAMValid (int H, int M, int S){
    return ((H>=0 && H<24)&&(M>=0 && M<=59)&&(S>=0 && S<=59));
}
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */

/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int HH, int MM, int SS){
    JAM j;
    (j).HH = HH;
    (j).MM = MM;
    (j).SS = SS;
    return(j);
}
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaJAM (JAM * J){
    int HH, MM, SS;
    while (1) {
        scanf("%d %d %d", &HH, &MM, &SS);
        if (IsJAMValid(HH, MM, SS)){
            break;
        }
        else {
            printf("Jam tidak valid\n");
        }
    }
    *J = MakeJAM(HH, MM, SS);
    
}
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
/* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh:
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk JAM <1,3,4> */

void TulisJAM (JAM J){
    printf("%d:%d:%d",(J).HH,(J).MM,(J).SS);
}

/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.
   Jika jam / menit / detik hanya satu digit, tuliskan satu digit tanpa 0 di depannya. */

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long JAMToDetik (JAM J){
    return((3600*(J).HH)+(60*(J).MM)+(J).SS);
}
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */

JAM DetikToJAM (long N){
   JAM J;
   long x;
   long N2;
   if (N>=86400){
      x = N%86400;
   }
   else if (N<0){
      x = N + 86400;
   }
   else{
      x = N;
   }

   Hour(J) = x / 3600;
   N2 = x%3600;
   Minute(J) = N2 / 60;
   Second(J) = (N2 % 60);
   return J;
}
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean JEQ (JAM J1, JAM J2){
    return(JAMToDetik(J1)==JAMToDetik(J2));
}
/* Mengirimkan true jika J1=J2, false jika tidak */
boolean JNEQ (JAM J1, JAM J2){
    return(JAMToDetik(J1)!=JAMToDetik(J2));
}
/* Mengirimkan true jika J1 tidak sama dengan J2 */
boolean JLT (JAM J1, JAM J2){
    return(JAMToDetik(J1)<JAMToDetik(J2));
}
/* Mengirimkan true jika J1<J2, false jika tidak */
boolean JGT (JAM J1, JAM J2){
    return(JAMToDetik(J1)>JAMToDetik(J2));
}
/* Mengirimkan true jika J1>J2, false jika tidak */
/* *** Operator aritmatika JAM *** */
JAM NextDetik (JAM J){
    return DetikToJAM(JAMToDetik(J)+1);
}
/* Mengirim 1 detik setelah J dalam bentuk JAM */
JAM NextNDetik (JAM J, int N){
    return DetikToJAM(JAMToDetik(J)+N);  
}
/* Mengirim N detik setelah J dalam bentuk JAM */
JAM PrevDetik (JAM J){
    return DetikToJAM(JAMToDetik(J)-1); 
}
/* Mengirim 1 detik sebelum J dalam bentuk JAM */
JAM PrevNDetik (JAM J, int N){
    return DetikToJAM(JAMToDetik(J)-N); 
}
/* Mengirim N detik sebelum J dalam bentuk JAM */
/* *** Kelompok Operator Aritmetika *** */
long Durasi (JAM JAw, JAM JAkh){
    long selisih;
    if (JAMToDetik (JAw) > JAMToDetik (JAkh)){
        selisih = (JAMToDetik (JAkh)) + (86400) - JAMToDetik(JAw);
    }else{
        selisih = (JAMToDetik (JAkh)) - JAMToDetik(JAw);
    }
    return selisih;
}
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
