//
// Created by miguel.xavier on 13/08/2026.
//

#include <stdio.h>
#include <ctype.h>

void primeiraMaiuscula(char *nome) {
    int inicioPalavra = 1;

    for (int i = 0; nome[i] != '\0'; i++) {
        if (nome[i] == ' ') {
            inicioPalavra = 1;
            continue;
        }

        if (inicioPalavra && islower(nome[i])) {
            nome[i] = toupper(nome[i]);
        }

        inicioPalavra = 0;
    }
}

int main() {
    char nome[100];

    printf("Informe o nome completo: ");
    scanf(" %[^\n]", nome);

    primeiraMaiuscula(nome);

    printf("%s\n", nome);

    return 0;
}
