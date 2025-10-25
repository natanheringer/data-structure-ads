#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int Chave;
    struct Item * Proximo; // para fazer o encadeamento dos elementos 
} Item;

int main() {


    system("cls");

    // alocação de memoria para o item
    Item * a = (Item *)malloc(sizeof(Item));
    Item * b = (Item *)malloc(sizeof(Item));
    Item * c = (Item *)malloc(sizeof(Item));
    Item * d = (Item *)malloc(sizeof(Item));
    
    a->Chave = 25; 
    b->Chave = 36; 
    c->Chave = 50; 
    d->Chave = 64; 

    a->Proximo = NULL; // ponteiro nao aponta para nada, nao inicializado 
    b->Proximo = NULL; // ponteiro nao aponta para nada, nao inicializado 
    c->Proximo = NULL; // ponteiro nao aponta para nada, nao inicializado 
    d->Proximo = NULL; // ponteiro nao aponta para nada, nao inicializado 
    
    // verificando o encadeamento 

        printf("\n antes de encadear na lista: \n");
        printf("a - %x \t %d \t %X \n", a, a->Chave, a->Proximo);
        printf("b - %x \t %d \t %X \n", b, b->Chave, b->Proximo);
        printf("c - %x \t %d \t %X \n", c, c->Chave, c->Proximo);
        printf("d - %x \t %d \t %X \n", d, d->Chave, d->Proximo);
        
    // Como verificar se c é o ultimo elemento da lista?

    if(c->Proximo == NULL ){

        printf("\nc eh o ultimo elemento da lista \n");
    } else {
        printf("existe item depois do c.\n\n");
    }

    // Dois itens diferentes podem ter o mesmo "Proximo"?

    Item * x = (Item *) malloc(sizeof(Item));
    Item * y = (Item *) malloc(sizeof(Item));
    
    x->Chave = 20;
    y->Chave = 45;

    x->Proximo = b;
    y->Proximo = b;

    printf("\n\nDois itens diferentes com o mesmo proximo, mas nao eh uma lista encadeada\n");
    printf("x - %x \t %d \t %X \n", x, x->Chave, x->Proximo);
    printf("y - %x \t %d \t %X \n", y, y->Chave, y->Proximo);
    
    // construindo a lista encadeada a, c, b, d

    a->Proximo = c;
    c->Proximo = b;
    b->Proximo = d;

        printf("\nApos o encadeamento da lista a, c, b, d: \n");
        printf("a - %x \t %d \t %X \n", a, a->Chave, a->Proximo);
        printf("b - %x \t %d \t %X \n", b, b->Chave, b->Proximo);
        printf("c - %x \t %d \t %X \n", c, c->Chave, c->Proximo);
        printf("d - %x \t %d \t %X \n", d, d->Chave, d->Proximo);

    printf("\n\na->Proximo->Proximo->Proximo->Chave: %d", a->Proximo->Proximo->Chave);
    printf("\n\n");
}