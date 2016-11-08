/* Stephanie Eun Ji Bang   n.USP 8994414 */

#ifndef __TABELASIMBOLO_VD_H__
#define __TABELASIMBOLO_VD_H__

#include "tipos.h"

/* A funcao verifica se a tabelaVetor t ja contem o string chave. Caso sim, ela
 * retorna um ponteiro para a entradaVetor dessa chave. Caso contrario, retorna
 * NULL. */
entradaVetor *procura_tabelaVetorDes(tabelaVetor *t, char *chave);

/* A funcao insere o string s do buffer b na ultima posicao da tabelaVetor t. */
void insere_tabelaVetorDes(tabelaVetor *t, buffer *b);

#endif
