/*
Disciplina: Estrutura de Dados
Atividade: Comparacao de desempenho entre metodos de ordenacao
Aluno: Miguel Rocha Xavier

Conseguiu chegar nos valores de referencia?
R: Sim. Nos cenarios ordenado e invertido os cinco metodos mostram
exatamente os valores de referencia, e no cenario aleatorio as medias
caem dentro das faixas esperadas.
Se nao, em quais metodos e por que?
R: Nao se aplica.

Metodos analisados:
- Bubble Sort
- Selection Sort
- Insertion Sort
- Merge Sort
- Quick Sort
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM 10000
#define QTD_METODOS 5
#define QTD_CENARIOS 3
#define RODADAS_ALEATORIO 3
#define QTD_CARTAS 8

/* Contadores globais, zerados antes de cada execucao */
long comparacoes;
long trocas;
long movimentacoes;

/* Vetor auxiliar usado pelo Merge Sort na intercalacao */
int temp[TAM];

const char *nomesMetodos[QTD_METODOS] = {
    "Bubble", "Selection", "Insertion", "Merge", "Quick"
};

const char *nomesCenarios[QTD_CENARIOS] = {
    "Ordenados", "Invertidos", "Aleatorios"
};

/* Resultado de um metodo em um cenario */
typedef struct {
    double comparacoes;
    double trocas;
    double movimentacoes;
    double tempo_ms;
} Resultado;

void zeraContadores(void)
{
    comparacoes = 0;
    trocas = 0;
    movimentacoes = 0;
}

/*
 * Troca dois elementos de posicao.
 * Conta 1 troca e 3 movimentacoes (aux = *a; *a = *b; *b = aux).
 * Trocar uma posicao com ela mesma nao conta, porque nenhum valor muda de lugar.
 */
void troca(int *a, int *b)
{
    int aux;

    if (a == b)
        return;

    aux = *a;
    *a = *b;
    *b = aux;
    trocas++;
    movimentacoes += 3;
}

/* ------------------------------------------------------------------ */
/* Bubble Sort                                                         */
/* ------------------------------------------------------------------ */
void bubbleSort(int v[], int n)
{
    int i, houveTroca;

    do {
        houveTroca = 0;
        for (i = 0; i < n - 1; i++) {
            comparacoes++;              /* comparacao entre vizinhos */
            if (v[i] > v[i + 1]) {
                troca(&v[i], &v[i + 1]); /* troca quando o par esta fora de ordem */
                houveTroca = 1;
            }
        }
    } while (houveTroca);
}

/* ------------------------------------------------------------------ */
/* Selection Sort                                                      */
/* ------------------------------------------------------------------ */
void selectionSort(int v[], int n)
{
    int i, j, min;

    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            comparacoes++;              /* comparacao na busca do menor */
            if (v[j] < v[min])
                min = j;
        }
        if (min != i)
            troca(&v[i], &v[min]);      /* no maximo uma troca por passagem */
    }
}

/* ------------------------------------------------------------------ */
/* Insertion Sort (nao faz trocas, so movimentacoes)                   */
/* ------------------------------------------------------------------ */
void insertionSort(int v[], int n)
{
    int i, j, chave;

    for (i = 1; i < n; i++) {
        chave = v[i];
        movimentacoes++;                /* guardar a chave */
        j = i - 1;

        /* j >= 0 e controle; v[j] > chave e a comparacao de dados.
           O contador so soma quando o segundo teste chega a ser feito. */
        while (j >= 0 && (comparacoes++, v[j] > chave)) {
            v[j + 1] = v[j];
            movimentacoes++;            /* deslocamento para a direita */
            j--;
        }

        v[j + 1] = chave;
        movimentacoes++;                /* insercao da chave */
    }
}

/* ------------------------------------------------------------------ */
/* Merge Sort (nao faz trocas, so movimentacoes)                       */
/* ------------------------------------------------------------------ */
void intercala(int v[], int inicio, int meio, int fim)
{
    int i = inicio, j = meio + 1, k = 0;

    while (i <= meio && j <= fim) {
        comparacoes++;                  /* comparacao na intercalacao */
        if (v[i] <= v[j])
            temp[k++] = v[i++];
        else
            temp[k++] = v[j++];
        movimentacoes++;                /* copia para temp */
    }
    while (i <= meio) {
        temp[k++] = v[i++];
        movimentacoes++;                /* copia para temp (sobra da esquerda) */
    }
    while (j <= fim) {
        temp[k++] = v[j++];
        movimentacoes++;                /* copia para temp (sobra da direita) */
    }

    for (i = 0; i < k; i++) {
        v[inicio + i] = temp[i];
        movimentacoes++;                /* copia de volta para v */
    }
}

