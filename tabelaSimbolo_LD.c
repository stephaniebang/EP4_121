/* Stephanie Eun Ji Bang   n.USP 8994414 */

#include "tabelaSimbolo_LD.h"
#include <stdlib.h>
#include <string.h>

#include <stdio.h>

int nova_entrada(tabelaLista *t, char *chave) {
   printf("%s   ", chave);
   if (!strcmp(t->chave, chave)) {printf("tem no primeiro\n");  return 0;}

   while (t->prox) {
      if (!strcmp(t->prox->chave, chave)) {printf("tem no meio\n");  return 0;}

      t = t->prox;
   }
   printf("nao tem\n");

   return 1;
}

void insere_tabelaListaDes(tabelaLista **entrada, buffer *b) {
   tabelaLista *novo;
   
   novo = malloc(sizeof(tabelaLista));
   novo->chave = malloc((b->ind+1)*sizeof(char));
   novo->valor = 1;
   novo->prox = NULL;
   novo->ant = *entrada;
   *entrada->prox = novo;

   strcpy(novo->chave, b->s);
}
