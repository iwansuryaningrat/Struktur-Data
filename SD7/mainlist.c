/* File : mainlist.c */
/* contoh ADT list berkait dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* infotype adalah integer */
/* Program   : mainlist.c */
/* Deskripsi : file BODY modul stack berkait */
/* NIM/Nama  : 24060119120027/Iwan Suryaningrat*/
/* Tanggal   : 5 November 2020*/
/***********************************/

#include <stdio.h>
#include "list.c"
#include "boolean.h"

int main(){ 

  //KAMUS----------------------------
  	List L,LA,LB,LC;
  	address P,Q;
  	int Z, X, Y;
	
  //ALGORITMA------------------------
  	
  	CreateList(&L);
  	CreateList(&LA);
  	CreateList(&LB);
  	CreateList(&LC);
  	
  	printf("Nama: Iwan Suryaningrat\nNim: 24060119120027\n");
	printf("\n-----------------------------------------------------------------\nOpsi: \n1. List opsi\n2. ListEmpty?\n3. InsVFirst\n4. InsVLast\n5. DelVFirst\n6. DelVLast\n7. Konkat\n0. Printinfo");
	
	while(1){ //looping ke opsi
		printf("\n\ninput opsi: \n"); 
		scanf("%d", &Z);
		
		if(Z == 1){
			printf("\n-----------------------------------------------------------------\nOpsi: \n1. List opsi\n2. ListEmpty?\n3. InsVFirst\n4. InsVLast\n5. DelVFirst\n6. DelVLast\n7. Konkat\n0. Printinfo");
		}
		else if(Z == 2){
			if(ListEmpty(L)){
				printf("List kosong");
			}
			else{
				printf("List tidak kosong");
			}
		}
		else if(Z == 3){
			printf("input X: ");			
			scanf("%d", &X);
			InsVFirst(&L, X);
		}
		else if(Z == 4){
			printf("input X: ");			
			scanf("%d", &X);
			InsVLast(&L, X);
		}
		else if(Z == 5){
			DelVFirst(&L, &Y);
		}
		else if(Z == 6){
			DelVLast(&L, &Y);
		}
		else if(Z == 7){
			InsVFirst(&LA, 6);
			InsVFirst(&LA, 10);
			InsVFirst(&LB, 4);
			InsVFirst(&LB, 8);
			InsVFirst(&LB, 12);
			
			printf("L1 = ");
			Printinfo(LA);
			
			printf("L2 = ");
			Printinfo(LB);
			Konkat(LA, LB, &LC);
			
			printf("Hasil konkat L1 & L2:\nL3 = ");
			Printinfo(LC);
		}
		else if(Z == 0){
			Printinfo(L);
		}
	}
    return 0;
}