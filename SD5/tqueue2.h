#ifndef tqueue2_H
#define tqueue2_H
#include "boolean.h"

/* Program   : tqueue2.h */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model II: head bergeser/jelajah */
/* NIM/Nama  : 24060119120027/Iwan Suryaningrat*/
/* Tanggal   : 1 Oktober 2020*/
/***********************************/

/* type tQueue2 = < wadah: array [1..5] of character ,
				head: integer ,
				tail: integer >
{cara akses: Q:tQueue2, Q.head=head(Q) ...} */
typedef struct { char wadah[6]; 
                  int head; 
                  int tail; 
				} tqueue2;

/*function isEmptyQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue2(tqueue2 Q);
 
/*function isFullQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue2(tqueue2 Q);

/*function isOneElement2(Q:tQueue2) -> boolean
{mengembalikan true jika Q 1 elemen}*/
boolean isOneElement2(tqueue2 Q);

/*procedure createQueue2 ( output Q:tQueue2)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dengan 0, elemen ' '}*/ 
void createQueue2(tqueue2 *Q);

/*Function Head2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terdepan} */
int head2(tqueue2 Q);

/*Function Tail2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terakhir} */
int tail2(tqueue2 Q);

/*Function InfoHead2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terdepan} */
char infoHead2(tqueue2 Q);

/*Function InfoTail2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terakhir} */
char infoTail2(tqueue2 Q);

/*function sizeQueue2(Q:tQueue2)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue2(tqueue2 Q);

/*procedure printQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak kondisi wadah ke layar}*/
void printQueue2(tqueue2 Q);

/*procedure viewQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen Queue yang terisi ke layar}*/
void viewQueue2(tqueue2 Q);

/*Function IsTailStop2(Q:TQueue2) -> boolean
{mengembalikan true jika Tail tidak dapat lagi geser}
{karena sudah di posisi kapasitas} */
boolean isTailStop2(tqueue2 Q);

/*Procedure ResetHead2(input/output Q:TQueue2)
{I.S:Tail=kapasitas, head>1; F.S:head=1 }
{Proses: mengembalikan Head ke indeks 1 }
{Elemen selain head ikut bergeser menyesuaikan} */
/*CATATAN: di praktikum ini, resetHead dilakukan ketika Enqueue */
void resetHead2(tqueue2 *Q);

/*procedure enQueue2( input/output Q:tQueue2, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q, jika tail(Q)=kapasitas, maka semua elemen digeser sehingga head(Q)=1 } */
void enqueue2(tqueue2 *Q, char E);
  
/*procedure deQueue2( input/output Q:tQueue2,output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q) lama, bila kosong, E=' '}
{proses: mengurangi elemen wadah Q, bila 1 elemen, maka Head dan Tail mengacu ke 0 } */
void dequeue2(tqueue2 *Q, char *E);

#endif
