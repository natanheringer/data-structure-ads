#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "musica.h"


Item * criarItem(char * Titulo, char * Autor, int Ano){

    Item * M = (Item *) malloc(sizeof(Item));

    if (M == NULL) {
        printf("Erro: nao existe memoria para o item (musica). \n");
        return NULL; 
    } 

    strcpy(M->Titulo, Titulo);
    strcpy(M->Autor, Autor);
    M->Ano = Ano;
    M->Anterior = NULL ;
    M->Posterior = NULL;

    return M; 

}

Lista * criarLista(char * Nome) {
    
    Lista * L = (Lista *) malloc(sizeof(Lista));
    
    if ( L == NULL ) {
        printf("ERRO: não foi possivel alocar memoria para a lista.\n");
        return NULL; 
    } 

    strcpy(L->Nome, Nome);
    L->Tamanho = 0;
    L->Inicio = NULL;
    L->Fim = NULL; 

    return L;

}

void exibirListaInicio(Lista * L){
    
    Item * Atual = L->Inicio;
    for (int i = 1; Atual != NULL; i++){
        printf("%d \t %s \t %s \t %d \n", i, Atual->Titulo, Atual->Autor, Atual->Ano);
        Atual = Atual->Posterior;
    }

    printf("\n");

}

void exibirListaFim(Lista * L){

    Item * Atual = L->Fim;
    for (int i = 1; Atual != NULL; i++){
        printf("%d \t %s \t %s \t %d \n", i, Atual->Titulo, Atual->Autor, Atual->Ano);
        Atual = Atual->Anterior;
    }

    printf("\n");

}