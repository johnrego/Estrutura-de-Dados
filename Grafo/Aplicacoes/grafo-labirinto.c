#include <stdio.h>

#define H 10
#define W 10

int solve(int row, int col, int depth);
void show();

char lab[H][W] = {
	"    x   x ",
	"xxx x x   ",
	"    xgxx  ",
	" xxxxxx   ",
	"    xxxxx ",
	"       x  ",
	"x xxx  x  ",
	"   x   x  ",
	"   x      ",
	"   x      ",
};

int main(){
	int i;
	for (i=0; ;i++){
		if (solve(0, 0, i)){
			printf("Caminho encontrado\n");
			break;
		}
	}
	show();
	return 0;
}

int solve(int row, int col, int depth){
	if (depth<=0){
		return 0;
	}
	if (row<0||row>=H||
		col<0||col>=W||
		lab[row][col]=='x'||
		lab[row][col]=='.'){
		return 0;
	}
	if (lab[row][col]=='g'){
		return 1;
	}
	depth--;
	lab[row][col] = '.';
	if (solve(row-1, col, depth)||
		solve(row+1, col, depth)||
		solve(row, col-1, depth)||
		solve(row, col+1, depth)){
		return 1;
	}
	lab[row][col] = ' ';
	return 0;
}

void show(){
	int i, j;
	for (i=0;i<H;i++){
		for (j=0;j<W;j++){
			printf("%c", lab[i][j]);
		}
		printf("\n");
	}
}