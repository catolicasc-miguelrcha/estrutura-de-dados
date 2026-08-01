//
// Created by miguel.xavier on 31/07/2026.
//
// Questão 4 - Fechamento do caixa
// Um mercado de bairro precisa fechar o caixa ao final do expediente. O operador digita o valor de cada venda realizada e, quando não houver mais vendas a registrar, digita o valor zero para encerrar.
// O programa deverá apresentar a quantidade de vendas registradas, o valor total vendido e o valor médio por venda. Se nenhuma venda for registrada, o sistema deverá avisar que não houve movimento. Desenvolva um programa em C ANSI para resolver esse problema.

#include <stdio.h>

typedef struct {
    int vendas;
    float totalVendas;
} Caixa;

void registrarVendas(Caixa *cx) {
    float venda;

    cx->vendas = 0;
    cx->totalVendas = 0;

    printf("Digite o valor de cada venda (0 para encerrar):\n");
    scanf("%f", &venda);

    while (venda != 0) {
        cx->vendas++;
        cx->totalVendas += venda;

        printf("Digite o valor de cada venda (0 para encerrar):\n");
        scanf("%f", &venda);
    }
}

void fecharCaixa(Caixa cx) {
    if (cx.vendas == 0) {
        printf("Nao houve movimento no caixa.\n");
        return;
    }

    printf("Quantidade de vendas: %i\n", cx.vendas);
    printf("Valor total vendido:  %.2f\n", cx.totalVendas);
    printf("Valor medio por venda:  %.2f\n", cx.totalVendas / cx.vendas);
}

int main() {
    Caixa cx;

    printf("Fechamento de Caixa\n");
    registrarVendas(&cx);
    fecharCaixa(cx);

    return 0;
}