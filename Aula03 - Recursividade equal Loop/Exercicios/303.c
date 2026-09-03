//
// Created by miguel.xavier on 13/08/2026.
//
// 3. Implemente apenas a função int somaDigitos(int x) que retorna
// a soma dos dígitos de x de forma recursiva.
// (Exemplo: 538 -> 5 + 3 + 8 = 16).

#include <stdio.h>
#include <stdlib.h>

int somaDigitos(int x) {

    if(x==0) {return 0;}

    return (x%10) + somaDigitos(x/10);
}

int main() {

    int x, soma;

    printf("Insira um numero: ");
    scanf("%i", &x);

    soma = somaDigitos(x);

    printf("Soma dos digitos: %i", soma);

    return 0;
}
