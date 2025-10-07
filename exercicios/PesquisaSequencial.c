#include <stdlib.h> 
#include <stdio.h>


#define ERRO -1 // indicador de que o elemento nao esta no vetor 


// prototipo da função 
int pesquisaSequencial(int arr[], int n, int chave);

// função principal 
int main() {
    // array de exemplo, 30 elementos 
    int numeros[] = {1,8,2,1,65,245,52,12,478,12,1,21,3,4,5,6,5,4,7,8,9,2,10,11,23,10,10,28,29,30};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
    int elemento; 
    int resultado; 

    // chama o elemento a ser pesquisado dentro do array 
    printf("\n Digite o elemento a buscar: ");
    scanf("%d", &elemento);

    // chama a funçãoo de pesquisa sequencial 
    resultado = pesquisaSequencial(numeros, tamanho, elemento);

    // verifica o resultado e imprime a posição ou mensagem de erro 
    if (resultado != ERRO){
        printf("Elemento %d encontrado na posicao %d\n", elemento, resultado);
    } else {
        printf("Elemento %d nao encontrado no vetor", elemento);
    }

}

int pesquisaSequencial(int arr[], int n, int chave) {

    int i; 

    for (i = 0; i < n; i++){
        if(arr[i] == chave){
            return i; // retorna a posição do elemento encontrado 
        }
    }

    // se pulou para cá, o elemento não foi encontrado
    return ERRO;

}