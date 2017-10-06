#ifndef __GRAFO_H__
#define __GRAFO_H__

typedef struct grafo_{
	int id;
	char *nome;
} grafo;

void a(int num, int **m, grafo *cidade, int nv);
int bpl(int id_a, int id_b, int lim, int **m, int nv);
void d(int **m, grafo *cidade, int nv);
void l(grafo *cidade, int nv);
void p(int a, int b, int **m, int nv);
#endif