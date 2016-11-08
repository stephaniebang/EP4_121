/* Stephanie Eun Ji Bang   n.USP 8994414 */

#ifndef __TIPOS_H__
#define __TIPOS_H__

typedef struct {
    char *s;
    int ind;
    int max;
} buffer;


/* Estruturas e funcoes para a tabela de simbolos com vetor */
typedef struct {
   char *chave;
   int valor;
} entradaVetor;

typedef struct {
   entradaVetor *v;
   int max;
   int ultimo;
} tabelaVetor;

/* A funcao retorna um ponteiro t para uma tabelaVetor vazia com capacidade de
 * n entradas. */
tabelaVetor *cria_tabelaVetor(int n);

/* A funcao realoca o dobro de espaco para a tabelaVD t. */
void realoca_tabelaVetor(tabelaVetor *t);

/* A funcao imprime o conteudo da tabelaVetor t. */
void imprime_tabelaVetor(tabelaVetor *t);

/* A funcao destroi a tabelaVetor t. */
void destroi_tabelaVetor(tabelaVetor *t);


/* Estrutura e funcoes para a tabela de simbolos com lista ligada */
typedef struct entrada {
    char *chave;
    int valor;
    struct entrada *prox;
    struct entrada *ant;
} tabelaLista;

/* A funcao retorna um ponteiro t para uma tabelaLista. */
tabelaLista *cria_tabelaLista();

/* A funcao destroi a tabelaLista t. */
void destroi_tabelaLista(tabelaLista *t);

#endif
