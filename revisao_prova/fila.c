#include <stdio.h> // biblioteca do printf
#include <stdlib.h> // biblioteca do malloc e free

#define MAX 5 // define o tamanho máximo da fila

// armazena a fila como um array de inteiros(5 elementos)
int fila[MAX]; // array que representa a fila

int primeiro = 0; // indica o indice(posição) do primeiro elemento da fila
int ultimo = 0; // indica o indice(posição) do último elemento da fila, onde entra o proximo elemento
int tamanho = 0; // armazena o tamanho atual da fila

// função para inserir um elemento na fila 
void enfileirar(int valor) {

    if (tamanho == MAX){

        printf("Fila cheia! Nao e possivel enfileirar %d\n", valor);
        return;

    }

    fila[ultimo] = valor; // insere o valor na posição 'ultimo' da fila
    ultimo = (ultimo + 1) % MAX; // atualiza o indice do último elemento, usando modulo para circular
    tamanho++; // incrementa o tamanho da fila 
    printf("Enfileirado: %d\n", valor);

}

int desenfileirar() {

    if (tamanho == 0) {

        printf("Fila vazia! Nao e possivel desenfileirar.\n");
        return -1; // retorna -1 para indicar que a fila está vazia

    }

    int valor = fila[primeiro]; // obtém o valor do primeiro elemento da fila
    primeiro = (primeiro + 1) % MAX; // atualiza o indice do primeiro elemento, usando modulo para circular
    tamanho--; // decrementa o tamanho da fila
    printf("Desenfileirado: %d\n", valor);

    return valor; // retorna o valor desenfileirado

}

void imprimirFila() {

    printf("Fila atual: ");

    int indice = primeiro; 
    
    for(int i = 0; i < tamanho; i++) {

        printf("[%d]", fila[indice]); // imprime o elemento na posição atual
        indice = (indice + 1) % MAX; // avança para o próximo índice, usando modulo para circular
        
    }

    printf("\n"); // nova linha após imprimir a fila

}

int main() {

    enfileirar(10);
    enfileirar(20);
    enfileirar(30);
    imprimirFila();

    desenfileirar();
    imprimirFila();

    enfileirar(40);
    enfileirar(50);
    enfileirar(60);
    imprimirFila();

    desenfileirar();
    desenfileirar();
    imprimirFila();

    enfileirar(70);
    imprimirFila();

    return 0;

}