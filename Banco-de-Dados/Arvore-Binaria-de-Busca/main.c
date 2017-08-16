#include <stdio.h>
#include <stdlib.h>

void insert_person(int id, char *name);
void remove_person(int id);
void view_person(int id);

int main(int argc, char* argv[]){
	FILE* file = fopen("id_names.txt", "r");
	int id;
	char name[256];
	char opt;
	if(!file) {
		printf("Error openning file!\n");
		exit(1);
	}

	while(fscanf(file, "%d ", &id) != EOF) {
		fgets(name, sizeof(name), file);
		printf("%d %s", id, name);
		insert_person(id, name);
	}

	while (1<2){
		printf("> ");
		scanf(" %c", &opt);
		if(opt == 'q')
			break;
		switch(opt) {
			case 'i':
				scanf("%d", &id);
				fgets(name, sizeof(name), stdin);
				insert_person(id, name);
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
	fclose(file);
	return 0;
}

void insert_person(int id, char *name){
}

void remove_person(int id){
}

void view_person(int id){
}