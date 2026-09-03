//
// Created by miguel.xavier on 13/08/2026.
//
// 1. Construa um algoritmo que use recursividade para resolver
// o problema matemático da série de Pitágoras, sabendo que 
// a série 1, 3, 6, 10, 15, 21, ...

#include <stdio.h>
#include <stdlib.h>

int serie(int pit);

int main() {

    int pit, seq = 1;

    printf("Insira um numero: ");
    scanf("%i", &pit);


    seq = serie(pit);

    printf("%i", seq);

    return 0;
}

// loop = decompor algo sempre
int serie(int pit) {
    if(pit==1) {return 1;}
    return serie(pit-1)+pit;
}
