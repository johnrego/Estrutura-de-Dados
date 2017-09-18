#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct grafo_{
	int id;
	char *nome;
} grafo;

int main(){
	FILE* file = fopen("mapa.txt", "r");
	if(!file) {
		printf("Error openning file!\n");
		exit(1);
	}
	int nv;
	char name[256];
	fscanf(file,"%d\n", &nv);
	grafo cidades[nv];
	for(int i=0;i<nv;i++){
		cidades[i].id = i+1;
		fgets(name, sizeof(name), file);
		name[strlen(name)-1] = '\0';
		cidades[i].nome = strdup(name);;
	}
	int m[nv][nv];
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
	while (1<2){
		printf("> ");
		scanf(" %c", &opt);
		if(opt == 'q')
			break;
		int num;
		switch(opt) {
			case 'a':
				scanf("%d", &num);
				if (num>nv){
					printf("id nao existe\n");
				}
				else{
					for (int i=0;i<nv;i++){
						if (m[num-1][i]>0){
							printf("%s, ", cidades[i].nome);
						}
					}
					printf("\n");
				}
			break;
			case 'd':
				printf("digraph {\n");
				for (int i=0;i<nv;i++){
					for (int j=0;j<nv;j++){
						if (m[i][j]>0){
							printf("\t%s -> %s;\n", cidades[i].nome, cidades[j].nome);
						}
					}
				}
				printf("}\n");
			break;
			case 'l':
				for (int i=0;i<nv;i++){
					printf("%d: %s\n", cidades[i].id, cidades[i].nome);
				}
			break;
			default:
			break;
		}
	}
	return 0;
}