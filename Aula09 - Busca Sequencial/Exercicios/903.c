/*
Disciplina: Estrutura de Dados
Atividade: Busca Sequencial
Aluno: Miguel Rocha Xavier
*/

#include <stdio.h>

#define TAM 1000

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

void testar(int v[], int n, int x, const char *descricao) {
    int comparacoes;
    int pos = buscaSequencial(v, n, x, &comparacoes);

    printf("%-20s valor %5d -> posicao %4d | comparacoes: %4d\n",
           descricao, x, pos, comparacoes);
}

int main() {
    int v[TAM];

    for (int i = 0; i < TAM; i++) {
        v[i] = i;
    }

    testar(v, TAM, 0, "Primeiro elemento:");
    testar(v, TAM, 999, "Ultimo elemento:");
    testar(v, TAM, 1500, "Valor inexistente:");

    printf("\nAnalise (n = %d):\n", TAM);
    printf("- Melhor caso (primeiro elemento): 1 comparacao.\n");
    printf("- Pior caso (ultimo ou ausente): n = %d comparacoes.\n", TAM);
    printf("- Caso medio: aproximadamente n/2 = %d comparacoes -> O(n).\n", TAM / 2);

    return 0;
}
