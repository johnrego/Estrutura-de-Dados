#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"

void a(int num){
	FILE* file = fopen("mapa.txt", "r");
	if(!file) {
		printf("Error openning file!\n");
		exit(1);
	}
	int nv;
	char name[256];
	fscanf(file,"%d\n", &nv);
	grafo cidade[nv];
	for(int i=0;i<nv;i++){
		cidade[i].id = i+1;
		fgets(name, sizeof(name), file);
		name[strlen(name)-1] = '\0';
		cidade[i].nome = strdup(name);
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
	for (int i=nv-1;i>-1;i--){
		free(cidade[i].nome);
	}
}

void d(){
	FILE* file = fopen("mapa.txt", "r");
	if(!file) {
		printf("Error openning file!\n");
		exit(1);
	}
	int nv;
	char name[256];
	fscanf(file,"%d\n", &nv);
	grafo cidade[nv];
	for(int i=0;i<nv;i++){
		cidade[i].id = i+1;
		fgets(name, sizeof(name), file);
		name[strlen(name)-1] = '\0';
		cidade[i].nome = strdup(name);
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
	printf("digraph {\n");
	for (int i=0;i<nv;i++){
		for (int j=0;j<nv;j++){
			if (m[i][j]>0){
				printf("\t%s -> %s;\n", cidade[i].nome, cidade[j].nome);
			}
		}
	}
	printf("}\n");
	for (int i=nv-1;i>-1;i--){
		free(cidade[i].nome);
	}
}

void l(){
	FILE* file = fopen("mapa.txt", "r");
	if(!file) {
		printf("Error openning file!\n");
		exit(1);
	}
	int nv;
	char name[256];
	fscanf(file,"%d\n", &nv);
	grafo cidade[nv];
	for(int i=0;i<nv;i++){
		cidade[i].id = i+1;
		fgets(name, sizeof(name), file);
		name[strlen(name)-1] = '\0';
		cidade[i].nome = strdup(name);
	}
	fclose(file);
	for (int i=0;i<nv;i++){
		printf("%d: %s\n", cidade[i].id, cidade[i].nome);
	}
	for (int i=nv-1;i>-1;i--){
		free(cidade[i].nome);
	}
}

void p(int a, int b){
	FILE* file = fopen("mapa.txt", "r");
	if(!file) {
		printf("Error openning file!\n");
		exit(1);
	}
	int nv;
	fscanf(file,"%d\n", &nv);
	fclose(file);
	for (int i=1;i<=nv;i++){
		if (bpl(a, b, i)){
			printf("Caminho encontrado.\n");
			break;
		}
	}
}

int bpl(int id_a, int id_b, int lim){
	if (lim <= 0){
		return 0;
	}
	if (id_a==id_b){
		return 1;
	}
	FILE* file = fopen("mapa.txt", "r");
	if(!file) {
		printf("Error openning file!\n");
		exit(1);
	}
	int nv;
	char name[256];
	fscanf(file,"%d\n", &nv);
	grafo cidade[nv];
	for(int i=0;i<nv;i++){
		cidade[i].id = i+1;
		fgets(name, sizeof(name), file);
		name[strlen(name)-1] = '\0';
		cidade[i].nome = strdup(name);
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
	for (int i=0;i<nv;i++){
		if (m[id_a-1][i]>0){
			if (bpl(i+1, id_b, lim-1)){
				return 1;
			}
		}
	}
	for (int i=nv-1;i>-1;i--){
		free(cidade[i].nome);
	}
	return 0;
}