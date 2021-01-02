#ifndef lstack_H
#define lstack_H

/* Program   : lstack.h */
/* Deskripsi : file HEADER modul stack berkait */
/* NIM/Nama  : 24060119120027/Iwan Suryaningrat*/
/* Tanggal   : 8 Oktober 2020*/
/***********************************/

/*definisi tipe, primitif, macro*/
#define NIL        NULL
#define top(S)     (S).top
#define infotop(S) (S).top->info
#define info(P)    (P)->info
#define down(P)    (P)->down

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

/*type address = pointer to telms {alamat memori}*/
typedef struct tag_elms* address;

/*type telms = < info: integer ; 
                 down: address
			    > {tipe elemen stack berkait} */
typedef struct tag_elms { int info; 
                           address down; } telms;

/* type lstack = <top: address> {Tumpukan Berkait} */
typedef struct { address top; } lstack;

/*********************************************/
/* Terjemahkan notasi algoritmik ke bahasa C */
/*********************************************/

/*procedure alokasi(input/output P:address,input E:integer)
{I.S.: E terdefinisi}
{F.S.: P terdefinisi info(P) = P^.info = E, atau nil}
{proses: mengalokasi ruang memori untuk nilai E} */
void alokasi(address *P, int E);

/*procedure dealokasi(input/output P:address)
{I.S.: P terdefinisi }
{F.S.: P nil}
{proses: membebaskan ruang memori}*/
void dealokasi(address *P);

/* function isEmptyLStack(S:lstack)-> boolean
{mengembalikan true jika stack kosong} */
boolean isEmptyLStack (lstack S);


/*procedure createLStack( output S:lstack)
{I.S.: -}
{F.s.: S terdefinisi}
{proses: membentuk stack kosong}*/
void createLStack(lstack *S);


/*procedure pushL( input/output S:lstack, input E:integer)
{I.S.: E terdefinisi }
{F.S.: S.top^.info = E atau S tetap}
{proses: memasukkan E sebagai top(S) } */
void pushL(lstack *S, int E);


/*procedure popL( input/output S:lstack, output X:integer)
{proses menghapus top(S), nilainya disalin di X}
{asumsi, jika stack kosong, maka X=-999} */
void popL(lstack *S, int *X);


/*procedure viewLStack( input S:lstack)	 
{I.S.: s terdefinisi }
{F.S.: -}
{proses: menampilkan isi stack ke layar, pesan khusus jika kosong} */
void viewLStack(lstack S);


/*function tinggiL(S:lstack) -> integer 
{menghitung panjang/tinggi/kedalaman tumpukan} */
int tinggiL(lstack S);

#endif