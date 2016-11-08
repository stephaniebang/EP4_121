/* Stephanie Eun Ji Bang   n.USP 8994414 */

#include "tabelaSimbolo_VD.h"
#include "tabelaSimbolo_LD.h"
#include "buffer.h"
#include "tipos.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int tipo_implementacao(char *tipo) {
   if (tipo[0] == 'V') {
      if (tipo[1] == 'D')   return 1;

      return 2;
   }

   if (tipo[0] == 'L') {
      if (tipo[1] == 'D')   return 3;

      return 4;
   }

   return 5;
}

int tipo_impressao(char *tipo) {
   if (tipo[0] == 'O')   return 0;

   return 1;
}

int main(int argc, char *argv[]) {
   buffer *palavra;
   FILE *file;
   int implementacao, impressao;

   /* Variaveis para a tabela em vetor */
   tabelaVetor *tab;
   entradaVetor *ent;

   /* Variaveis para a tabela em lista */

   /* Recebendo os argumentos */
   if (argc != 4) {
      printf("Numero de argumentos invalido.\n");
      printf("Esperado: [nome do arquivo] [tipo de implementacao] [modo de impressao]\n");

      return 0;
   }

   file = fopen(argv[1], "r");
   implementacao = tipo_implementacao(argv[2]);
   impressao = tipo_impressao(argv[3]);

   tab = cria_tabelaVetor(50);

   palavra = cria_buffer(10);
   
   /* Guardando a primeira palavra, se ela existir */
   le_palavra(file, palavra);

   while (palavra->ind) {
      /* Buscando a palavra lida na tabela */
      ent = procura_tabelaVetorDes(tab, palavra->s);

      if (ent)   /* Se a palavra ja esta na tabela */
         ent->valor++;

      else   /* Se a palavra ainda nao esta na tabela */
         insere_tabelaVetorDes(tab, palavra);

      /* Lendo a proxima palavra */
      le_palavra(file, palavra);
   }

   fclose(file);

   imprime_tabelaVetor(tab);

   return 0;
}
