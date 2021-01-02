/***********************************/
/* Program   : list.c */
/* Deskripsi : file BODY modul stack berkait */
/* NIM/Nama  : 24060119120027/Iwan Suryaningrat*/
/* Tanggal   : 14 November 2020*/
/***********************************/

/* contoh ADT list berkait dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* infotype adalah integer */

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
	} 
	else{
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

/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list setelah elemen X */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
void InsVAfter (List * L, infotype Y, address Prec){
    // Kamus Lokal
    address P;

    // Algoritma
    P = Alokasi(Y);
    InsertAfter(L,P,Prec);

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

/* I.S. list tidak kosong */
/* F.S. Elemen list setelah X dihapus */
/* dan alamat elemen setelah X di-dealokasi */
void DelVAfter (List * L, infotype * X, address P){
    // Kamus lokal
    address Pdel;

    //Algoritma
    (*X) = info(next(P));
    DelAfter(L,Pdel,P);
    Dealokasi(Pdel);

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

/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
int NbElmt(List L){
	// Kamus Lokal
	address P;
	int X = 0;

	// Algoritma
	P = First (L);
    while (P != Nil){
        X++;
        P = next (P);
    }
    return X;
}

/** ----- Pencarian Sebuah Elemen List ----- **/
/* Mencari apakah ada elemen list dengan Info(P) = X
   Jika ada, mengirimkan address elemen tersebut
   Jika tidak ada, mengirimkan Nil */
address Search (List L, infotype X){
	// Kamus Lokal
    address P;
    boolean Found;

    // Algoritma
    P = First(L);
    Found = false;
    while ((P != Nil) && (!Found)){
    	if (X == info(P)){
    		Found = true;
    	}
    	else{
        	P = next(P);
    	}
    }
    return P;
}

/* Mencari apakah ada elemen list yang beralamat P
   Mengirimkan true jika ada, false jika tidak ada */
boolean FSearch (List L, address P){
	// Kamus Lokal
    address Pcek;
    boolean Found;

    // Algoritma
    Pcek = First(L);
    Found = false;
    while ((Pcek != Nil) && (!Found)) {
    	if (Pcek == P) {
        	Found = true;
    	} 
    	else {
        	Pcek = next(Pcek);
		}
    }
    return Found;
}

/* Mengirimkan address elemen sebelum elemen yang nilainya = X
   Mencari apakah ada elemen list dengan Info(P) = X
   Jika ada, mengirimkan address Prec, dengan
   Next(Prec) = P dan Info(P) = X
   Jika tidak ada, mengirimkan Nil
   Jika P adalah elemen pertama, maka mengirimkan Nil
   Search dengan spesifikasi seperti ini menghindari traversal ulang
   jika setelah Search akan dilakukan operasi lain */
address SearchPrec (List L, infotype X){
	// Kamus Lokal
    address P;
    boolean Found;

    // Algoritma
    P = First(L);
    Found = false;
    if (P == Nil) {
    	return Nil;
    } 
    else {
    	while ((next(P) != Nil) && (!Found)) {
        	if (X == info(next(P))) {
        		Found = true;
        	}
        	else {
        		P = next(P);
    		}
    	}
    }
    if (next(P) == Nil) {
    	return Nil;
    } 
    else {
    	return P;
    }
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
/* Mengirimkan nilai info(P) yang maksimum */
infotype Max (List L){
	// Kamus lokal
	address P;
	int X;

	// Algoritma
	P = First (L);
    while (P != Nil){
        if(info(P)>info(next(P))){
            X = info(P);
        }
        else{
            X = info(next(P));
        }
        P = next(P);
    }
    return X;
}

/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
address AdrMax(List L){
	// Kamus Lokal
	address P;
	int X;

	// Algoritma
	P = First(L);
	if (P == Nil){
		X = -999;
	}
	else{
		X = First(L);
	}
	while (P != Nil){
		if (X > info(P)){
			X = info(P);
		}
		P = next(P);
	}
	return X;
}

/* Mengirimkan nilai info(P) yang minimum */
infotype Min (List L){
	// Kamus Lokal
	address P;
	int X;

	// Algoritma
	P = First (L);
    while (P != Nil){
        if(info(P)<info(next(P))){
            X = info(P);
        }
        else{
            X = info(next(P));
        }
        P = next (P);
    }
    return X;
}

/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
address AdrMin (List L){
	// Kamus Lokal
	infotype A;
	address P;

	// Algoritma
	A = Min(L);
	P = Search(L,A);
	return P;
}

/* Mengirimkan nilai rata-rata info(P) */
infotype Average (List L){
	// Kamus Lokal
	address P;
	int X = 0;

	// Algoritma
	P = First (L);
    while (P != Nil){
        X += info(P);
        P = next (P);
    }
    X = X/NbElmt(L);
    return X;
}

/****************** PROSES TERHADAP LIST ******************/
/* Delete semua elemen list dan alamat elemen di-dealokasi */
void DelAll (List *L){
	// Kamus Lokal
	address P;

	// Algoritma
	P = First (*L);
    next(P) = Nil;
    P = Nil;
    First(*L) = Nil;
}

/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
void InversList (List *L){
	// Kamus Lokal
	address P, Pt;

	// Algoritma
	CreateList(&Pt);
	if (P != Nil){
		while (next(P) != Nil){
			Pt = next(P);
			DelAfter(&L,&P,Pt);
			InsertFirst(&L,Pt);
		}
	}
}

/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
List FInversList (List L){
	// Kamus Lokal
	List Li;
    address P, Pt;
    boolean gagal;

    // Algoritma
    gagal = false;
    CreateList(&Li);
    P = First(L);
    while ((P != Nil) && (!gagal)) {
    	Pt = Alokasi(info(P));
    	if (Pt != Nil) {
        	InsertFirst(&Li, Pt);
        	P = next(P);
    	} 
    	else {
        	DelAll(&Li);
        	gagal = true;
    	}
    }
    return Li;
}

/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
void CopyList (List *L1, List *L2){
	// Kamus Lokal

    // Algoritma
    First(*L2) = First(*L1);

}

/* Mengirimkan list yang merupakan salinan L dengan melakukan alokasi
   elemen baru. Jika ada alokasi gagal, hasilnya list kosong dan semua
   elemen yang terlanjur dialokasi, harus didealokasi. */
List FCopyList (List L){
	// Kamus Lokal
    address P, Pt;
    List Lt;
    boolean gagal;

    // Algoritma
    gagal = false;
    CreateList(&Lt);
    P = First(L);
    while ((P != Nil)&&(!gagal)) {
    	Pt = Alokasi(info(P));
    	if (Pt != Nil) {
        	InsertLast(&Lt,Pt);
        	P = next(P);
    	} 
    	else {
        	gagal = true;
        	DelAll(&Lt);
    	}
    }
    return Lt;
}

/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur
dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */
void CpAlokList (List Lin, List *Lout){
	// Kamus Lokal  
    address P, Pt;
    boolean gagal;

    // Algoritma 
    CreateList(Lout);
    gagal = false;
    P = First(Lin);
    while ((P != Nil)&&(!gagal)) {
    	Pt = Alokasi(info(P));
    	if (Pt != Nil) {
        	InsertLast(&Lout,Pt);
        	P = next(P);
    	} 
    	else {
        	gagal = true;
        	DelAll(Lout);
    	}
    }
}

/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2
*/
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2)*/
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
void Konkat1 (List * L1, List * L2, List * L3){
	// Kamus Lokal
	address P;

	// Algoritma
	if (First(*L1) == Nil){
        First(*L3) = First(*L2);
    }
    else {
        First(*L3) = First(*L1);
        P = First(*L1);
        while (next(P) != Nil){
            P = next(P);
        }
        next(P) = First(*L2);
    }
    First(*L1) = Nil;
    First(*L2) = Nil;
}

/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */
void PecahList (List *L1, List *L2, List L){
	/* Kamus Lokal */
    address P, Pt;
    boolean gagal;
    int i, N;


    /* Algoritma */
    CreateList(L1);
    CreateList(L2);
    gagal = false;
    i = 1;
    N = NbElmt(L)/2;
    P = First(L);
    while ((P != Nil)&&(!gagal)) {
    	Pt = Alokasi(info(P));
    	if (i <= N) {
        	if (Pt != Nil) {
        		InsertLast(L1,Pt);
        		P = next(P);
        		i++;
        	} 
        	else {
        		gagal = true;
        		DelAll(L1);
        	}
    	} 
    	else {
        	if (Pt != Nil) {
        		InsertLast(L2,Pt);
        		P = next(P);
        		i++;
        	} 
        	else {
        		gagal = true;
        		DelAll(L2);
        	}
    	}
    }
}