
#include <stdio.h>
#include "matriks.h"
#include <math.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
    return ((i>= BrsMin && i<=BrsMax) && (j>=KolMin && j<=KolMax));
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
    return BrsMin;
}
indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
    return KolMin;
}
indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
    return (BrsMin + NBrsEff(M) - 1);
}
indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
    return (KolMin + NKolEff(M) -1);
}
boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
    return ((i>= GetFirstIdxBrs(M) && i<=GetLastIdxBrs(M))&&(j>=GetFirstIdxKol(M) && j<=GetLastIdxKol(M)));
}

ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
    return (Elmt(M,i,i));
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
    MakeMATRIKS(NBrsEff(MIn), NKolEff(MIn), MHsl);
    for (indeks i = GetFirstIdxBrs(MIn) ; i<=GetLastIdxBrs(MIn) ; i++){
        for (indeks j = GetFirstIdxKol(MIn) ; j<=GetLastIdxKol(MIn) ; j++){
            Elmt(*MHsl, i, j) = Elmt(MIn, i, j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
{
    MakeMATRIKS(NB, NK, M);
    for (indeks i = GetFirstIdxBrs(*M) ; i<=GetLastIdxBrs(*M) ; i++){
        for (indeks j = GetFirstIdxKol(*M) ; j<=GetLastIdxKol(*M) ; j++){
            scanf("%d", &Elmt(*M, i, j));
        }
    }
}

void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    for (indeks i = GetFirstIdxBrs(M) ; i<=GetLastIdxBrs(M) ; i++){
        for (indeks j = GetFirstIdxKol(M) ; j<GetLastIdxKol(M) ; j++){
            printf("%d ", Elmt(M,i,j));
        }
        if (GetLastIdxBrs(M) == i) {
            printf("%d", Elmt(M, i, GetLastIdxKol(M)));
        } else {
            printf("%d\n", Elmt(M, i, GetLastIdxKol(M)));
        }
    }
}


/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
{
    MATRIKS M;
    MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &M);
    for (indeks i = GetFirstIdxBrs(M) ; i<=GetLastIdxBrs(M) ; i++){
        for (indeks j = GetFirstIdxKol(M) ; j<=GetLastIdxKol(M) ; j++){
            Elmt(M, i, j) = Elmt(M1, i, j) + Elmt(M2, i, j);
        }
    }
    return M;
}

MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
{
    MATRIKS M;
    MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &M);
    for (indeks i = GetFirstIdxBrs(M) ; i<=GetLastIdxBrs(M) ; i++){
        for (indeks j = GetFirstIdxKol(M) ; j<=GetLastIdxKol(M) ; j++){
            Elmt(M, i, j) = Elmt(M1, i, j) - Elmt(M2, i, j);
        }
    }
    return M;
}

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
    MATRIKS M;
    MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &M);
    for (indeks i = GetFirstIdxBrs(M) ; i<=GetLastIdxBrs(M) ; i++){
        for (indeks j = GetFirstIdxKol(M) ; j<=GetLastIdxKol(M) ; j++){
            Elmt(M, i, j) = 0;
        }
    }
    for (indeks i = GetFirstIdxBrs(M1) ; i<=GetLastIdxBrs(M1) ; i++){
        for (indeks j = GetFirstIdxKol(M1) ; j<=GetLastIdxKol(M1) ; j++){
            for (indeks k = GetFirstIdxKol(M2) ; k<=GetLastIdxKol(M2) ; k++){
                Elmt(M, i ,k) += Elmt(M1, i, j) * Elmt(M2, j, k);
            }
            
        }
    }
    return M;
}

MATRIKS KaliKons (MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
    MATRIKS M1;
    MakeMATRIKS(NBrsEff(M), NKolEff(M), &M1);
    for (indeks i = GetFirstIdxBrs(M1) ; i<=GetLastIdxBrs(M1) ; i++){
        for (indeks j = GetFirstIdxKol(M1) ; j<=GetLastIdxKol(M1) ; j++){
            Elmt(M1, i, j) = Elmt(M, i, j) * X;
        }
    }
    return M1;
}

