#ifndef tqueue3_H
#define tqueue3_H 
#include "boolean.h"

/* Program   : tqueue3.h */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model III: head memutar searah jarum jam */
/* NIM/Nama  : 24060119120027/Iwan Suryaningrat*/
/* Tanggal   : 1 Oktober 2020*/
/***********************************/

/* type tQueue3 = < wadah: array [1..5] of integer ,
				head: integer ,
				tail: integer >
{cara akses: Q:tQueue3, Q.head=head(Q) ...} */
typedef struct { char wadah[6]; 
                  int head; 
                  int tail; 
				} tqueue3;

/*function isEmptyQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue3(tqueue3 Q);
 
/*function isFullQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue3(tqueue3 Q);

/*function isOneElement3(Q:tQueue3) -> boolean
{mengembalikan true jika Q 1 elemen}*/
boolean isOneElement3(tqueue3 Q);

/*procedure createQueue3 ( output Q:tQueue3)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dan elemen dengan nil}*/ 
void createQueue3(tqueue3 *Q);

/*Function Head3(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terdepan} */
int head3(tqueue3 Q);

/*Function Tail3(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terakhir} */
int tail3(tqueue3 Q);

/*Function InfoHead3(Q:Tqueue2) -> character
{mengembalikan nilai elemen terdepan} */
char infoHead3(tqueue3 Q);

/*Function InfoTail3(Q:Tqueue2) -> character
{mengembalikan nilai elemen terakhir} */
char infoTail3(tqueue3 Q);

/*function sizeQueue3(Q:tQueue3)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue3(tqueue3 Q);

/*procedure printQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak kondisi wadah ke layar}*/
void printQueue3(tqueue3 Q);

/*procedure viewQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen Queue yang terisi ke layar}*/
void viewQueue3(tqueue3 Q);

/*procedure enQueue3( input/output Q:tQueue3, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q sebagai tail } */
void enqueue3(tqueue3 *Q, char E);
  
/*procedure deQueue3( input/output Q:tQueue3,output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q), bila kosong E=' '}
{proses: mengurangi elemen wadah Q, bila 1 elemen, maka Head dan Tail mengacu ke 0 } */
void dequeue3(tqueue3 *Q, char *E);

#endif
