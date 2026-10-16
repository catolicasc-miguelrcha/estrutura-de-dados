/*
Disciplina: Estrutura de Dados
Atividade: Busca Sequencial
Aluno: Miguel Rocha Xavier
*/

#include <stdio.h>
#include <math.h>

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

int buscaBinaria(int v[], int n, int x, int *comparacoes) {
    int inicio = 0, fim = n - 1;
    *comparacoes = 0;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        (*comparacoes)++;
        if (v[meio] == x) {
            return meio;
        }
        if (v[meio] < x) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

void testar(int v[], int n, int x, const char *descricao) {
    int compSeq, compBin;

    buscaSequencial(v, n, x, &compSeq);
    buscaBinaria(v, n, x, &compBin);

    printf("%-12s %8d %12d %10d\n", descricao, x, compSeq, compBin);
}

int main() {
    int v[TAM];

    for (int i = 0; i < TAM; i++) {
        v[i] = i;
    }

    printf("%-12s %8s %12s %10s\n", "Caso", "Valor", "Sequencial", "Binaria");
    printf("-------------------------------------------\n");
    testar(v, TAM, 0, "Primeiro");
    testar(v, TAM, 999, "Ultimo");
    testar(v, TAM, 1500, "Ausente");

    double log2n = log2(TAM);
    printf("\nReferencias: n = %d | log2(n) = %.2f (teto = %d)\n",
           TAM, log2n, (int) ceil(log2n));

    // Sequencial: 1 comparacao no melhor caso e n no pior (ultimo ou ausente) -> O(n).
    // Binaria: no maximo teto(log2(n)) = 10 comparacoes em qualquer caso -> O(log n).
    printf("- Sequencial: melhor caso 1, pior caso n = %d -> O(n).\n", TAM);
    printf("- Binaria: nunca passa de teto(log2 n) = %d -> O(log n).\n", (int) ceil(log2n));

    return 0;
}
