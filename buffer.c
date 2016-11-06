#include "buffer.h"
#include <stdlib.h>
#include <string.h>

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

   strcpy(b->s, tmp);
   free(b->s);

   b->s = tmp;
   b->max *= 2;
}

void insere_buffer(buffer *b, char c) {
   if (b->ind == b->max)   realoca_buffer(b);

   b->s[b->ind] = c;
   b->ind++;
}

void destroi_buffer(buffer *b) {
   free(b->s);
   free(b);
}
