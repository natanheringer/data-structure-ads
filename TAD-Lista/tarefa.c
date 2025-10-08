#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tarefa.h"

Planner * CriarLista(int N) {

    // perguntar se há memoria para armazenar o planner
    // existe memoria? se sim, continua. se nao, alerta
    // converter byte em uma estrutura para formato Planner atraves do casting 
    Planner * P = (Planner *) malloc(sizeof(Planner));

    if (P == NULL){
        printf("ERRO: Nao foi possivel alocar memoria para o planner\n");
        return NULL; 
    }

    // inicializando a capacidade do P como N 
    P->Capacidade = N; // A capacidade do planner é "N". 
    P->Tamanho = 0; // Inicialmente, a lista de tarefas está vazia 
    // Alocar memoria dinamicamente  
    P->Dados = (Tarefa *) malloc(N * sizeof(Tarefa)); // calcula o tamanho de uma tarefa e multiplicando pelo nmr de elementos do vetor

    // Se nao tivermos memoria para alocar memoria para o vetor de tarefas 
    if (P->Dados == NULL){
        printf("ERRO: nao foi possivel alocar memoria para o vetor de tarefas\n");
        free(P);
        return NULL; 
    }

    printf("%x\n", P);
    return P; 


}

void DestruirLista(Planner *P){
    if (P == NULL) return;
    free(P->Dados);
    free(P);
}

void AdicionarTarefa(Planner *P, Tarefa T) {

    // se nao houver nada dentro, apenas retorne 
    // verifica espaço vazioo
    if (P == NULL || P->Tamanho == P->Capacidade){

        return; 

    }

    // inserção no primeiro lugar livre
    P->Dados[P->Tamanho] = T; // copiando T no primeiro espaço vazio  
    P->Tamanho++; // atualizando o tamanho 

}

int GerarHTMLTabela(Planner *Lista, char *CaminhoArquivo) {
    if (Lista == NULL || CaminhoArquivo == NULL) {
        return -1;
    }

    FILE *arquivo = fopen(CaminhoArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para escrita.\n");
        return -1;
    }

    // Cabeçalho HTML
    fprintf(arquivo,
        "<!DOCTYPE html>\n"
        "<html lang=\"pt-BR\">\n"
        "<head>\n"
        "  <meta charset=\"UTF-8\">\n"
        "  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
        "  <title>Planner de Tarefas</title>\n"
        "  <style>\n"
        "    table { border-collapse: collapse; width: 100%%; }\n"
        "    th, td { border: 1px solid #ddd; padding: 8px; text-align: left; }\n"
        "    th { background-color: #4CAF50; color: white; }\n"
        "    .status-afazer { color: red; font-weight: bold; }\n"
        "    .status-em-andamento { color: orange; font-weight: bold; }\n"
        "    .status-feito { color: green; font-weight: bold; }\n"
        "    .progress-bar {\n"
        "      background-color: #ddd;\n"
        "      border-radius: 5px;\n"
        "      overflow: hidden;\n"
        "      width: 100px;\n"
        "      height: 15px;\n"
        "    }\n"
        "    .progress-fill {\n"
        "      background-color: #4CAF50;\n"
        "      height: 100%%;\n"
        "      width: 0%%;\n"
        "    }\n"
        "  </style>\n"
        "</head>\n"
        "<body>\n"
        "<h1>Planner de Tarefas</h1>\n"
        "<table>\n"
        "  <tr>\n"
        "    <th>Título</th>\n"
        "    <th>Responsável</th>\n"
        "    <th>Status</th>\n"
        "    <th>Progresso</th>\n"
        "    <th>Avaliação</th>\n"
        "  </tr>\n");

    // Função auxiliar para traduzir status para texto e classes CSS
    for (int i = 0; i < Lista->Tamanho; i++) {
        Tarefa t = Lista->Dados[i];
        char *status_text;
        char *status_class;

        switch (t.Status) {
            case A_FAZER:
                status_text = "A Fazer";
                status_class = "status-afazer";
                break;
            case EM_ANDAMENTO:
                status_text = "Em Andamento";
                status_class = "status-em-andamento";
                break;
            case FEITO:
                status_text = "Feito";
                status_class = "status-feito";
                break;
            default:
                status_text = "Desconhecido";
                status_class = "";
        }

        // Progresso em percentual
        int progresso_percent = (int)(t.Progresso * 100);

        fprintf(arquivo,
            "  <tr>\n"
            "    <td>%s</td>\n"
            "    <td>%s</td>\n"
            "    <td class=\"%s\">%s</td>\n"
            "    <td>\n"
            "      <div class=\"progress-bar\">\n"
            "        <div class=\"progress-fill\" style=\"width:%d%%\"></div>\n"
            "      </div>\n"
            "      %d%%\n"
            "    </td>\n"
            "    <td>%d</td>\n"
            "  </tr>\n",
            t.Titulo, t.Responsavel, status_class, status_text, progresso_percent, progresso_percent, t.Avaliacao);
    }

    // Rodapé HTML
    fprintf(arquivo,
        "</table>\n"
        "</body>\n"
        "</html>\n");

    fclose(arquivo);
    return 0;
}

