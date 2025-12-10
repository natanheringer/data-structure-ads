#include <stdio.h> // biblioteca do printf

// função que aplica o algoritmo de ordenação em um vetor
void bubbleSort(int numeroArray[], int quantidadeNumeros){
    // numeroArray: vetor de numeros a ser ordenado (declaração do vetor)
    // quantidadeNumeros: tamanho do vetor (quantidade de elementos no vetor)



    for (int i = 0; i < quantidadeNumeros - 1; i++){

        // Primeiro laço que controla quantas passadas faremos pelo vetor 
        // apos cada passada, o maior elemento sobe para o final do vetor 
        // exemplo 5, 3, 8, 4 
        // apos a primeira passada, o 8 estara na ultima posicao
        // apos a segunda passada, o 5 estara na penultima posição 
        // assim estará ordenado o vetor

        for (int j = 0; j < quantidadeNumeros - 1; j++){

            // Se o elemento atual for maior que o proximo elemento, trocamos eles de lugar 
            if (numeroArray[j] > numeroArray[j + 1]) {

                // guarda o valor da esquerda em uma variavel auxiliar
                // ou seja aux recebe o valor do numeroArray[j]
                int aux = numeroArray[j];

                // troca os valores de j e j + 1
                // que significa que o valor maior vai para a direita 
                numeroArray[j] = numeroArray[j + 1]; 

                // coloca o valor maior na direita
                // pois assim o vetor vai ficando ordenado
                numeroArray[j + 1] = aux; 

            }

        }
        
        // Exibe a quantidade de passadas necessárias para ordenar o vetor
        // sob a condição de que seja a última passada 
        if(i+1 >= quantidadeNumeros - 1)
        printf("\nForam necessarias %d passados pelo vetor de tamanho %d para que este fosse ordenado\n", i, quantidadeNumeros);
        
    }
        
}

int main () {

    int numeros[] = {64, 34, 25, 899, 22, 11, 90, 50, 2, 3, 53, 12, 765, 75, 53, 7, 6, 0, 9, 8, 120, 324, 56, 76, 30};
    // vetor a ser ordenado

    bubbleSort(numeros, 25);
    // chama a função bubbleSort, passando o vetor numeros e o tamanho 25
    printf("\nvetor ordenado: \n"); 
    for (int i = 0; i < 25; i++){
        
        printf("%d ", numeros[i]);
        // imprime o vetor ordenado  

    }

    return 0;

}




