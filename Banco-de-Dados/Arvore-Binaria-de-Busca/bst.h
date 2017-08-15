#ifndef __BST_H__
#define __BST_H__
typedef struct bst_{
	int value;
	struct bst_ *left; //esquerda
	struct bst_ *right; //direita
} bst;

bst *new_node(int value);
bst *new_tree(int value, bst *left, bst *right);
void display_tree(bst *node, int level);
void display_leaves(bst *node, int level);
void destroy_tree(bst *node);
int size(bst *node);
int contains(bst *node, int value);
int max(int n1, int n2);
int min(int n1, int n2);
int height(bst *node);
int smallest(bst *node);
int biggest(bst *node);
int sum(bst *node);
#endif