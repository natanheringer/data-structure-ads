#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "musica.h"

int main() {

    Item * D = criarItem("Aquarela                      ", "Toquinho                    ", 1983);
    Item * E = criarItem("Romaria                       ", "Renato Teixeira             ", 1978);
    Item * F = criarItem("Eu nasci há dez mil anos atrás", "Raul Seixas                 ", 1976);
    Item * G = criarItem("Cálice                        ", "Chico Buarque e Gilberto Gil", 1978);
    Item * H = criarItem("Tempo Perdido                 ", "Legião Urbana               ", 1986);
    Item * I = criarItem("Águas de Março                ", "Tom Jobim e Elis Regina     ", 1972);

    //printf("%s", F->Autor);

    D->Posterior = E;
    E->Posterior = F;
    F->Posterior = G;
    G->Posterior = H;
    H->Posterior = I;

    I->Anterior = H; 
    H->Anterior = G; 
    G->Anterior = F; 
    F->Anterior = E;
    E->Anterior = D;


    Lista * MinhaLista1 = criarLista("MPB");

    MinhaLista1->Inicio = D;
    MinhaLista1->Fim = I; 
    MinhaLista1->Tamanho = 6; 


    
    printf("\n");
    
    exibirListaFim(MinhaLista1);

    // questao 1 - excluir a musica mais recente da lista 

    G->Posterior = NULL; 
    MinhaLista1->Fim = G; 
    MinhaLista1->Tamanho--; 
    free(H);
    exibirListaInicio(MinhaLista1);

    // questao 2 - inserir aquarela antes de romaria 

    Item * X = criarItem ("Como Nossos Pais", "Elis Regina", 1976);

    D->Posterior = X; 
    X->Anterior = D; 

    X->Posterior = E; 
    E->Anterior = X; 



}
