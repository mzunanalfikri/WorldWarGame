#include "matriks.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M){
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
    M->NBrsEff = NB;
    M->NKolEff = NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j){
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
    return (((BrsMin <= i) && (i <= BrsMax)) && (KolMin <= j) && (j <= KolMax));
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M){
/* Mengirimkan indeks baris terkecil M */
    return BrsMin;
}

indeks GetFirstIdxKol (MATRIKS M){
/* Mengirimkan indeks kolom terkecil M */
    return KolMin;
}

indeks GetLastIdxBrs (MATRIKS M){
/* Mengirimkan indeks baris terbesar M */
    return M.NBrsEff;
}

indeks GetLastIdxKol (MATRIKS M){
/* Mengirimkan indeks kolom terbesar M */
    return M.NKolEff;
}
boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
    return ((BrsMin <= i) && (i <= M.NBrsEff) && (KolMin <= j) && (j <= M.NKolEff));
}

ElType GetElmtDiagonal (MATRIKS M, indeks i){
/* Mengirimkan elemen M(i,i) */
    return M.Mem[i][i];
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
/* Melakukan assignment MHsl  MIn */
    MHsl->NBrsEff = MIn.NBrsEff;
    MHsl->NKolEff = MIn.NKolEff;
    for (int i = BrsMin; i < BrsMin+MIn.NBrsEff; i++){
        for (int j = KolMin; j < KolMin+ MIn.NKolEff; j++){
            MHsl->Mem[i][j] = MIn.Mem[i][j];
        }
    }
}
/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK){
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/  
    if (!(IsIdxValid(NB,NK))){
        return;
    }
    M->NBrsEff = NB;
    M->NKolEff = NK;
    for (int i = BrsMin; i < BrsMin+M->NBrsEff; i++){
        for (int j = KolMin; j < KolMin+ M->NKolEff; j++){
            scanf("%d",&(M->Mem[i][j]));
        }
    }
}

void TulisMATRIKS (MATRIKS M){
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
    for (int i = BrsMin; i < BrsMin+M.NBrsEff; i++){
        printf("%d",M.Mem[i][1]);
        for (int j = KolMin+1; j <= M.NKolEff; j++){
            printf(" %d",M.Mem[i][j]);
        }
        if (i != M.NBrsEff){
            printf("\n");
        }
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2){
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
    MATRIKS M3;
    M3.NBrsEff = M1.NBrsEff;
    M3.NKolEff = M1.NKolEff;
    for (int i = BrsMin; i < BrsMin+M1.NBrsEff; i++){
        for (int j = KolMin; j < KolMin+ M1.NKolEff; j++){
            M3.Mem[i][j] = M1.Mem[i][j] + M2.Mem[i][j];
        }
    }
    return M3;
}

MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2){
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 � M2 */
    MATRIKS M3;
    M3.NBrsEff = M1.NBrsEff;
    M3.NKolEff = M1.NKolEff;
    for (int i = BrsMin; i < BrsMin+M1.NBrsEff; i++){
        for (int j = KolMin; j < KolMin+ M1.NKolEff; j++){
            M3.Mem[i][j] = M1.Mem[i][j] - M2.Mem[i][j];
        }
    }
    return M3;
}

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2){
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
    MATRIKS M3;
    M3.NBrsEff = M1.NBrsEff;
    M3.NKolEff = M2.NKolEff;
    for (int i = BrsMin; i < BrsMin+M1.NBrsEff; i++){
        for (int j = KolMin; j < KolMin+ M2.NKolEff; j++){
            for (int k = KolMin; k < KolMin+ M1.NKolEff; k++){
                M3.Mem[i][j] += M1.Mem[i][k] * M2.Mem[k][j];
            }
        }
    }
    return M3;
}

