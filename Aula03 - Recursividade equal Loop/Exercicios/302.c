//
// Created by miguel.xavier on 13/08/2026.
//
// 2. Implemente uma função recursiva em C
// ANSI que calcule o número de elementos pares em
// um vetor de inteiros.

#include <stdio.h>
#include <stdlib.h>

int contarPares(int v[], int n) {

    if(n==0) {return 0;}

    if(v[n-1]%2==0) {
        return contarPares(v, n-1)+1;
    }

    return contarPares(v, n-1);
}

int main() {

    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    int pares;

    pares = contarPares(v, n);

    printf("Numero de pares: %i", pares);

    return 0;
}
