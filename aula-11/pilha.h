#ifndef PILHA_H
#define PILHA_H

typedef struct Item {

    int Chave; 
    struct Item *Anterior; 

} Item; 

typedef struct Pilha {

    int Tamanho;
    Item *Topo; 

} Pilha;


Item * criarItem(int Chave);

Pilha * criarPilha();

// manipulando elementos da pilha
// passa parametros atraves das variaveis
void empilhar(Pilha * P, Item * I);

void desempilhar(Pilha * P);

#endif