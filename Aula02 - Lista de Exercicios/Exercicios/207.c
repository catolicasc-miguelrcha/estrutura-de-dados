//
// Created by miguel.xavier on 13/08/2026.
//

#include <stdio.h>

void fatorial(int n, double *fat) {
    if (n < 0) {
        printf("O número deve ser maior ou igual a zero\n");
        return;
    }

    *fat = 1;

    for (int i = 2; i <= n; i++) {
        *fat *= i;
    }
}

int main() {
    int n;
    double fat;

    printf("Informe um número inteiro positivo: ");
    scanf("%d", &n);

    fatorial(n, &fat);

    if (n >= 0) {
        printf("Fatorial: %.0lf\n", fat);
    }

    return 0;
}
