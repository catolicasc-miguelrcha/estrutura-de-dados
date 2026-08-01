//
// Created by miguel rocha on 31/07/26.
//
// Questão 8 - Desempenho da equipe de vendas
// Uma rede de lojas acompanha o desempenho de quatro vendedores ao longo de três meses. O programa deverá ler os valores vendidos e armazená-los em uma matriz 4x3, onde cada linha representa um vendedor e cada coluna representa um mês.
// Ao final, o sistema deverá apresentar o total vendido por cada vendedor, o total vendido em cada mês, o total geral da rede e o número do vendedor que mais vendeu no período. Desenvolva um programa em C ANSI para resolver esse problema.
// R.: arquivo: Questao08.c

#include <stdio.h>

int main() {
    float vendas[4][3];
    float totalVendedor[4];
    float totalMes[3];
    float totalGeral = 0;
    int melhorVendedor = 0;
    int i;
    int j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            printf("Digite o valor vendido pelo vendedor %d no mes %d: \n", i + 1, j + 1);
            scanf("%f", &vendas[i][j]);
        }
    }

    for (i = 0; i < 4; i++) {
        totalVendedor[i] = 0;

        for (j = 0; j < 3; j++) {
            totalVendedor[i] += vendas[i][j];
        }

        totalGeral += totalVendedor[i];

        if (totalVendedor[i] > totalVendedor[melhorVendedor]) {
            melhorVendedor = i;
        }
    }

    for (j = 0; j < 3; j++) {
        totalMes[j] = 0;

        for (i = 0; i < 4; i++) {
            totalMes[j] += vendas[i][j];
        }
    }

    for (i = 0; i < 4; i++) {
        printf("Total vendido pelo vendedor %d: R$ %.2f\n", i + 1, totalVendedor[i]);
    }

    for (j = 0; j < 3; j++) {
        printf("Total vendido no mes %d: R$ %.2f\n", j + 1, totalMes[j]);
    }

    printf("Total geral da rede: R$ %.2f\n", totalGeral);
    printf("Vendedor que mais vendeu: %d\n", melhorVendedor + 1);

    return 0;
}