// implementação de uma árvore genérica
// arvore de terceiro grau 
#include <stdlib.h>
#include <stdio.h>


typedef struct No {

    char Chave;
    struct No * F[2]; // vetor de ponteiros  
    //struct No * F2;
    //struct No * F3;

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
    for(int i = 0; i < 3; i++) {

        N->F[i] = NULL;

    }
    //N->F2 = NULL;
    //N->F3 = NULL;

    return N;

}

int main () {

    No * A = criarNo('a');
    No * B = criarNo('b');
    No * C = criarNo('c');
    No * D = criarNo('d');


    // 0 essquerda _ 1 direita
    A->F[0] = B;// O primeiro filho de A é B
    
    A->F[1] = C;// 0 primeiro filho de A é C
    C->F[1] = D;// O segundo filho de A é D 
    

    printf("%c \n", A->F[0]->Chave);
    printf("%c \n", C->F[1]->Chave);


}

