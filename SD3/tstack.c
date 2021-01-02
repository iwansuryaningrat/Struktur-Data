/* Program   :  */
/* Deskripsi : */
/* NIM/Nama  : 24060119120027/Iwan Suryaningrat*/
/* Tanggal   :  September 2020*/
/***********************************/

#include <stdio.h>
#include "tstack.c"

/* type tstack = < wadah : array[1..10] of character,
                   top   : integer > */
typedef struct{
  char wadah[11];
  int top;
} tstack;

/*procedure createStack( output T: tstack)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = ' ' }
	{Proses: menginisialisasi T} */
void createStack (tstack * T){
  // Kamus lokal
  int i;

  // Algoritma
  (*T).top = 0;
  for (i = 1; i < 11; i++)
    {
      (*T).wadah = ' ';
    }
}

/*function top( T: tstack) -> integer
	{mengembalikan posisi puncak stack } */
int top (tstack T){
  // Algoritma
  return T.top;
}

/*function infotop( T: tstack) -> character
	{mengembalikan nilai elemen top stack } */
char infotop (tstack T){
  // Algoritma
  return T.wadah[T.top];
}

/*function isEmptyStack( T: tstack) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStack (tstack T){
    if (T.wadah == 0){
        return true;
    }
    else{
        return false;
    }
}

/*function isFullStack( T: tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack (tstack T){
    if (T.top == 1){
        return true;
    }
    else{
        return false;
    }
}

/*procedure push ( input/output T:tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (tstack * T, char E){
  if (!isFullStack (*T))
    {
      (*T).top++;
      (*T).wadah[(*T).top] = E;
    }
}

/*procedure pop ( input/output T:tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau ' ' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop (tstack * T, char *X){
  if (!isEmptyStack (*T))
    {
      (*X) = infotop (*T);
      (*T).wadah[(*T).top] = ' ';
      (*T).top -= 1;
    }
}

/*procedure printStack ( input T:tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar} 
	{setiap elemen dipisah tanda titik koma } */
void printStack (tstack T){
  // Kamus lokal
  int i;

  // Algoritma
  for (i = 1; i < 11; i++)
    {
      printf (T.wadah[i]);
    }
}

/*procedure viewStack ( input T:tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}  
	{setiap elemen dipisah tanda titik koma } */
void viewStack (tstack T){
    // Kamus lokal
  int i;

  // Algoritma
  for (i = 1; i < 11; i++){
      printf (T.wadah[i]);
      printf (';');
    }
}

/* selanjutnya tugas algoritma palindrom dikerjakan di main */

/* kerjakan prosedur berikut bila tugas palindrom sudah sukses */
/*procedure pushBabel1 ( input/output T:tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) atau menjadi kosong bila penuh }
	{Proses: menumpuk top atau menghapus semua elemen }*/
void pushBabel1 (tstack * T, char E);