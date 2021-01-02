/* Program   : tqueue.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model I: head selalu di posisi 0 atau 1 */
/* NIM/Nama  : 24060119120027/Iwan Suryaningrat */
/* Tanggal   : 24 September 2020*/
/***********************************/

#include <stdio.h>
#include "tqueue1.h"
#include "boolean.h"

/*procedure createQueue ( output Q:tQueue)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dan elemen dengan ' ' }*/ 
void createQueue(tqueue *Q)
{
	//kamus lokal
	int i;
	
	//algortima
	(*Q).head = 0;
	(*Q).tail = 0;
	for (i=1;i<6;i++){
		(*Q).wadah[i] = ' ';
	}
}

/*function Head(Q:tQueue)-> integer 
{mengembalikan elemen terdepan antrian Q} */
int Head(tqueue Q){
	//kamus lokal
	
	//algortima
	return Q.head;
}

/*function Tail(Q:tQueue)-> integer 
{mengembalikan elemen terakhir antrian Q} */
int Tail(tqueue Q){
	//kamus lokal
	
	//algortima
	return Q.tail;
}

/*function infoHead(Q:tQueue)-> character 
{mengembalikan nilai elemen terdepan antrian Q} */
int infoHead(tqueue Q){
	//kamus lokal
	
	//algortima
	if (!isEmptyQueue(Q)){
		return Q.wadah[Q.head];
	}
}

/*function infoTail(Q:tQueue)-> character 
{mengembalikan nilai elemen terakhir antrian Q} */
int infoTail(tqueue Q){
	//kamus lokal
	
	//algoritma
	if (isEmptyQueue(Q) == false){
		return Q.wadah[Q.tail];
	}
}

/*function sizeQueue(Q:tQueue)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue(tqueue Q){
	//kamus lokal
	
	//algortima
	if (isOneElement(Q) == true){
		return 1;
	// } else{ (isOneElement(Q) == false)
		return Q.tail - Q.head;
	}
}

/*procedure printQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua elemen wadah ke layar}*/
void printQueue(tqueue Q){
	//kamus lokal
	int i;
	
	//algoritma
	for (i=1;i<6;i++){
		printf ("%c, ",Q.wadah[i]);
	}
}

/*procedure viewQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen Queue yang terisi, ke layar}*/
void viewQueue(tqueue Q){
	//kamus lokal
	int i;
	
	//algoritma
	for (i=1;i<6;i++){
		if (Q.wadah[i] != ' '){
			printf ("%c, ",Q.wadah[i]);
		}
	}
}

/*function isEmptyQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue(tqueue Q){
	//kamus lokal
	
	//algoritma
	if (Q.head == 0){
		return true;
	} else { // (Q.head != 0)
		return false;
	}
}

/*function isFullQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue(tqueue Q){
	//kamus lokal
	
	//algoritma
	if (Q.tail == 5){
		return true;
	} else { // (Q.tail != 5)
		return false;
	}
}

/*function isOneElement(Q:tQueue) -> boolean
{mengembalikan true jika hanya ada 1 elemen }*/
boolean isOneElement(tqueue Q){
	//kamus lokal
	
	//algoritma
	if (Q.tail == 1 && Q.head == 1){
		return true;
	} else { // (Q.tail != 1 && Q.head != 1)
		return false;
	}
}

/*procedure enqueue( input/output Q:tQueue, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1, bila belum penuh}
{proses: menambah elemen wadah Q } */
void enqueue(tqueue *Q, int E){
	// Kamus lokal

	// Algoritma
	if (isFullQueue(*Q) == false){
		(*Q).tail = (*Q).tail + 1;
		(*Q).wadah[(*Q).tail] = E;
	}
}
  
/*procedure deQueue( input/output Q:tQueue, output E: character )
{I.S.: }
{F.S.: E=infohead(Q) atau E=' ' bila Q kosong, elemen wadah Q berkurang 1 }
{proses: mengurangi elemen wadah Q, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail menjadi 0 } */
void dequeue(tqueue *Q, int *E){
	// Kamus lokal
	int i;

	// Algoritma
	if (isEmptyQueue(*Q) == false){
		(*E) = infoHead(*Q);
		if (isOneElement(*Q) == true){
			(*Q).wadah[*E] = ' ';
			(*Q).head = 0;
			(*Q).tail = 0;
		} else{
			(*Q).wadah[*E] = ' ';
			for (i = (*E); i < (*Q).tail; i++){
				(*Q).wadah[i] = (*Q).wadah[i+1];
			}
		}
	} else{ // (isEmptyQueue(*Q) == true)
		(*E) = ' ';
	}
}

/*tambahan*/
/*procedure enqueue2( input/output Q1:tQueue, input/output Q2:tQueue, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q1 atau Q2 bertambah 1, bila belum penuh}
{proses: menambah elemen wadah pada antrian terpendek dari Q1 atau Q2} */
void enqueue2(tqueue *Q1, tqueue *Q2, int E){
	// Kamus lokal

	// Algoritma
	if (sizeQueue(*Q1) < sizeQueue(*Q2)){
		if (isFullQueue(*Q1) == false){
			(*Q1).tail = (*Q1).tail + 1;
			(*Q1).wadah[(*Q1).tail] = E;
		}
	} else{ // (sizeQueue(*Q1) > sizeQueue(*Q2))
		if (isFullQueue(*Q2) == false){
			(*Q2).tail = (*Q2).tail + 1;
			(*Q2).wadah[(*Q2).tail] = E;
		}
	}
}

/*procedure deQueue2( input/output Q1:tQueue, input/output Q2:tQueue, output E: character )
{I.S.: }
{F.S.: E=infohead Q1 atau Q2 atau E=' ' bila Q1 dan Q2 kosong, elemen wadah Q1 atau Q2 berkurang 1 }
{proses: mengurangi elemen wadah antrian terpanjang Q1 atau Q2, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail antrian menjadi 0 } */
void dequeue2(tqueue *Q1, tqueue *Q2, int *E){
	// Kamus lokal
	int i;

	// Algoritma
	if (!isEmptyQueue(*Q1) || !isEmptyQueue(*Q2)){
		if (sizeQueue(*Q1) > sizeQueue(*Q2)){
			if (isOneElement(*Q1) == true){
				(*Q1).wadah[*E] = ' ';
				(*Q1).head = 0;
				(*Q1).tail = 0;
			} else{
				(*Q1).wadah[*E] = ' ';
				for (i = (*E); i < (*Q1).tail; i++){
					(*Q1).wadah[i] = (*Q1).wadah[i+1];
				}
			}
		} else{ // (sizeQueue(*Q1) < sizeQueue(*Q2))
			if (isOneElement(*Q2) == true){
				(*Q2).wadah[*E] = ' ';
				(*Q2).head = 0;
				(*Q2).tail = 0;
			} else{
				(*Q2).wadah[*E] = ' ';
				for (i = (*E); i < (*Q2).tail; i++){
					(*Q2).wadah[i] = (*Q2).wadah[i+1];
				}
			}
		}
	}
}
