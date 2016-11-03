#include <stdlib.h>
#include <string.h>
#include "tabelaSimbolo_LD.h"

tabelaLD *cria_tabelaLD() {
    return NULL;
}

void insere_tabelaLD(tabelaLD **t, char *chave) {
    tabelaLD *aux, *ant, *novo;

    /* Percorrendo a tabela e procurando uma possivel entrada ja existente */
    for (aux = *t, ant = NULL; aux; aux = aux->prox, ant = aux)
        if (!strcmp(aux->chave, chave))    break;

    if (!aux) {    /* Se chave for uma entrada nova */
        novo = malloc(sizeof(tabelaLD));
        novo->chave = malloc((strlen(chave)+1)*sizeof(char));
        novo->valor = 0;
        novo->prox = NULL;

        if (!ant)    /* Se a tabela esta vazia */
            *t = novo;

        else    /* Se a chave for inserida no ultimo espaco da tabela */
            ant->prox = novo;
    }

    else    /* Se chave ja foi inserida */
        aux->valor++;
}

void destroi_tabelaLD(tabelaLD *t) {
    tabelaLD *prox, *ant;

    prox = t;

    while (prox) {
        ant = prox;
        prox = ant->prox;

        free(ant);
    }
}