void PKaliKons (MATRIKS * M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{
    for (indeks i = GetFirstIdxBrs(*M) ; i<=GetLastIdxBrs(*M) ; i++){
        for (indeks j = GetFirstIdxKol(*M) ; j<=GetLastIdxKol(*M) ; j++){
            Elmt(*M, i, j) = Elmt(*M, i, j) * K;
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
    if (NBElmt(M1) != NBElmt(M2) ){
        return false;
    } else {
        for (indeks i = GetFirstIdxBrs(M1) ; i<=GetLastIdxBrs(M1) ; i++){
            for (indeks j = GetFirstIdxKol(M1) ; j<=GetLastIdxKol(M1) ; j++){
                if (Elmt(M1, i, j) != Elmt(M2, i, j)) return false;
            }
        }
    }
    return true;
}

boolean NEQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
    return !(EQ(M1, M2));
}

boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
    return (NBrsEff(M1)==NBrsEff(M2) && NKolEff(M1)==NKolEff(M2));
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
    return (NBrsEff(M)*NKolEff(M));
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
    return (NBrsEff(M)==NKolEff(M));
}
boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
    boolean found = true;
    if(IsBujurSangkar(M)){
        for (indeks i = GetFirstIdxBrs(M) ; i<=GetLastIdxBrs(M) ; i++){
            for (indeks j = GetFirstIdxKol(M) ; j<=GetLastIdxKol(M) ; j++){
                if (Elmt(M, i, j) != Elmt(M, j, i)) found = false;
            }
        }
    } else {
        found = false;
    }
    return found;
}

boolean IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
    if(!(IsBujurSangkar(M))){
        return false;
    } else {
        for (indeks i = GetFirstIdxBrs(M) ; i<=GetLastIdxBrs(M) ; i++){
            for (indeks j = GetFirstIdxKol(M) ; j<=GetLastIdxKol(M) ; j++){
                if (i == j){
                    if (Elmt(M, i, j) != 1) return false;
                } else {
                    if (Elmt(M, i, j) != 0) return false;
                }
            }
        }
    }
    return true;
}

boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
    float count = 0;
    for (indeks i = GetFirstIdxBrs(M) ; i<=GetLastIdxBrs(M) ; i++){
        for (indeks j = GetFirstIdxKol(M) ; j<=GetLastIdxKol(M) ; j++){
            if (Elmt(M, i, j) != 0) count=count+1;
        }
    }
    float max = 0.05*NBElmt(M);
    return ((count) <= (max));
}
MATRIKS Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
    MATRIKS M1;
    MakeMATRIKS(NBrsEff(M), NKolEff(M), &M1);
    M1 = KaliKons(M, -1);
    return M1;
}



float Determinan (MATRIKS M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
{
    float result;
    MATRIKS minor;
    if (NBrsEff(M)==1){
        result = Elmt(M, 1, 1);
    } else if (NBrsEff(M)==2){
        result = Elmt(M, 1,1)*Elmt(M,2,2) - Elmt(M, 1, 2)*Elmt(M, 2,1);
    } else {
        result = 0;
        for (int i = GetFirstIdxBrs(M) ; i <= GetLastIdxBrs(M) ; i++){

            MATRIKS M1;
            MakeMATRIKS(NBrsEff(M)-1, NKolEff(M)-1 , &M1);
            int new_b = 1;
            for (int k = 1 ; k<=NBrsEff(M) ; k++){
                int new_k = 1;
                if (k != 1){
                    for (int j = 1 ; j <= NBrsEff(M) ; j++){
                        if (j != i){
                            Elmt(M1, new_b, new_k) = Elmt(M, k, j);
                            new_k++;
                        }
                    }
                    new_b++;
                }
            }

            result += pow((-1.0), (i+1)) * Elmt(M, 1, i) * Determinan(M1);
        }
    }
    return result;
}

void PInverse1 (MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
    PKaliKons(M, -1);
}

void Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
    MATRIKS M1;
    CopyMATRIKS(*M, &M1);
    for (indeks i = GetFirstIdxBrs(M1) ; i<=GetLastIdxBrs(M1) ; i++){
        for (indeks j = GetFirstIdxKol(M1) ; j<=GetLastIdxKol(M1) ; j++){
            Elmt(*M, i, j) = Elmt(M1, j, i);
        }
    }
}
