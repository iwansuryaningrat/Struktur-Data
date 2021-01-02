/***********************************/
/* Program   : mainlist.c */
/* Deskripsi : file BODY modul stack berkait */
/* NIM/Nama  : 24060119120027/Iwan Suryaningrat*/
/* Tanggal   : 14 November 2020*/
/***********************************/

/* contoh ADT list berkait dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#include <stdio.h>
#include "list.c"
#include "boolean.h"

int main(){   
    //KAMUS
    List A,B,C;
    address P,Prec,Lt;
    int X;
    
    //ALGORITMA
    CreateList (&A);
    CreateList (&B);
    CreateList (&C);

    P = Alokasi(1);
    Prec = Alokasi(3);

    InsertFirst(&A,P);
    printf("elemen awal : ");
    Printinfo(A);

    InsVFirst (&A,3);
    printf("\nsetelah Insfirst 3 : ");
    Printinfo(A);

    InsVLast (&A,6);
    printf("\nsetelah InsVLast 6 : ");
    Printinfo(A);

    InsVAfter(&A,2,P);
    printf("\nsetelah InsVAfter : ");
    Printinfo(A);

    DelVFirst(&A,&X);
    printf("\nsetelah DelVFirst : ");
    Printinfo(A);
    printf("Elemen yang diambil %d\n",X);

    DelVLast (&A,&X);
    printf("\nsetelah DelVLast : ");
    Printinfo(A);
    printf("Elemen yang diambil : %d\n",X);

    DelVAfter (&A,&X,P);
    printf("\nsetelah DelVAfter : ");
    Printinfo(A);
    printf("Elemen yang diambil : %d",X);

    InsVFirst(&B,8);
    InsVLast(&B,9);
    InsVLast(&B,10);
    printf("\n\nElemen A : ");
    Printinfo(A);
    printf("Elemen B : ");
    Printinfo(B);
    Konkat(A,B,&C);
    printf("\nList setelah Konkat : ");
    Printinfo(C);

    printf("banyak elemen : %d",NbElmt(C));

    DelAll(&A);
    printf("\n\nElemen A setelah DelAll : ");
    Printinfo(A);

    B = FInversList(B);
    printf("Elemen B setelah invers : ");
    Printinfo(B);
    printf("Elemen yang dicari di B : ");
    scanf("%d",&X);
     
    P = Search(B,X);
    printf("Banyak di B : %d\n",P);
    Konkat1(&A,&B,&C);
    printf("\nElemen A setelah Konkat1 : ");
    Printinfo(A);
    printf("\nElemen B setelah Konkat1 : ");
    Printinfo(B);
    printf("\nElemen C setelah Konkat1 : ");
    Printinfo(C);
    List L1,L2,L;
    CreateList(&L1);
    CreateList(&L2);
    CreateList(&L);
    InsVFirst(&L,1);
    InsVLast(&L,2);
    PecahList (&L1,&L2,C);
    printf("\nElemen L1 setelah PecahList dari C : ");
    Printinfo(L1);
    printf("\nElemen L2 setelah PecahList dari C : ");
    Printinfo(L2);

    CpAlokList(L1,&L);
    Printinfo(L);

    P = Average(C);
    printf("Rata rata elemen List C : %d\n",P);

    return 0;
}