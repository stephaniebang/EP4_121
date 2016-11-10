/* Stephanie Eun Ji Bang   n.USP 8994414 */

#include "tabelaSimbolo_VD.h"
#include "tabelaSimbolo_LD.h"
#include "buffer.h"
#include "tipos.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
   buffer *palavra;
   FILE *file;
/*   int implementacao, impressao;*/

   /* Variaveis para a tabela em vetor */
   tabelaVetor *tabV;
   entradaVetor *entV;

   /* Variaveis para a tabela em lista */
   tabelaLista *tabL, *aux;

   /* Recebendo os argumentos */
   if (argc != 4) {
      printf("Numero de argumentos invalido.\n");
      printf("Esperado: [nome do arquivo] [tipo de implementacao] [modo de impressao]\n");

      return 0;
   }

   file = fopen(argv[1], "r");


/*   tabV = cria_tabelaVetor(50);*/

   /* Guardando a primeira palavra, se ela existir */
   palavra = cria_buffer(10);
   
   le_palavra(file, palavra);

   if (palavra->ind)   tabL = cria_tabelaLista(palavra);
   
   while (palavra->ind) {
      /* Vetor desordenado *
         * Buscando a palavra lida na tabela *
         entV = procura_tabelaVetorDes(tabV, palavra->s);

         if (entV)   * Se a palavra ja esta na tabela *
            entV->valor++;

         else   * Se a palavra ainda nao esta na tabela *
            insere_tabelaVetorDes(tabV, palavra);
      }*/

      aux = tabL;

      /* Lista desordenada */
      if (nova_entrada(aux, palavra->s))
         insere_tabelaListaDes(&aux, palavra);

      else
         aux->valor++;

      /* Lendo a proxima palavra */
      le_palavra(file, palavra);
   }

   fclose(file);

/*      imprime_tabelaVetor(tabV);
      destroi_tabelaVetor(tabV);
*/
      imprime_tabelaLista(tabL);
      destroi_tabelaLista(tabL);

   return 0;
}
