#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int Chave;
    struct Item * Proximo; // para fazer o encadeamento dos elementos
} Item; 

Item * criarItem(int Chave);
void exibirLista(Item * Inicio); 

void inserirItem(Item * Inicio, Item * I, int Posicao);
void excluirItem(Item * Inicio, Item * I, int Posicao);

int main() {

    system("cls");

    Item * a = criarItem(25);
    Item * b = criarItem(36);
    Item * c = criarItem(50);
    Item * d = criarItem(64);

    a->Proximo = b;
    a->Proximo = c;
    c->Proximo = d;

    Item * P = criarItem(75);


    a->Proximo = b->Proximo;
    c->Proximo = d->Proximo;
    free(b);
    free(d);

    exibirLista(a);
    exibirLista(c);
}

Item * criarItem(int Chave){

    Item * x = (Item *) malloc(sizeof(Item));

    x->Chave = Chave; 

    x->Proximo = NULL;

    return x; 

}

void exibirLista(Item * Inicio){

    Item * x = (Item *) malloc (sizeof(Item));
    printf("\n");


    printf("Caminhando pela lista atraves do for: \n\n");
    for (x = Inicio; x != NULL; x = x->Proximo){
        printf("%x \t %d \t %X \n", x, x->Chave, x->Proximo);
    }


}