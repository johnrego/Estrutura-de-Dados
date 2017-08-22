#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
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
	atualiza_altura(no);
	no = rebalancea(no);
	return no;
}

bst *remove_menor(bst *no){
	if ((*no).esquerdo == NULL){
		bst *aux = (*no).direito;
		destroi_no(no);
		return aux;
	}
	(*no).esquerdo = remove_menor((*no).esquerdo);
	atualiza_altura(no);
	no = rebalancea(no);
	return no;
}

bst *remover(bst *no, int id){
	if (no == NULL){
		return NULL;
	}
	if (id < (*no).id){
		(*no).esquerdo = remover((*no).esquerdo, id);
		atualiza_altura(no);
		no = rebalancea(no);
		return no;
	}
	if (id > (*no).id){
		(*no).direito = remover((*no).direito, id);
		atualiza_altura(no);
		no = rebalancea(no);
		return no;
	}
	if ((*no).esquerdo == NULL){
		bst *aux = (*no).direito;
		destroi_no(no);
		return aux;
	}
	if ((*no).direito == NULL){
		bst *aux = (*no).esquerdo;
		destroi_no(no);
		return aux;
	}
	(*no).id = menor_valor((*no).direito);
	(*no).direito = remove_menor((*no).direito);
	atualiza_altura(no);
	no = rebalancea(no);
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
	destroi_no(no);
}

void destroi_no(bst *no){
	free((*no).nome);
	free(no);
}

int altura(bst *no){
	if (no == NULL){
		return 0;
	}
	return (*no).altura;
}

int max(int n1, int n2){
	if (n1 < n2){
		return n2;
	}
	return n1;
}

void atualiza_altura(bst *no){
	if (no == NULL){
		return;
	}
	(*no).altura = 1+max(altura((*no).esquerdo),altura((*no).direito));
}

int fator_eq(bst *no){
	if (no == NULL){
		return NULL;
	}
	return altura((*no).esquerdo)-altura((*no).direito);
}

bst *rot_direito(bst *no){
	if (no == NULL){
		return NULL;
	}
	if ((*no).esquerdo == NULL){
		return no;
	}
	bst *a = no;
	bst *b = (*no).esquerdo;
	bst *a2 = (*b).direito;
	(*b).direito = a;
	(*a).esquerdo = a2;
	atualiza_altura(a);
	atualiza_altura(b);
	return b;
}

bst *rot_esquerdo(bst *no){
	if (no == NULL){
		return NULL;
	}
	if ((*no).direito == NULL){
		return no;
	}
	bst *a = no;
	bst *b = (*no).direito;
	bst *a2 = (*b).esquerdo;
	(*b).esquerdo = a;
	(*a).direito = a2;
	atualiza_altura(a);
	atualiza_altura(b);
	return b;
}

bst *rebalancea(bst *no){
	if (no != NULL && (*no).esquerdo != NULL && fator_eq((*no).esquerdo) == 1 && fator_eq(no) == 2){
		no = rot_direito(no);
	}
	else if (no != NULL && (*no).direito != NULL && fator_eq((*no).direito) == -1 && fator_eq(no) == -2){
		no = rot_esquerdo(no);
	}
	else if (no != NULL && (*no).esquerdo != NULL && (*(*no).esquerdo).direito && fator_eq((*no).esquerdo) == -1 && fator_eq(no) == 2){
		(*no).esquerdo = rot_esquerdo((*no).esquerdo);
		no = rot_direito(no);
	}
	else if (no != NULL && (*no).direito != NULL && (*(*no).direito).esquerdo && fator_eq((*no).direito) == 1 && fator_eq(no) == -2){
		(*no).direito = rot_direito((*no).direito);
		no = rot_esquerdo(no);
	}
	return no;
}

int AVL(bst *no){
	if (no == NULL){
		return 1;
	}
	int altura_esquerdo = 0;
	if ((*no).esquerdo != NULL){
		altura_esquerdo = (*(*no).esquerdo).altura;
	}
	int altura_direiro = 0;
	if ((*no).direito != NULL){
		altura_direiro = (*(*no).direito).altura;
	}
	int fe = altura_esquerdo - altura_direiro;
	if (fe < -1 || fe > 1){
		return 0;
	}
	return AVL((*no).esquerdo) && AVL((*no).direito);
}