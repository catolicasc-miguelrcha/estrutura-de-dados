//
// Created by miguel.xavier on 13/08/2026.
//

#include <stdio.h>
#include <stdlib.h>


int fatorial(int k);


int main() {

    int k, fat = 1;

    printf("fat: ");
    scanf("%i", &k);
    

    fat = fatorial(k);

    printf("%i", fat);

    return 0;
}

// loop
int fatorial(int k) {
    if(k==1) {return 1;}
    return k*fat(k-1);
}
