//
// Created by miguel.xavier on 13/08/2026.
//

#include <stdio.h>

#define VETOR_ANIMAIS 10

typedef struct {
    char raca[50];
    char cor[50];
    char sexo[1];
    double peso;
} Animal;

void lerAnimal(Animal *a) {
   
    for (int i = 0; i < VETOR_ANIMAIS; i++) {
        printf("Informe a raça do animal %d: ", i + 1);
        scanf("%s", a[i].raca);

        printf("Informe a cor do animal %d: ", i + 1);
        scanf("%s", a[i].cor);

        printf("Informe o sexo do animal %d (M/F): ", i + 1);
        scanf("%s", a[i].sexo);

        printf("Informe o peso do animal %d: ", i + 1);
        scanf("%lf", &a[i].peso);
    }

}

void imprimirAnimal(Animal *a) {
    
    for (int i = 0; i < VETOR_ANIMAIS; i++) {
        printf("\nAnimal %d:\n", i + 1);
        printf("Raça: %s\n", a[i].raca);
        printf("Cor: %s\n", a[i].cor);
        printf("Sexo: %s\n", a[i].sexo);
        printf("Peso: %.2lf\n", a[i].peso);
    }

}

int main() {
    Animal animais[VETOR_ANIMAIS];

    lerAnimal(animais);
    imprimirAnimal(animais);

    return 0;
}