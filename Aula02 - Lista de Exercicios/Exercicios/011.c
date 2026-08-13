//
// Created by miguel.xavier on 13/08/2026.
//

#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
    double peso;
} Pessoa;

void lerPessoa(Pessoa *p) {
    printf("Informe o nome: ");
    scanf("%s", p->nome);

    printf("Informe a idade: ");
    scanf("%d", &p->idade);

    printf("Informe o peso: ");
    scanf("%lf", &p->peso);
}

void imprimirPessoa(Pessoa p) {
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Peso: %.2lf\n", p.peso);
}

int main() {
    Pessoa p;

    lerPessoa(&p);
    imprimirPessoa(p);

    return 0;
}