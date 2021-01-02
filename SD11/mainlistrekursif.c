/************************************/
/* Program   : listrekursif.c */
/* Deskripsi : realisasi body modul list */
/* NIM/Nama  : 24060119120027/Iwan Suryaningrat*/
/* Tanggal   : 3 Desember 2020*/
/***********************************/

#include <stdio.h>
#include "listrekursif.c"

int main(){
	// Kamus
	List L,M,N,O,P,Q,R;
	CreateList (&L);
	CreateList (&M);
	CreateList (&N);
 	CreateList (&O);
 	CreateList (&P);
 	CreateList (&Q);
	int a;
	int Acc;
	int b;
	
	// Realisasi
	if (IsEmptyList(L)){
		printf("List Kosong\n");
	}
	else{
		printf("List tidak Kosong\n");
	}
	
	printf("Konso (menambah didepan list)\n L : ");
	L = Konso (L, 2);
	L = Konso(L, 7);
	Printlist (L);
	printf("\n\n");
	
	printf("Kons0 (menambah diakhir list)\n L : ");
	L = Kons0(L, 9);
	Printlist (L);
	printf("\n\n");
	
	printf("Jumlah elemen L : ");
	printf("%d\n", NBElmtlist(L));
	printf("Jumlah elemen L : ");
	NBElmtlist1(L, &a);
	printf("%d\n", a);
	printf("Jumlah elemen L : ");
	NBElmtlistAcc(L, 0, &b);
	printf("%d\n\n", b);
	
	if (Search(L, 7)){
		printf("Elemen ditemukan\n\n");
	}
	else{
		printf("Elemen tidak ditemukan\n\n");
	}
	
	printf("Elemen pertama L : %d\n\n", FirstElmt(L));
	
	printf("Elemen terakhir L : %d\n\n", LastElmt(L));
	
	printf("Tail dari L :\n ");
	Q = Tail(L);
	Printlist (Q);
	printf("\n\n");
	
	printf("Head dari L :\n ");
	Q = Head(L);
	Printlist (Q);
	printf("\n\n");

	printf("Copy L ke M\n M : ");
	M = Copy(L);
	Printlist (M);
	printf("\n\n");
	
	printf("MengCopy L ke N\n N : ");
	MengCopy(L, &N);
	Printlist (N);
	printf("\n\n");
	
	printf("Concat (menggabung L dan M)\n O : ");
	O = Concat(L, M);
	Printlist (O);
	printf("\n\n");
	
	printf("Concat1 (menggabung L dan M)\n P : ");
	P = Concat1(L, M);
	Printlist (P);
	printf("\n");
	
	printf("Mengconcat (menggabung L dan N)\n R : ");
	Mengconcat(L, N, &R);
	Printlist (R);
	printf("\n");
}
