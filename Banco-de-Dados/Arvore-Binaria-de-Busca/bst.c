#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <strings.h>
#include "bst.h"

bst *novo_no(int id, char *nome){
	bst *no = (bst*)malloc(sizeof(bst));
	(*no).esquerdo = NULL;
	(*no).direito = NULL;
	(*no).id = id;
	(*no).nome = strdup(nome);
	return no;
}

bst *insere(bst *no, int id, char *nome){
	if (no == NULL){
		return novo_no(id, nome);
	}
	if ((*no).id > id){
		(*no).esquerdo = insere((*no).esquerdo, id, nome);
	}
	else {
		(*no).direito = insere((*no).direito, id, nome);
	}
	return no;
}

bst *remove_menor(bst *no){
	if ((*no).esquerdo == NULL){
		return (*no).direito;
	}
	(*no).esquerdo = remove_menor((*no).esquerdo);
	return no;
}

bst *remover(bst *no, int id){
	if (no == NULL){
		return NULL;
	}
	if (id < (*no).id){
		(*no).esquerdo = remover((*no).esquerdo, id);
		return no;
	}
	if (id > (*no).id){
		(*no).direito = remover((*no).direito, id);
		return no;
	}
	if ((*no).esquerdo == NULL){
		return (*no).direito;
	}
	if ((*no).direito == NULL){
		return (*no).esquerdo;
	}
	(*no).id = menor_valor((*no).direito);
	(*no).direito = remove_menor((*no).direito);
	return no;
}

int min(int n1, int n2){
	if (n1 < n2){
		return n1;
	}
	return n2;
}
int menor_valor(bst *no){
	if (no == NULL){
		return INT_MAX;
	}
	return min(menor_valor((*no).esquerdo),(*no).id);
}

bst *encontra(bst *no, int id){
	if (no == NULL){
		return no;
	}
	if ((*no).id == id){
		return no;
	}
	if (id > (*no).id){
		return encontra((*no).direito, id);
	}
	return encontra((*no).esquerdo, id);
}

void destroi_arvore(bst *no){
	if (no == NULL){
		return;
	}
	destroi_arvore((*no).esquerdo);
	destroi_arvore((*no).direito);
	free((*no).nome);
	free(no);
}