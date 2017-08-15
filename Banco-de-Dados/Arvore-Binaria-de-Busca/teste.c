#include <stdio.h>
#include "bst.h"

int main(){
	bst *n1 = new_node(1);
	bst *n3 = new_node(3);
	bst *n2 = new_tree(2, n1, n3);
	bst *n5 = new_node(5);
	bst *n7 = new_node(7);
	bst *n6 = new_tree(6, n5, n7);
	bst *n4 = new_tree(4, n2, n6);
	display_tree(n4, 0);
	printf("Tamnaho: %d\n", size(n4));
	printf("%d\n", contains(n4, 10));
	printf("Altura: %d\n", height(n4));
	printf("Maior: %d\n", biggest(n4));
	printf("Menor: %d\n", smallest(n4));
	printf("Soma: %d\n", sum(n4));
	display_leaves(n4, 0);
	destroy_tree(n4);
	return 0;
}