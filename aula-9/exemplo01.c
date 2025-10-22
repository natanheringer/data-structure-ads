#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int Chave;
    struct Item * Proximo; // para fazer o encadeamento dos elementos 
} Item;

int main() {


    system("cls");

    // alocação de memoria para o item
    Item * x = (Item *)malloc(sizeof(Item));
    x->Chave = 98; 
    x->Proximo = NULL; // ponteiro nao aponta para nada, nao inicializado 
    
        printf("Endereco de memoria (hexadecimal): %p\n", x);
        printf("Endereco de memoria (binario octal): %o\n", x);
        
        printf("x->Chave: %d\n", x->Chave);
        printf("x->Proximo%d\n", x->Proximo);
        
    // obs:



}