void mergeSortRec(int v[], int inicio, int fim)
{
    int meio;

    if (inicio < fim) {
        meio = (inicio + fim) / 2;
        mergeSortRec(v, inicio, meio);
        mergeSortRec(v, meio + 1, fim);
        intercala(v, inicio, meio, fim);
    }
}

void mergeSort(int v[], int n)
{
    mergeSortRec(v, 0, n - 1);
}

/* ------------------------------------------------------------------ */
/* Quick Sort (pivo no fim do vetor)                                   */
/* ------------------------------------------------------------------ */
int particiona(int v[], int inicio, int fim)
{
    int pivo, i, j;

    pivo = v[fim];
    movimentacoes++;                    /* guardar o pivo */
    i = inicio - 1;

    for (j = inicio; j < fim; j++) {
        comparacoes++;                  /* comparacao com o pivo */
        if (v[j] < pivo) {
            i++;
            troca(&v[i], &v[j]);        /* so conta se i != j */
        }
    }
    troca(&v[i + 1], &v[fim]);          /* pivo na posicao final */
    return i + 1;
}

void quickSortRec(int v[], int inicio, int fim)
{
    int p;

    if (inicio < fim) {
        p = particiona(v, inicio, fim);
        quickSortRec(v, inicio, p - 1);
        quickSortRec(v, p + 1, fim);
    }
}

void quickSort(int v[], int n)
{
    quickSortRec(v, 0, n - 1);
}

/* ------------------------------------------------------------------ */
/* Apoio                                                               */
/* ------------------------------------------------------------------ */
typedef void (*MetodoOrdenacao)(int[], int);

MetodoOrdenacao metodos[QTD_METODOS] = {
    bubbleSort, selectionSort, insertionSort, mergeSort, quickSort
};

/* op 1: ordenado, op 2: invertido, op 3: aleatorio */
void geraNumero(int v[], int n, int op)
{
    int i;

    for (i = 0; i < n; i++) {
        if (op == 1)
            v[i] = i + 1;
        else if (op == 2)
            v[i] = n - i;
        else
            v[i] = rand() % 10000;
    }
}

