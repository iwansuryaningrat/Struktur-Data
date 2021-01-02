#include <stdio.h>
#include "tqueue3.h"
#include "boolean.h"

/* Program   : tqueue3.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model III: head memutar searah jarum jam */
/* NIM/Nama  : 24060119120027/Iwan Suryaningrat*/
/* Tanggal   : 1 Oktober 2020*/
/***********************************/

/* type tQueue3 = < wadah: array [1..5] of integer ,
				head: integer ,
				tail: integer >
{cara akses: Q:tQueue3, Q.head=head(Q) ...} */
// typedef struct { int wadah[6]; 
//                   int head; 
//                   int tail 
// 				} tqueue3;

/*function isEmptyQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue3(tqueue3 Q){
	// Kamus lokal

	// Algoritma
	if (Q.head == 0 && Q.tail == 0){
		return true;
	}
	else{
		return false;
	}
}
 
/*function isFullQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue3(tqueue3 Q){
	//kamus lokal
	
	//algoritma
	if (Q.tail == 5){
		return true;
	} else { // (Q.tail != 5)
		return false;
	}
}

/*function isOneElement3(Q:tQueue3) -> boolean
{mengembalikan true jika Q 1 elemen}*/
boolean isOneElement3(tqueue3 Q){
	//kamus lokal
	
	//algoritma
	if (Q.tail == 1 && Q.head == 1){
		return true;
	} 
	else { // (Q.tail != 1 && Q.head != 1)
		return false;
	}
}

/*procedure createQueue3 ( output Q:tQueue3)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dan elemen dengan nil}*/ 
void createQueue3(tqueue3 *Q){
	// Kamus lokal
	int i;

	// Algoritma
	(*Q).head = 0;
	(*Q).tail = 0;
	for (i=1;i<6;i++){
		(*Q).wadah[i] = ' ';
	}
}

/*Function Head3(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terdepan} */
int head3(tqueue3 Q){
	//kamus lokal
	
	//algortima
	return Q.head;
}

/*Function Tail3(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terakhir} */
int tail3(tqueue3 Q){
	//kamus lokal
	
	//algortima
	return Q.tail;
}

/*Function InfoHead3(Q:Tqueue2) -> character
{mengembalikan nilai elemen terdepan} */
char infoHead3(tqueue3 Q){
	//kamus lokal
	
	//algortima
	if (!isEmptyQueue3(Q)){
		return Q.wadah[Q.head];
	}
}

/*Function InfoTail3(Q:Tqueue2) -> character
{mengembalikan nilai elemen terakhir} */
char infoTail3(tqueue3 Q){
	//kamus lokal
	
	//algoritma
	if (!isEmptyQueue3(Q)){
		return Q.wadah[Q.tail];
	}
}

/*function sizeQueue3(Q:tQueue3)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue3(tqueue3 Q){
	// Kamus lokal

	// Algoritma
	if (isEmptyQueue3(Q)){
		return 0;
	}
	else{
		if (isOneElement3(Q)){
			return 1;
		}
		else{
			if (Q.head < Q.tail){
				return Q.tail - Q.head + 1;
			}
			else{
				return ((5-Q.head+1) + (Q.tail));
			}
		}
	}
}

/*procedure printQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak kondisi wadah ke layar}*/
void printQueue3(tqueue3 Q){
	//kamus lokal
	int i;
	
	//algoritma
	for (i=1;i<6;i++){
		printf ("%c, ",Q.wadah[i]);
	}
}

/*procedure viewQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen Queue yang terisi ke layar}*/
void viewQueue3(tqueue3 Q){
	//kamus lokal
	int i;
	
	//algoritma
	for (i=1;i<6;i++){
		if (Q.wadah[i] != ' '){
			printf ("%c, ",Q.wadah[i]);
		}
	}
}

/*procedure enQueue3( input/output Q:tQueue3, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q sebagai tail } */
void enqueue3(tqueue3 *Q, char E){
	// Kamus lokal

	// Algoritma
	if (!isFullQueue3(*Q)){
		if (isEmptyQueue3(*Q)){
			(*Q).head = 1;
			(*Q).tail = 1;
			(*Q).wadah[(*Q).tail] = E;
		}
		else{
			(*Q).tail = ((*Q).tail%5) + 1;
			(*Q).wadah[(*Q).tail] = E;
		}
	}
	else{
		printf("Queue Penuh!!");
	}
}
  
/*procedure deQueue3( input/output Q:tQueue3,output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q), bila kosong E=' '}
{proses: mengurangi elemen wadah Q, bila 1 elemen, maka Head dan Tail mengacu ke 0 } */
void dequeue3(tqueue3 *Q, char *E){
	// Kamus lokal

	// Algoritma
	if (!isEmptyQueue3(*Q)){
		(*E) = infoHead3(*Q);
		(*Q).wadah[(*Q).head] = ' ';
		if (isOneElement3(*Q)){
			(*Q).head = 0;
			(*Q).tail = 0;
		}
		else{
			(*Q).head = ((*Q).head % 5) + 1;
		}
	}
	else{
		(*E) = ' ';
	}
}

