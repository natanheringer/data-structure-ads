#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

Item * criarItem(int Chave) {

    Item * I = (Item *) malloc(sizeof(Item));

    if (I == NULL) {

        printf("ERRO: nao há espaço em memória para mais um item!\n");
        return NULL; 

    }

    I->Chave = Chave; 
    I->Anterior = NULL; 

    return I; 

}

Pilha * criarPilha() {

    Pilha * P = (Pilha *) malloc(sizeof(Pilha));

    if (P == NULL) {

        printf("ERRO: Não há memória para a pilha");
        return NULL; 

    }

    // Inicializa a pilha como 0 
    P->Tamanho = 0; 
    // inicializa o topo dela como nulo
    P->Topo = NULL; 

    // retorna a variavel pilha
    return P; 

}

void empilhar(Pilha * P, Item * I) {

    if (I == NULL) {

        printf("ERRO: Item nulo!\n");
        

    }

    // modificando ponteiros 
    I->Anterior = P->Topo; // inserindo o I acima do antigo topo da pilha
    P->Topo = I; // Atualizando o topo da pilha para I 

    P->Tamanho++; //
     
}

// desfaz as operações do empilhar
void desempilhar(Pilha * P) {

    if(P->Topo == NULL) {

        printf("ERRO: stack underflow!\n");
        return;
    }

    // topo da pilha é o ultimo 
    Item * I = P->Topo;
    // novo topo da pilha é o inserido antes do I
    P->Topo = I->Anterior;
    //Liberar memoria do ultimo
    free(I);
    // diminui o tamanho da pilha em 1
    P->Tamanho--;

}