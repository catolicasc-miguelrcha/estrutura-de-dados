//
// Created by miguel.xavier on 13/08/2026.
//

#include <stdio.h>

typedef struct {
    int ID;
    char nome[50];
    char cor[50];
    double preco;
    double peso;
} Peca;

void lerPeca(Peca *p) {
    printf("Informe o ID da peça: ");
    scanf("%d", &p->ID);

    printf("Informe o nome da peça: ");
    scanf("%s", p->nome);

    printf("Informe a cor da peça: ");
    scanf("%s", p->cor);

    printf("Informe o preço da peça: ");
    scanf("%lf", &p->preco);

    printf("Informe o peso da peça: ");
    scanf("%lf", &p->peso);
}

void imprimirPeca(Peca p) {
    printf("ID: %d\n", p.ID);
    printf("Nome: %s\n", p.nome);
    printf("Cor: %s\n", p.cor);
    printf("Preço: %.2lf\n", p.preco);
    printf("Peso: %.2lf\n", p.peso);
}

int main() {
    Peca p;

    lerPeca(&p);
    imprimirPeca(p);

    return 0;
}