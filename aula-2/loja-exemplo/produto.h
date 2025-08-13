#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct {

    char produto[100];
    int quantidade;
    float preco;

} Produto;

Produto criarProduto(Produto P);

void cadastrarProduto(Produto P);

void excluirProduto(Produto P);

Produto buscarProduto(int id);


#endif