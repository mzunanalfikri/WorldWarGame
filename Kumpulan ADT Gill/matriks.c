#include "matriks.h"
#include <stdio.h>


/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M){
    NBrsEff(*M)=NB;
    NKolEff(*M)=NK;
}
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j){
    return((i<=BrsMax)&&(i>=BrsMin))&&((j<=KolMax)&&(j>=KolMin));
}
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M){
    return(BrsMin);
}
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxKol (MATRIKS M){
    return(KolMin);
}
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxBrs (MATRIKS M){
    return(NBrsEff(M));
}
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxKol (MATRIKS M){
    return(NKolEff(M));
}
/* Mengirimkan indeks kolom terbesar M */
boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
    return((i<=NBrsEff(M))&&(i>=GetFirstIdxBrs(M)))&&((j<=NKolEff(M))&&(j>=GetFirstIdxKol(M)));
}
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
ElType GetElmtDiagonal (MATRIKS M, indeks i){
    return(Elmt(M,i,i));
}
/* Mengirimkan elemen M(i,i) */

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
    int i,j;
    MakeMATRIKS(NBrsEff(MIn),NKolEff(MIn),MHsl);
    for(i=GetFirstIdxBrs(MIn);i<=NBrsEff(MIn);i++){
        for(j=GetFirstIdxKol(MIn);j<=NKolEff(MIn);j++){
            Elmt(*MHsl,i,j)=Elmt(MIn,i,j);
        }
    }
}
/* Melakukan assignment MHsl  MIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK){
    int i,j;
    MakeMATRIKS(NB,NK,M);
    for(i=GetFirstIdxBrs(*M);i<=NBrsEff(*M);i++){
        for(j=GetFirstIdxKol(*M);j<=NKolEff(*M);j++){
            scanf("%d",&Elmt(*M,i,j));
        }
    }
}
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
void TulisMATRIKS (MATRIKS M){
    int i,j;
    for(i=GetFirstIdxBrs(M);i<=NBrsEff(M);i++){
        for(j=GetFirstIdxKol(M);j<=NKolEff(M);j++){
            if(j!=NKolEff(M)){
                printf("%d ",Elmt(M,i,j));
            }else if ((j==NKolEff(M))&&(i==NBrsEff(M))){
                printf("%d",Elmt(M,i,j));
            }else{
                printf("%d\n",Elmt(M,i,j));
            }
        }
    }
}
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2){
    int i,j;
    MATRIKS M3;
    MakeMATRIKS(NBrsEff(M1),NKolEff(M2),&M3);
    for(i=GetFirstIdxBrs(M1);i<=NBrsEff(M1);i++){
        for(j=GetFirstIdxKol(M1);j<=NKolEff(M1);j++){
            Elmt(M3,i,j)=Elmt(M1,i,j)+Elmt(M2,i,j);
        }
    }return(M3);
}
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2){
    int i,j;
    MATRIKS M3;
    MakeMATRIKS(NBrsEff(M1),NKolEff(M2),&M3);
    for(i=GetFirstIdxBrs(M1);i<=NBrsEff(M1);i++){
        for(j=GetFirstIdxKol(M1);j<=NKolEff(M1);j++){
            Elmt(M3,i,j)=Elmt(M1,i,j)-Elmt(M2,i,j);
        }
    }return(M3);
}
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2){
    MATRIKS M3;
    int i,j,sum,k;
    MakeMATRIKS(NBrsEff(M1),NKolEff(M2),&M3);
    for(i=GetFirstIdxBrs(M1);i<=NBrsEff(M1);i++){
        for(j=GetFirstIdxKol(M2);j<=NKolEff(M2);j++){
            Elmt(M3,i,j)=0;
            for(k=GetFirstIdxBrs(M2);k<=NBrsEff(M2);k++){
                Elmt(M3,i,j)+=(Elmt(M1,i,k)*Elmt(M2,k,j));
            }
        }
    }return(M3);
}
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
MATRIKS KaliKons (MATRIKS M, ElType X){
    int i,j;
    MATRIKS MOut;
    MakeMATRIKS(NBrsEff(M),NKolEff(M),&MOut);
    for(i=GetFirstIdxBrs(M);i<=NBrsEff(M);i++){
        for(j=GetFirstIdxKol(M);j<=NKolEff(M);j++){
            Elmt(MOut,i,j)=X*Elmt(M,i,j);
        }
    }return(MOut);
}
/* Mengirim hasil perkalian setiap elemen M dengan X */
void PKaliKons (MATRIKS * M, ElType K){
    int i,j;
    for(i=GetFirstIdxBrs(*M);i<=NBrsEff(*M);i++){
        for(j=GetFirstIdxKol(*M);j<=NKolEff(*M);j++){
            Elmt(*M,i,j)*=K;
        }
    }
}
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2){
    int i,j;
    boolean sama ;
    sama = true;
    if((NBrsEff(M1)==NBrsEff(M2))&&(NKolEff(M1)==NKolEff(M2))){
        for(i=GetFirstIdxBrs(M1);i<=NBrsEff(M1);i++){
            for(j=GetFirstIdxKol(M1);j<=NKolEff(M1);j++){
                if(Elmt(M1,i,j)!=Elmt(M2,i,j)){
                    sama = false;
                    break;
                }
            }
        }return(sama);
    }else{
        return false;
    }
}
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
boolean NEQ (MATRIKS M1, MATRIKS M2){
    if(!EQ(M1,M2)){
        return true;
    }else{
        return false;
    }
}
/* Mengirimkan true jika M1 tidak sama dengan M2 */
boolean EQSize (MATRIKS M1, MATRIKS M2){
    return((NBrsEff(M1)==NBrsEff(M2))&&(NKolEff(M1)==NKolEff(M2)));
}
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M){
    return(NBrsEff(M)*NKolEff(M));
}
/* Mengirimkan banyaknya elemen M */

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M){
    return(NBrsEff(M)==NKolEff(M));
}
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
boolean IsSimetri (MATRIKS M){
    int i,j;
    boolean sama;
    sama= true;
    if(IsBujurSangkar(M)){
        for(i=GetFirstIdxBrs(M);i<=NBrsEff(M);i++){
            for(j=GetFirstIdxKol(M);j<=NKolEff(M);j++){
                if(Elmt(M,i,j)!=Elmt(M,j,i)){
                    sama = false;
                    break;
                }
            }
        }return(sama);
    }else{
        return false;
    }
}
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
boolean IsSatuan (MATRIKS M){
    int i,j;
    boolean satu,nol;
    satu=true;
    nol=true;
    if(IsBujurSangkar(M)){
        for(i=GetFirstIdxBrs(M);i<=NBrsEff(M);i++){
            for(j=GetFirstIdxKol(M);j<=NKolEff(M);j++){
                if((i==j)&&(Elmt(M,i,j)!=1)){
                    satu = false;
                    break;
                }else if((i!=j)&&(Elmt(M,i,j)!=0)){
                    nol=false;
                    break;
                }
            }
        }
        if((satu)&&(nol)){
            return true;
        }else{
            return false;
        }
    }else{
        return(false);
    }
}
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
boolean IsSparse (MATRIKS M){
    int i,j,hitung,hasil;
    hitung=0;
    for(i=GetFirstIdxBrs(M);i<=NBrsEff(M);i++){
        for(j=GetFirstIdxKol(M);j<=NKolEff(M);j++){
            if(Elmt(M,i,j)!=0){
                hitung+=1;
            }
        }
    }
    hasil = 0.05*NBElmt(M);
    return(hitung<=hasil);
}
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
MATRIKS Inverse1 (MATRIKS M){
    int i,j;
    MATRIKS M3;
    MakeMATRIKS(NBrsEff(M),NKolEff(M),&M3);
    for(i=GetFirstIdxBrs(M);i<=NBrsEff(M);i++){
        for(j=GetFirstIdxKol(M);j<=NKolEff(M);j++){
            Elmt(M3,i,j)=Elmt(M,i,j)*(-1);
        }
    }return(M3);
}
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
float Determinan (MATRIKS M){
    float koef,det;
    float temp[BrsMax+1][KolMax+1]; // Matriks sementara yang berelemen real

    /* ALGORITMA */
    if(NBrsEff(M) == 2)
    {
        det = Elmt(M, GetFirstIdxBrs(M), GetFirstIdxKol(M)) * Elmt(M, GetLastIdxBrs(M), GetLastIdxKol(M)) -
            Elmt(M, GetFirstIdxBrs(M), GetLastIdxKol(M)) * Elmt(M, GetLastIdxBrs(M), GetFirstIdxKol(M));
        return det;
    }
    else // lebih dari matriks 2 x 2
    {
        //Mengisi matriks temp bertipe real
        for (int i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
        {
            for (int j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
            {
                temp[i][j] = (float)Elmt(M, i, j);
            }
        }

        // Membentuk matriks segitiga atas
        for (int i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
        {
            for (int j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
            {
                if (j > i)
                {
                    koef = temp[j][i] / temp[i][i];
                    for (int k = GetFirstIdxBrs(M); k <= GetLastIdxBrs(M); k++)
                    {
                        temp[j][k] -= koef * temp[i][k];
                    }
                }
            }
        }
        // Determinan didapatkan dari perkalian diagonalnya
        det = 1;
        for (int i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) det *= temp[i][i];

        if (det == 0) return 0;
        else return det;
    }
    
}
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
void PInverse1 (MATRIKS * M){
    int i,j;
    for(i=GetFirstIdxBrs(*M);i<=NBrsEff(*M);i++){
        for(j=GetFirstIdxKol(*M);j<=NKolEff(*M);j++){
            Elmt(*M,i,j)*=(-1);
        }
    }
}
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
void Transpose (MATRIKS * M){
    int i,j;
    ElType Temp;
    for(i=GetFirstIdxBrs(*M);i<=NBrsEff(*M);i++){
        for(j=GetFirstIdxKol(*M);j<=i;j++){
            Temp = Elmt(*M,i,j);
            Elmt(*M,i,j)=Elmt(*M,j,i);
            Elmt(*M,j,i)=Temp;
        }
    }
    
}
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */

