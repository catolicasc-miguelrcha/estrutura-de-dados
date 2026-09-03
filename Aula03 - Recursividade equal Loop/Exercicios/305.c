//
// Created by miguel.xavier on 13/08/2026.
//
// 5. Dada a função para imprimir os termos de uma lista simplesmente
// encadeada, transforme em uma função que utilize recursividade
// para imprimir esta lista.

#include <stdio.h>
#include <stdlib.h>

struct no {
    int valor;
    struct no *prox;
};

typedef struct no No;

// versao iterativa (ponto de partida)
// void imprimeLista(No *inicio) {
//     No *atual = inicio;
//     while(atual != NULL) {
//         printf("%i ", atual->valor);
//         atual = atual->prox;
//     }
// }

// versao recursiva
void imprimeLista(No *inicio) {

    if(inicio==NULL) {return;}

    printf("%i ", inicio->valor);

    imprimeLista(inicio->prox);
}

No* inserirFim(No *inicio, int valor) {

    No *novo = (No*) malloc(sizeof(No));
    No *atual;

    novo->valor = valor;
    novo->prox = NULL;

    if(inicio==NULL) {return novo;}

    atual = inicio;
    while(atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = novo;

    return inicio;
}

int main() {

    No *lista = NULL;

    lista = inserirFim(lista, 10);
    lista = inserirFim(lista, 20);
    lista = inserirFim(lista, 30);
    lista = inserirFim(lista, 40);

    imprimeLista(lista);

    return 0;
}
