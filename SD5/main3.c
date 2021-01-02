/* Program   : main3.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model III: head memutar searah jarum jam */
/* NIM/Nama  : 24060119120027/Iwan Suryaningrat*/
/* Tanggal   : 1 Oktober 2020*/
/***********************************/


#include <stdio.h>
#include "tqueue3.c"
#include "boolean.h"

int main(){
    // Kamus utama
    tqueue3 T;
    char A;

    // Algoritma

    // creatQueue3
    createQueue3(&T);

    // printQueue3
    printQueue3(T);
    printf("\n");

    // enqueue3
    enqueue3(&T, 'A');
    enqueue3(&T, 'B');
    enqueue3(&T, 'C');
    enqueue3(&T, 'D');
    enqueue3(&T, 'E');

    // printQueue3
    printQueue3(T);
    printf("\n");

    // viewQueue3
    viewQueue3(T);
    printf("\n");

    // head3
    printf("Head = %d\n", head3(T));
    
    // infoHead3
    printf("Nilai elemen Head adalah %c\n", infoHead3(T));

    // tail3
    printf("Tail = %d\n", tail3(T));
    
    // infoTail3
    printf("Nilai elemen Tail adalah %c\n", infoTail3(T));

    // sizeQueue3
    printf("Panjang queue = %d\n", sizeQueue3(T));

    // dequeue3
    printf("Dequeue3\n");
    dequeue3(&T, &A);
    printQueue3(T);
    printf("\n");
    printf("Head = %d\n", head3(T));
    printf("Tail = %d\n", tail3(T));

    // sizeQueue3
    printf("Panjang queue = %d\n", sizeQueue3(T));


    return 0;
}