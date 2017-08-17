#ifndef __BST_H__
#define __BST_H__
typedef struct bst_{
	int id;
	int altura;
	char *nome; 
	struct bst_ *esquerdo;
	struct bst_ *direito;
} bst;

bst *encontra(bst *no, int id);
bst *insere(bst *no, int id, char *nome);
bst *novo_no(int id, char *nome);
bst *rebalancear(bst *no);
bst *remove_menor(bst *no);
bst *remover(bst *no, int id);
bst *rot_direito(bst *no);
bst *rot_esquerdo(bst *no);
int altura(bst *no);
int fator_eq(bst *no);
int max(int n1, int n2);
int min(int n1, int n2);
int menor_valor(bst *no);
void atualiza_altura(bst *no);
void destroi_arvore(bst *no);
void destroi_no(bst *no);;
#endif