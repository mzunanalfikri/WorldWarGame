#include "matriks.h"
#include <stdio.h>

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
    return ((i>=BrsMin) && (i<=BrsMax) && (j>=KolMin) && (j<=KolMax));
}
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
    return (BrsMin);
}
indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
    return (KolMin);
}
indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
    return (BrsMin + NBrsEff(M) - 1);
}
indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
    return (KolMin + NKolEff(M) - 1);
}
boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
    return ((i>0) && (j>0) && (i <= GetLastIdxBrs(M)) && (j <= GetLastIdxKol(M)));
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
    /* KAMUS LOKAL */
    indeks i,j;

    /* ALGORITMA */
    NBrsEff(*MHsl) = GetLastIdxBrs(MIn);
    NKolEff(*MHsl) = GetLastIdxKol(MIn);

    for (i=BrsMin;i<=NBrsEff(*MHsl);i++)
    {
        for (j=KolMin;j<=NKolEff(*MHsl);j++)
        {
            Elmt(*MHsl,i,j) = Elmt(MIn,i,j);
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
    /* KAMUS LOKAL */
    indeks i,j;
    ElType x;

    /* ALGORITMA */
    if (IsIdxValid(NB,NK))
    {
        MakeMATRIKS(NB,NK,M);
        for (i=BrsMin;i<=NB;i++)
        {
            for (j=KolMin;j<=NK;j++)
            {
                scanf("%d",&x);
                Elmt(*M,i,j) = x;
            }
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
    /* KAMUS LOKAL */
    indeks i,j;

    /* ALGORITMA */
    for (i=BrsMin;i<=GetLastIdxBrs(M);i++)
    {
        for (j=KolMin;j<GetLastIdxKol(M);j++)
        {
            printf("%d ",Elmt(M,i,j));
        }

        if (i != GetLastIdxBrs(M))
        {
            printf("%d\n",Elmt(M, i, GetLastIdxKol(M)));
        }
        else
        {
            printf("%d", Elmt(M, i, GetLastIdxKol(M)));
        }
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
{
    /* KAMUS LOKAL */
    MATRIKS MH;
    indeks i,j;

    /* ALGORITMA */
    MakeMATRIKS(GetLastIdxBrs(M1),GetLastIdxKol(M1),&MH);
    for (i=BrsMin;i<=NBrsEff(M1);i++)
    {
        for (j=KolMin;j<=NKolEff(M1);j++)
        {
            Elmt(MH,i,j) = Elmt(M1,i,j) + Elmt(M2,i,j);
        }
    }
    return (MH);
}
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 � M2 */
{
    /* KAMUS LOKAL */
    MATRIKS MH;
    indeks i,j;

    /* ALGORITMA */
    MakeMATRIKS(GetLastIdxBrs(M1),GetLastIdxKol(M1),&MH);
    for (i=BrsMin;i<=GetLastIdxBrs(M1);i++)
    {
        for (j=KolMin;j<=GetLastIdxKol(M1);j++)
        {
            Elmt(MH,i,j) = Elmt(M1,i,j) - Elmt(M2,i,j);
        }
    }

    return (MH);
}
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
    /* KAMUS LOKAL */
    MATRIKS MH;
    indeks i,j,k;
    ElType sum;

    /* ALGORITMA */
    MakeMATRIKS(NBrsEff(M1),NKolEff(M2),&MH);
    // proses mengalikan antar dua matriks
    for (i=BrsMin;i<=GetLastIdxBrs(M1);i++)
    {
        for (j=KolMin;j<=GetLastIdxKol(M2);j++)
        {
            sum = 0;
            for (k=KolMin;k<=GetLastIdxKol(M1);k++)
            {
                sum = sum + (Elmt(M1,i,k) * Elmt(M2,k,j));
            }

            Elmt(MH,i,j) = sum;
        }
    }

    return (MH);
}
MATRIKS KaliKons (MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
    /* KAMUS LOKAL */
    MATRIKS MH;
    indeks i,j;

    /* ALGORITMA */
    MakeMATRIKS(GetLastIdxBrs(M),GetLastIdxKol(M),&MH);
    for (i=BrsMin;i<=GetLastIdxBrs(M);i++)
    {
        for (j=KolMin;j<=GetLastIdxKol(M);j++)
        {
            Elmt(MH,i,j) = X * Elmt(M,i,j);
        }
    }

    return (MH);
}
void PKaliKons (MATRIKS * M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{
    /* KAMUS LOKAL */
    indeks i,j;

    /* ALGORITMA */
    for (i=BrsMin;i<=GetLastIdxBrs(*M);i++)
    {
        for (j=KolMin;j<=GetLastIdxKol(*M);j++)
        {
            Elmt(*M,i,j) = K * Elmt(*M,i,j);
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
    /* KAMUS LOKAL */
    indeks i,j;
    boolean Sama;

    /* ALGORITMA */
    if (EQSize(M1,M2))
    {
        Sama = true; i = BrsMin; // Inisialisasi
        while ((Sama) && i<=GetLastIdxBrs(M1))
        {
            j = KolMin; // Inisialisasi
            while ((Sama) && j<=GetLastIdxKol(M1))
            {
                if (Elmt(M1,i,j) != Elmt(M2,i,j))
                {
                    Sama = false;
                }
                else // Elemennya sama
                {
                    j++;
                }
            }
            i++;
        }
    }
    else // Ukuran matriks tak sama
    {
        Sama = false;
    }

    return (Sama);
}
boolean NEQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
    /* KAMUS LOKAL */
    indeks i,j;
    int count;

    /* ALGORITMA */
    if (EQSize(M1,M2))
    {
        count = 0;
        for (i=BrsMin;i<=GetLastIdxBrs(M1);i++)
        {
            for (j=KolMin;j<=GetLastIdxKol(M1);j++)
            {
                if ((Elmt(M1,i,j)) != Elmt(M2,i,j))
                {
                    count++;
                }
            }
        }

        if (count>0)
        {
            return true;
        }
        else // count = 0
        {
            return false;
        }
    }
    else // Ukuran matriks tak sama
    {
        return true;
    }
}
boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
    return ((NBrsEff(M1)==NBrsEff(M2)) && (NKolEff(M1)==NKolEff(M2)));
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
    return (NBrsEff(M) == NKolEff(M));
}
boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
     /* KAMUS LOKAL */
    indeks i,j;
    boolean Sama;

    /* ALGORITMA */
    if (IsBujurSangkar(M))
    {
        Sama = true; i = BrsMin; // Inisialisasi
        while ((Sama) && i<=GetLastIdxBrs(M))
        {
            j = KolMin; // Inisialisasi
            while((Sama) && j<=GetLastIdxKol(M))
            {
                if (Elmt(M,i,j) != Elmt(M,j,i))
                {
                    Sama = false;
                }
                else // Elemennya sama
                {
                    j++;
                }
            }

            i++;
        }
    }
    else // Matriks tak bujur sangkar
    {
        Sama = false;
    }

    return (Sama);
}
boolean IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
     /* KAMUS LOKAL */
    indeks i,j;
    boolean satuan;

    /* ALGORITMA */
    if (IsBujurSangkar(M))
    {
        satuan = true; i = BrsMin; // Inisialisasi
        while ((satuan) && i<=GetLastIdxBrs(M))
        {
            j = KolMin; // Inisialisasi
            while ((satuan) && j<=GetLastIdxKol(M))
            {
                if (i == j)
                {
                    if (Elmt(M,i,j) != 1)
                    {
                        satuan = false;
                    }
                    else // Elemennya bukan 1
                    {
                        j++;
                    }
                }
                else // i != j
                {
                    if (Elmt(M,i,j) != 0)
                    {
                        satuan = false;
                    }
                    else // Elemennya bukan 1
                    {
                        j++;
                    }
                }
            }

            i++;
        }
    }
    else // Bukan matriks bujur sangkar
    {
        satuan = false;
    }

    return (satuan);
}
boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks �jarang� dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
    /* KAMUS LOKAL */
    indeks i,j;
    float sparse,count;

    /* ALGORITMA */
    count = 0; sparse = 0; i = BrsMin; // Inisialisasi
    while ((sparse<=5) && i<=GetLastIdxBrs(M))
    {
        j = KolMin; // Inisialisasi
        while ((sparse<=5) && j<=GetLastIdxKol(M))
        {
            if (Elmt(M,i,j) != 0)
            {
                count++;
                sparse = (count/NBElmt(M))*100;
                j++;
            }
            else // Elemen adalah nol
            {
                j++;
            }
        }
        i++;
    }
    if (sparse<=5)
    {
        return true;
    }
    else // bukan matriks sparse
    {
        return false;
    }
}
MATRIKS Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
    /* KAMUS LOKAL */
    indeks i,j;

    /* ALGORITMA */
    for (i=BrsMin;i<=GetLastIdxBrs(M);i++)
    {
        for (j=KolMin;j<=GetLastIdxKol(M);j++)
        {
            Elmt(M,i,j) = Elmt(M,i,j)*(-1);
        }
    }

    return (M);
}
float Determinan (MATRIKS M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
{
    /* KAMUS LOKAL */
    indeks i,j,k;
    float ratio,det;
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
        for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
        {
            for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
            {
                temp[i][j] = (float)Elmt(M, i, j);
            }
        }

        // Membentuk matriks segitiga atas
        for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
        {
            for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
            {
                if (j > i)
                {
                    ratio = temp[j][i] / temp[i][i];
                    for (k = GetFirstIdxBrs(M); k <= GetLastIdxBrs(M); k++)
                    {
                        temp[j][k] -= ratio * temp[i][k];
                    }
                }
            }
        }
        // Determinan didapatkan dari perkalian diagonalnua
        det = 1;
        for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
        {
            det *= temp[i][i];
        }

        if (det == 0)
        {
            return 0;
        }
        else
        {
            return det;
        }
    }

}
void PInverse1 (MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
    /* KAMUS LOKAL */
    indeks i,j;

    /* ALGORITMA */
    for (i=BrsMin;i<=GetLastIdxBrs(*M);i++)
    {
        for (j=KolMin;j<=GetLastIdxKol(*M);j++)
        {
            Elmt(*M,i,j) = Elmt(*M,i,j)*(-1);
        }
    }
}
void Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
    /* KAMUS LOKAL */
    indeks i,j;
    MATRIKS M1;

    /* ALGORITMA */
    CopyMATRIKS(*M,&M1);

    // proses transpose;
    for (i=BrsMin;i<=GetLastIdxBrs(*M);i++)
    {
        for (j=KolMin;j<=GetLastIdxKol(*M);j++)
        {
            Elmt(*M,i,j) = Elmt(M1,j,i);
        }
    }
}
