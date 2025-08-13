#ifndef PESSOA_H
#define PESSOA_H


typedef struct {
    int ID;
    char Nome[50];
    int Idade;
} Pessoa;

// Constructors in C 
Pessoa criarPessoa(int id, char * nome, int idade);

void cadastrarPessoa(Pessoa P);

void excluirPessoa(Pessoa P);

Pessoa buscarPessoa(int id);

Pessoa corrigirIdade(Pessoa p, int idade);

float calcularIdadeMedia(Pessoa * P);

// Quando usar void?
// void = vazio (nao necessita valor de retorno)

#endif