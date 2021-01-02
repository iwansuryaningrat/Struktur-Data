/************************************/
/* Program   : MainListGandaLast.c */
/* Deskripsi : aplikasi driver modul list circular*/
/* NIM/Nama  : 24060119120027/Iwan Suryaningrat*/
/* Tanggal   : 26 November 2020*/
/***********************************/
#include <stdio.h>
#include "ListGandaLast.c"

int main(){
	// Kamus Main
	List L;
	address O,P,Q,R,S,T;
	
	// Algoritma
	CreateList(&L);
	
	printf("Insert First : \n L :");
	O = Alokasi(20);
	InsertFirst (&L, O);
	P = Alokasi(25);
	InsertFirst (&L, P);
	Q = Alokasi(30);
	InsertFirst (&L, Q);
	Printinfo (L);
	printf("\n\n");
	
	printf("Insert After : \n L :");
	R = Alokasi(35);
	InsertAfter (&L, R, P);
	Printinfo (L);
	printf("\n\n");
	
	printf("Insert Last : \n L :");
	S = Alokasi(40);
	InsertLast (&L, S);
	Printinfo (L);
	printf("\n\n");
	
	printf("Delete First : \n L :");
	DelFirst (&L, &T);
	Printinfo (L);
	printf("\n\n");
	
	printf("Delete Last : \n L :");
	DelLast (&L, &T);
	Printinfo (L);
	printf("\n\n");
	
	printf("Delete After : \n L :");
	DelAfter (&L, &T, P);
	Printinfo (L);
	printf("\n\n");

return 0;
}
