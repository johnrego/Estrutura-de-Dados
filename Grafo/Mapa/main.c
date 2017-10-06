#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"

int main(){
	FILE* file = fopen("mapa.txt", "r");
	if(!file) {
		printf("Error openning file!\n");
		exit(1);
	}
	int nv;
	char name[256];
	fscanf(file,"%d\n", &nv);
	grafo *cidade;
	cidade = malloc(nv*sizeof(grafo));
	for(int i=0;i<nv;i++){
		cidade[i].id = i+1;
		fgets(name, sizeof(name), file);
		name[strlen(name)-1] = '\0';
		cidade[i].nome = strdup(name);
	}
	int **m;
	m = malloc(nv*sizeof(int*));
	for (int i=0;i<nv;i++){
		m[i] = malloc(nv*sizeof(int));
	}
	for (int i=0;i<nv;i++){
		for (int j=0;j<nv;j++){
			m[i][j] = 0;
		}
	}
	int na;
	fscanf(file,"%d\n", &na);
	for (int i=0;i<na;i++){
		int a,b;
		fscanf(file,"%d %d\n", &a, &b);
		m[a-1][b-1] = 1;
	}
	fclose(file);

	char opt;
	int n1, n2;
	while (1<2){
		printf("> ");
		scanf(" %c", &opt);
		if(opt == 'q')
			break;
		switch(opt) {
			case 'a':
				scanf("%d", &n1);
				a(n1, m, cidade, nv);				
			break;
			case 'd':
				d(m, cidade, nv);
			break;
			case 'l':
				l(cidade, nv);
			break;
			case 'p':
				scanf("%d %d", &n1, &n2);
				p(n1, n2, m, nv);
			break;
			default:
			break;
		}
	}
	for (int i=nv-1;i>-1;i--){
		free(cidade[i].nome);
	}
	return 0;
}