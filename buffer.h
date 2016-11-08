/* Stephanie Eun Ji Bang   n.USP 8994414 */

#ifndef __BUFFER_H__
#define __BUFFER_H__

#include <stdio.h>
#include "tipos.h"

/* A funcao retorna um ponteiro do buffer b vazio com capacidade n. */
buffer *cria_buffer(int n);

/* A funcao realoca o dobro de espaco para o buffer de ponteiro b. */
void realoca_buffer(buffer *b);

/* A funcao adiciona o char c no buffer b. */
void insere_buffer(buffer *b, char c);

/* A funcao reseta o buffer b. */
void reseta_buffer(buffer *b);

/* A funcao le uma palavra do arquivo f e a guarda no buffer b. */
void le_palavra(FILE *f, buffer *b);

/* A funcao destroi o buffer b. */
void destroi_buffer(buffer *b);

#endif
