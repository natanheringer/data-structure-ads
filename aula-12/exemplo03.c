// implementação de uma árvore genérica
// arvore de terceiro grau 
#include <stdlib.h>
#include <stdio.h>


typedef struct No {

    char Chave;
    struct No * Esquerdo; // vetor de ponteiros  
    struct No * Direito; // vetor de ponteiros  
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
    
    N->Esquerdo = NULL;
    N->Direito = NULL;


    
    //N->F2 = NULL;
    //N->F3 = NULL;

    return N;

}

// função para contar os nós

int contarNos(No * N) {

    if ( N == NULL ) {

        return 0;

    } else {

        return 1 + contarNos(N->Esquerdo) + contarNos(N->Direito);

    }

}

// função para calcular altura


int contarNos(No * N) {

    if ( N == NULL ) {

        return 0;

    } else {

        

    }

}


int main () {

    // primeiro nivel: 10 

    No * Raiz = criarNo(10);

    // segundo nivel: 12 e 15

    Raiz->Esquerdo = criarNo(12);
    Raiz->Direito = criarNo(15);

    // terceiro nivel: 16, 18 e 20

    Raiz->Esquerdo->Esquerdo = criarNo(16);
    Raiz->Esquerdo->Direito = criarNo(18);
    Raiz->Direito->Direito = criarNo(20);
    
    // quarto nivel: 17 19 

    Raiz->Direito->Direito->Esquerdo = criarNo(17);
    Raiz->Direito->Direito->Direito = criarNo(20);
    
    // teste: 
    printf("Quantidade de nos: %d \n", contarNos(Raiz));

}

