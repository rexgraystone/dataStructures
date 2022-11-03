/*
	15. Write a program to search for a key element given a binary search tree.
*/

#include <stdlib.h> 
#include <stdio.h> 

struct binarySearch_tree 
{ 
	int data; 
	struct binarySearch_tree *right, *left; 
}; 
typedef struct binarySearch_tree node; 

void insert(node ** tree, int val) 
{ 
	node *temp = NULL;
	if(!(*tree))
	{
		temp = (node *)malloc(sizeof(node));
		temp->left = temp->right = NULL;
		temp->data = val;
		*tree = temp;
		return;
	}
	if(val<(*tree)->data)
	{
		insert(&(*tree)->left, val);
	}
	else if(val>(*tree)->data)
	{
		insert(&(*tree)->right, val);
	}
}

void print_preorder(node * tree)
{
	if (tree)
	{ 
		printf("%d\n", tree->data);
		print_preorder(tree->left);
		print_preorder(tree->right);
	}
}

void printInOrder(node * tree)
{
	if (tree)
	{ 	
		printInOrder(tree->left);
		printf("%d\n", tree->data);
		printInOrder(tree->right);
	}
}

void printPostOrder(node * tree)
{
	if (tree)
	{ 
		printPostOrder(tree->left);
		printPostOrder(tree->right);
		printf("%d\n", tree->data);
	}
}

void deltree(node * tree)
{
	if (tree)
	{
		deltree(tree->left);
		deltree(tree->right);
		free(tree);
	}
}

node * search(node **tree, int val)
{
	if(!(*tree))
	{
		return NULL;
	}
	if (val<(*tree)->data)
	{
		search(&((*tree)->left), val);
	}
	else if (val>(*tree)->data)
	{
		search(&((*tree)->right), val);
	}
	else if (val==(*tree)->data)
	{
		return *tree;
	}
}

int main()
{
	node *root;
	node *tmp;
	root=NULL;
	insert(&root, 9);
	insert(&root, 4);
	insert(&root, 15);
	insert(&root, 6);
	insert(&root, 12);
	insert(&root, 17);
	insert(&root, 2);
	printf("Pre order display\n");
	print_preorder(root);
	printf("In order display\n");
	printInOrder(root);
	printf("Post order display\n");
	printPostOrder(root);
	tmp=search(&root, 4);
	if(tmp)
	{
	 	printf("Searched node = %d\n", tmp->data);
	}
	else
	{
	 	printf("Data not found in tree\n");
	}
	deltree(root);
	return 0;
}