#include <stdio.h>  // biblioteca necessaria para usar FILE

int main () { // função principal por onde a execução do programa começa

    FILE *arquivo; // Declara uma variavel ponteiro do tipo FILE, que será usada para manipular arquivos 

    //abre ou cria um arquivo "a.txt" no modo "w" (escrita)
    // se o arquivo existir, ele será sobreescrito 
    // Se não existir, será criado 
    // A função retorna o endereço de um ponteiro FILE, armazenada na variavel arquivo
    arquivo = fopen("a.txt", "w");
    
    // Tratamento de erro na abertura do arquivo. 
    // se o fopen falhar, retorna NULL 
    if(arquivo == NULL) {
    
        printf("Erro ao abrir o arquivo!\n"); 
        return 1; // sai do programa com codigo de erro
    
    } 

    // Escreve uma string dentro do arquivo 
    fprintf(arquivo, "Ah nao cara!"); // fprintf escreve em arquivos ao invés de na tela 

    fclose(arquivo); // fecha o arquivo para garantir que os dados sejam salvos corretamente

    return 0; // indica que o programa terminou com sucesso 

}