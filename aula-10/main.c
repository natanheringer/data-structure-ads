#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fifo.h"

int main() {

    Fila * Normal = criarFila();

    Item * a = criarItem(10);
    Item * b = criarItem(20);
    Item * c = criarItem(30);
    Item * d = criarItem(45);
    Item * e = criarItem(21);
    
    enfileirar(Normal, a);
    enfileirar(Normal, b);
    desenfileirar(Normal);
    enfileirar(Normal, c);
    enfileirar(Normal, d);
    enfileirar(Normal, e);
    desenfileirar(Normal);
    desenfileirar(Normal);

    //enfileirar(Normal, criarItem(77));

    exibirFila(Normal);

    //desenfileirar(Normal);

    //exibirFila(Normal);

    return 0;

}
