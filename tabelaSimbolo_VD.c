/* Stephanie Eun Ji Bang   n.USP 8994414 */

#include "tabelaSimbolo_VD.h"
#include <stdlib.h>
#include <string.h>

entradaVetor *procura_tabelaVetorDes(tabelaVetor *t, char *chave) {
   int i;

   for (i = 0; i < t->ultimo; i++)
      if (!strcmp(chave, t->v[i].chave))   /* Se a chave ja esta na tabela */
         return (&t->v[i]);
      
   return NULL;   /* Se a chave nao esta na tabela */
}

void insere_tabelaVetorDes(tabelaVetor *t, buffer *b) {
   entradaVetor nova;

   nova.chave = malloc((b->ind+1)*sizeof(char));
   nova.valor = 1;

   strcpy(nova.chave, b->s);

   /* Checando se a tabelaVD t alcancou sua capacidade maxima */
   if (t->ultimo == t->max)   realoca_tabelaVetor(t);

   /* Inserindo a chave no ultimo espaco livre da tabela */
   t->v[t->ultimo] = nova;
   t->ultimo++;
}
