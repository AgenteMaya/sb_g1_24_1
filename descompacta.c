#include "codifica.h"

void descompacta(FILE *arqBin, FILE *arqTexto, struct compactadora *v){
   unsigned char valor_char; //byte que vai receber byte a byte do arqbin
   unsigned int valor_char_aux = 0; // int que vai receber bit a bit do valor_char para construir o valor
   int qtd; // qtd de bits que tem no valor_char_aux que está sendo construido
   
   while (fread(&valor_char, sizeof(unsigned char), 1, arqBin) == 1) {
      for (int i = 0; i < 8; i++){
         valor_char_aux = (valor_char_aux << 1) + ((valor_char >> (7-i)) & 1);
         qtd+=1;
         for(int j = 0; j < 32; j++){
            if ((v+j)->codigo == valor_char_aux && (v+j)->tamanho == qtd && (v+j)->simbolo != 4){
               fputc((v+j)->simbolo, arqTexto);
               valor_char_aux = 0;
               qtd = 0;
               break;
            }
         }
      }
	}
}