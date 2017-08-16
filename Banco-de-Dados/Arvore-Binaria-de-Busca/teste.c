#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void insert_person(int id, char *nome);
void remove_person(int id);
void view_person(int id);

bst *no = NULL;

int main(){
	int id;
	char nome[256];
	char opt;
	while (1<2){
		printf("> ");
		scanf(" %c", &opt);
		if(opt == 'q')
			break;
		switch(opt) {
			case 'i':
				scanf("%d", &id);
				fgets(nome, sizeof(nome), stdin);
				insert_person(id, nome);
			break;
			case 'r':
				scanf("%d", &id);
				remove_person(id);
			break;
			case 'v':
				scanf("%d", &id);
				view_person(id);
			break;
			default:
			break;
		}
	}
	free(no);
	return 0;
}

void insert_person(int id, char *nome){
	no = insere(no, id, nome);
}

void remove_person(int id){
	no = remover(no, id);
}

void view_person(int id){
	bst *aux = encontra(no, id);
	if (aux != NULL){
		printf("%s\n", (*aux).nome);
	}
	else {
		printf("Id not found\n");
	}
}