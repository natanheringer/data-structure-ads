#include <stdio.h>
#include <stdlib.h>
#include <time.h> // data e hora


// rand(): gera um número pseudo-aleatório
// srand(): estabelece um ponto de partida para gerar número

#define TAMANHO 1000

int main() {


    int V[TAMANHO]; // vetor de tamanho 20

    srand(time(NULL));
    for (int i = 0; i < TAMANHO; i++) V[i] = rand() % 100;

    // disparar tempo de execução (monitoramento de tempo de uso de CPU)
    clock_t T0 = clock();
    
    for (int i = 0; i < TAMANHO; i++) printf("%d\t", V[i]);
    clock_t TF = clock();

    double TempoCPU = ((double)(TF - T0)) / CLOCKS_PER_SEC;

    printf("\n\ninicio: %d", T0);
    printf("\n\nfim: %d", TF);
    printf("\n\nTempo de CPU: %f", TempoCPU);

}