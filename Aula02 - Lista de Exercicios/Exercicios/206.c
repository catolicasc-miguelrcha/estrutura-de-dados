//
// Created by miguel.xavier on 13/08/2026.
//

#include <stdio.h>

void somar(int *a, int *b, int *res) {
    *res = *a + *b;
}

void subtrair(int *a, int *b, int *res) {
    *res = *a - *b;
}

void multiplicar(int *a, int *b, int *res) {
    *res = *a * *b;
}

int main() {
    int a, b, soma, subtracao, multiplicacao;

    printf("Informe o valor de a: ");
    scanf("%d", &a);

    printf("Informe o valor de b: ");
    scanf("%d", &b);

    somar(&a, &b, &soma);
    subtrair(&a, &b, &subtracao);
    multiplicar(&a, &b, &multiplicacao);

    printf("Soma: %d\n", soma);
    printf("Subtração: %d\n", subtracao);
    printf("Multiplicação: %d\n", multiplicacao);

    return 0;
}
