#include "codifica.h"
#include <stdlib.h>
/*Mayara Ramos Damazio 2210833 3WC */

void compacta(FILE *arqTexto, FILE *arqBin, struct compactadora *v){
    unsigned char char_atual;
    unsigned char char_aux;
    unsigned char buffer = 0;
    int qtd_bits_buffer = 0;

    struct compactadora* estrutura_certa = NULL;
    unsigned int valor_char = 0;

    int tamanho_char = 0;

    while (1){
        char_atual = fgetc(arqTexto); //pegar o chat do texto txt
        
        if (feof(arqTexto)){ //testar se chegou no final do aquivo
            break;
        }

        for (int i = 0; i < 32; i++){ //procurar o enderço da estrutura que está o char específico
            char_aux = (v + i)->simbolo;
            if (char_atual == char_aux){
                estrutura_certa = v + i;    
                break;                     //se achou, sai do for
            }
        }
        
        if (estrutura_certa){                           //se o ponteiro não for nulo, é pq foi achado, se não char não existe na estrutura
            valor_char = estrutura_certa->codigo;       //guardando em variáveis as informacoes desse char
            tamanho_char = estrutura_certa->tamanho;
        }
        else{
            exit(2);
        }

        for (int i = 0; i < tamanho_char; i++){
            buffer = (buffer << 1) + ((valor_char >> (tamanho_char-1-i)) & 1);
            qtd_bits_buffer++;
            if (qtd_bits_buffer == 8){
                fwrite(&buffer, sizeof(unsigned char), 1, arqBin);
                buffer = 0;
                qtd_bits_buffer = 0;
            }
        }
        
    }
    
    valor_char = (v + 31)->codigo;
    tamanho_char = (v + 31)->tamanho;
    for (int i = 0; i < tamanho_char; i++){
            buffer = (buffer << 1) + ((valor_char >> (tamanho_char-1-i)) & 1);
            qtd_bits_buffer++;
            if (qtd_bits_buffer == 8){
                fwrite(&buffer, sizeof(unsigned char), 1, arqBin);
                buffer = 0;
                qtd_bits_buffer = 0;
            }
            else if (tamanho_char < 8 && i == tamanho_char -1){
                int deslocamento = 8 - qtd_bits_buffer;
                buffer = buffer << deslocamento; 
                fwrite(&buffer, sizeof(unsigned char), 1, arqBin);
                buffer = 0;
                qtd_bits_buffer = 0;
            }
        }
    
    if (qtd_bits_buffer != 0){
        fwrite(&buffer, sizeof(unsigned char), 1, arqBin);
    }       
}

