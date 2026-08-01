//
// Created by miguel rocha on 31/07/26.
//
// Questão 9 - Avaliação física modularizada
// Uma academia deseja modularizar o processamento das avaliações físicas de seis alunos. O programa deverá ler o peso e a altura de cada aluno, armazenando os dados em vetores.
// O sistema deverá utilizar três funções: uma função sem parâmetro e sem retorno para exibir o cabeçalho do relatório, uma função que receba peso e altura e retorne o índice de massa corporal, calculado pela fórmula imc = peso / (altura * altura), e uma função que receba o vetor de índices e a quantidade de alunos e retorne o índice médio da turma.
// Ao final, o programa deverá apresentar o relatório com o índice de cada aluno e o índice médio. Desenvolva um programa em C ANSI para resolver esse problema.
// R.: arquivo: Questao09.c

#include <stdio.h>

#define QTD_ALUNOS 6

void exibirCabecalho(void) {
    printf("\n===== Relatorio de Avaliacao Fisica =====\n");
}

float calculaIMC(float peso, float altura) {
    return peso / (altura * altura);
}

float mediaTurma(float imc[], int qtd) {
    float soma = 0;
    int i;

    for (i = 0; i < qtd; i++) {
        soma += imc[i];
    }

    return soma / qtd;
}

int main() {
    float peso[QTD_ALUNOS];
    float altura[QTD_ALUNOS];
    float imc[QTD_ALUNOS];
    int i;

    for (i = 0; i < QTD_ALUNOS; i++) {
        printf("Digite o peso do aluno %d (kg): \n", i + 1);
        scanf("%f", &peso[i]);
        printf("Digite a altura do aluno %d (m): \n", i + 1);
        scanf("%f", &altura[i]);

        imc[i] = calculaIMC(peso[i], altura[i]);
    }

    exibirCabecalho();

    for (i = 0; i < QTD_ALUNOS; i++) {
        printf("Aluno %d - IMC: %.2f\n", i + 1, imc[i]);
    }

    printf("IMC medio da turma: %.2f\n", mediaTurma(imc, QTD_ALUNOS));

    return 0;
}