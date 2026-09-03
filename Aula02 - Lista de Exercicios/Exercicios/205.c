//
// Created by miguel.xavier on 13/08/2026.
//

#include <stdio.h>

void areaCirculo(float r, float *area) {
    const float PI = 3.141592;

    *area = PI * r * r;
}

int main() {
    float r, area;

    printf("Informe o raio do círculo: ");
    scanf("%f", &r);

    areaCirculo(r, &area);

    printf("Área: %.2f\n", area);

    return 0;
}
