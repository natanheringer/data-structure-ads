#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int Chave; // chave do item (o que é chave? chave é um campo que identifica unicamente um item)
    struct Item * Proximo; // encadeamento dos elementos
} Item;

Item * criarItem(int Chave);
void exibirLista(Item * Inicio);