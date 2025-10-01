#include <stdio.h>
#include <stdlib.h>

#define ERRO -1 // usado como indicador que o elemento nao esta no vetor

int PesquisaBinaria (int * V, int N, int Chave);
int PesquisaBinariaRecursiva (int * V, int Esquerda, int Direita, int Chave);

int main(){
    int Numeros[] = {1, 2, 4, 5, 6, 7, 8, 10, 12, 14, 15, 16, 18, 20, 21, 22}; // declarar o vetor
    int Tamanho = sizeof(Numeros) / sizeof(Numeros[0]);
    int Elemento = 35; 

    int Posicao; 
    Posicao = PesquisaBinaria(Numeros, Tamanho, Elemento);
    Posicao = PesquisaBinariaRecursiva(Numeros, 0, Tamanho - 1, Elemento); 

    if (Posicao == ERRO){
        printf("O Elemento [%d] nao esta no vetor!\n\n", Elemento);
    } else {
        printf("O Elemento [%d] esta na posicao %d\n\n", Elemento, Posicao);
    }

}

// Versao iterativa 

int PesquisaBinaria(int * V, int N, int Chave){

        // variavel para esquerda direita e meio 

        int Esquerda = 0; // inicio da particao
        int Direita = N - 1; // final da particao 

        while(Esquerda <= Direita){
            int Meio = (Esquerda + Direita) / 2;
            if(V[Meio] == Chave){
                return Meio; 
            } else if(V[Meio] < Chave){
                Esquerda = Meio + 1; // descartando a parte do meio e o que esta antes dela 
            } else {
                Direita = Meio - 1; // descartando parte do meio e o que esta depois dela
            }
        }
        // se nao achar 
        return ERRO; 

    }

    // versao recursiva 

    int PesquisaBinariaRecursiva(int * V, int Esquerda, int Direita, int Chave){

        if(Esquerda > Direita){
            return ERRO; 
        }

        int Meio = (Esquerda + Direita) / 2;

        if(V[Meio] == Chave) {
            return Meio;
        } else if(V[Meio] < Chave){
            return PesquisaBinariaRecursiva(V, Meio + 1, Direita, Chave);
        } else {
            return PesquisaBinariaRecursiva(V, Esquerda, Meio - 1, Chave);
        }


    }