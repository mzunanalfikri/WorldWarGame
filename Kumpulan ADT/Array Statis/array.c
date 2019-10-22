#include "array.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt *T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
    Neff(*T) = 0;
}
/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
    return Neff(T);
}
int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
    return IdxMax;
}
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
    return IdxMin;
}
IdxType GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
    return (IdxMin + Neff(T)) - 1; //karena indeks pertama belom tentu dari array ke 1
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return ((IdxMin<=i) && (i<=IdxMax));
}
boolean IsIdxEff (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    return ((GetFirstIdx(T)<=i) && (i<=GetLastIdx(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    return (Neff(T) == 0);
}
/* *** Test tabel penuh *** */
boolean IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return (Neff(T) == IdxMax);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt *T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks
 IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
    /* KAMUS LOKAL */
    int N;
    ElType El;
    IdxType i;

    /* ALGORITMA */
    //Pembacaan indeks hingga benar
    do
    {
        scanf("%d",&N);
    }
    while((N<0) || (N>IdxMax));
    //Pengisian array
    if(N == 0)
    {
        MakeEmpty(T);
    }
    else
    {
        for(i=IdxMin;i<=N;i++)
        {
            scanf("%d",&El);
            Elmt(*T, i) = El;
        }
        Neff(*T) = N;
    }
}
void BacaIsiTab (TabInt *T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
/* Dibaca elemen satu per satu dan disimpan mulai dari IdxMin */
/* Pembacaan dihentikan jika pengguna memasukkan nilai -9999 */
/* Jika dari pertama dimasukkan nilai -9999 maka terbentuk T kosong */
{
    /* KAMUS LOKAL */
    int Undef = -9999;
    ElType x;
    IdxType i;

    /* ALGORITMA */
    i = IdxMin;
	scanf("%d", &x);
	while ((x != Undef) && (i<=IdxMax))
    {
		Elmt(*T,i) = x;
		scanf("%d", &x);
		i++;
	}
	Neff(*T) = i-1;
}
void TulisIsi (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
 Maka tercetak di layar:
 [1]1
 [2]20
 [3]30
 [4]50
 */
{
    /* KAMUS LOKAL */
    IdxType i;

    /* ALGORITMA */
    if (IsEmpty(T))
    {
        printf("Tabel kosong\n");
    }
    else //Tabel tak kosong
    {
        for(i=IdxMin;i<=GetLastIdx(T);i++)
        {
            printf("[%d]%d\n",i,Elmt(T, i));
        }
    }
}
void TulisIsiTab (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
 antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
 di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
    /* KAMUS LOKAL */
    IdxType i;

    /* ALGORITMA */
    printf("[");
    if (IsEmpty(T))
    {
        printf("]");
    }
    else //Tabel tak kosong
    {
        for(i=IdxMin;i<GetLastIdx(T);i++)
        {
            printf("%d,",Elmt(T, i));
        }

        printf("%d]",Elmt(T, GetLastIdx(T)));
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
{
    /* KAMUS LOKAL */
    TabInt NTab;
    IdxType i;
    ElType El;

    /* ALGORITMA */
    for(i=IdxMin;i<=NbElmt(T1);i++)
    {
        Elmt(NTab, i) = (Elmt(T1, i)) + (Elmt(T2, i));
    }
    Neff(NTab) = i-1;

    return NTab;

    return NTab;
}
TabInt MinusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
    /* KAMUS LOKAL */
    TabInt NTab;
    IdxType i;

    /* ALGORITMA */
    for(i=IdxMin;i<=NbElmt(T1);i++)
    {
        Elmt(NTab, i) = (Elmt(T1, i)) - (Elmt(T2, i));
    }
    Neff(NTab) = i-1;

    return NTab;
}
TabInt KaliTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan */
{
    /* KAMUS LOKAL */
    TabInt NTab;
    IdxType i;
    ElType El;

    /* ALGORITMA */
    for(i=IdxMin;i<=NbElmt(T1);i++)
    {
        Elmt(NTab, i) = (Elmt(T1, i)) * (Elmt(T2, i));
    }
    Neff(NTab) = i-1;

    return NTab;

}
TabInt KaliKons (TabInt Tin, ElType c)
/* Prekondisi : Tin tidak kosong */
/* Mengirimkan tabel dengan setiap elemen Tin dikalikan c */
{
    /* KAMUS LOKAL */
    TabInt NTab;
    IdxType i;

    /* ALGORITMA */
    MakeEmpty(&NTab);
    for(i=IdxMin;i<=GetLastIdx(Tin);i++)
    {
        Elmt(NTab,i) = (Elmt(Tin,i))*c;
    }
    Neff(NTab) = i-1;

    return NTab;

}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
{
    /* KAMUS LOKAL */
    IdxType i;
    boolean IsElmEQ;

    /* ALGORITMA */
    if(Neff(T1) != Neff(T2))
    {
        return false;
    }
    else // Neff nya sama
    {
        IsElmEQ = true; i = GetFirstIdx(T1);
        while(IsElmEQ && i<=GetLastIdx(T1))
        {
            if (Elmt(T1, i) != Elmt(T2, i))
            {
                IsElmEQ = false;
            }
            else //elemen sama
            {
                i++;
            }
        }
        return IsElmEQ;
    }
}
boolean IsLess (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 < T2, */
/* yaitu : sesuai dg analogi 'Ali' < Badu'; maka [0, 1] < [2, 3] */
{
    /* KAMUS LOKAL */
    IdxType i;

    /* ALGORITMA */
    for (i=IdxMin; i<=NbElmt(T1); i++ )
    {
        if (i>NbElmt(T2))
        {
            return false;
        }

        if (Elmt(T1,i)<Elmt(T2,i))
        {
            return true;
        }

        if (Elmt(T1,i)>Elmt(T2,i))
        {
            return false;
        }
    }

    return (T1.Neff<T2.Neff);

}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
{
    /* KAMUS LOKAL */
    IdxType i;

    /* ALGORITMA */
    if(IsEmpty(T))
    {
        return IdxUndef;
    }
    else //Array tak kosong
    {
        //Skema searching tanpa boolean
        i = GetFirstIdx(T);
        while((Elmt(T, i) != X) && (i<GetLastIdx(T)))
        {
            i++;
        }

        if(Elmt(T, i) == X)
        {
            return i;
        }
        else
        {
            return IdxUndef;
        }
    }
}
IdxType Search2 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
{
    /* KAMUS LOKAL */
    IdxType i;
    boolean Found;

    /* ALGORITMA */
    if(!IsEmpty(T))
    {
        //Skema searching dgn boolean
        Found = false; i = GetFirstIdx(T);
        while((!Found) && (i<=NbElmt(T)))
        {
            if (Elmt(T, i) == X)
            {
                Found = true;
            }
            else // elemen tak sama
            {
                i++;
            }
        }

        if(Found)
        {
            return i;
        }
    }

    return IdxUndef;
}
boolean SearchB (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */
{
    /* KAMUS LOKAL */
    IdxType i;
    boolean Found;

    /* ALGORITMA */
    if(IsEmpty(T))
    {
        return false;
    }
    else //Array tak kosong
    {
        //Skema searching dgn boolean
        Found = false; i = GetFirstIdx(T);
        while((!Found) && (i<=GetLastIdx(T)))
        {
            if (Elmt(T, i) == X)
            {
                Found = true;
            }
            else // elemen tak sama
            {
                i++;
            }
        }

        return Found;
    }
}

boolean SearchSentinel (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* dengan metoda sequential search dengan sentinel */
/* Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C
 yang tidak dipakai dalam definisi tabel */
 {
    /* KAMUS LOKAL */
    IdxType i;

    /* ALGORITMA */
    Elmt(T,0) = X; //insiasi sentinel
    i = GetLastIdx(T);
    while ((i>0) && ((Elmt(T, i) != X)))
    {
        i--;
    }

    if (i>0)
    {
        return true;
    }
    else // i=0
    {
        return false;
    }
 }

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
{
    /* KAMUS LOKAL */
    IdxType i;
    ElType NMax;

    /* ALGORITMA */
    NMax = Elmt(T,IdxMin);
    for ((i=IdxMin+1);i<=GetLastIdx(T);i++)
    {
        if(NMax <= (Elmt(T,i)))
        {
            NMax = Elmt(T,i);
        }
    }

    return NMax;
}
ElType ValMin (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
{
    /* KAMUS LOKAL */
    IdxType i;
    ElType NMin;

    /* ALGORITMA */
    NMin = Elmt(T,IdxMin);
    for ((i=IdxMin+1);i<=GetLastIdx(T);i++)
    {
        if(NMin >= (Elmt(T,i)))
        {
            NMin = Elmt(T,i);
        }
    }

    return NMin;
}

/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai maksimum pada tabel */
{
    /* KAMUS LOKAL */
    IdxType i,IMax;

    /* ALGORITMA */
    IMax = IdxMin;
    i = 2;
    while (i<=GetLastIdx(T))
    {
        if ((Elmt(T,IMax)) < (Elmt(T,i)))
        {
            IMax = i;
        }
        i++;
    }

    return IMax;
}
IdxType IdxMinTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai minimum pada tabel */
{
    /* KAMUS LOKAL */
    IdxType i,IMin;

    /* ALGORITMA */
    IMin = IdxMin;
    i = 2;
    while (i<=GetLastIdx(T))
    {
        if ((Elmt(T,IMin)) > (Elmt(T,i)))
        {
            IMin = i;
        }
        i++;
    }

    return IMin;
}
/* ********** OPERASI LAIN ********** */
void CopyTab (TabInt Tin, TabInt * Tout)
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
{
    /* KAMUS LOKAL */
    IdxType i;

    /* ALGORITMA */
    //Meng-copy tabel
    Neff(*Tout) = Neff(Tin);
    for (i=IdxMin;i<=NbElmt(Tin);i++)
    {
        Elmt(*Tout,i) = Elmt(Tin,i);
    }
}
TabInt InverseTab (TabInt T)
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
{
    /* KAMUS LOKAL */
    IdxType i,j;
    TabInt Tout;

    /* ALGORITMA */
    //Meng-reverse tabel
	Neff(Tout) = Neff(T);
	j=1;
	for (i=NbElmt(T); i>=IdxMin; i--)
    {
		Elmt(Tout,j) = Elmt(T,i);
		j++;
	}
	return (Tout);
}
boolean IsSimetris (TabInt T)
/* Menghasilkan true jika tabel simetrik */
/* Tabel disebut simetrik jika: */
/*      elemen pertama = elemen terakhir, */
/*      elemen kedua = elemen sebelum terakhir, dan seterusnya */
/* Tabel kosong adalah tabel simetris */
{
    /* KAMUS LOKAL */
    IdxType i,j;

	i=1;
	j=T.Neff;
	while ((Elmt(T,i) == Elmt(T,j)) && (i<=T.Neff))
    {
		i++;
		j--;
	}

	return (i == (T.Neff+1));
}

/* ********** SORTING ********** */
void MaxSortDesc (TabInt * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menurun dengan Maximum Sort */
/* Proses : mengurutkan T sehingga elemennya menurun/mengecil */
/*          tanpa menggunakan tabel kerja */
{
    /* KAMUS LOKAL */
    IdxType i,j,k;
    ElType temp,elmax;

    /* ALGORITMA */
    if (IsEmpty(*T))
    {
        MakeEmpty(T);
    }
    else //Tabel tak kosong
    {
        //Skema maximum sort
        j = 1;
        for (i=IdxMin; i<NbElmt(*T); i++)
        {
            elmax = Elmt(*T,i);
            k = i;
            for (j=i+1; j<=NbElmt(*T); j++)
            {
                if (Elmt(*T,j) > elmax)
                {
				elmax = Elmt (*T,j);
				k = j;
                }
            }

            temp = Elmt (*T,i);
            Elmt(*T,i) = elmax;
            Elmt(*T,k) = temp;
        }
    }
}
void InsSortAsc (TabInt * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menaik dengan Insertion Sort */
/* Proses : mengurutkan T sehingga elemennya menaik/membesar */
/*          tanpa menggunakan tabel kerja */
{
    /* KAMUS LOKAL */
    IdxType i,j;
    ElType temp;

    /* ALGORITMA */
    if (IsEmpty(*T))
    {
        MakeEmpty(T);
    }
    else //Tabel tak kosong
    {
        //Skema insertion sort
        for (i=2; i<=NbElmt(*T); i++)
        {
            temp = Elmt(*T,i);
            j = i-1;
            while (temp < Elmt(*T,j) && j>1)
            {
                Elmt(*T,j+1) = Elmt(*T,j);
                j--;
            }

            if (temp >= Elmt(*T,j))
            {
                Elmt(*T,j+1) = temp;
            }
            else
            {
                Elmt(*T,j+1) = Elmt(*T,j);
                Elmt(*T,j) = temp;
            }
        }
    }
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
    Neff(*T) += 1;
	Elmt(*T,NbElmt(*T)) = X;
}
void AddEli (TabInt * T, ElType X, IdxType i)
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas
 terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */
{
    /* KAMUS LOKAL */
    IdxType j;

    /* ALGORITMA */
	Neff(*T) += 1;
	if (i < NbElmt(*T))
    {
		for (j = NbElmt(*T); j > i; j--)
		{
			Elmt(*T,j) = Elmt(*T,j-1);
		}
		Elmt(*T,i) = X;
	}
	else
    {
		Elmt(*T,i) = X;
	}
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
    if (!IsEmpty(*T))
    {
        *X = Elmt(*T,GetLastIdx(*T));
        Neff(*T) -= 1;
    }
}
void DelEli (TabInt * T, IdxType i, ElType * X)
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
{
    /* KAMUS LOKAL */
    IdxType j;
    ElType temp;

    /* ALGORITMA */
    if ((!IsEmpty(*T)) && IsIdxValid(*T,i))
    {
        *X = Elmt(*T,i);
        for (j=i; j<GetLastIdx(*T); j++)
        {
            Elmt(*T,j) = Elmt(*T,j+1);
        }
    }
}

/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */
void AddElUnik (TabInt * T, ElType X)
/* Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/*      dan semua elemennya bernilai unik, tidak terurut */
/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T,
 jika belum ada elemen yang bernilai X.
 Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S.
 dan dituliskan pesan "nilai sudah ada" */
/* Proses : Cek keunikan dengan sequential search dengan sentinel */
/*          Kemudian tambahkan elemen jika belum ada */
{
    /* KAMUS LOKAL */
    IdxType i,j;

	/* ALGORITMA */
	if (!IsEmpty(*T))
    {
		j=0;
		for (i=1; i<=Neff(*T); i++)
		{
			if (X == Elmt(*T,i))
			{
				j=1;
			}
		}
		if (j==1)
		{
			printf("nilai sudah ada\n");
		}
        else
        {
			Neff(*T) += 1;
			Elmt(*T,NbElmt(*T)) = X;
		}
	} else
	{
		Neff(*T) += 1;
		Elmt (*T,1) = X;
	}
}

/* ********** TABEL DGN ELEMEN TERURUT MEMBESAR ********** */
IdxType SearchUrut (TabInt T, ElType X)
/* Prekondisi: Tabel T boleh kosong. Jika tidak kosong, elemen terurut membesar. */
/* Mengirimkan indeks di mana harga X dengan indeks terkecil diketemukan */
/* Mengirimkan IdxUndef jika tidak ada elemen tabel bernilai X */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel kosong */
{
    /* KAMUS LOKAL */
    IdxType i;
	boolean Found;

    /* ALGORITMA */
	if (!IsEmpty(T))
    {
		Found = false;
		i = 1;
		while ((!Found) && (i<=T.Neff))
		{
			if (X == T.TI[i])
			{
				Found = true;
			}
			i++;
		}

		if (Found)
        {
			return (i-1);
		}
        else
        {
			return (IdxUndef);
		}
	}
	else
	{
		return (IdxUndef);
	}
}
ElType MaxUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai maksimum pada tabel */
{
    return Elmt(T,GetLastIdx(T));
}
ElType MinUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai minimum pada tabel*/
{
    return Elmt(T,GetFirstIdx(T));
}
void MaxMinUrut (TabInt T, ElType * Max, ElType * Min)
/* I.S. Tabel T tidak kosong, elemen terurut membesar */
/* F.S. Max berisi nilai maksimum T;
 Min berisi nilai minimum T */
 {
     *Max = Elmt(T,GetLastIdx(T));
     *Min = Elmt(T,GetFirstIdx(T));
 }
void Add1Urut (TabInt * T, ElType X)
/* Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel */
/* Nilai dalam tabel tidak harus unik. */
/* I.S. Tabel T boleh kosong, boleh penuh. */
/*      Jika tabel isi, elemennya terurut membesar. */
/* F.S. Jika tabel belum penuh, menambahkan X. */
/*      Jika tabel penuh, maka tabel tetap. */
/* Proses : Search tempat yang tepat sambil geser */
/*          Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan */
{
    /* KAMUS LOKAL */
    IdxType i,j,k;

    /* ALGORITMA */
	j=0;
	if (!IsFull(*T))
    {
		Neff(*T) += 1;
		i = 1;
		while ((i<NbElmt(*T)) && (j==0))
		{
			if (X < Elmt(*T,i))
			{
				j = 1;
			}
			i++;
		}
		if (j == 1) {
			for (k=NbElmt(*T); k>=i; k--) {
				Elmt(*T,k) = Elmt(*T,k-1);
			}
			Elmt(*T,i-1) = X;
		} else {
			Elmt(*T,Neff(*T)) = X;
		}
	}
}
void Del1Urut (TabInt * T, ElType X)
/* Menghapus X yang pertama kali (pada indeks terkecil) yang ditemukan */
/* I.S. Tabel tidak kosong */
/* F.S. Jika ada elemen tabel bernilai X , */
/*      maka banyaknya elemen tabel berkurang satu. */
/*      Jika tidak ada yang bernilai X, tabel tetap. */
/*      Setelah penghapusan, elemen tabel tetap kontigu! */
/* Proses : Search indeks ke-i dengan elemen ke-i = X. */
/*          Delete jika ada. */
{
    /* KAMUS LOKAL */
    IdxType i,j;

    /* ALGORITMA */
	i = IdxUndef;
	for (j=NbElmt(*T); j>=1; j--)
    {
		if (X == Elmt(*T,j))
		{
			i = j;
		}
	}
	if (i != IdxUndef)
	{
		for (j=i; j<NbElmt(*T); j++)
		{
			Elmt(*T,j) = Elmt(*T,j+1);
		}
		Neff(*T) -= 1;
	}

}
