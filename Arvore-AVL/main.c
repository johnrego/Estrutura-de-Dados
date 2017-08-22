#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void insert_person(int id, char *nome);
void remove_person(int id);
void view_person(int id);

bst *no = NULL;

int main(){
	FILE* file = fopen("id_names.txt", "r");
	int id;
	char nome[256];
	char opt;
	if(!file) {
		printf("Error openning file!\n");
		exit(1);
	}

	while(fscanf(file, "%d ", &id) != EOF) {
		fgets(nome, sizeof(nome), file);
		printf("%d %s", id, nome);
		insert_person(id, nome);
	}
	fclose(file);
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
	destroi_arvore(no);
	return 0;
}

void insert_person(int id, char *nome){
	no = insere(no, id, nome);
	if (!AVL(no)){
		printf("Arvove nao AVL.\n");
	}
}

void remove_person(int id){
	no = remover(no, id);
	printf("%d\n", AVL(no));
	if (!AVL(no)){
		printf("Arvove nao AVL.\n");
	}
}

void view_person(int id){
	bst *aux = encontra(no, id);
	if (aux != NULL){
		printf("%s", (*aux).nome);
	}
	else {
		printf("Id not found\n");
	}
}