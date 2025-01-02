#include "codifica.h"
#include <stdlib.h>
#include <stdio.h>


void relatorio_bin(FILE* arqOriginal, FILE* arqCriado, FILE* arqRelatorio);
void relatorio_txt(FILE* arqOriginal, FILE* arqCriado, FILE* arqRelatorio);

int main(void){
	int k = 0;
	
	struct compactadora v_compacta_original[] = {
	{'K',1,12},
	{'W',2,12},
	{'Y',3,12},
	{'Z',2,11},
	{'J',3,11},
	{'X',1,9},
	{'\n',1,8},
	{'H',1,7},
	{'F',36,7},
	{'G',37,7},
	{'B',1,6},
	{'Q',16,6},
	{',',17,6},
	{'V',19,6},
	{'.',49,6},
	{'P',48,6},
	{'D',1,5},
	{'C',17,5},
	{'O',16,5},
	{'M',25,5},
	{'R',1,4},
	{'L',7,4},
	{'N',6,4},
	{'A',5,4},
	{'T',9,4},
	{'S',14,4},
	{'U',15,4},
	{'I',13,4},
	{'E',1,3},
	{' ',5,3},
	{0, 0, 0},
	{4,0,12}
	};
	
	struct compactadora v_compacta_degenerada[] = {
	{'A', 1, 30},
	{'B', 1, 2},
	{'C', 1, 3},
	{'D', 1, 4},
	{'E', 1, 5},
	{'F', 1, 6},
	{'G', 1, 7},
	{'H', 1, 8},
	{'I', 1, 9},
	{'J', 1, 10},
	{'K', 1, 11},
	{'L', 1, 12},
	{'M', 1, 13},
	{'N', 1, 14},
	{'O', 1, 15},
	{'P', 1, 16},
	{'Q', 1, 17},
	{'R', 1, 18},
	{'S', 1, 19},
	{'T', 1, 20},
	{'U', 1, 21},
	{'V', 1, 22},
	{'W', 1, 23},
	{'X', 1, 24},
	{'Y', 1, 25},
	{'Z', 1, 26},
	{' ', 1, 27},
	{'.', 1, 28},
	{',', 1, 29},
	{'\n', 0, 30},
    {0, 0, 0},
	{4, 1, 1}
};


	struct compactadora* v_estruturas[] = {v_compacta_original, v_compacta_degenerada};

    FILE* arqIn1txt;
    FILE* arqIn1bin;

    FILE* arqOutbin;
    FILE* arqOutTxt;

	FILE* arqCriadoTxt;
	FILE* arqOriginalTxt;

	FILE* arqCriadobin;
	FILE* arqOriginalbin;

	FILE* arqRelatorio;

	char* vNomeArqTxt [] = {"k1.txt", "k2.txt", "k3.txt", "k4.txt", "k5.txt", "k6.txt", "k7.txt", "k8.txt"};
	char* vNomeArqBin [] = {"k1.bin", "k2.bin", "k3.bin", "k4.bin", "k5.bin", "k6.bin", "k7.bin", "k8.bin"};
	char* vNomeArqBinOut [] = {"arqNovoBinOrig1.bin", "arqNovoBinOrig2.bin", "arqNovoBinOrig3.bin", "arqNovoBinOrig4.bin", "arqNovoBinOrig5.bin", "arqNovoBinOrig6.bin", "arqNovoBinOrig7.bin", "arqNovoBinOrig8.bin",
	"arqNovoBinDeg1.bin", "arqNovoBinDeg2.bin", "arqNovoBinDeg3.bin", "arqNovoBinDeg4.bin", "arqNovoBinDeg5.bin", "arqNovoBinDeg6.bin", "arqNovoBinDeg7.bin", "arqNovoBinDeg8.bin"};
	char* vNomeArqTxtOut [] = {"arqNovoTxtOrig1.txt", "arqNovoTxtOrig2.txt", "arqNovoTxtOrig3.txt", "arqNovoTxtOrig4.txt", "arqNovoTxtOrig5.txt", "arqNovoTxtOrig6.txt", "arqNovoTxtOrig7.txt", "arqNovoTxtOrig8.txt",
	"arqNovoTxtDeg1.txt", "arqNovoTxtDeg2.txt", "arqNovoTxtDeg3.txt", "arqNovoTxtDeg4.txt", "arqNovoTxtDeg5.txt", "arqNovoTxtDeg6.txt", "arqNovoTxtDeg7.txt", "arqNovoTxtDeg8.txt"};

	char* vArqsRelatorios[] = {"arqRelatorioEstruturaOriginal.txt", "arqRelatorioEstruturaDegenerada.txt"};

	for (int j = 0; j < 2; j++){		

		arqRelatorio = fopen(vArqsRelatorios[j], "w");

		if (!arqRelatorio){
			printf("Nao foi possivel abrir arq %s", vArqsRelatorios[j]);
			exit(2);
		}

		for( int i = 0; i < 8; i++){

			arqIn1txt = NULL;
			arqIn1bin = NULL;

			arqOutbin = NULL;
			arqOutTxt = NULL;

			arqCriadoTxt = NULL;
			arqOriginalTxt = NULL;

			arqCriadobin = NULL;
			arqOriginalbin = NULL;
			
			arqIn1txt = fopen(vNomeArqTxt[i], "r");

			if (!arqIn1txt){
				printf("Nao foi possivel abrir arq %s", vNomeArqTxt[i]);
				exit(2);
			}

			arqOutbin = fopen(vNomeArqBinOut[k], "wb");
			if (!arqOutbin){
				printf("Nao foi possivel abrir arq %s", vNomeArqBinOut[k]);
				exit(2);
			}

			
			compacta(arqIn1txt, arqOutbin, v_estruturas[j]);

			fclose(arqIn1txt);
			fclose(arqOutbin);

			arqIn1bin = fopen(vNomeArqBinOut[k], "rb");

			if (!arqIn1bin){
				printf("Nao foi possivel abrir arq %s", vNomeArqBinOut[k]);
				exit(2);
			}
			
			arqOutTxt = fopen(vNomeArqTxtOut[k], "w");
			if (!arqOutTxt){
				printf("Nao foi possivel  arq %s", vNomeArqTxtOut[k]);
				exit(2);
			}

			descompacta(arqIn1bin, arqOutTxt, v_estruturas[j]);	

			fclose(arqIn1bin);
			fclose(arqOutTxt);

			arqCriadoTxt = fopen(vNomeArqTxtOut[k], "r");

			if (!arqCriadoTxt){
				printf("Nao foi possivel abrir arq %s", vNomeArqTxtOut[k]);
				exit(2);
			}

			arqOriginalTxt = fopen(vNomeArqTxt[i], "rb");

			if (!arqOriginalTxt){
				printf("Nao foi possivel abrir arq %s", vNomeArqBin[i]);
				exit(2);
			}

			fprintf(arqRelatorio, "      %s - %s\n", vNomeArqTxt[i], vNomeArqTxtOut[k]);

			relatorio_txt(arqOriginalTxt, arqCriadoTxt, arqRelatorio);

			fclose(arqOriginalTxt);
			fclose(arqCriadoTxt);

			

			arqCriadobin = fopen(vNomeArqBinOut[k], "rb");

			if (!arqCriadobin){
				printf("Nao foi possivel abrir arq %s", vNomeArqBinOut[k]);
				exit(2);
			}

			arqOriginalbin = fopen(vNomeArqBin[i], "rb");

			if (!arqOriginalbin){
				printf("Nao foi possivel abrir arq %s", vNomeArqBin[i]);
				exit(2);
			}

			fprintf(arqRelatorio, "      %s - %s\n", vNomeArqBin[i], vNomeArqBinOut[k]);
			relatorio_bin(arqOriginalbin, arqCriadobin, arqRelatorio);

			fclose(arqOriginalbin);
			fclose(arqCriadobin);
			k++;
		}
		fclose(arqRelatorio);
	}
    return 0;
}

void relatorio_bin(FILE* arqOriginal, FILE* arqCriado, FILE* arqRelatorio){
	unsigned char char_original;
	unsigned char char_criado;	

	while (fread(&char_criado, sizeof(unsigned char), 1, arqCriado) == 1){
		fread(&char_original, sizeof(unsigned char), 1, arqOriginal);
		fprintf(arqRelatorio, "       %02x    -     %02x\n", char_original, char_criado);
	}
	fprintf(arqRelatorio, "\n\n");
}

void relatorio_txt(FILE* arqOriginal, FILE* arqCriado, FILE* arqRelatorio){
	char str_original [200];
	char str_criado [200];	

	while (fgets(str_criado, sizeof(str_criado),arqCriado)){
		fgets(str_original, sizeof(str_original),arqOriginal);
		fprintf(arqRelatorio, "%s\n%s\n", str_original, str_criado);
	}
	fprintf(arqRelatorio, "\n");

}