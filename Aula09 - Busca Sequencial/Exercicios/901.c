/*
Disciplina: Estrutura de Dados
Atividade: Busca Sequencial
Aluno: Miguel Rocha Xavier
*/

#include <stdio.h>

#define TAM 10

int buscaSequencial(int v[], int n, int x, int *comparacoes) {
    *comparacoes = 0;
    for (int i = 0; i < n; i++) {
        (*comparacoes)++;
        if (v[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int v[TAM], x, comparacoes, pos;

    for (int i = 0; i < TAM; i++) {
        printf("Digite o %do numero: ", i + 1);
        scanf("%d", &v[i]);
    }

    printf("Numero a pesquisar: ");
    scanf("%d", &x);

    pos = buscaSequencial(v, TAM, x, &comparacoes);

    if (pos != -1) {
        printf("Valor %d encontrado na posicao %d.\n", x, pos);
    } else {
        printf("Valor %d nao encontrado.\n", x);
    }
    printf("Comparacoes realizadas: %d\n", comparacoes);

    return 0;
}
