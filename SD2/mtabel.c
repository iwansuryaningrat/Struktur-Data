/* Program   : mtabel.c */
/* Deskripsi : */
/* NIM/Nama  : 24060119120027/Iwan Suryaningrat*/
/* Tanggal   : 10 September 2020*/
/***********************************/

#include <stdio.h>
#include "tabel.h"

int main(){
    Tabel t1;
    int i;
    int x = 5;
    int *Pos;
    int *Byk;
    int N;

    scanf("%d", &N);

    createTabel(&t1);
    printTable(&t1);
    getSize(&t1);
    isEmptyTable(&t1);
    isFullTable(&t1);
    populate1(&t1)
    searchX1(&t1, x, &Pos);
    countX(&t1, x, &Byk);
    getmaxEl(&t1);

    delXTable(&t1,x);


    return 0;
}