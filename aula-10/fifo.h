#ifndef FIFO_H
#define FIFO_H

//========================================================//
//    Definindo da estrutura do Item da fila encadeada    //
//========================================================//
typedef struct Item {

    int Chave; // elemento
    struct Item * Proximo;

}Item;

typedef struct Fila {

    Item * Inicio;
    Item * Fim; 
    int Tamanho;

}Fila;

// prototipos
Item * criarItem(int Chave);
Fila * criarFila();
void * enfileirar(Fila * F, Item * I);
void * exibirFila(Fila * F);
void desenfileirar(Fila * F);

#endif