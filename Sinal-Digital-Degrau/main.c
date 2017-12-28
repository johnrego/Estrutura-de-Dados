#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]){
	if(argc < 2){
		return 0;
	}
	int valor[argc-1];
	int i = 0;
	for(i=1;i<argc;i++){
		sscanf(argv[i], "%d", &valor[i-1]);
	}
	printf("x(t)=");
	if(valor[0]>0){
		printf("u(t)");
	}
	else{
		printf("-u(t)");
	}
	for(i=1;i<argc-1;i++){
		if(valor[i-1]>valor[i]){
			printf("-u(t-%d)", i);
		}
		if(valor[i-1]<valor[i]){
			printf("+u(t-%d)", i);
		}
	}
	printf("\n");
	return 0;
}