#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(){
	FILE* file = fopen("mapa.txt", "r");
	if(!file) {
		printf("Error openning file!\n");
		exit(1);
	}
	int ncid;
	fscanf(file,"%d\n", &ncid);
	
	fclose(file);
	char opt;
	while (1<2){
		printf("> ");
		scanf(" %c", &opt);
		if(opt == 'q')
			break;
		switch(opt) {
			case 'a':
				/*o programa deve ler um indice numerico de uma cidade e listar os nomes das cidades adjacentes*/
			break;
			case 'd':
				/*o programa deve gerar o grafo .dot do graphviz na saida padrao*/
			break;
			case 'l':
				/*o programa deve mostrar a lista decidades com seus id's*/
			break;
			default:
			break;
		}
	}
	return 0;
}