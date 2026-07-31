//
// Created by miguel.xavier on 31/07/2026.
//
// Questão 2 - Faixas de tarifa de energia
// Uma distribuidora de energia aplica faixas de tarifa conforme o consumo mensal registrado no medidor. Até 100 kWh o valor da tarifa é de R$ 0,60 por kWh. Acima de 100 kWh e até 250 kWh a tarifa é de R$ 0,85 por kWh. Acima de 250 kWh a tarifa é de R$ 1,10 por kWh.
// O programa deverá ler o consumo registrado no mês e apresentar a faixa em que o cliente se enquadra e o valor total da conta. Desenvolva um programa em C ANSI para resolver esse problema.
// R.: arquivo: Questao02.c

#include <stdio.h>

typedef struct {
    float consumoMes;
} Cliente;

void tarifasEnergia(Cliente *cl) {
    printf("Qual o consumo registrado do mes de energia?\n");
    scanf("%f", &cl->consumoMes);
}

void validacaoTarifas(Cliente *cl) {
    float valorTotalTarifas;
    float tarifas;

    if (cl->consumoMes <= 100) {
        printf("Faixa: ate 100 kWh\n");
        tarifas = 0.60;
    }
    else if (cl->consumoMes <= 250) {
        printf("Faixa: acima de 100 ate 250 kWh\n");
        tarifas = 0.85;
    }
    else {
        printf("Faixa: acima de 250 kWh\n");
        tarifas = 1.10;
    }

    valorTotalTarifas = cl->consumoMes * tarifas;

    printf("Valor da conta: R$ %.2f\n", valorTotalTarifas);
}

int main() {
    Cliente cl;

    tarifasEnergia(&cl);
    validacaoTarifas(&cl);

    return 0;
}