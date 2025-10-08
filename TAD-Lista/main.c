#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tarefa.h"

int main() {

    // APLICACAO DA ESTRUTURA (STRUCT) TAREFA QUE ESTA NO TAREFA.H
    // TITULO - RESPONSAVEL - STATUS - PROGRESSO - AVALIACAO 
    Tarefa T1 = {"Entrega do relatorio de BD: ", "Ana Paula", EM_ANDAMENTO, 0.75, 4};
    Tarefa T2 = {"Entrega do relatorio de BD: ", "Saulo de Tarso", A_FAZER, 0.20, 2};
    Tarefa T3 = {"Revisão do código fonte: ", "Carlos Silva", FEITO, 1.00, 3};
    Tarefa T4 = {"Testes unitários: ", "Mariana Souza", EM_ANDAMENTO, 0.50, 5};
    Tarefa T5 = {"Documentação do projeto: ", "João Pereira", A_FAZER, 0.10, 6};
    Tarefa T6 = {"Análise de requisitos: ", "Fernanda Lima", FEITO, 1.00, 7};
    Tarefa T7 = {"Implementação do módulo X: ", "Ricardo Gomes", EM_ANDAMENTO, 0.30, 8};
    Tarefa T8 = {"Correção de bugs: ", "Juliana Mendes", A_FAZER, 0.05, 9};
    Tarefa T9 = {"Reunião com cliente: ", "Paulo Andrade", FEITO, 1.00, 1};
    Tarefa T10 = {"Planejamento da sprint: ", "Laura Campos", EM_ANDAMENTO, 0.60, 10};
    

    Planner * UCB = CriarLista(2000); 



    AdicionarTarefa(UCB, T1); 
    AdicionarTarefa(UCB, T2); 
    AdicionarTarefa(UCB, T3); 
    AdicionarTarefa(UCB, T4); 
    AdicionarTarefa(UCB, T5); 
    AdicionarTarefa(UCB, T6); 
    AdicionarTarefa(UCB, T7); 
    AdicionarTarefa(UCB, T8); 
    AdicionarTarefa(UCB, T9); 
    AdicionarTarefa(UCB, T10); 

    int resultado = GerarHTMLTabela(UCB, "tarefas.html");
    if (resultado == 0) {
    printf("\nArquivo HTML gerado com sucesso!\n");
    } else {
    printf("\nFalha ao gerar arquivo HTML.\n");
    }


    for(int i = 0; i < UCB->Tamanho; i++){
        printf("%d\t%s\n", i, UCB->Dados[i].Titulo);
    }

    free(UCB);



    printf("%d\n\n", UCB->Tamanho); // adiciona tarefa(acima) e imprime o tamanho
    printf("%d\n\n", UCB->Dados[0].Titulo); // adiciona tarefa(acima) e imprime o tamanho
    

}