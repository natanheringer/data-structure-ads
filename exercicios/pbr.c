#include <stdio.h>
#include <stdlib.h>

#define ERRO -1 // indicador que o elemento nao esta no vetor


// prototipos de funcoes
int PesquisaBinariaRecursiva(int * V, int Esquerda, int Direita, int Chave);

int main(){
    // declaracao do array a ser pesquisado 
    int Numeros[] = {1,2,3,4,5,6,7,8,10,12,14,15,16,16,17,18,19,20,21,22,24,26,28,29,33,34,40,50};
    // tamanho da operacao (?)
    int Tamanho = sizeof(Numeros) / sizeof(Numeros[0]);
    int Elemento;

    printf("\n\nselecione o elemento\n\n");
    scanf("%d", &Elemento); 

    // Posicao do elemento a ser usado para dividir o array
    int Posicao;
    // declaracao da primeira posicao (?)
    Posicao = PesquisaBinariaRecursiva (Numeros, 0, Tamanho - 1, Elemento);


    // Funcao que mostra a posicao que o numero escolhido esta 
    // ou se nao estiver, avisa que nao esta no array
    if(Posicao == ERRO){
        printf("O Elemento [%d] nao esta no vetor!\n\n", Elemento);
    } else {
        printf("O Elemento [%d] esta na posicao %d\n\n", Elemento, Posicao);
    }

}

// Versao Recursiva
int PesquisaBinariaRecursiva(int * V, int Esquerda, int Direita, int Chave){

    if(Esquerda > Direita){
        return ERRO;
    }
    // para descobrir o centro do array,
    // pega a direita e esquerda e divide ao meio 
    int Meio = (Esquerda + Direita) / 2;

    // Realizacao da funcao que determina os passos 
    // de dividir o  array no meio até encontrar o Elemento
    if(V[Meio] == Chave){
        return Meio; // se a chave for exatamente o numero do meio, retorna ele rapidamente
    } else if (V[Meio] < Chave){
        // se o Elemento estiver acima do meio, executa 
        // excluindo o que for anterior ao meio
        return PesquisaBinariaRecursiva(V, Meio + 1, Direita, Chave);
    } else {
        // senao, exclui o que esta depois do meio 
        return PesquisaBinariaRecursiva(V, Esquerda, Meio - 1, Chave);  
    }
}
