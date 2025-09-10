#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// prototipos funcoes 

void insertionSort(int * V, int N);
void showVector(int * V, int N);

// obs
// * V = passagem de parametro por REFERENCIA(PONTEIROS)
// N = passagem de parametro por VALOR 




int main() {
    //declarar vetor 
    int Conjunto[] = {1, 9, 7, 8, 5, 2}; //24 bytes 
    int Tamanho = sizeof(Conjunto) / sizeof(int);
    
    clock_t T0 = clock();
    insertionSort(Conjunto, Tamanho);
    clock_t TF = clock();

    // pedir para ordenar vetor 
    showVector(Conjunto, Tamanho);

    double TempoCPU = (double) (TF - T0) / CLOCKS_PER_SEC;
    printf("Tempo de CPU(ticks): %f\n", TempoCPU);



}


// implementacao das funcoes auxiliares 
void insertionSort(int * V, int N){
    // primeiro elemento depois da parte ordenada(primeiro eleento da parte NÃO ordenada) 
    int Chave;
    // coordenada da chave (posicao)
    int i;
    // comparador da posicao da chave com os elementos ordenados
    int j; 

    for(i = 1; i < N; i++){
        Chave = V[i];
        j = 1 - 1;


        while(V[j] > Chave && j >= 0){
                V[j + 1] = V[j];
                j--;
        }

        V[j + 1] = Chave;
   

    }

}
void showVector(int * V, int N){

    int i;

    for(i = 0; i < N; i++){
        printf("%d\t", V[i]);
    }
    printf("\n");

}