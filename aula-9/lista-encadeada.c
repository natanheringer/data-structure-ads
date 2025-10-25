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

    // alocação de memoria para o item
    Item * a = criarItem(25);
    Item * b = criarItem(36);
    Item * c = criarItem(50);
    Item * d = criarItem(64);
       
    // construindo a lista encadeada a, c, b, d

    a->Proximo = b;
    b->Proximo = c;
    c->Proximo = d;
    
    // exibirLista(a);

    // Inserir o item P, de chave 75, entre os itens b e c da lista

    Item * P = criarItem(75);
    b->Proximo = P;
    P->Proximo = c;

    // exibirLista(a);

    // excluir o item b da lista

    // a->Proximo = P;
    // ou:

    a->Proximo = b->Proximo; 
    free(b);

    exibirLista(a);

}

Item * criarItem(int Chave){
    
    Item * x = (Item *) malloc(sizeof(Item));

    x->Chave = Chave;

    x->Proximo = NULL;

    return x;

}

void exibirLista(Item * Inicio){
    
    // pegando os bytes e organizando em itens 
    // safe guard para compiladores diferentes (portabilidade)
    Item * x = (Item *) malloc (sizeof(Item));
    printf("\n");

    // caminhando pela lista pelo for

    printf("\npelo for: \n\n");

    for (x = Inicio; x != NULL; x = x->Proximo){
        printf("%x \t %d \t %X \n", x, x->Chave, x->Proximo);
    }

}