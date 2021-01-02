/************************************/
/* Program   : listGandaLast.c */
/* Deskripsi : realisasi body modul list circular*/
/* NIM/Nama  : 24060119120027/Iwan Suryaningrat*/
/* Tanggal   : 26 November 2020*/
/***********************************/

#include <stdio.h>
#include "listganda.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
/* Mengirim true jika list kosong */
boolean ListEmpty (List L){
	// Kamus Lokal
	
	// Algoritma
	return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */
void CreateList (List * L){
	// Kamus Lokal
	
	// Algoritma
	First(*L) = Nil;
	Last(*L) = Nil;
}

/****************** Manajemen Memori ******************/
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
address Alokasi (infotype X){
	// Kamus Lokal
	address P;
	
	// Algoritma
	P = (address) malloc(sizeof(ElmtList));
    if (P != Nil ){
		info(P) = X;
		next(P) = Nil;
		prev(P) = Nil;
    }
}

/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
void Dealokasi (address P){
	// Kamus Lokal
	
	// Algoritma
    info(P) = 0;
	next(P) = Nil;
	prev(P) = Nil;
	P = Nil;
	free(P);
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVFirst (List * L, infotype X){
	// Kamus Lokal
	address P;
	
	// Algoritma
	P = Alokasi(X);
	InsertFirst(L,P);
}

/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
void InsVLast (List * L, infotype X){
	// Kamus Lokal
	address P;
	
	// Algoritma
	P = Alokasi(X);
	InsertLast(L,P);
}

/*** PENGHAPUSAN ELEMEN ***/
/* I.S. List L tidak kosong */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/* dan alamat elemen pertama di-dealokasi */
void DelVFirst (List * L, infotype * X){
	// Kamus Lokal
	address P;
	
	// Algoritma
	DelFirst(L,&P);
	(*X) = info(P);
	Dealokasi(P);
}

/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/* dan alamat elemen terakhir di-dealokasi */
void DelVLast (List * L, infotype * X){
	// Kamus Lokal
	address P;
	
	// Algoritma
	DelLast(L,&P);
	(*X) = info(P);
	Dealokasi(P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertFirst (List * L, address P){
	// Kamus Lokal
	
	// Algoritma
	if (ListEmpty(*L)){
		Last(*L) = P;
	}
	else{
		next(P) = First(*L);
		prev(First(*L)) = P;
		prev(P) = Nil;
	}
	First(*L) = P;
}

/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/* P sudah dialokasi */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertAfter (List * L, address P, address Prec){
	// Kamus Lokal
	
	// Algoritma
	next(P) = next(Prec);
	next(Prec) = P;
	prev(P) = Prec;
	prev(next(Prec)) = P;
}

/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertLast (List * L, address P){
	// Kamus Lokal
	
	// Algoritma
	if (ListEmpty(*L)){
		InsertFirst(L,P);
	}
	else{
		next(Last(*L)) = P;
		prev(P) = Last(*L);
		Last(*L) = P;
		next(P) = Nil;
	}
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelFirst (List * L, address * P){
	// Kamus Lokal
	
	// Algoritma
	(*P) = First(*L);
	First(*L) = next(First(*L));
	prev(First(*L)) = Nil;
}

/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelP (List * L, infotype X){
	// Kamus Lokal
	address P, Q;
	
	// Algoritma
	P = First(*L);
	Q = next(P);
	if(info(P) == X && Q == Nil){
		DelFirst(L,&P);
	}
	else{
		while(info(Q) != X){
			P = next(P);
			Q = next(P);
		}
		DelAfter(L,&Q,P);
	}
}

/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelLast (List * L, address * P){
	// Kamus Lokal
	
	// Algoritma
	if(!(ListEmpty(*L))){
		(*P) = Last(*L);
		if(prev(*P) == Nil){
			First(*L) = Nil;
			Last(*L) = Nil;
		}
		else{
			Last(*L) = prev(*P);
			next(Last(*L)) = Nil;
		}
	}
}

/* I.S. List tidak kosong. Prec adalah anggota list */
/* F.S. Menghapus Next(Prec): */
/* Pdel adalah alamat elemen list yang dihapus */
void DelAfter (List * L, address * Pdel, address Prec){
	// Kamus Lokal
	
	// Algoritma
	if(!(ListEmpty(*L))){
		(*Pdel) = next(Prec);
		next(Prec) = next(next(Prec));
		prev(next(Prec)) = Prec;
		next(*Pdel) = Nil;
		prev(*Pdel) = Nil;
		
	}
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "list kosong" */
void Printinfo (List L){
	// Kamus Lokal
	address P;
	
	// Algoritma
	if (!(ListEmpty(L))){
		P = First(L);
		while (P != Last(L)){
			printf("%d;", info(P));
			P = next(P);
		}
		printf("%d;", info(P));
	}
}
