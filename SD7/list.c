/* File : list.c */
/* contoh ADT list berkait dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* infotype adalah integer */
/* Program   : list.c */
/* Deskripsi : file BODY modul stack berkait */
/* NIM/Nama  : 24060119120027/Iwan Suryaningrat*/
/* Tanggal   : 5 November 2020*/
/***********************************/

#include "list.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */
// typedef struct {
//     address First;
// } List;

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
/* Mengirim true jika list kosong */
boolean ListEmpty (List L){
	if (First(L) == Nil){
		return true;
	} else{
		return false;
	}
}

/****************** PEMBUATAN LIST KOSONG ******************/
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */
void CreateList (List *L){
	First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
address Alokasi (infotype X){
	// Kamus lokal
	address P;

	// Algortima
	(P) = (address) malloc(sizeof(ElmtList));
	if ((P) != Nil){
		info(P) = X;
		next(P) = Nil;
		return P;
	}
	else{
		return Nil;
	}
}

/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
void Dealokasi (address P){
	//kamus lokal 

	//algoritma 
    info(P) = 0;
	next(P) = Nil;
	P = Nil;
}


/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertFirst (List *L, address P){
	// Kamus Lokal

	// Algortima
	next(P) = First(*L);
	First(*L) = P;
}

/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/* P sudah dialokasi */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertAfter (List *L, address P, address Prec){
	// Kamus Lokal

	// Algoritma
	next(P) = next(Prec);
	next(Prec) = P;
}

/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertLast (List *L, address P){
	// Kamus Lokal
	address *Last;

	// Algoritma
	if(First(*L) == Nil){
		InsertFirst(L, P);
	}
	else{
		(*Last) = First(*L);
		while(next(*Last)!= Nil){
			(*Last) = (next(*Last));
		}
		InsertAfter(L,P,*Last);
	}
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelFirst (List *L, address *P){
	// Kamus Lokal

	// Algoritma
	(*P) = First(*L);
	First(*L) = next(First(*L));
}

/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelP (List *L, infotype X){
	// Kamus Lokal
	address *Prec;
	address P;

	// Algoritma
	if(P=First(*L)){
		DelFirst(L, &P);
	}
	else{
		*Prec = First(*L);
		while(next(*Prec) != P){
			(*Prec) = next(*Prec);
		}
		DelAfter(L, &P, *Prec);
	}
}

/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelLast (List *L, address *P){
	// Kamus Lokal
	address PrecLast;
	address *Last;

	// ALgoritma
	(*Last) = First(*L);
	(PrecLast) = Nil;
	while(next(*Last) != Nil){
		(PrecLast) = (*Last);
		(*Last) = next(*Last);
	}
	(*P) = (*Last);
	if((PrecLast) == Nil){
		First(*L) = Nil;
	}
	else{
		next(PrecLast) = Nil;
	}
}

/* I.S. List tidak kosong. Prec adalah anggota list */
/* F.S. Menghapus Next(Prec): */
/* Pdel adalah alamat elemen list yang dihapus */
void DelAfter (List *L, address *Pdel, address Prec){
	// Kamus Lokal

	// Algoritma
	*Pdel = next(Prec);
	next(Prec) = next(next(Prec));
	next(*Pdel) = Nil;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVFirst (List *L, infotype X){
	// Kamus Lokal
	address P;

	// ALgoritma
	P = Alokasi(X);
	if(P!=Nil){
		next(P) = First(*L);
		First(*L) = P;
	}
}

/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
void InsVLast (List *L, infotype X){
	// Kamus Lokal
	address P;
	address *Last;

	// Algoritma
	P = Alokasi(X);
	if(P != Nil){
		if(First(*L) == Nil){
			InsertFirst(L, P);
		}
		else{
			(*Last) = First(*L);
			while(next(*Last)!= Nil){
				(*Last) = (next(*Last));
			}
			InsertAfter(L,P,*Last);
		}
	}
}

/*** PENGHAPUSAN ELEMEN ***/
/* I.S. List L tidak kosong */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/* dan alamat elemen pertama di-dealokasi */
void DelVFirst (List * L, infotype * X){
	// Kamus Lokal
	address P;

	// Algortima
	(P) = First(*L);
	(*X) = info(P);
	First(*L) = next(P);
	next(P) = Nil;
}

/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/* dan alamat elemen terakhir di-dealokasi */
void DelVLast (List * L, infotype * X){
	// Kamus Lokal
	address PrecLast;
	address *Last;

	// Algoritma
	(*Last) = First(*L);
	(PrecLast) = Nil;
	while(next(*Last) != Nil){
		(PrecLast) = (*Last);
		(*Last) = next(*Last);
	}
	(*X) = info(*Last);
	if((PrecLast) == Nil){
		First(*L) = Nil;
	}
	else{
		next(PrecLast) = Nil;
	}
}

/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "list kosong" */
void Printinfo (List L){
	// Kamus Lokal
	address P;

	// Algoritma
	P = First(L);
	while((P) != Nil){
		printf("%d;", info(P));
		(P) = next(P);
	}
	printf("\n");
}

/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
/* harus di-dealokasi dan L3=Nil*/
/* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang â€œbaruâ€ */
/* Elemen L3 adalah hasil alokasi elemen yang â€œbaruâ€. */
/* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
/* dan semua elemen yang pernah dialokasi didealokasi */
void Konkat (List L1, List L2, List *L3){
	// Kamus Lokal
	address P;

	// Algoritma
	if(First(L1) == Nil){
		First(*L3) = First(L2);
	}
	else{
		First(*L3) = First(L1);
		(P) = First(*L3);
		while(next(P) != Nil){
			(P) = next(P);
		}
		next(P) = First(L2);
	}
}
