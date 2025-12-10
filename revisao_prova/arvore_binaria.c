#include <stdio.h> // biblioteca do printf
#include <stdlib.h> // biblioteca do malloc e free

typedef struct No {

    int valor; // valor armazenado no nó
    struct No *esquerdo; // ponteiro para o filho esquerdo
    struct No *direito; // ponteiro para o filho direito 

} No; 

// função para criar um novo nó 

No* criarNo(int valorNo) {

    No *novo = (No *) malloc(sizeof(No)); // aloca memoria para o novo nó 

    novo->valor = valorNo; // atribui valor ao valor do nó  
    novo->esquerdo = NULL; // inicializa o ponteiro esquerdo como NULL, vazio 
    novo->direito = NULL; // inicializa o ponteiro direito como NULL, vazio 

    return novo; // retorna o ponteiro para o novo nó criado 

}

// função para inserir um valor na arvore binaria 
No* inserirNo(No *raiz, int valorNo) {

    if (raiz == NULL) {

        return criarNo(valorNo); // se a raiz for NULL, cria um novo nó e retorna ele 

    }

    if (valorNo < raiz->valor) { // se o valor a ser inserido for menor que o valor da raiz, insere a esquerda

        raiz->esquerdo = inserirNo(raiz->esquerdo, valorNo); // insere na subarvore esquerda

    } else { // caso contrário, insere á direita 
       
        raiz->direito = inserirNo(raiz->direito, valorNo); // insere na subarvore direita

    }

    return raiz; // retorna a raiz atualizada

}

// caminhamento da arvore em ordem esquerda-> raiz -> direita 
void emOrdem(No *raiz) {

    if (raiz == NULL) {
        
        return; // se o nó for vazio, retorna

    }

    emOrdem(raiz->esquerdo); // percorre a subarvore esquerda
    printf("%d ", raiz->valor); // visita o nó raiz
    emOrdem(raiz->direito); // percorre a subarvore direita

}

int main() {

    No *raiz = NULL; // começamos com a arvore vazia 

    raiz = inserirNo(raiz, 50); // insere o nó com valor 50
    raiz = inserirNo(raiz, 30); // insere o nó com valor 30
    raiz = inserirNo(raiz, 70); // insere o nó com valor
    raiz = inserirNo(raiz, 20); // insere o nó com valor 20
    raiz = inserirNo(raiz, 40); // insere o nó com valor 40

    printf("Caminhamento em ordem da arvore binaria: \n");
    emOrdem(raiz); // realiza o caminhamento em ordem da arvore, imprime os valores em ordem crescente
    printf("\n");

    return 0; // encerra o programa com sucesso

}
