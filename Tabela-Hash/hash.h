#ifndef __HASH_H__
#define __HASH_H__

typedef struct Aluno{
	int matricula;
	char nome[256];
	float n1, n2, n3;	
} aluno;

typedef struct Hash{
	int qtd, table_size;
	aluno **itens;	
} hash;

typedef struct Aluno aluno;
typedef struct Hash hash;
hash *criaHash(int table_size);
void liberaHash(hash *ha);
int valorString(char *str);
int insereSemColisao(hash *ha, aluno al);
int buscaSemColisao(hash *ha, int mat, aluno *al);
int insereEndAberto(hash *ha, aluno al);
int buscaEndAberto(hash *ha, int mat, aluno *al);
int remocaoEndAberto(hash *ha, int mat);
int chaveDivisao(int chave, int table_size);
int sondagemLinear(int pos, int i,int table_size);
int sondagemQuadratica(int pos, int i, int table_size);
int duploHash(int h1, int chave, int i, int table_size);
#endif