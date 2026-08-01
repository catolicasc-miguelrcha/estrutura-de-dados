//
// Created by miguel rocha on 31/07/26.
//
// Questão 10 - Boletim da escola técnica
// Uma escola técnica precisa fechar o boletim de quatro alunos, cada um com três notas bimestrais. O programa deverá ler as notas e armazená-las em uma matriz 4x3, onde cada linha representa um aluno e cada coluna representa um bimestre.
// O sistema deverá utilizar duas funções: uma função que receba a matriz e o número da linha e retorne a média daquele aluno, e uma função que receba a média e retorne o caractere A para aprovado, quando a média for maior ou igual a 7, o caractere R para recuperação, quando a média for maior ou igual a 5, e o caractere P para reprovado nos demais casos.
// Ao final, o programa deverá exibir a média e a situação de cada aluno e a quantidade de aprovados da turma. Utilize os protótipos abaixo. Desenvolva um programa em C ANSI para resolver esse problema.
// float calculaMediaAluno(float notas[][3], int linha);
// char defineSituacao(float media);
// R.: arquivo: Questao10.c

#include <stdio.h>

#define QTD_ALUNOS 4
#define QTD_BIMESTRES 3

float calculaMediaAluno(float notas[][QTD_BIMESTRES], int linha);
char defineSituacao(float media);

float calculaMediaAluno(float notas[][QTD_BIMESTRES], int linha) {
    float soma = 0;
    int j;

    for (j = 0; j < QTD_BIMESTRES; j++) {
        soma += notas[linha][j];
    }

    return soma / QTD_BIMESTRES;
}

char defineSituacao(float media) {
    if (media >= 7) {
        return 'A';
    } else if (media >= 5) {
        return 'R';
    } else {
        return 'P';
    }
}

int main() {
    float notas[QTD_ALUNOS][QTD_BIMESTRES];
    float media;
    char situacao;
    int aprovados = 0;
    int i;
    int j;

    for (i = 0; i < QTD_ALUNOS; i++) {
        for (j = 0; j < QTD_BIMESTRES; j++) {
            printf("Digite a nota do aluno %d no bimestre %d: \n", i + 1, j + 1);
            scanf("%f", &notas[i][j]);
        }
    }

    for (i = 0; i < QTD_ALUNOS; i++) {
        media = calculaMediaAluno(notas, i);
        situacao = defineSituacao(media);

        if (situacao == 'A') {
            aprovados++;
        }

        printf("Aluno %d - Media: %.2f - Situacao: %c\n", i + 1, media, situacao);
    }

    printf("Quantidade de aprovados: %d\n", aprovados);

    return 0;
}