void copiaVetor(int origem[], int destino[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        destino[i] = origem[i];
}

int estaOrdenado(int v[], int n)
{
    int i;

    for (i = 0; i < n - 1; i++)
        if (v[i] > v[i + 1])
            return 0;
    return 1;
}

/*
 * Executa um metodo sobre uma copia de vetorBase.
 * O tempo mede somente a chamada da ordenacao.
 */
Resultado executa(int m, int vetorBase[], int vetorTeste[], int n)
{
    Resultado r;
    clock_t inicio, fim;

    copiaVetor(vetorBase, vetorTeste, n);
    zeraContadores();

    inicio = clock();
    metodos[m](vetorTeste, n);
    fim = clock();

    if (!estaOrdenado(vetorTeste, n))
        printf("ATENCAO: %s nao ordenou o vetor!\n", nomesMetodos[m]);

    r.comparacoes = comparacoes;
    r.trocas = trocas;
    r.movimentacoes = movimentacoes;
    r.tempo_ms = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;
    return r;
}

void imprimeLinha(void)
{
    printf("==========================================================================\n");
}

/* ------------------------------------------------------------------ */
/* Validacao com as 8 cartas do simulador                              */
/* ------------------------------------------------------------------ */
/* Preencha com a sequencia inicial das cartas anotada no simulador */
int cartas[QTD_CARTAS] = { 10, 7, 1, 4, 5, 12, 3, 11 };

void validacao(void)
{
    int vetorTeste[QTD_CARTAS];
    int m, i;
    Resultado r;

    imprimeLinha();
    printf("VALIDACAO - %d CARTAS:", QTD_CARTAS);
    for (i = 0; i < QTD_CARTAS; i++)
        printf(" %d", cartas[i]);
    printf("\n");
    imprimeLinha();
    printf("%-12s %14s %14s %16s\n", "Metodo", "Comparacoes", "Trocas", "Movimentacoes");
    for (m = 0; m < QTD_METODOS; m++) {
        r = executa(m, cartas, vetorTeste, QTD_CARTAS);
        printf("%-12s %14.0f %14.0f %16.0f\n", nomesMetodos[m],
               r.comparacoes, r.trocas, r.movimentacoes);
    }
    printf("\n");
}

/* ------------------------------------------------------------------ */
/* Tabelas e resumo                                                    */
/* ------------------------------------------------------------------ */
void imprimeTabela(int c, Resultado res[])
{
    int m;

    imprimeLinha();
    printf("CENARIO %d - DADOS %s - %d ELEMENTOS", c + 1,
           c == 0 ? "ORDENADOS" : (c == 1 ? "INVERTIDOS" : "ALEATORIOS"), TAM);
    if (c == 2)
        printf(" (media de %d execucoes)", RODADAS_ALEATORIO);
    printf("\n");
    imprimeLinha();
    printf("%-12s %14s %14s %16s %12s\n",
           "Metodo", "Comparacoes", "Trocas", "Movimentacoes", "Tempo (ms)");
    for (m = 0; m < QTD_METODOS; m++)
        printf("%-12s %14.0f %14.0f %16.0f %12.3f\n", nomesMetodos[m],
               res[m].comparacoes, res[m].trocas,
               res[m].movimentacoes, res[m].tempo_ms);
    printf("\n");
}

/* indicador 0: comparacoes, 1: movimentacoes, 2: tempo */
double valorIndicador(Resultado r, int indicador)
{
    if (indicador == 0)
        return r.comparacoes;
    if (indicador == 1)
        return r.movimentacoes;
    return r.tempo_ms;
}

/* Monta em buffer o(s) nome(s) do(s) melhor(es) metodo(s), mostrando empates */
void melhores(Resultado res[], int indicador, char *buffer)
{
    int m;
    double menor = valorIndicador(res[0], indicador);

    for (m = 1; m < QTD_METODOS; m++)
        if (valorIndicador(res[m], indicador) < menor)
            menor = valorIndicador(res[m], indicador);

    buffer[0] = '\0';
    for (m = 0; m < QTD_METODOS; m++) {
        if (valorIndicador(res[m], indicador) == menor) {
            if (buffer[0] != '\0')
                strcat(buffer, "/");
            strcat(buffer, nomesMetodos[m]);
        }
    }
}

/* O resumo nao aponta o melhor por trocas: Insertion e Merge marcam zero
   porque nao trocam elementos, e nao porque trabalham menos. */
void imprimeResumo(Resultado res[QTD_CENARIOS][QTD_METODOS])
{
    int c;
    char comp[64], mov[64], tempo[64];

    imprimeLinha();
    printf("RESUMO\n");
    imprimeLinha();
    printf("%-12s %-20s %-20s %-20s\n",
           "Cenario", "Menos comparacoes", "Menos movimentacoes", "Menor tempo");
    for (c = 0; c < QTD_CENARIOS; c++) {
        melhores(res[c], 0, comp);
        melhores(res[c], 1, mov);
        melhores(res[c], 2, tempo);
        printf("%-12s %-20s %-20s %-20s\n", nomesCenarios[c], comp, mov, tempo);
    }
    printf("\n");
}

int main(void)
{
    static int vetorBase[TAM];
    static int vetorTeste[TAM];
    Resultado res[QTD_CENARIOS][QTD_METODOS];
    Resultado r;
    int c, m, rodada;

    srand((unsigned)time(NULL));

    validacao();

    for (c = 0; c < QTD_CENARIOS; c++) {
        for (m = 0; m < QTD_METODOS; m++) {
            res[c][m].comparacoes = 0;
            res[c][m].trocas = 0;
            res[c][m].movimentacoes = 0;
            res[c][m].tempo_ms = 0;
        }

        if (c < 2) {
            /* Ordenado e invertido: o arranjo e sempre o mesmo, uma execucao basta */
            geraNumero(vetorBase, TAM, c + 1);
            for (m = 0; m < QTD_METODOS; m++)
                res[c][m] = executa(m, vetorBase, vetorTeste, TAM);
        } else {
            /* Aleatorio: vetor novo a cada rodada, o mesmo para os cinco metodos */
            for (rodada = 0; rodada < RODADAS_ALEATORIO; rodada++) {
                geraNumero(vetorBase, TAM, 3);
                for (m = 0; m < QTD_METODOS; m++) {
                    r = executa(m, vetorBase, vetorTeste, TAM);
                    res[c][m].comparacoes += r.comparacoes;
                    res[c][m].trocas += r.trocas;
                    res[c][m].movimentacoes += r.movimentacoes;
                    res[c][m].tempo_ms += r.tempo_ms;
                }
            }
            for (m = 0; m < QTD_METODOS; m++) {
                res[c][m].comparacoes /= RODADAS_ALEATORIO;
                res[c][m].trocas /= RODADAS_ALEATORIO;
                res[c][m].movimentacoes /= RODADAS_ALEATORIO;
                res[c][m].tempo_ms /= RODADAS_ALEATORIO;
            }
        }

        imprimeTabela(c, res[c]);
    }

    imprimeResumo(res);

    return 0;
}
