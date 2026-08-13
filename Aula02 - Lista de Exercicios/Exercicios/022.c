//
// Created by miguel.xavier on 13/08/2026.
//

#include <stdio.h>

#define VETOR_MAX 100

void media(const int *v, int n, float *m) {
    if (n <= 0) {
        printf("A quantidade de elementos deve ser maior que zero\n");
        return;
    }

    int soma = 0;

    for (int i = 0; i < n; i++) {
        soma += v[i];
    }

    *m = (float) soma / n;
}

int main() {
    int v[VETOR_MAX], n;
    float m;

    printf("Informe a quantidade de elementos: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Informe o elemento %d: ", i + 1);
        scanf("%d", &v[i]);
    }

    media(v, n, &m);

    if (n > 0) {
        printf("Média: %.2f\n", m);
    }

    return 0;
}
