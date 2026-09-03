//
// Created by miguel.xavier on 13/08/2026.
//

#include <stdio.h>
#include <ctype.h>

void paraMaiusculas(char *texto) {
    for (int i = 0; texto[i] != '\0'; i++) {
        texto[i] = toupper(texto[i]);
    }
}

int main() {
    char texto[100];

    printf("Informe um texto: ");
    scanf(" %[^\n]", texto);

    paraMaiusculas(texto);

    printf("%s\n", texto);

    return 0;
}
