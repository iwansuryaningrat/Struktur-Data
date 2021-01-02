/************************************/
/* Program   : listrekursif.c */
/* Deskripsi : realisasi body modul list */
/* NIM/Nama  : 24060119120027/Iwan Suryaningrat*/
/* Tanggal   : 3 Desember 2020*/
/***********************************/

#include <stdio.h>
#include "listrekursif.h"

/* Mengirim true jika list kosong */
boolean IsEmptyList (List L){
	// Kamus lokal
	
	// Algoritma
	if (L == Nil){
		return true;
	}
	else{
		return false;
	}
}

/* I.S. sembarang */
/* F.S. Terbentuk list kosong */
void CreateList (List *L){
	// Kamus lokal
	
	// Algoritma
	(*L) = Nil;
}

/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
address Alokasi (infotype X){
	// Kamus lokal
	address P;
	
	// Algoritma
	P = (address) malloc(sizeof(ElmtList));
    if (P != Nil ){
		info(P) = X;
		next(P) = Nil;
    }
}

/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
void Dealokasi (address P){
	// Kamus lokal 

	// Algoritma 
    info(P) = 0;
	next(P) = Nil;
	P = Nil;
	free(P);
}

/* mengirimkan list L dengan tambahan e sebagai elemen pertamanya */
/* jika alokasi gagal, mengirimkan L */
List Konso (List L, infotype e){
	// Kamus lokal
	address P;
	
	// Algoritma
	P = Alokasi (e);
	if (P == Nil){
		return L;
	}
	else{
		next(P) = L;
		return P;
	}
}

/* mengirimkan list L dengan menambah e sebagai elemen terakhir */
/* jika alokasi gagal, mengirimkan L */
List Kons0(List L, infotype e){
	// Kamus lokal
	address P, Last;
	
	// Algoritma
	P = Alokasi(e);
	if(P==Nil){
		return L;
	}
	else{
		if(IsEmptyList(L)){
			return L;
		}
		else{
			Last = L;
			while (next(Last)!=Nil){
				Last = next(Last);
			}
			next(Last) = P;
			return L;
		}
	}
}

/* I.S. L terdefinisi */
/* F.S. Setiap elemen lisst diprint */
void Printlist (List L){
	// Kamus lokal
	
	// Algoritma
	if (IsEmptyList(L)){
		
	}
	else{
		printf("%d ", info(L));
		Printlist(next(L));
	}
}

/* mengirimkan banyaknnya elemen list L, nol jika L kosong */
int NBElmtlist(List L){
	// Kamus lokal
	
	// Algoritma
	if(IsEmptyList(L)){
		return 0;
	}
	else{
		return (1+NBElmtlist(next(L)));
	}
}

/* I.S. L terdefinisi */
/* F.S. N berisi banyaknya elemen list */
void NBElmtlist1(List L, int *N){
	// Kamus lokal
	int N1;
	
	// Algoritma
	if(IsEmptyList(L)){
		(*N) = 0;
	}
	else{
		NBElmtlist1(next(L), &N1);
		(*N) = 1 + N1;
	}
}

/* I.S. L terdefinisi */
/* F.S. N berisi banyaknya elemen list */
void NBElmtlistAcc(List L, int Acc, int *N){
	// Kamus lokal
	
	// Algoritma
	if(IsEmptyList(L)){
		(*N) = (Acc);
	}
	else{
		(Acc) = (Acc) + 1;
		NBElmtlistAcc(next(L), Acc, N);
	}
}

/* mengirim true jika X adalah anggota list, false jika tidak */
boolean Search(List L, infotype X){
	// Kamus lokal
	
	// Algoritma
	if (IsEmptyList(L)){
		return false;
	}
	else{
		if(info(L) == X){
			return true;
		}
		else{
			Search(next(L), X);
		}
	}
}

/* mengirimkan elemen pertama sebuah list L yang tidak kosong */
infotype FirstElmt(List L){
	// Kamus lokal
	
	// Algoritma
	return info(L);
}

/* mengirimkan elemen terakhir sebuah list L yang tidak kosong */
infotype LastElmt(List L){
	// Kamus lokal
	
	// Algoritma
	if (next(L)==Nil){
		return info(L);
	}
	else{
		LastElmt(next(L));
	}
}

/* mengirimkan list L tanpa elemen pertamanya, mungkin yang dikirimkan adalah list kosong */
List Tail(List L){
	// Kamus lokal
	
	// Algoritma
	return next(L);
}

/* mengirimkan list L tanpa elemen terakhirnya, mungkin yang dikirimkan adalah list kosong */
List Head(List L){
	// Kamus lokal
	
	// Algoritma
	if (next(L) != Nil){
            return Konso (Head(Tail(L)), FirstElmt(L));
    }
}

/* mengirimkan salinan list L */
/* jika alokasi gagal, mengirimkan L */
List Copy(List L){
	// Kamus lokal
	
	// Algoritma
	if(IsEmptyList(L)){
		return L;
	}
	else{
		Konso(Copy(Tail(L)),FirstElmt(L));
	}
}

/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */
/*jika alokasi gagal, Lout adalah ??? */
void MengCopy(List Lin, List *Lout){
	// Kamus lokal
	List Ltemp;
	
	// Algoritma
	if(IsEmptyList(Lin)){
		(*Lout) = Lin;
	}
	else{
		MengCopy(Tail(Lin), &Ltemp);
		(*Lout) = Konso(Ltemp,FirstElmt(Lin));
	}
}

/* mengirimkan salinan hasil konkatenasi list L1 dan L2 */
List Concat(List L1, List L2){
	// Kamus lokal
	
	// Algoritma
	if (IsEmptyList(L1)){
		return Copy (L2);
	}
	else{
		return Konso(Concat(Tail(L1), L2), FirstElmt(L1));
	}
}

/* mengirimkan salinan hasil konkatenasi list L1 dan L2 */
List Concat1(List L1, List L2){
	// Kamus lokal
	
	// Algoritma
	if (IsEmptyList(L2)){
		return Copy (L1);
	}
	else{
		return Kons0(Concat1(L1, Head(L2)), LastElmt(L2));
	}
}

/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi List L1 dan L2 */
void Mengconcat(List L1, List L2, List *LHsl){
	// Kamus lokal
	List L;

	// Algoritma
	if(IsEmptyList(L1)){
		(*LHsl) = Copy(L2);
	}
	else{
		Mengconcat(Tail(L1), L2, &L);
		(*LHsl) = Konso(L, FirstElmt(L1));
	}
}