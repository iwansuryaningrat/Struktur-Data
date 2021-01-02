/* Program   : mainlstack.c */
/* Deskripsi : file DRIVER modul stack berkait */
/* NIM/Nama  : 24060119120027/Iwan Suryaningrat*/
/* Tanggal   : 8 Oktober 2020*/
/***********************************/

#include <stdio.h>
#include "lstack.c"

int main(){ 

	//KAMUS----------------------------
    lstack A;  /*variabel parameter aktual linked Stack */
    address B; /*variabel parameter aktual address */
    int E;
    int X;
    int i;
	
	//ALGORITMA------------------------
	createLStack(&A);
	for (i = 0; i < 5; i++){
		printf("Masukkan Nilai : ");
		scanf("%d", &E);
		pushL(&A, E);
	}
	
	printf("Stacknya adalah: \n");
	viewLStack(A);

	printf("Tinggi lstack:%d\n", tinggiL(A) );

	popL(&A, &X);
	printf("Stacknya adalah: \n");
	viewLStack(A);
	printf("Tinggi lstack:%d\n", tinggiL(A) );

    return 0;
}
