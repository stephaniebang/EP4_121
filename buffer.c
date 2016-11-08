/* Stephanie Eun Ji Bang   n.USP 8994414 */

#include "buffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

buffer *cria_buffer(int n) {
   buffer *b;

   b = malloc(sizeof(buffer));
   b->s = malloc(n*sizeof(char));
   b->ind = 0;
   b->max = n;

   return b;
}

void realoca_buffer(buffer *b) {
   char *tmp;
   int i;

   tmp = malloc(2*b->max*sizeof(char));

   for (i = 0; i < b->max; i++)   tmp[i] = b->s[i];

   free(b->s);

   b->s = tmp;
   b->max *= 2;
}

void insere_buffer(buffer *b, char c) {
   if (b->ind == b->max)   realoca_buffer(b);

   b->s[b->ind] = c;
   b->ind++;
}

void reseta_buffer(buffer *b) {
   int i;

   for (i = 0; i < b->max; i ++)   b->s[i] = 0;

   b->ind = 0;
}

void le_palavra(FILE *f, buffer *b) {
   char c = fgetc(f);

   /* Resetando o buffer */
   reseta_buffer(b);

   /* Procurando a primeira letra da palavra */
   while ((c < 'A' || (c > 'Z' && c < 'a') || c > 'z') && c != EOF)   c = fgetc(f);

   /* Guardando a palavra no buffer */
   while ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
      insere_buffer(b, tolower(c));
   
      c = fgetc(f);
   }
}

void destroi_buffer(buffer *b) {
   free(b->s);
   free(b);
}
