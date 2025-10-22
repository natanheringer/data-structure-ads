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
    
      
        printf("a - %x \t %d \t %X \n", a, a->Proximo, a->Chave);
        printf("b - %x \t %d \t %X \n", b, b->Proximo, b->Chave);
        printf("c - %x \t %d \t %X \n", c, c->Proximo, c->Chave);
        printf("d - %x \t %d \t %X \n", d, d->Proximo, d->Chave);
        
    // 



}