#ifndef __TABELASIMBOLO_LD_H__
#define __TABELASIMBOLO_LD_H__

#include "tipos.h"

/* A funcao retorna um ponteiro da tabelaLD t. */
tabelaLD *cria_tabelaLD();

/* A funcao retorna um ponteiro p para a nova entrada ou para a entrada ja
 * existente de uma chave */

void insere_tabelaLD(tabelaLD **t, char *chave);

/* A funcao destroi a tabelaLD t */
void destroi_tabelaLD(tabelaLD *t);

#endif
