#include <stdio.h> // biblioteca do printf e scanf

// função da pesquisa sequencial: Percorre o vetor do inicio ao fim, comparando cada elemento com a chave buscada 
// retorna a posição do elemento se encontrado 
int buscaSequencial(int numerosArray[], int quantidadeNumeros, int numeroRequerido){ 
    // numerosArray: vetor onde vamos procurar o numeroRequerido
    // quantidadeNumeros: tamanho do Array 
    // numeroRequerido: numero que queremos encontrar no vetor 

    printf("quantidade de numeros no array: %d\n", quantidadeNumeros);

    for (int i = 0; i < quantidadeNumeros; i++){

        // Laço de repetição que percorre cada posição do vetor de 0 até quantidadeNumeros - 1
        // i é o indice atual do vetor que estamos percorrendo, começando em 0 até quantidadeNumeros - 1  
        // Em cada iteração, verificamos se o elemento na posição i é igual ao numeroRequerido
        // ou seja, se i é igual a numero requerido 
        
        // Se o numerosArray[i](passando o i como elemento dentro do vetor)
        // for igual ao numeroRequerido, retornamos o indice i 
        // ou seja, a posição que o numero requerido possuia
        if (numerosArray[i] == numeroRequerido) {

            // retorna a posição de onde o numeroRequerido foi encontrado
            return i; 
            
        }

    }

    return -1; // se o laço terminar sem achar o numeroRequerido, retornamos -1
               // que indica "não encontrado no vetor" 

}

int main() {

    // teste simples

    int numeros[] = {10, 23, 45, 70, 11, 3, 5, 90, 34, 22}; // vetor de numeros para teste 

    int posicao = buscaSequencial(numeros, 20, 11); 
    // chama a função buscaSequencial, passando o vetor numeros, o tamanho é 10, e o numeroRequerido é 5

    printf("O numero 5 foi encontrado na posicao: %d\n", posicao);



    return 0; 


}