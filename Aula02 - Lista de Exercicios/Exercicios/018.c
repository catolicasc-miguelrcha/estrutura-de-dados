//
// Created by miguel.xavier on 13/08/2026.
//

#include <stdio.h>

void ordenar3(int *a, int *b, int *c) {
    int temp;

    if (*a > *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }

    if (*b > *c) {
        temp = *b;
        *b = *c;
        *c = temp;
    }

    if (*a > *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main() {
    int a, b, c;

    printf("Informe o valor de a: ");
    scanf("%d", &a);

    printf("Informe o valor de b: ");
    scanf("%d", &b);

    printf("Informe o valor de c: ");
    scanf("%d", &c);

    ordenar3(&a, &b, &c);

    printf("Ordem crescente: %d, %d, %d\n", a, b, c);

    return 0;
}
