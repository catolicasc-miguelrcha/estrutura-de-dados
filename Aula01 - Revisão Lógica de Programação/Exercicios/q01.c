//
// Created by miguel.xavier on 31/07/2026.
//
// Questão 1 - Pagamento ao produtor rural
// Uma cooperativa agrícola precisa calcular o valor pago ao produtor a cada entrega de leite. O programa deverá ler a quantidade de litros entregues, o valor pago por litro e o percentual descontado a título de transporte. Ao final, o sistema deverá apresentar o valor bruto da entrega, o valor descontado e o valor líquido a ser pago ao produtor. Desenvolva um programa em C ANSI para resolver esse problema.
// R.: arquivo: Questao01.c

#include <stdio.h>

typedef struct {
    float qtdLitros;
    float valorLitros;
    int percentual;
} ProdutorRural;

void menu(ProdutorRural *r) {

    printf("Qtd de litros entregues? ");
    scanf("%f", &r->qtdLitros);

    printf("Valor pago por litro? ");
    scanf("%f", &r->valorLitros);

    printf("Percentual de transporte (%%)? ");
    scanf("%d", &r->percentual);
}

float calcValorPago(ProdutorRural r) {
    return r.qtdLitros * r.valorLitros;
}

float calcPercentual(ProdutorRural r) {
    float valorBruto = calcValorPago(r);
    return valorBruto * (r.percentual / 100.0f);
}

float valorLiquido(ProdutorRural r) {
    float valorBruto = calcValorPago(r);
    float desconto = calcPercentual(r);
    return valorBruto - desconto;
}

int main() {
    ProdutorRural r;

    menu(&r);

    printf("Valor Bruto: %.2f\n", calcValorPago(r));
    printf("Valor Desconto: %.2f\n", calcPercentual(r));
    printf("Valor Liquido: %.2f\n", valorLiquido(r));

    return 0;
}
