#include <stdio.h>
#include <stdlib.h>

//typedef A B: o tipo A também é reconhecido por B

typedef struct {

    char nome[30];
    char telefone[10];
    char endereco[100];


} Pessoa;



int main() {
    system("cls");

    char x = 8;
    char y = 7;
    char z = x + y;

    int w[10];

    // tamanhos de tipos de dados em C
    printf("char \t %d \n,", sizeof(char));
    printf("int \t %d \n", sizeof(int));
    printf("float \t %d \n", sizeof(float));
    printf("vector \t %d \n", sizeof(w));
    printf("Pessoa \t %d \n", sizeof(Pessoa));


    printf("%d", z);



}