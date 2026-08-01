//
// Created by miguel rocha on 31/07/26.
//
// Questão 5 - Monitoramento de umidade do solo
// Uma estação de monitoramento ambiental coleta medições de umidade em vários pontos de uma plantação. O programa deverá ler quantos pontos serão monitorados e, para cada ponto, ler três medições reais.
// Ao final de cada ponto, o sistema deverá apresentar a média das três medições daquele ponto e informar se o solo está seco, quando a média for menor que 40, ou úmido, quando a média for maior ou igual a 40. Utilize estruturas de repetição encadeadas. Desenvolva um programa em C ANSI para resolver esse problema.
// R.: arquivo: Questao05.c

#include <stdio.h>

int main() {

    int ptsMonitorados;
    float medF,medS,medT;

    printf("Digite quantos pontos serao monitorados?: \n");
    scanf("%d", &ptsMonitorados);

    for (int i = 0; i < ptsMonitorados; i++) {
        printf("Digite a primeira medicao: \n");
        scanf("%f", &medF);
        printf("Digite a segunda medicao: \n");
        scanf("%f", &medS);
        printf("Digite a terceira medicao: \n");
        scanf("%f", &medT);

        float media = (medF + medS + medT)/3;

        printf("Ponto de medicao: %i ", i);
        printf("Media: %.2f\n ", media);

        if (media < 40) {
            printf("Este ponto esta seco.\n");
        } else {
            printf("Este ponto esta seco.\n");
        }
    }
}
