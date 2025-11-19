// implementação de uma árvore genérica
// arvore de terceiro grau 
#include <stdlib.h>
#include <stdio.h>


typedef struct No {

    char Chave;
    struct No * F1;
    struct No * F2;
    struct No * F3;

} No;


No * criarNo (char Chave) {
    // N para armazenar o nó
    // alocação de memoria para o nó
    No * N = (No *) malloc(sizeof(No));

    if (N == NULL) {

        printf("ERRO: não há espaço em memoria para armazenar o nó\n\n");
        return NULL;

    }

    N->Chave = Chave; 
    N->F1 = NULL;
    N->F2 = NULL;
    N->F3 = NULL;

    return N;

}

int main () {

    No * A = criarNo('a');
    No * B = criarNo('b');
    No * C = criarNo('c');
    No * D = criarNo('d');

    A->F1 = B;// 0 primeiro filho de A é B
    A->F2 = C;// O segundo filho de A é C 
    A->F3 = D;// O terceiro filho de A é C 

    printf("%c \n", A->F2->Chave);


}

