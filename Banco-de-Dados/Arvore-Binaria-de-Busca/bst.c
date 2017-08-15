#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "bst.h"

bst *new_node(int value){
	bst *node = (bst*)malloc(sizeof(bst));
	(*node).left = NULL;
	(*node).right = NULL;
	(*node).value = value;
	return node;
}

bst *new_tree(int value, bst *left, bst *right){
	bst *node = new_node(value);
	(*node).left = left;
	(*node).right = right;
	return node;
}

void display_tree(bst *node, int level){
	if (node == NULL){
		return;
	}
	int i;
	for (i=0;i<level;i++){
		printf(" ");
	}
	printf("%d\n", (*node).value);
	display_tree((*node).left, level+1);
	display_tree((*node).right, level+1);
}

void display_leaves(bst *node, int level){
	if (node == NULL){
		return;
	}
	if ((*node).left == NULL && (*node).left == NULL){
		printf("%d\n", (*node).value);
	}
	display_leaves((*node).left, level+1);
	display_leaves((*node).right, level+1);
}

void destroy_tree(bst *node){
	if (node == NULL){
		return;
	}
	destroy_tree((*node).left);
	destroy_tree((*node).right);
	free(node);
}

int size(bst *node){
	if (node == NULL){
		return 0;
	}
	return 1+size((*node).left)+size((*node).right);
}

int contains(bst *node, int value){
	if (node == NULL){
		return 0;
	}
	if ((*node).value == value){
		return 1;
	}
	if (value > (*node).value){
		return contains((*node).right, value);
	}
	return contains((*node).left, value);
}

int max(int n1, int n2){
	if (n1 > n2){
		return n1;
	}
	return n2;
}

int min(int n1, int n2){
	if (n1 < n2){
		return n1;
	}
	return n2;
}

int height(bst *node){
	if (node == NULL){
		return 0;
	}
	return 1+max(height((*node).right),height((*node).left));
}

int smallest(bst *node){
	if (node == NULL){
		return INT_MAX;
	}
	return min(smallest((*node).left),(*node).value);
}

int biggest(bst *node){
	if (node == NULL){
		return INT_MIN;
	}
	return max((*node).value,biggest((*node).right));
}

int sum(bst *node){
	if (node == NULL){
		return 0;
	}
	return (*node).value+sum((*node).left)+sum((*node).right);
}