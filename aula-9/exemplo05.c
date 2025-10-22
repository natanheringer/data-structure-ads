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
    
    // construindo a lista encadeada a, c, b, d

    a->Proximo = b;
    b->Proximo = c;
    c->Proximo = d;
    
    // pegando os bytes e organizando em itens 
    // safe guard para compiladores diferentes (portabilidade)
    Item * x = (Item *) malloc (sizeof(Item));

    // caminhando pela lista pelo for

    printf("\npelo for: \n\n");

    for (x = a; x != NULL; x = x->Proximo){
        printf("%x \t %d \t %X \n", x, x->Chave, x->Proximo);
    }

    printf("\n");

    // caminhando pela lista manualmente
    
    printf("\npelo modo manual: \n\n");

    x = a; // x aponta para a
 
    printf("%x \t %d \t %X \n", x, x->Chave, x->Proximo); // = 25, x = a

    x = x->Proximo;
       
    printf("%x \t %d \t %X \n", x, x->Chave, x->Proximo); // = 36, x = b

    x = x->Proximo;
       
    printf("%x \t %d \t %X \n", x, x->Chave, x->Proximo); // = 50, x = c

    x = x->Proximo;
       
    printf("%x \t %d \t %X \n", x, x->Chave, x->Proximo); // = 64, x = d
  

    // caminhando pela lista por um while 

    printf("\n");
    printf("\npelo while: \n\n");

    x = a;

    while( x != NULL ) {
        printf("%x \t %d \t %X \n", x, x->Chave, x->Proximo);
        x = x->Proximo;
        
    }

}