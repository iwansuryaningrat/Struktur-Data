#include <stdio.h>
#include "tqueue2.h"
#include "boolean.h"

/* Program   : tqueue2.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model II: head bergeser/jelajah */
/* NIM/Nama  : 24060119120027/Iwan Suryaningrat*/
/* Tanggal   : 1 Oktober 2020*/
/***********************************/

/* type tQueue2 = < wadah: array [1..5] of character ,
				head: integer ,
				tail: integer >
{cara akses: Q:tQueue2, Q.head=head(Q) ...} */
// typedef struct { char wadah[6]; 
//                   int head; 
//                   int tail 
// 				} tqueue2;

/*function isEmptyQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue2(tqueue2 Q){
	// Kamus lokal

	// Algoritma
	if (Q.head == 0 && Q.tail == 0){
		return true;
	}
	else{
		return false;
	}
}
 
/*function isFullQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue2(tqueue2 Q){
	//kamus lokal
	
	//algoritma
	if (Q.tail == 5){
		return true;
	} else { // (Q.tail != 5)
		return false;
	}
}

/*function isOneElement2(Q:tQueue2) -> boolean
{mengembalikan true jika Q 1 elemen}*/
boolean isOneElement2(tqueue2 Q){
	//kamus lokal
	
	//algoritma
	if (Q.tail == 1 && Q.head == 1){
		return true;
	} 
	else { // (Q.tail != 1 && Q.head != 1)
		return false;
	}
}

/*procedure createQueue2 ( output Q:tQueue2)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dengan 0, elemen ' '}*/ 
void createQueue2(tqueue2 *Q){
	// Kamus lokal
	int i;

	// Algoritma
	(*Q).head = 0;
	(*Q).tail = 0;
	for (i=1;i<6;i++){
		(*Q).wadah[i] = ' ';
	}
}

/*Function Head2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terdepan} */
int head2(tqueue2 Q){
	//kamus lokal
	
	//algortima
	return Q.head;
}

/*Function Tail2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terakhir} */
int tail2(tqueue2 Q){
	//kamus lokal
	
	//algortima
	return Q.tail;
}

/*Function InfoHead2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terdepan} */
char infoHead2(tqueue2 Q){
	//kamus lokal
	
	//algortima
	if (!isEmptyQueue2(Q)){
		return Q.wadah[Q.head];
	}
}

/*Function InfoTail2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terakhir} */
char infoTail2(tqueue2 Q){
	//kamus lokal
	
	//algoritma
	if (!isEmptyQueue2(Q)){
		return Q.wadah[Q.tail];
	}
}

/*function sizeQueue2(Q:tQueue2)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue2(tqueue2 Q){
	//kamus lokal
	
	//algortima
	if (isEmptyQueue2(Q)){
		return 0;
	}
	else{
		if (isOneElement2(Q)){
			return 1;
		}else{ // (isOneElement(Q) == false)
			return Q.tail - Q.head + 1;
		}
	}
}

/*procedure printQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak kondisi wadah ke layar}*/
void printQueue2(tqueue2 Q){
	//kamus lokal
	int i;
	
	//algoritma
	for (i=1;i<6;i++){
		printf ("%c, ",Q.wadah[i]);
	}
}

/*procedure viewQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen Queue yang terisi ke layar}*/
void viewQueue2(tqueue2 Q){
	//kamus lokal
	int i;
	
	//algoritma
	for (i=1;i<6;i++){
		if (Q.wadah[i] != ' '){
			printf ("%c, ",Q.wadah[i]);
		}
	}
}

/*Function IsTailStop2(Q:TQueue2) -> boolean
{mengembalikan true jika Tail tidak dapat lagi geser}
{karena sudah di posisi kapasitas} */
boolean isTailStop2(tqueue2 Q){
	// Kamus Lokal

	// Algoritma
	if (Q.tail == 5){
		return true;
	}
	else{
		return false;
	}
}

/*Procedure ResetHead2(input/output Q:TQueue2)
{I.S:Tail=kapasitas, head>1; F.S:head=1 }
{Proses: mengembalikan Head ke indeks 1 }
{Elemen selain head ikut bergeser menyesuaikan} */
/*CATATAN: di praktikum ini, resetHead dilakukan ketika Enqueue */
void resetHead2(tqueue2 *Q){
    // Kamus lokal
    int i;
    int j;

    // Algoritma
    if(!isEmptyQueue2(*Q)){
        j = 0;
        if((*Q).head > 1 && (*Q).tail == 5){
            for(i = (*Q).head; i <= (*Q).tail; i++){
                j = j + 1;
                (*Q).wadah[j] = (*Q).wadah[i];
                (*Q).wadah[i] = ' ';
            }
            (*Q).head = 1;
            (*Q).tail = j;
        }
    }
}

/*procedure enQueue2( input/output Q:tQueue2, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q, jika tail(Q)=kapasitas, maka semua elemen digeser sehingga head(Q)=1 } */
void enqueue2(tqueue2 *Q, char E){
    // Kamus lokal

    // Algoritma
    if(!isFullQueue2(*Q)){
        if(isTailStop2(*Q)){
            resetHead2(Q);
        }
        else if(isEmptyQueue2(*Q)){
            (*Q).head = (*Q).head + 1;
        }
        (*Q).tail = (*Q).tail + 1;
        (*Q).wadah[(*Q).tail] = E;
    }
    else{
        printf("Queue penuh!!!\n");
    }
    
}
  
/*procedure deQueue2( input/output Q:tQueue2,output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q) lama, bila kosong, E=' '}
{proses: mengurangi elemen wadah Q, bila 1 elemen, maka Head dan Tail mengacu ke 0 } */
void dequeue2(tqueue2 *Q, char *E){
    // Kamus lokal

    // Algoritma
    if(!isEmptyQueue2(*Q)){
        (*E) = infoHead2(*Q);
        if(isOneElement2(*Q)){
            (*Q).head = 0;
            (*Q).tail = 0;
      	    (*Q).wadah[(*Q).head] = ' ';
        }
        else{
        	(*Q).wadah[(*Q).head] = ' ';
            (*Q).head = (*Q).head + 1;
        }
        
    }
    else{
        (*E) = ' ';
        printf("Queue kosong!!!\n");
    }
}

