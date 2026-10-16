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

int buscaBinariaRecursiva(int v[], int inicio, int fim, int x, int *chamadas) {
    (*chamadas)++;

    if (inicio > fim) {
        return -1;
    }

    int meio = (inicio + fim) / 2;

    if (v[meio] == x) {
        return meio;
    }
    if (v[meio] < x) {
        return buscaBinariaRecursiva(v, meio + 1, fim, x, chamadas);
    }
    return buscaBinariaRecursiva(v, inicio, meio - 1, x, chamadas);
}

int main() {
    int v[TAM], x, chamadas = 0, pos;

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

    pos = buscaBinariaRecursiva(v, 0, TAM - 1, x, &chamadas);

    if (pos != -1) {
        printf("Valor %d encontrado na posicao %d do vetor ordenado.\n", x, pos);
    } else {
        printf("Valor %d nao encontrado.\n", x);
    }
    printf("Chamadas realizadas: %d\n", chamadas);

    return 0;
}
