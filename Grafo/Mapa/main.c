#include <stdio.h>
#include "grafo.h"

int main(){
	char opt;
	int n1, n2;
	while (1<2){
		printf("> ");
		scanf(" %c", &opt);
		if(opt == 'q')
			break;
		switch(opt) {
			case 'a':
				scanf("%d", &n1);
				a(n1);				
			break;
			case 'd':
				d();
			break;
			case 'l':
				l();
			break;
			case 'p':
				scanf("%d %d", &n1, &n2);
				p(n1, n2);
			break;
			default:
			break;
		}
	}
	return 0;
}