//
// Created by miguel rocha on 31/07/26.
//
// Questão 6 - Análise dos tempos de atendimento
// Uma central de atendimento deseja analisar o tempo gasto no atendimento de dez chamados. O programa deverá ler dez tempos reais, em minutos, e armazenar os valores em um vetor.
// Ao final, o sistema deverá apresentar o maior tempo, o menor tempo, o tempo médio de atendimento e a quantidade de chamados que ficaram acima da média. Desenvolva um programa em C ANSI para resolver esse problema.
// R.: arquivo: Questao06.c

#include <stdio.h>

int main() {
    int v[10];
    int i;
    int soma = 0;
    int maior;
    int menor;
    float media;
    int acimaMedia = 0;

    for (i = 0; i < 10; i++) {
        printf("Digite o tempo em minutos que levou este atendimento: %i\n", i + 1);
        scanf("%d", &v[i]);
    }

    maior = v[0];
    menor = v[0];

    for (i = 0; i < 10; i++) {
        soma += v[i];

        if (v[i] > maior) {
            maior = v[i];
        }

        if (v[i] < menor) {
            menor = v[i];
        }
    }

    media = (float) soma / 10;

    for (i = 0; i < 10; i++) {
        if (v[i] > media) {
            acimaMedia++;
        }
    }

    printf("Maior tempo: %d min\n", maior);
    printf("Menor tempo: %d min\n", menor);
    printf("Tempo medio: %.2f min\n", media);
    printf("Chamados acima da media: %d\n", acimaMedia);

    return 0;
}