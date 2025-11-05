#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fifo.h"

//========================
// Declaração das funções 
//========================
Item * criarItem(int Chave){

    Item * x = (Item *) malloc(sizeof(Item));

    if (x == NULL) {
        printf("Erro: nao existe memoria para o item (musica). \n");
        return NULL; 
    } 

    x->Chave = Chave;
    x->Proximo = NULL;
    
    return x; 

}

//=============================================
// Alocação de memoria para a criação da fila 
//=============================================
Fila * criarFila() {

    Fila * F = (Fila *) malloc(sizeof(Fila));

    if(F == NULL){
        printf("ERRO: nao foi posivel alocar memoria para a fila");
        return NULL; 
    }

    // Inicializações 
    // tamanho da fila é igual a zero 
    F->Tamanho = 0;
    F->Inicio = NULL;
    F->Fim = NULL; 

    return F; 

}

void * enfileirar(Fila * F, Item * I){

    // verifica se a fila está vazia e insere o elemento
    if(F->Tamanho == 0){
        F->Inicio = I;
    } else {
        F->Fim->Proximo = I; 
    }

    F->Fim = I; 
    // incrementa
    F->Tamanho++;

}

void * exibirFila(Fila * F) {

    Item * x = (Item *) malloc(sizeof(Item));

    for(x = F->Inicio; x != NULL; x = x->Proximo){
        printf("%d \t", x->Chave);
    }

    printf("\n");

}

void desenfileirar(Fila * F){

    if(F->Tamanho == 0){
        printf("ERRO: a fila esta vazia");
        return;
    } 

    Item * Atual = F->Inicio;

    F->Inicio = F->Inicio->Proximo;
    free(Atual);
    F->Tamanho--; 
        
}