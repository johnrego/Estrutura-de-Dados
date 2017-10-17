#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

hash *criaHash(int table_size){
	hash *ha = (hash*)malloc(sizeof(hash));
	(*ha).table_size = table_size;
	(*ha).itens = (aluno**)malloc(table_size*sizeof(aluno*));
	(*ha).qtd = 0;
	for (int i=0;i<(*ha).table_size;i++){
		(*ha).itens[i] = NULL;
	}
	return ha;
}

void liberaHash(hash *ha){
	if (ha!=NULL){
		for (int i=0;i<(*ha).table_size;i++){
			free((*ha).itens[i]);
		}
		free((*ha).itens);
		free(ha);
	}
}

int valorString(char *str){
	int valor = 7;
	int tam = strlen(str);
	for (int i=0;i<tam;i++){
		valor = 31*valor+(int)str[i];
	}
	return valor;
}

int chaveDivisao(int chave, int table_size){
	return (chave&0x7FFFFFFF)%table_size;
}

int insereSemColisao(hash *ha, aluno al){
	if (ha==NULL||(*ha).qtd==(*ha).table_size){
		return 0;
	}
	int chave = al.matricula;
	int pos = chaveDivisao(chave, (*ha).table_size);
	aluno *novo;
	novo = (aluno*)malloc(sizeof(aluno));
	*novo = al;
	(*ha).itens[pos] = novo;
	(*ha).qtd++;
	return 1;
}

int insereEndAberto(hash *ha, aluno al){
	if (ha==NULL||(*ha).qtd==(*ha).table_size){
		return 0;
	}
	int chave = al.matricula;
	int pos, newPos;
	pos = chaveDivisao(chave, (*ha).table_size);
	for (int i=0;i<(*ha).table_size;i++){
		newPos = sondagemLinear(pos, i, (*ha).table_size);
		if ((*ha).itens[newPos]==NULL){
			aluno *novo;
			novo = (aluno*)malloc(sizeof(aluno));
			*novo = al;
			(*ha).itens[newPos] = novo;
			(*ha).qtd++;
			return 1;
		}
	}
	return 0;
}

int buscaSemColisao(hash *ha, int mat, aluno *al){
	if (ha==NULL){
		return 0;
	}
	int pos = chaveDivisao(mat, (*ha).table_size);
	if ((*ha).itens[pos]==NULL){
		return 0;
	}
	*al = *((*ha).itens[pos]);
	return 1;
}

int buscaEndAberto(hash *ha, int mat, aluno *al){
	if (ha==NULL){
		return 0;
	}
	int pos, newPos;
	pos = chaveDivisao(mat, (*ha).table_size);
	for (int i=0;i<(*ha).table_size;i++){
		newPos = sondagemLinear(pos, i, (*ha).table_size);
		if ((*ha).itens==NULL){
			return 0;
		}
		if ((*(*ha).itens[newPos]).matricula == mat){
			*al = *((*ha).itens[newPos]);
			return 1;
		}
	}
	return 0;
}

int sondagemLinear(int pos, int i,int table_size){
	return ((pos+i)&0x7FFFFFFF)%table_size;
}

int sondagemQuadratica(int pos, int i, int table_size){
	pos += 2*i + 5*i*i;
	return (pos&0x7FFFFFFF)%table_size;
}

int duploHash(int h1, int chave, int i, int table_size){
	int h2 = chaveDivisao(chave, table_size-1)+1;
	return ((h1+i*h2)&0x7FFFFFFF)%table_size;
}

