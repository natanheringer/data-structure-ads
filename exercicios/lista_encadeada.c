#include <stdio.h>
#include <stdlib.h>


// primeiro bloco 
// definir struct 
// Chave e ponteiro(Proximo)
// Chave indica o inicio ou posição atual 
// Proximo indica a posição sucessora da chave
typedef struct Item {
    
    int Chave;
    struct Item * Proximo;

} Item; 

Item * criarItem(int Chave);
void exibirLista(Item * Inicio);

int main(){

    system("cls");

    Item * a = criarItem(20);
    Item * b = criarItem(30);
    Item * c = criarItem(40);
    Item * d = criarItem(59);

    a->Proximo = b;
    b->Proximo = c;
    c->Proximo = d; 
    //system( wmplayer )

    a->Proximo = b->Proximo; 
    free(b);
    
    exibirLista(a);

    c->Proximo = d->Proximo; 
    free(d);

    exibirLista(c);

}

Item * criarItem(int Chave){

    // pegando os bytes e organizando em itens 
    // safe guard para compiladores diferentes (portabilidade)
    

}