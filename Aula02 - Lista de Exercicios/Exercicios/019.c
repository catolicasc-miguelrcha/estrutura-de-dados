//
// Created by miguel.xavier on 13/08/2026.
//
// Atenção: usa windows.h, só compila no Windows.
//

#include <stdio.h>
#include <windows.h>

void imprimirNaPosicao(int linha, int coluna, char *msg) {
    COORD pos;
    pos.X = coluna;
    pos.Y = linha;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    printf("%s", msg);
}

int main() {
    int linha, coluna;
    char msg[100];

    printf("Informe a linha: ");
    scanf("%d", &linha);

    printf("Informe a coluna: ");
    scanf("%d", &coluna);

    printf("Informe a mensagem: ");
    scanf(" %[^\n]", msg);

    imprimirNaPosicao(linha, coluna, msg);

    return 0;
}
