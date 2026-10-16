/*
Disciplina: Estrutura de Dados
Atividade: Busca Sequencial
Aluno: Miguel Rocha Xavier
*/

#include <stdio.h>

#define TAM 10

// Insertion Sort (Unidade II)
void insertionSort(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
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

int main() {
    int v[TAM], x, comparacoes, pos;

    for (int i = 0; i < TAM; i++) {
        printf("Digite o %do numero: ", i + 1);
        scanf("%d", &v[i]);
    }

    insertionSort(v, TAM);

    printf("Vetor ordenado:");
    for (int i = 0; i < TAM; i++) {
        printf(" %d", v[i]);
    }
    printf("\n");

    printf("Numero a pesquisar: ");
    scanf("%d", &x);

    pos = buscaBinaria(v, TAM, x, &comparacoes);

    if (pos != -1) {
        printf("Valor %d encontrado na posicao %d do vetor ordenado.\n", x, pos);
    } else {
        printf("Valor %d nao encontrado.\n", x);
    }
    printf("Comparacoes realizadas: %d\n", comparacoes);

    return 0;
}
