#include <stdio.h> // biblioteca do printf

int buscaBinaria(int numeroArray[], int quantidadeNumeros, int numeroRequerido) {
    // numeroArray: vetor onde vamos procurar o numeroRequerido 
    // quantidadeNumeros: tamanho do Array
    // numeroRequerido: numero que queremos encontrar no vetor

    // Definindo os índices inicial e final para a busca
    int inicio = 0;                  // indice inicial do vetor
                                     // começa na posição 0 do vetor

    int fim = quantidadeNumeros - 1; // fim representa o limite direito do vetor 
                                     // ou seja, na ultima posição do vetor 

    while (inicio <= fim) {

        int meio = (inicio + fim) / 2; // calcula o indice do meio do vetor 

        // Verifica se o numeroRequerido está na posição do meio
        if (numeroArray[meio] == numeroRequerido) {

            return meio; // retorna a posição do numeroRequerido encontrado, que é o meio

        } else if (numeroArray[meio] < numeroRequerido) {
            // se o valor do meio for menor que o numeroRequerido

            // Ajusta o inicio para buscar na metade direita do vetor 
            // "exclui" a metade esquerda do vetor 
            inicio = meio + 1; 
            
        } else {
            // caso contrario, se o valor do meio for maior que o numeroRequerido 
            // significa que o numeroRequerido está na metade esquerda do vetor 

            // Portanto, ajusta o fim para buscar na metade esquerda do vetor
            // excluindo a metade direita da busca
            fim = meio - 1;

        }

        
    }
    
    // saimos do while, não encontramos o elemento, retornamos -1 
    return -1;

}

int main() { 

    int numeros[] = {3, 12, 23, 34, 45, 56, 67, 78, 89, 90}; // vetor de numeros para teste
    int posicao = buscaBinaria(numeros, 10, 67); // chama a função buscaBinaria com os parametros desejados
    // dado o numero 67, a função deve retornar a posição 6 

    
    printf("O numero 67 foi encontrado na posicao: %d\n", posicao);

    return 0; // encerra o programa com sucesso

}


