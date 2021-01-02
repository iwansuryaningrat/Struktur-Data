/* Program   : listCir.c */
/* Deskripsi : file BODY modul list CIRCULAR */
/* NIM/Nama  : 24060119120027/Iwan Suryaningrat*/
/* Tanggal   : 19 November 2020*/
/***********************************/

#include "listCir.h"
#include <stdlib.h>
#include "boolean.h"
#include <stdio.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
/* Mengirim true jika list kosong */
boolean ListEmpty (List L){
	// Kamus Lokal	

	// Algoritma
	return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
/*procedure createLStack( output S:lstack)
{I.S.: -}
{F.s.: S terdefinisi}
{proses: membentuk stack kosong}*/
void CreateList (List *L){
	// Kamus Lokal

	// Algoritma
	First(*L) = Nil;
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
  	if (P != Nil){
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
void Dealokasi(address *P){
	// Kamus Lokal 

  	// Algoritma 
    info((*P)) = 0;
	next((*P)) = Nil;
	(*P) = Nil;
	//free((*P));
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/ 
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
address Search (List L, infotype X) {
    // Kamus Lokal
    address P;
    boolean find = false;

    // Algoritma
    P = First(L);
    do{
		if(X == info(P)){
			find = true;
		}
		else{
			P = next(P);
		}
	}
	while((P!=First(L))&&(!find));
	if(!find){
		P = Nil;
	}
    return P;
}

/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
boolean FSearch (List L, address P) {
    // Kamus lokal
    address PSearch;
    boolean find = false;

	// Algoritma
    PSearch = First(L);
    do{
		if(PSearch == P){
			find = true;
		}
		else{
			PSearch = next(PSearch);
		}
	}
	while((PSearch!=First(L))&&(!find));
    return find;
}

/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P */
/* dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain*/
address SearchPrec (List L, infotype X, address *Prec){
    // Kamus Lokal
    address P;
    boolean find = false;

    // Algoritma
    if(!ListEmpty(L)){
	    *Prec = Nil;
	    P = First(L);
		do{
		 	if(X == info(P)){
				next(*Prec) = P;
				find = true;
			} 
			else{
		    	P = next(P);
			}
		}
		while(P != First(L)&&(!find));
		if(!find){
			*Prec = Nil;
		}
	    return *Prec;
	}
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVFirst (List * L, infotype X){
	// Kamus lokal
	address P;

	// Algoritma
	P = Alokasi(X);
	if(P != Nil){
		InsertFirst(&(*L), P);
	}
}

/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
void InsVLast (List *L, infotype X){
	// Kamus Lokal
	address P;

	// Algoritma
	P = Alokasi(X);
	if(P != Nil){
		if(First(*L) == Nil){
			InsertFirst(&(*L), P);
		}
		else{
			InsertLast(&(*L),P);
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

	// Algoritma
	if(!ListEmpty(*L)){
		DelFirst(&(*L), &P);
		(*X) = info(P);
	}
}

/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/* dan alamat elemen terakhir di-dealokasi */
void DelVLast (List * L, infotype * X){
	// Kamus Lokal
	address P;

	// Algoritma
	if(!ListEmpty(*L)){
		DelLast(&(*L), &P);
		(*X) = info(P);
	}
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/ 
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertFirst (List * L, address P){
	// Kamus Lokal
	address Last;	

	// Algoritma
	if(ListEmpty(*L)){ 
		First(*L) = P;
		next(P) = First(*L);
	}
	else{
		Last = First(*L);
		while(next(Last) != First(*L)){ //mencari last
			Last = (next(Last));
		}
		next(P) = First(*L); //memasukkan P
		First(*L) = P;
	
		next(Last) = First(*L);	 //menyambungkan next last ke first L
	}
}

/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/* P sudah dialokasi */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertAfter (List * L, address P, address Prec){
	// Kamus Lokal

	// Algoritma
	if(ListEmpty(*L)){
		InsertFirst(&(*L), P);
	}
	else{
		next(P) = next(Prec);
		next(Prec) = P;
	}
}

/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertLast (List * L, address P){
	//kamus lokal
	address Last;
	//algoritma
	if(ListEmpty(*L)){ 
		InsertFirst(L, P);
	}
	else{
		Last = First(*L); //menemukan last
		while(next(Last) != First(*L)){
			Last = (next(Last));
		}
		InsertAfter(&(*L),P,Last);
		next(P) = First(*L);
	}
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelFirst (List * L, address * P){
	// Kamus Lokal
	address Last;

	// Algoritma
	if(!ListEmpty(*L)){
		Last = First(*L); //mencari address last
			while(next(Last) != First(*L)){ 
				Last = (next(Last));
			}
		(*P) = First(*L); //menyimpan first(L)
		First(*L) = next(First(*L));
		next(*P) = Nil;
		next(Last) = First(*L);
	}
}

/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelP (List * L, infotype X){
	// Kamus Lokal
	address *Prec;
	address P;
	address Last;

	// Algoritma	
	if(P=First(*L)){
		DelFirst(&(*L), &P);
	}
	else{
		Last = First(*L);
		while(next(Last) != First(*L)){ //mencari last
			Last = (next(Last));
		}
		*Prec = First(*L);
		while(next(*Prec) != P){
			(*Prec) = next(*Prec);
		}
		DelAfter(L, &P, *Prec);
		if(*Prec == Last){
			next(P) = First(*L);
		}
		else{
			next(Last) = First(*L);
		}
	}
}

/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelLast (List * L, address * P){
	// Kamus Lokal
	address PrecLast, Last;
	
	// Algoritma
	if(!ListEmpty(*L)){
		Last = First(*L);
		PrecLast = Nil;
		while(next(Last) != First(*L)){
			PrecLast = Last;
			Last = next(Last);
		}
		(*P) = Last;
		if(PrecLast == Nil){
			First(*L) = Nil;
		}
		else{
			next(PrecLast) = First(*L);
		}
	}
}

/* I.S. List tidak kosong. Prec adalah anggota list */
/* F.S. Menghapus Next(Prec): */
/* Pdel adalah alamat elemen list yang dihapus */
void DelAfter (List * L, address * Pdel, address Prec){
	// Kamus Lokal

	// Algoritma
	if(!ListEmpty){
		*Pdel = next(Prec);
		next(Prec) = next(next(Prec));
		next(*Pdel) = Nil;
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
	if(!ListEmpty(L)){
		P = First(L);
		do{printf("%d;", info(P));
		(P) = next(P);
		}while(P != First(L));
	}
	printf("\n");
}

/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */ 
int NbElmt (List L) {
	// Kamus Lokal
	address P;
	int i = 0;
	
	// Algoritma
	P = First(L);
	do{
		i++;
		P = next(P);
	}
	while(P!=First(L));
	return i;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
/* Mengirimkan nilai info(P) yang maksimum */
infotype Max (List L){
	// Kamus Lokal
	address P;
	infotype max = -999;

	// Algoritma
	P = First(L);
	max = info(First(L));
	do{
		if(info(P) > max){
			max = info(P);
		}
		P = next(P);
	}
	while(P!=First(L));
	return max;
}

/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
address AdrMax (List L){
    // Kamus Lokal
    infotype max;
    address P;

    // Algoritma
    max = Max(L);
    P = Search(L,max);
    return P;
}

/* Mengirimkan nilai info(P) yang minimum */
infotype Min (List L){
    // Kamus Lokal
    infotype min;
    address P;
    
    // Algoritma
    P = First(L);
    min = info(P);
    P = next(P);
    do{
      if(min>info(P)){
        min = info(P);
      }
      P = next(P);
    }
    while(P!=First(L));
    return min;
}

/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
address AdrMin (List L){
	// Kamus Lokal
	address P;
	infotype min;
	
	// Algoritma
	min = Min(L);
	P = Search(L, min);
	return P;
}

/* Mengirimkan nilai rata-rata info(P) */ 
infotype Average (List L){
	// Kamus Lokal
	address P;
	float jumlah;
	
	// Algoritma
	P = First(L);
	jumlah = info(P);
	P = next(P);
	while(P != First(L)){
		jumlah = jumlah + info(P);
		P = next(P);
	}
	printf("%.2f", jumlah / NbElmt(L));
}

/****************** PROSES TERHADAP LIST ******************/
/* Delete semua elemen list dan alamat elemen di-dealokasi */
void DelAll (List *L){
	// Kamus Lokal
	address P;
	
	// Algoritma
	while (!ListEmpty(*L)){
		DelFirst(L, &P);
	}
}

/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
void InversList (List *L){
	// Kamus Lokal
    address P,Q, temp;
	
	// Algoritma
    P = First(*L);
    Q = Nil;
    do{
        temp = next(P);
        next(P) = Q;
        Q = P;
        P = temp;
    }
    while(P != (First(*L)));
	First(*L) = Q;
}

/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
List FInversList (List L){
    // Kamus Lokal
    List ListBaru;	
    address P, Q;
    boolean gagal = false;
	
	// Algoritma
    CreateList(&ListBaru);
    P = First(L);
    do{
		Q = Alokasi(info(P));
		if(Q != Nil){
			InsertFirst(&ListBaru, Q);
			P = next(P);
		}
		else{
			DelAll,(&ListBaru);
			gagal = true;
		}
	}
	while ((P != First(L)) && (!gagal));
    return ListBaru;
}

/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
void CopyList(List * L1, List *L2){
    // Kamus Lokal
    
    // Algoritma
    First(*L2) = First(*L1);
}

/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */
List FCopyList (List L){
    // Kamus Lokal
    address P, Q;
    List NewList;
    boolean gagal = false;

    // Algoritma
    CreateList(&NewList);
    P = First(L);
    while ((P != Nil)&&(!gagal)) {
		Q = Alokasi(info(P));
		if (Q != Nil) {
			InsertLast(&NewList,Q);
			P = next(P);
		}
		else{
			gagal = true;
			DelAll(&NewList);
      }
    }
    return NewList;
}

/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur
dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */ 
void CpAlokList (List Lin, List *Lout) {
    // Kamus Lokal
    address P, Q;
    boolean gagal = false;
    
    // Algoritma
    CreateList(Lout);
    P = First(Lin);
    while ((P != Nil)&&(!gagal)){
		Q = Alokasi(info(P));
		if (Q != Nil) {
			InsertLast(Lout,Q);
			P = next(P);
		}
		else{
			gagal = true;
			DelAll(Lout);
		}
    }
}

/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
/* harus di-dealokasi dan L3=Nil*/
/* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang �baru� */
/* Elemen L3 adalah hasil alokasi elemen yang â€œbaruâ€. */
/* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
/* dan semua elemen yang pernah dialokasi didealokasi */
void Konkat (List L1, List L2, List *L3) {
    // Kamus Lokal
    address P, Q, Last;
    boolean gagal = false;

    // Algoritma
    P = First(L1);
    do{
		Q = Alokasi(info(P));
		if (Q != Nil) {
		    InsertLast(&(*L3),Q);
		    P = next(P);
		}
		else{
			gagal = true;
			DelAll(L3);
		}
	}
	while((P != First(L1))&&(!gagal));
    if(!gagal){
		P = First(L2);
		Last = First(L2);
		do{
			Q = Alokasi(info(P));
			if(Q != Nil){
				InsertLast(&(*L3),Q);
				P = next(P);
        	}
			else{
				gagal = true;
				DelAll(L3);
	        }
		}
		while((P != First(L2))&&(!gagal));
    }
}

/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2 */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2)*/
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
void Konkat1(List * L1, List * L2, List * L3){
	// Kamus Lokal
	address P, Last;
	
	// Algoritma
	if(First(*L1) == Nil){
		First(*L3) = First(*L2);
	}
	else{
		First(*L3) = First(*L1);
		P = First(*L3);
		Last = First(*L3);
		while(next(P) != First(*L3)){
			P = next(P);
			Last = next(Last);
		}
		next(P) = First(*L2);
		next(Last) = First(*L2);
		do{
			Last = next(Last);
		}
		while(next(Last) != First(*L2));
		next(Last) = First(*L3);
		First(*L1) = Nil;
		First(*L2) = Nil;
	}
}
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */
void PecahList (List *L1, List *L2, List L) {
    // Kamus Lokal
    address P, Q;
    boolean gagal = false;
    int i = 1;
	int N;
    
    // Algoritma
    if(!ListEmpty(L)){
	    CreateList(L1); //mengkosongkan list1 dan list2
	    CreateList(L2);
	    N = NbElmt(L)/2;
	    P = First(L);
	    do{
			Q = Alokasi(info(P));
			if(i<=N){
	        	if(Q!= Nil){
					InsertLast(L1,Q);
					P = next(P);
					i++;
	       		}
				else{
					gagal = true;
					DelAll(L1);
	        	}
	       }
			else{
	        	if (Q != Nil) {
					InsertLast(L2,Q);
					P = next(P);
					i++;
	        }
				else{
					gagal = true;
					DelAll(L2);
	        }
	      }
	    }
	    while((P != First(L))&&(!gagal));
	}
}