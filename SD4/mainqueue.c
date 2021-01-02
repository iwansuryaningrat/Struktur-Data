/* Program   : mainqueue.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model I: head selalu di posisi 0 atau 1 */
/* NIM/Nama  : 24060119120027/Iwan Suryaningrat */
/* Tanggal   : 24 September 2020*/
/***********************************/

#include <stdio.h>
#include "tqueue.c"
#include "boolean.h"

int main (){
	//kamus
	tqueue A;
	tqueue B;
	char X;
	int Y;
	int Z;

	//algoritma
	createQueue(&A);
	printf ("\n");
	
	printf ("%d\n",Head(A));
	printf ("%d\n",Tail(A));
	printf ("%c\n",infoHead(A));
	printf ("%c\n",infoTail(A));
	printf ("%d\n",sizeQueue(A));

	printQueue(A);
	printf ("\n");
	viewQueue(A);
	
	// isEmptyQueue(A)
	printf ("\n");
	if (isEmptyQueue(A) == true){
		printf ("Queue kosong\n");
	} else {
		printf ("Queue tidak kosong\n");
	}

	// isFullQueue(A)
	if (isFullQueue(A) == true){
		printf ("Queue penuh\n");
	} else {
		printf ("Queue tidak penuh\n");
	}
	// isOneElement(A)
	if (isOneElement(A) == true){
		printf ("Queue hanya 1 element\n");
	} else {
		printf ("Queue kosong atau lebih dari 1 element\n");
	}

	enqueue(&A, 'X');
	printQueue(A);
	printf ("\n");
	viewQueue(A);
	printf ("\n");

	dequeue(&A, &Y);
	printQueue(A);
	printf ("\n");
	viewQueue(A);
	printf ("\n");

	enqueue2(&A, &B, 'X');

	dequeue2(&A, &B, &Z);	

	return 0;	
}
