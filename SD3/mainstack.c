/* Program   :  */
/* Deskripsi : */
/* NIM/Nama  : 24060119120027/Iwan Suryaningrat*/
/* Tanggal   :  September 2020*/
/***********************************/

#include <stdio.h>
#include "tstack.h"

int main(){
    // Kamus Lokal
    tstack A;
    char X;

    // input
    scanf("%c", &X)

    // Algoritma

    createStack(&A);
    
    // Top
    printf("%c", top(A));

    // infotop
    printf("%c", infotop(A));

    isEmptyStack(A);
    isFullStack(A)

    // push 
    push(&A, 'X');

    // Pop
    pop(&A, &X);

    // Printstack
    printStack(A);

    // viewStack
    viewStack(A);

    
    
    return 0;
}