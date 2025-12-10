#include <stdio.h> // biblioteca do printf
#include <stdlib.h> // biblioteca do malloc e free

#define MAX 5 // define o tamanho máximo da pilha

// vetor que representa a pilha 
int pilha[MAX]; // os elementos da pilha serão armazenados aqui

// variavel que determina e controla o topo da pilha 
int topo = -1; // inicializa o topo como -1, indicando que a pilha está vazia
               // topo = 0 significa que há um elemento na pilha 
               // topo = 1 significa que há dois elementos na pilha, e assim por diante
               // topo = MAX - 1 significa que a pilha está cheia

// função PUSH que empilha inserindo um elemento no topo da pilha 
void push(int elemento) {

    if (topo == MAX - 1) {

        printf("Pilha cheia! Nao e possivel empilhar %d\n", elemento);
        return; 

    }

    topo++;
    pilha[topo] = elemento; // insere o elemento no topo da pilha
    printf("Empilhado: %d\n", elemento);

}

// função POP que desempilha removendo o elemento do topo da pilha 
int pop() {

    if (topo == -1) {

        printf("Pilha vazia! Nao e possivel desempilhar.\n");
        return -1; // retorna -1 para indicar que a pilha está vazia

    }

    int elemento = pilha[topo]; // obtém o elemento do topo da pilha
    topo--; // decrementa o topo para remover o elemento
    printf("Desempilhado: %d\n", elemento);
    return elemento; // retorna o elemento desempilhado

}

// função para imprimir os elementos atuais da pilha 
void imprimirPilha() {

    printf("Pilha atual: \n");
    if (topo == -1) {
        
        printf("Pilha vazia!\n");
        return;

    }

    for (int i = topo; i >= 0; i--) {

        printf("[%d]\n", pilha[i]); // imprime cada elemento do topo até a base 

    }

    printf("\n"); // nova linha após imprimir a pilha

}

int main() {

    push(10);
    push(20);
    push(30);
    imprimirPilha();

    pop();
    imprimirPilha();

    push(40);
    push(50);
    push(60); // tenta empilhar quando a pilha está cheia
    imprimirPilha();

    pop();
    pop();
    pop();
    pop(); // tenta desempilhar quando a pilha está vazia
    imprimirPilha();
    pop();
    pop();
    imprimirPilha();

    return 0; // encerra o programa com sucesso

}