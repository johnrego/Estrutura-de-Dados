#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"

void a(int num, int **m, grafo *cidade, int nv){
	if (num>nv){
		printf("id nao existe\n");
	}
	else{
		for (int i=0;i<nv;i++){
			if (m[num-1][i]>0){
				printf("%s, ", cidade[i].nome);
			}
		}
		printf("\n");
	}
}

void d(int **m, grafo *cidade, int nv){
	printf("digraph {\n");
	for (int i=0;i<nv;i++){
		for (int j=0;j<nv;j++){
			if (m[i][j]>0){
				printf("\t%s -> %s;\n", cidade[i].nome, cidade[j].nome);
			}
		}
	}
	printf("}\n");
}

void l(grafo *cidade, int nv){
	for (int i=0;i<nv;i++){
		printf("%d: %s\n", cidade[i].id, cidade[i].nome);
	}
}

void p(int a, int b, int **m, int nv){
	for (int i=1;i<=nv;i++){
		if (bpl(a, b, i, m, nv)){
			printf("Caminho encontrado.\n");
			break;
		}
	}
}

int bpl(int id_a, int id_b, int lim, int **m, int nv){
	if (lim <= 0){
		return 0;
	}
	if (id_a==id_b){
		return 1;
	}
	for (int i=0;i<nv;i++){
		if (m[id_a-1][i]>0){
			if (bpl(i+1, id_b, lim-1, m, nv)){
				return 1;
			}
		}
	}
	return 0;
}