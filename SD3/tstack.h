#ifndef tstack_H
#define tstack_H 

/* Program   : tstack.h */
/* Deskripsi : file HEADER modul stack */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/

#include "boolean.h"

/* type tstack = < wadah : array[1..10] of character,
                   top   : integer > */
typedef	struct { char wadah[11];
                 int  top; 
			   } tstack;
				 
/*procedure createStack( output T: tstack)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = ' ' }
	{Proses: menginisialisasi T} */
void createStack (tstack *T);

/*function top( T: tstack) -> integer
	{mengembalikan posisi puncak stack } */
int top (tstack T);

/*function infotop( T: tstack) -> character
	{mengembalikan nilai elemen top stack } */
char infotop (tstack T);

/*function isEmptyStack( T: tstack) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStack (tstack T);

/*function isFullStack( T: tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack (tstack T);

/*procedure push ( input/output T:tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (tstack *T, char E);

/*procedure pop ( input/output T:tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau ' ' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop (tstack *T, char *X);

/*procedure printStack ( input T:tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar} 
	{setiap elemen dipisah tanda titik koma } */
void printStack (tstack T);

/*procedure viewStack ( input T:tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}  
	{setiap elemen dipisah tanda titik koma } */
void viewStack (tstack T);

/* selanjutnya tugas algoritma palindrom dikerjakan di main */
	
/* kerjakan prosedur berikut bila tugas palindrom sudah sukses */
/*procedure pushBabel1 ( input/output T:tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) atau menjadi kosong bila penuh }
	{Proses: menumpuk top atau menghapus semua elemen }*/
void pushBabel1 (tstack *T, char E);

#endif
