/* Stephanie Eun Ji Bang   n.USP 8994414 */

#include "tabelaSimbolo_LD.h"
#include <stdlib.h>
#include <string.h>

void insere_tabelaListaDes(tabelaLista **t, char *chave) {
    tabelaLista *aux, *ant, *novo;

    /* Percorrendo a tabela e procurando uma possivel entrada ja existente */
    for (aux = *t, ant = NULL; aux; aux = aux->prox, ant = aux)
        if (!strcmp(aux->chave, chave))    break;

    if (!aux) {    /* Se chave for uma entrada nova */
        novo = malloc(sizeof(tabelaLista));
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
