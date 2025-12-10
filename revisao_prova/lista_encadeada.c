#include <stdio.h> // biblioteca do printf 
#include <stdlib.h> // biblioteca do malloc e free 

typedef struct No {
    int valor; // valor inteiro armazenado no nó
    struct No *proximo; // ponteiro que aponta para o proximo nó da lista 
} No;

// função que cria o nó e retorna o ponteiro para ele 
No* criarNo(int valor) {

    No *novoNo = (No *) malloc (sizeof(No)); // aloca memoria para um novo nó

    novoNo->valor = valor; // atribui o valor ao nó
    novoNo->proximo = NULL; // inicializa o ponteiro proximo como NULL

    return novoNo; // retorna o ponteiro para o novo nó criado

}

No* inserirNo(No *inicio, int valor) {

    No *novo = criarNo(valor); // cria um novo nó com o valor desejado

    novo->proximo = inicio; // o próximo do novo nó aponta para o início atual da lista
                            // isso faz o no se tornar o cabeça da lista

    return novo; // retorna o novo nó que agora é o início da lista

}

void imprimirLista(No *p) {

    printf("Lista Encadeada: \n");

    while (p != NULL) { // percorre a lista até o final (NULL)

        printf("No: %X \t Valor: %d \t Proximo: %X\n", p, p->valor, p->proximo); // imprime o endereço do nó, seu valor e o endereço do próximo nó

        p = p->proximo; // avança para o próximo nó

    }

}

int main() {

    No *inicio = NULL; // inicializa o inicio da lista como NULL, vazia 

    inicio = inserirNo(inicio, 10); // insere o nó com valor 10
    inicio = inserirNo(inicio, 20); // insere o nó com valor 20
    inicio = inserirNo(inicio, 30); // insere o nó com valor 30
    inicio = inserirNo(inicio, 40); // insere o nó com valor 40
    inicio = inserirNo(inicio, 50); // insere o nó com valor 50

    imprimirLista(inicio); // percorre e imprime a lista encadeada

    return 0; // encerra o programa com sucesso

}
