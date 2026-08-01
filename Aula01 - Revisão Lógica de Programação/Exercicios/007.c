//
// Created by miguel rocha on 31/07/26.
//
// Questão 7 - Consulta de estoque da farmácia
// Uma farmácia mantém um pequeno controle de estoque com oito produtos. O programa deverá ler, para cada produto, o código inteiro e a quantidade em estoque, armazenando os dados em vetores paralelos.
// Em seguida, o sistema deverá ler o código de um produto procurado pelo atendente e informar a posição em que ele foi encontrado e a quantidade disponível. Caso o código não exista no estoque, o programa deverá avisar que o produto não foi cadastrado. Desenvolva um programa em C ANSI para resolver esse problema.
// R.: arquivo: Questao07.c

#include <stdio.h>

int main() {
    int codigo[8];
    int quantidade[8];
    int i;
    int codigoProcurado;
    int posicao = -1;

    for (i = 0; i < 8; i++) {
        printf("Digite o codigo do produto %d: \n", i + 1);
        scanf("%d", &codigo[i]);
        printf("Digite a quantidade em estoque do produto %d: \n", i + 1);
        scanf("%d", &quantidade[i]);
    }

    printf("Digite o codigo do produto procurado: \n");
    scanf("%d", &codigoProcurado);

    for (i = 0; i < 8; i++) {
        if (codigo[i] == codigoProcurado) {
            posicao = i;
            break;
        }
    }

    if (posicao == -1) {
        printf("Produto nao cadastrado.\n");
    } else {
        printf("Produto encontrado na posicao: %d\n", posicao);
        printf("Quantidade disponivel: %d\n", quantidade[posicao]);
    }

    return 0;
}