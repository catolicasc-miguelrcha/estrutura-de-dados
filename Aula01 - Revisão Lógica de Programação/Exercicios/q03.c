//
// Created by miguel.xavier on 31/07/2026.
//
// Questão 3 - Conversor de medidas da oficina
// Uma oficina mecânica utiliza um terminal de consulta
// que converte medidas usadas no dia a dia da equipe.
// O programa deverá apresentar um menu com quatro opções
// de conversão: metros para centímetros, quilogramas para gramas, horas para minutos e litros para mililitros.
// O usuário deverá escolher uma opção e informar o valor a ser convertido. O sistema deverá apresentar o resultado da conversão escolhida e avisar quando a opção digitada não existir. Utilize a estrutura de seleção. Desenvolva um programa em C ANSI para resolver esse problema.

#include <stdio.h>

int conversorMCM() {
    float m;
    float cm;

    printf("Digite o valor em metros");
    scanf("%f", &m);

    float conversor = m * 100;

    printf("O valor em metros e: %.2f", conversor);
}

int conversorKGG() {
    float kg;
    float g;

    printf("Digite o valor em quilogramas");
    scanf("%f", &kg);

    float conversor = kg * 1000;

    printf("O valor em quilogramas e: %.2f", conversor);
}

int conversorHRM() {
    float hr;
    float m;

    printf("Digite o valor em horas");
    scanf("%f", &hr);

    float conversor = hr * 60;

    printf("O valor em minutos e: %.2f", conversor);
}

int conversorLML() {
    float l;
    float ml;

    printf("Digite o valor em litros");
    scanf("%f", &l);

    float conversor = l * 1000;

    printf("O valor em ml e: %.2f", conversor);
}

int menu(void) {
    int ch;
    do {
        printf("\n Conversor de medidas da oficina\n");
        printf("[1] m -> cm\n");
        printf("[2] kg -> g\n");
        printf("[3] hr -> min\n");
        printf("[4] l -> ml\n");
        printf("Digite a opcao: \n");
        scanf("%i", &ch);
        getchar();

        switch (ch) {
            case 1:
                conversorMCM();
                break;
            case 2:
                conversorKGG();
                break;
            case 3:
                conversorHRM();
                break;
            case 4:
                conversorLML();
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (ch != 4);

}

int main() {
    menu();
}