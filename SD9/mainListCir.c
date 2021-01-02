/************************************/
/* Program   : mainListCir.c */
/* Deskripsi : aplikasi driver modul list */
/* NIM/Nama  : 24060119120027/Iwan Suryaningrat*/
/* Tanggal   : 19 November 2020*/
/***********************************/

#include <stdio.h>
#include "listCir.c"

int main(){
	// Kamus Utama
	List A, B, C, D, E, F, G, H;
	address M, N, O, P, Q, R;
	infotype X;
	
	// Algoritma
	/****************** PEMBUATAN LIST KOSONG ******************/
	CreateList(&A);
	CreateList(&B);
	
	/****************** TEST LIST KOSONG ******************/
	printf("Apakah List Kosong ? : ");
	if (ListEmpty(A)){
		printf("List Kosong\n\n");
	}
	else{
		printf("List Tidak Kosong\n\n");
	}
	
	printf("Insert First\n A : ");
	M = Alokasi(11);
	InsertFirst (&A, M);
	N = Alokasi(23);
	InsertFirst (&A, N);
	O = Alokasi(34);
	InsertFirst (&A, O);
	Printinfo(A);
	printf("\n\n");
	
	printf("Insert After (Menambah 45 setelah 34)\n A : ");
	P = Alokasi(45);
	InsertAfter (&A, P, O);
	Printinfo(A);
	printf("\n\n");
	
	printf("Insert last\n A : ");
	Q = Alokasi(56);
	InsertLast (&A, Q);
	Printinfo(A);
	printf("\n\n");
	
	printf("Delete First\n A : ");
	DelFirst (&A, &R);
	Printinfo(A);
	printf("\n\n");
	
	printf("Delete P (P = 45)\n A : ");
	DelP (&A, 45);
	Printinfo(A);
	printf("\n\n");
	
	printf("Delete Last\n A : ");
	DelLast (&A, &R);
	Printinfo(A);
	printf("\n\n");
	
	printf("Delete After (Menghapus elemen setelah 34)\n L : ");
	DelAfter (&A, &R, O);
	Printinfo(A);
	printf("\n\n");
	
	printf("InsV First\n B : ");
	InsVFirst (&B, 75);
	InsVFirst (&B, 85);
	InsVFirst (&B, 95);
	Printinfo(B);
	printf("\n\n");
	
	printf("InsV Last\n B : ");
	InsVLast (&B, 90);
	Printinfo(B);
	printf("\n\n");
	
	printf("DelV First\n B : ");
	DelVFirst (&B, &X);
	Printinfo(B);
	printf("\n\n");
	
	printf("DelV Last\n B : ");
	DelVLast (&B, &X);
	Printinfo(B);
	printf("\n\n");
	
	printf("Search (Mencari alamat dengan elemen 85)\n Alamat/address : ");
	printf("%d", Search(B, 85));
	printf("\n\n");
	
	printf("FSearch (Menentukan apakah alamat P ditemukan pada list A, alamat P sebelumnya dialokasikan dengan nilai 45)\n Alamat/address : ");
	if(FSearch (A, P) == true){
		printf("alamat ditemukan");
	}
	else{
		printf("alamat tidak ditemukan");
	}
	printf("\n\n");
	
	printf("Search Prec (Mencari alamat sebelum elemen 95)\n Alamat/address : ");
	printf("%d", SearchPrec (B, 95, &R));
	printf("\n\n");
	
	printf("Jumlah elemen List B : ");
	printf("%d", NbElmt(B));
	printf("\n\n");
	
	printf("Max (Mengoutput elemen terbesar dari list B)\n Max : ");
	printf("%d", Max (B));
	printf("\n\n");
	
	printf("Address Max (Mengoutput alamat elemen terbesar dari list B)\n Alamat/address : ");
	printf("%d", AdrMax (B));
	printf("\n\n");
	
	printf("Min (Mengoutput elemen terkecil dari list B)\n Min : ");
	printf("%d", Min (B));
	printf("\n\n");
	
	printf("Address Min (Mengoutput alamat elemen terkecil dari list B)\n Alamat/address : ");
	printf("%d", AdrMin (B));
	printf("\n\n");
	
	printf("Average (Mencari rata rata dari elemen list B)\n Average : ");
	Average (B);
	printf("\n\n");
	
	printf("Invers List (Mengoutput invers list B, B berubah)\n B : ");
	InversList (&B);
  	Printinfo(B);
	printf("\n\n");
	
	printf("FInvers List (Menyalin invers list B, B tidak berubah)\n B : ");
	FInversList (B);
	printf("\n\n");
	
	printf("Copy List (Mengoutput hasil copy list B yang disalin ke list C)\n C : ");
	CopyList (&B,&C);
	Printinfo(C);
	printf("\n\n");
	
	printf("FCopy (Mengoutput hasil copy list B)\n B : ");
	FCopyList (B);
	printf("\n\n");
	
	printf("CpAlok List (Mengoutput hasil copy list B yang disalin ke list D dengan alokasi)\n D : ");
	CpAlokList (B, &D);
	Printinfo(D);
	printf("\n\n");
	
	printf("Konkat (Menggabung list A dan B menghasilkan list E)\n E : ");
	Konkat (A, B, &E);
	Printinfo(E);
	printf("\n\n");
	
	printf("Konkat1 (Menggabung List C dan D menghasilkan List F, List C dan D dikosongkan)\n F : ");
	Konkat1 (&C,&D,&F);
	Printinfo(F);
	printf("\n C :");
	Printinfo(C);
	printf("\n D :");
	Printinfo(D);
	printf("\n\n");
	
	printf("Pecah List (memecah list F)\n G : ");
	PecahList (&G, &H, F);
	Printinfo(G);
	printf("\n H : ");
	Printinfo(H);
	printf("\n\n");
	
	printf("DelAll (Menghapus list B)\n B : ");
	DelAll(&B);
	Printinfo(B);

	return 0;
}