/* Program   : main2.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model II: head bergeser/jelajah */
/* NIM/Nama  : 24060119120027/Iwan Suryaningrat*/
/* Tanggal   : 1 Oktober 2020*/
/***********************************/


#include <stdio.h>
#include "tqueue2.c"
#include "boolean.h"

int main(){
    // Kamus utama
    tqueue2 T;
    char A;

    // Algoritma

    // creatQueue2
    createQueue2(&T);

    // printQueue2
    printQueue2(T);
    printf("\n");

    // enqueue2
    enqueue2(&T, 'A');
    enqueue2(&T, 'B');
    enqueue2(&T, 'C');
    enqueue2(&T, 'D');
    enqueue2(&T, 'E');

    // printQueue2
    printQueue2(T);
    printf("\n");

    // viewQueue2
    viewQueue2(T);
    printf("\n");

    // head2
    printf("Head = %d\n", head2(T));
    
    // infoHead2
    printf("Nilai elemen Head adalah %c\n", infoHead2(T));

    // tail2
    printf("Tail = %d\n", tail2(T));
    
    // infoTail2
    printf("Nilai elemen Tail adalah %c\n", infoTail2(T));

    // sizeQueue2
    printf("Panjang queue = %d\n", sizeQueue2(T));
    
    // dequeue2
    printf("Dequeue2\n");
    dequeue2(&T, &A);
    printQueue2(T);
    printf("\n");
    printf("Head = %d\n", head2(T));
    printf("Tail = %d\n", tail2(T));

    // resetHead2
    printf("resetHead2\n");
    resetHead2(&T);
    printQueue2(T);
    printf("\n");
    printf("Head = %d\n", head2(T));
    printf("Tail = %d\n", tail2(T));

    // sizeQueue2
    printf("Panjang queue = %d\n", sizeQueue2(T));
    
    return 0;
}