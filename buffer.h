#ifndef __BUFFER_H__
#define __BUFFER_H__

#include "tipos.h"

/* A funcao retorna um ponteiro do buffer b vazio com capacidade n. */
buffer *cria_buffer(int n);

/* A funcao realoca o dobro de espaco para o buffer de ponteiro b. */
void realoca_buffer(buffer *b);

/* A funcao adiciona o char c no buffer b. */
void insere_buffer(buffer *b, char c);

/* A funcao destroi o buffer b. */
void destroi_buffer(buffer *b);

#endif
