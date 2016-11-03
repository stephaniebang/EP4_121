#ifndef __TIPOS_H__
#define __TIPOS_H__

typedef struct entrada {
    char *chave;
    int valor;
    struct entrada *prox;
} tabelaLD;

typedef struct {
    char *s;
    int ind;
    int max;
} buffer;

#endif
