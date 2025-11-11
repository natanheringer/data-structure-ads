<<<<<<< HEAD
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
=======
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
>>>>>>> b774f88f07f2f76caf23a667e95a548cf2c87905

}

Item * criarItem(int Chave){

<<<<<<< HEAD
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

=======
    // pegando os bytes e organizando em itens 
    // safe guard para compiladores diferentes (portabilidade)
    
>>>>>>> b774f88f07f2f76caf23a667e95a548cf2c87905

}