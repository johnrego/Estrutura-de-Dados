#include <stdio.h>
#include <string.h>
#include "hash.h"

int main(){
	int tam = 8;
	char nomes[8][10] = {"Nome0", "Nome1", "Nome2", "Nome3", "Nome4", "Nome5", "Nome6", "Nome7"};
	hash *ha = criaHash(tam);
	aluno al[tam];
	for (int i=0;i<tam;i++){
		al[i].matricula = i;
		strcpy(al[i].nome, nomes[i]);
		if (!insereEndAberto(ha, al[i])){
			printf("Erro na Insercao.\n");
		}
	}
	aluno al1;
	for (int i=0;i<tam;i++){
		if(buscaEndAberto(ha, i, &al1)){
			printf("%s\n", al1.nome);
		}
		else{
			printf("Nao Encontrado!\n");
		}
	}
	if (!remocaoEndAberto(ha, 1)){
		printf("Erro na remocao\n");
	}
	for (int i=0;i<tam;i++){
		if(buscaEndAberto(ha, i, &al1)){
			printf("%s\n", al1.nome);
		}
		else{
			printf("Nao Encontrado!\n");
		}
	}
	liberaHash(ha);
	return 0;
}