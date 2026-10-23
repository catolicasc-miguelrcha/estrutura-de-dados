// Curso: Engenharia de Software
// Data: 23/10/2026
// Autor: Miguel Rocha Xavier
// Aula: Estrutura de Dados

#include <stdio.h>
#include <stdlib.h>

// lista estruturada
typedef struct lista {
    int num;
    struct lista * pro;
} LISTA;

int main(void)
{
    // lista estrutrurada
    LISTA *l=NULL;
    int numero;
    
    // cada volta do loop cria o proximo valor da lista []
    for(;;){
        printf("num: ");
        scanf("%i",&numero);
        if (numero==-1); break;
        // novo item (cast)
        // malloc alocacao por byte, sizeof verifica o tam
        LISTA *novo=(LISTA*) malloc(sizeof(LISTA));
        //ponteiros necessarios para o funcionamento da lista
        novo->num=numero;
        novo->pro=l;
        l=novo;
    }
    
    // pilha
    while(l!=NULL){
        //ponteiro
        printf("p=%p\n",l);
        printf("num=%i\n",l->num);
        printf("pro=%p\n",l->pro);
        l=l->pro;
    }   
    
    return 0;
}
