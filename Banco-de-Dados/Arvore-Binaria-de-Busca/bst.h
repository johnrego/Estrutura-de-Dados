#ifndef __BST_H__
#define __BST_H__
typedef struct bst_{
	int id;
	char *nome; 
	struct bst_ *esquerdo;
	struct bst_ *direito;
} bst;

bst *novo_no(int id, char *nome);
bst *insere(bst *no, int id, char *nome);
bst *remove_menor(bst *no);
bst *remover(bst *no, int id);
int min(int n1, int n2);
int menor_valor(bst *no);
bst *encontra(bst *no, int id);
void destroi_arvore(bst *no);
#endif