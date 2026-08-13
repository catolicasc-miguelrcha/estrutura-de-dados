//
// Created by miguel.xavier on 13/08/2026.
//

#include <stdio.h>
#include <math.h>

void bhaskara(float a, float b, float c, float *x1, float *x2) {
    float delta = b * b - 4 * a * c;

    if (delta < 0) {
        printf("Sem raízes reais\n");
        *x1 = *x2 = NAN;
        return;
    }

    *x1 = (-b + sqrt(delta)) / (2 * a);
    *x2 = (-b - sqrt(delta)) / (2 * a);
}

int main() {
    float a, b, c, x1, x2;

    printf("Informe o valor de a: ");
    scanf("%f", &a);

    printf("Informe o valor de b: ");
    scanf("%f", &b);

    printf("Informe o valor de c: ");
    scanf("%f", &c);

    bhaskara(a, b, c, &x1, &x2);

    if (!isnan(x1)) {
        printf("x1 = %.2f\n", x1);
        printf("x2 = %.2f\n", x2);
    }

    return 0;
}
