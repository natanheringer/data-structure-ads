#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

int main() {

    system("cls");
    //system("gcc pilha.c");
    // Pilha criada 
    // Stack é uma variavel do tipo pilha que guarda um endereço de memória
    // é o endereço da pilha 
    Pilha * Stack = criarPilha();

    empilhar(Stack, criarItem(12));
    empilhar(Stack, criarItem(17));
    empilhar(Stack, criarItem(25));
    empilhar(Stack, criarItem(40));
    empilhar(Stack, criarItem(90));

    desempilhar(Stack);
    
    printf("%d", Stack->Topo->Chave);



}