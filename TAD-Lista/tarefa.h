
#ifndef TAREFA_H
#define TAREFA_H

// tamanho dos vetores de chaves (caracteres das strings)
#define TAM_TITULO 96
#define TAM_NOME 48 

// definicoes dos status 
#define A_FAZER 0
#define EM_ANDAMENTO 1 
#define FEITO 2

// estrutura do item Tarefa
typedef struct {

    char Titulo[TAM_TITULO];
    char Responsavel[TAM_NOME];
    int Status; 
    float Progresso;
    int Avaliacao; 

} Tarefa;

// estrutura da lista (moldura da lista)
typedef struct {
    
    Tarefa * Dados;
    int Tamanho; 
    int Capacidade; 

} Planner; 

// prototipo das operacoes que lidam com o TAD Lista 
// parametros o inteiro 
Planner * CriarLista(int N); // o retorno é um endereço de memoria de um Planner 
void DestruirLista(Planner *P); // liberar memoria do P 
// acrescentar tarefa numa função especifica do Planner
void AdicionarTarefa(Planner *P, Tarefa T);
int GerarHTMLTabela(Planner *Lista, char *CaminhoArquivo);

#endif