/*
Disciplina: Estrutura de Dados
Atividade: Busca Sequencial
Aluno: Miguel Rocha Xavier
*/

#include <stdio.h>

#define TAM 10

int buscaTodas(int v[], int n, int x, int posicoes[], int *comparacoes) {
    int ocorrencias = 0;
    *comparacoes = 0;
    for (int i = 0; i < n; i++) {
        (*comparacoes)++;
        if (v[i] == x) {
            posicoes[ocorrencias] = i;
            ocorrencias++;
        }
    }
    return ocorrencias;
}

int main() {
    int v[TAM], posicoes[TAM], x, comparacoes, ocorrencias;

    for (int i = 0; i < TAM; i++) {
        printf("Digite o %do numero: ", i + 1);
        scanf("%d", &v[i]);
    }

    printf("Numero a pesquisar: ");
    scanf("%d", &x);

    ocorrencias = buscaTodas(v, TAM, x, posicoes, &comparacoes);

    if (ocorrencias > 0) {
        printf("Valor %d encontrado nas posicoes:", x);
        for (int i = 0; i < ocorrencias; i++) {
            printf(" %d", posicoes[i]);
        }
        printf("\n");
    } else {
        printf("Valor %d nao encontrado.\n", x);
    }
    printf("Total de ocorrencias: %d\n", ocorrencias);
    printf("Comparacoes realizadas: %d\n", comparacoes);

    return 0;
}
