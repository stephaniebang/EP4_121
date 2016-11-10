/* Stephanie Eun Ji Bang   n.USP 8994414 */

#ifndef __TABELASIMBOLO_LD_H__
#define __TABELASIMBOLO_LD_H__

#include "tipos.h"

/* A funcao percorre a tabelaLista t ate encontrar uma entrada correspondete a
 * string chave */
int nova_entrada(tabelaLista *t, char *chave);

/* A funcao insere uma nova entrada da chave contida no buffer *b na tabelaLista
 * entrada. */
void insere_tabelaListaDes(tabelaLista **entrada, buffer *b);

#endif
