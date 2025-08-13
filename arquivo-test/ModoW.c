#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE * fp; // fp aponta para arquivo

    fp = fopen("bd/test.txt", "w"); // abre arquivo
    if(fp == NULL){
        printf("Arquivo nao encontrado");
        exit(1);

    }
    fprintf(fp, "Flamengo eliminado, urubuzada caiu\n\n");

    for (int i = 1; i <= 10; i++){

        fprintf(fp, "8 * %d = %d", i, 8 * i); // tabuada do 8

    }


    fclose(fp); // fecha arquivo 

    return 0; // encerra



}