/* Program   : tabel.c */
/* Deskripsi : */
/* NIM/Nama  : 24060119120027/Iwan Suryaningrat*/
/* Tanggal   : 10 September 2020*/
/***********************************/

#include <stdio.h>
#include "tabel.h"

/*procedure createTable( output T: Tabel)
	{I.S.: -}
	{F.S.: size=0, setiap elemen wadah=-999}
	{Proses: menginisialisasi T} */
void creatTabel(tabel *T){
    int i;

    (*T).size = 0;
    for (i = 1; i < 11; i++){
        (*T).wadah = -999;
    }
}

/*procedure printTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen T ke layar} */
void printTable(Tabel T){
    int i;

    for (i = 1; i < 11; i++){
        printf("%d", T.wadah[i]);
    }
}

/*procedure viewTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen T yang terisi ke layar} */
void viewTable (Tabel T){
    int i;
    
    for (i = 1; i < 11; i++){
        if (T.wadah[i] != 0){
            printf("%d", T.wadah[i]);
        }
        else{
            i = i + 1;
        }
    }
}

/*function getStize( T: Tabel) -> integer
	{mengembalikan banyak elemen pengisi T } */
int getSize(Tabel T){
    return T.size;
}

/*function countEmpty( T: Tabel) -> integer
	{mengembalikan banyak elemen T yang belum terisi } */
int countEmpty (Tabel T){
    int i;
    int x = 0;
    
    for ( i = 1; 1 < 11; i++){
        if (T.wadah[i] == 0){
            x = x + 1;
        }
        else{
            i = i + 1;
        }
    }
}

/*function isEmptyTable( T: Tabel) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyTable (Tabel T){
    if (T.size == 0){
        return true;
    }else{
        return false;
    }
}

/*function isFullTable( T: Tabel) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullTable (Tabel T){
    if (T.size == 11){
		return true;
	}
	else{
		return false;
	}
}

/*procedure populate1 ( input/output T:Tabel, input N: integer )
	{I.S.: T terdefinisi, N terdefinisi dalam rentang 1..10}
	{F.S.: T.wadah terisi sebanyak N elemen }
	{Proses: mengisi elemen T.wadah sebanyak N kali dari keyboard}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populate1 (Tabel *T, int N){
    int i;
	
	if (N > 0 && N < 11){
		for (i = 1; i <= N; i++){
			scanf("%d", &T.wadah[i]);
		}    
    }
}

/*procedure searchX1 ( input T:Tabel, input X: integer, output Pos: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: Pos berisi posisi ketemu di T.wadah, atau -999 jika tidak ketemu }
	{Proses: mencari elemen bernilai X dalam T.wadah}*/
void searchX1 (Tabel T, int X, int *Pos){
	int i;

	(*Pos) = 1;
	for (i = 1; i < 11; i++){
		if (T.wadah[i] != X){
			return (*Pos) = (*Pos) + 1;
		}
		else{
			return (*P);
		}
	}
}

/*procedure countX ( input T:Tabel, input X: integer, output Byk: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: Byk berisi banyaknya X di T.wadah, atau 0 jika tidak ketemu }
	{Proses: menghitung elemen bernilai X dalam T.wadah}*/
void countX (Tabel T, int X, int *Byk){
    int i;
    
    for (i = 1; i < 11; i++){
        if (T.wadah[i] == X){
            (*Byk) = (*Byk) + 1;
        }
    }
    
    if (*Byk > 0){
        return *Byk;
    }
    else{
        return 0;
    }
}

/*function getMaxEl ( T: Tabel) -> integer
	{mengembalikan nilai elemen terbesar } */
int getMaxEl (Tabel T){
    int i;
	int temp = -999;
    
    for (i = 1; i < 11; i++){
        if (temp < T.wadah[i]){
            temp = T.wadah[i];
			return temp;
        }
		else{
			return temp;
		}
    }
	
}

/*procedure addXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai X}*/
void addXTable (Tabel *T, int X){
    if (isFullTable(*T) != true){
        
    }
}

/*procedure delXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen bernilai X, geser semua elemen sisa}*/
void delXTable (Tabel *T, int X){
	int i;
	int j;

	for (i = 1; i < 11; i++){
		if (T.wadah[i] == X){
			for (j = i; j < 11; j++){
				T.wadah[j] = T.wadah[j+1];
			}
		}
	}
}

/*procedure delAllXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang semua elemen bernilai X jika belum kosong}
	{Proses: menghapus semua elemen bernilai X, geser elemen sisa}*/
void delAllXTable (Tabel *T, int X);
