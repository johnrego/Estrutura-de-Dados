#include <stdio.h>

int solve(int cl, int ml, int cr, int mr, int boat, int depth);

int main(){
	int i;
	for (i=0; ;i++){
		if (solve(3, 3, 0, 0, 1, i)){
			break;;
		}
	}
	return 0;
}

int solve(int cl, int ml, int cr, int mr, int boat, int depth){
	if (depth<=0){
		return 0;
	}
	if (cl<0||cl>3||
		cr<0||cr>3||
		ml<0||ml>3||
		cr<0||mr>3||
		(ml>=1&&cl>ml)||
		(mr>=1&&cr>mr)){
		return 0;
	}
	if (cl==0&&ml==0&&
		cr==3&&mr==3){
		printf("%d %d %d %d %d\n", cl, ml, cr, mr, boat);
		return 1;
	}
	depth--;
	if (solve(cl-boat, ml, cr+boat, mr, -boat, depth)||
		solve(cl-2*boat, ml, cr+2*boat, mr, -boat, depth)||
		solve(cl, ml-boat, cr, mr+boat, -boat, depth)||
		solve(cl, ml-2*boat, cr, mr+2*boat, -boat, depth)||
		solve(cl-boat, ml-boat, cr+boat, mr+boat, -boat, depth)){
		printf("%d %d %d %d %d\n", cl, ml, cr, mr, boat);
		return 1;
	}
	return 0;
}