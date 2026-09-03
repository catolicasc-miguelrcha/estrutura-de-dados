//
// Created by miguel.xavier on 13/08/2026.
//
// 4. Implemente uma função recursiva em C ANSI que retorne o maior
// elemento de um vetor de inteiros. Considere que n é o tamanho do
// vetor. A função deve comparar os elementos de forma recursiva e
// retornar o maior valor armazenado.

#include <stdio.h>
#include <stdlib.h>

int maiorValor(int v[], int n) {

    int maiorResto;

    if(n==1) {return v[0];}

    maiorResto = maiorValor(v, n-1);

    if(v[n-1] > maiorResto) {return v[n-1];}

    return maiorResto;
}

int main() {

    int v[] = {4, 9, 2, 7, 15, 3, 8};
    int n = 7;
    int maior;

    maior = maiorValor(v, n);

    printf("Maior valor: %i", maior);

    return 0;
}
