#include <stdlib.h>
#include <stdio.h>

typedef struct Item {

    int Chave;
    struct Item * Proximo; // ponteiro para fazer encadeamento dos elementos

} Item;

// prototipo da função criarItem 
Item * criarItem(int Chave);
// prototipo da função exibirLista
void exibirLista(Item * Inicio);

int main() {

    system("cls");

    Item * a = criarItem(10);
    Item * b = criarItem(20);
    Item * c = criarItem(30);
    Item * d = criarItem(40);

    a->Proximo = b;
    b->Proximo = c;
    c->Proximo = d;

    exibirLista(a);
    exibirLista(b);
    free(a);
    free(b);

    return 0; 

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