MATRIKS KaliKons (MATRIKS M, ElType X){
/* Mengirim hasil perkalian setiap elemen M dengan X */
    MATRIKS M3;
    M3.NBrsEff = M.NBrsEff;
    M3.NKolEff = M.NKolEff;
    for (int i = BrsMin; i < BrsMin+M.NBrsEff; i++){
        for (int j = KolMin; j < KolMin+ M.NKolEff; j++){
            M3.Mem[i][j] = M.Mem[i][j] * X;
        }
    }
    return M3;
}
void PKaliKons (MATRIKS * M, ElType K){
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
    for (int i = BrsMin; i < BrsMin+M->NBrsEff; i++){
        for (int j = KolMin; j < KolMin+ M->NKolEff; j++){
            M->Mem[i][j] *= K;
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2){
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
    if (!(NBElmt(M1) == NBElmt(M2))){
        return (0);
    }
    for (int i = BrsMin; i < BrsMin+M1.NBrsEff; i++){
        for (int j = KolMin; j < KolMin+ M1.NKolEff; j++){
            if (!(M1.Mem[i][j] == M2.Mem[i][j])){
                return (0);
            }
        }
    }
    return ((GetFirstIdxBrs(M1)==GetFirstIdxBrs(M2)) && (GetLastIdxKol(M1) == GetLastIdxKol(M2)));
}

boolean NEQ (MATRIKS M1, MATRIKS M2){
/* Mengirimkan true jika M1 tidak sama dengan M2 */
    return (!EQ(M1,M2));
}

boolean EQSize (MATRIKS M1, MATRIKS M2){
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
    return ((M1.NBrsEff == M2.NBrsEff) && (M1.NKolEff == M2.NKolEff));
}
/* ********** Credits to Muhammad Ayyub Abdurrahman 13518076 ********** */

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M){
/* Mengirimkan banyaknya elemen M */
    return (M.NKolEff*M.NBrsEff);
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M){
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
    return (M.NKolEff == M.NBrsEff);
}

boolean IsSimetri (MATRIKS M){
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
    if (IsBujurSangkar(M)){
        for (int i = BrsMin; i < BrsMin+M.NBrsEff; i++){
            for (int j = KolMin; j < KolMin+ M.NKolEff; j++){
                if (!(M.Mem[i][j] == M.Mem[j][i])){
                    return (0);
                }
            }
        }
        return 1;
    }
    return (0);
}

boolean IsSatuan (MATRIKS M){
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
    if (IsBujurSangkar(M)){
        for (int i = BrsMin; i < BrsMin+M.NBrsEff; i++){
            for (int j = KolMin; j < KolMin+ M.NKolEff; j++){
                if (!(((i==j) && (M.Mem[i][j] == 1)) || (M.Mem[i][j] == 0))) {
                    return (0);
                }
            }
        }
        return 1;
    }
    return (0);
}
boolean IsSparse (MATRIKS M){
/* Mengirimkan true jika M adalah matriks sparse: mariks �jarang� dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
    int count = 0;
    for (int i = BrsMin; i < BrsMin+M.NBrsEff; i++){
        for (int j = KolMin; j < KolMin+ M.NKolEff; j++){
            if (M.Mem[i][j] == 0){
                count += 1;
            }
        }
    }
    return (count >= 0.95*NBElmt(M));
}

MATRIKS Inverse1 (MATRIKS M){
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
    MATRIKS M2;
    M2.NBrsEff = M.NBrsEff;
    M2.NKolEff = M.NKolEff;
    
    for (int i = BrsMin; i < BrsMin+M.NBrsEff; i++){
        for (int j = KolMin; j < KolMin+ M.NKolEff; j++){
            M2.Mem[i][j] = M.Mem[i][j]*-1;
        }
    }
    return M2;
}

float Determinan (MATRIKS M){
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
    float pos = 0;
	float neg = 0;
	if (GetLastIdxBrs(M) == 2){
		int a = M.Mem[1][1];
		int b = M.Mem[1][2];
		int c = M.Mem[2][1];
		int d = M.Mem[2][2];
		return ((a*d)-(b*c));
	}

	else {
		for (int j = 1;j<=M.NKolEff;j++){
			float x = 1;
			for (int i = 1;i<=M.NBrsEff;i++){
				if (i+j-1>M.NKolEff){
					x *= M.Mem[i][i+j-1-(M.NKolEff)]; 
				}
				else{
					x *= M.Mem[i][i+j-1];
				}
			}
			pos += x;
		}
		for (int j = M.NKolEff;j>=KolMin;j--){
			float y = 1;
			for (int i = 1;i<=M.NBrsEff;i++){
				if (j-i+1<KolMin){
					y *= M.Mem[i][j-i+1+(M.NKolEff)];
				}
				else{
					y *= M.Mem[i][j-i+1];
				}
			}
			neg += y;
		}
		return pos - neg;
	}
}

void PInverse1 (MATRIKS * M){
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
    for (int i = BrsMin; i < BrsMin+M->NBrsEff; i++){
        for (int j = KolMin; j < KolMin+ M->NKolEff; j++){
            M->Mem[i][j] *= -1;
        }
    }
}
void Transpose (MATRIKS * M){
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
    for (int i = BrsMin; i < BrsMin+M->NBrsEff; i++){
        for (int j = KolMin; j < KolMin+ M->NKolEff; j++){
            if (i <= j){
                int temp;
                temp = M->Mem[i][j];
                M->Mem[i][j] = M->Mem[j][i];
                M->Mem[j][i] = temp;
            }
        }
    }
}
