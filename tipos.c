/* Stephanie Eun Ji Bang   n.USP 8994414 */

#include "tipos.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Funcoes para a tabela de simbolos com vetor */
tabelaVetor *cria_tabelaVetor(int n) {
   tabelaVetor *t;

   t = malloc(sizeof(tabelaVetor));
   t->v = malloc(n*sizeof(entradaVetor));
   t->max = n;
   t->ultimo = 0;

   return t;
}

void realoca_tabelaVetor(tabelaVetor *t) {
   int i;
   entradaVetor *tmp;

   tmp = malloc(2*t->max*sizeof(entradaVetor));

   for (i = 0; i < t->max; i++)   tmp[i] = t->v[i];

   free(t->v);

   t->v = tmp;
   t->max *= 2;
}

void imprime_tabelaVetor(tabelaVetor *t) {
   int i;

   for (i = 0; i < t->ultimo; i++)
      printf("%s %d\n", t->v[i].chave, t->v[i].valor);
}

void destroi_tabelaVetor(tabelaVetor *t) {
   free(t->v);
   free(t);
}


/* Funcoes para a tabela de simbolos com lista ligada */
tabelaLista *cria_tabelaLista(buffer *b) {
    tabelaLista *t;

    t = malloc(sizeof(tabelaLista));
    t->chave = malloc((b->ind+1)*sizeof(char));
    t->prox = t->ant = NULL;
    t->valor = 0;

    strcpy(t->chave, b->s);

    return t;
}

void imprime_tabelaLista(tabelaLista *t) {
   tabelaLista *aux;

   for (aux = t; aux; aux = aux->prox)
      printf("%s %d\n", aux->chave, aux->valor);
}

void destroi_tabelaLista(tabelaLista *t) {
    tabelaLista *prox, *ant;

    prox = t;

    while (prox) {
        ant = prox;
        prox = ant->prox;

        free(ant);
    }
}
