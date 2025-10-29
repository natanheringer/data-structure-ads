#ifndef MUSICA_H
#define MUSICA_H 

// nesta aplicação, Item é uma "musica"
typedef struct Item {

    // Dados das musicas
    // Ou chaves
    char Titulo[50];
    char Autor[100];
    int Ano;
    // estrutura da lista duplamente encadeada
    struct Item * Anterior; // musica que toca antes 
    struct Item * Posterior; // musica que toca depois

} Item; 

typedef struct Lista {

    char Nome [100]; // nome da playlist
    int Tamanho; 
    Item * Inicio; 
    Item * Fim; 

} Lista; 


// Prototipo das funções
Item * criarItem(char * Titulo, char * Autor, int Ano);
Lista * criarLista(char * Nome);

void exibirListaInicio(Lista * L);
void exibirListaFim(Lista * L);


#endif