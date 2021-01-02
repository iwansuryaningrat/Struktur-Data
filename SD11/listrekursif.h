/************************************/
/* Program   : listrekursif.c */
/* Deskripsi : realisasi body modul list */
/* NIM/Nama  : 24060119120027/Iwan Suryaningrat*/
/* Tanggal   : 3 Desember 2020*/
/***********************************/

/* contoh ADT list berkait dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#ifndef list1_H
#define list1_H
#include <stdlib.h>
#include "boolean.h"
#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define First(L) ((L).First)

typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist { 
    infotype info;
    address next;
} ElmtList;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */
typedef address List;

/* Mengirim true jika list kosong */
boolean IsEmptyList (List L);

/* I.S. sembarang */
/* F.S. Terbentuk list kosong */
void CreateList (List *L);
	
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
address Alokasi (infotype X);

/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
void Dealokasi (address P);
	
/* mengirimkan list L dengan tambahan e sebagai elemen pertamanya */
/* jika alokasi gagal, mengirimkan L */
List Konso (List L, infotype e);

/* mengirimkan list L dengan menambah e sebagai elemen terakhir */
/* jika alokasi gagal, mengirimkan L */
List Kons0(List L, infotype e);

/* I.S. L terdefinisi */
/* F.S. Setiap elemen lisst diprint */
void Printlist (List L);

/* mengirimkan banyaknnya elemen list L, nol jika L kosong */
int NBElmtlist(List L);

/* I.S. L terdefinisi */
/* F.S. N berisi banyaknya elemen list */
void NBElmtlist1(List L, int *N);

/* I.S. L terdefinisi */
/* F.S. N berisi banyaknya elemen list */
void NBElmtlistAcc(List L, int Acc, int *N);

/* mengirim true jika X adalah anggota list, false jika tidak */
boolean Search(List L, infotype X);

/* mengirimkan elemen pertama sebuah list L yang tidak kosong */
infotype FirstElmt(List L);

/* mengirimkan elemen terakhir sebuah list L yang tidak kosong */
infotype LastElmt(List L);

/* mengirimkan list L tanpa elemen pertamanya, mungkin yang dikirimkan adalah list kosong */
List Tail(List L);

/* mengirimkan list L tanpa elemen terakhirnya, mungkin yang dikirimkan adalah list kosong */
List Head(List L);

/* mengirimkan salinan list L */
/* jika alokasi gagal, mengirimkan L */
List Copy(List L);

/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */
/*jika alokasi gagal, Lout adalah ??? */
void MengCopy(List Lin, List *Lout);

/* mengirimkan salinan hasil konkatenasi list L1 dan L2 */
List Concat(List L1, List L2);

/* mengirimkan salinan hasil konkatenasi list L1 dan L2 */
List Concat1(List L1, List L2);

/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi List L1 dan L2 */
void Mengconcat(List L1, List L2, List *LHsl);

#endif