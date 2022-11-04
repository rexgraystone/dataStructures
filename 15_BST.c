/*
	15. Write a program to search for a key element given a binary search tree.
*/

#include <stdlib.h> 
#include <stdio.h> 

struct binarySearchTree { // Structure of a node 
	int data; 
	struct binarySearchTree *right, *left; // Pointers to the left and right nodes
}; 
typedef struct binarySearchTree node; 

void insert(node ** tree, int val) { // Insert an element into the tree
	node *temp = NULL; 
	if(!(*tree)) { // If the tree is empty
		temp = (node *)malloc(sizeof(node));
		temp -> left = temp -> right = NULL;
		temp -> data = val;
		*tree = temp;
		return;
	}
	if(val < (*tree) -> data) { // If the value is less than the data of the current node	
		insert(&(*tree) -> left, val);
	}
	else if(val > (*tree) -> data) { // If the value is greater than the data of the current node
		insert(&(*tree) -> right, val);
	}
}

void printPostOrder(node * tree) { // Print the tree in preorder
	if (tree) { // If the tree is not empty
		printf("%d\n", tre -> data); // Print the data of the current node
		printPostOrder(tree -> left); // Print the left subtree
		printPostOrder(tree -> right); // Print the right subtree
	}
}

void printInOrder(node * tree) { // Print the tree in inorder
	if (tree) { // If the tree is not empty
		printInOrder(tree -> left); // Print the left subtree
		printf("%d\n", tree -> data); // Print the data of the current node
		printInOrder(tree -> right); // Print the right subtree
	}
}

void printPostOrder(node * tree) { // Print the tree in postorder
	if (tree) { // If the tree is not empty
		printPostOrder(tree -> left); // Print the left subtree
		printPostOrder(tree -> right); // Print the right subtree
		printf("%d\n", tree -> data); // Print the data of the current node
	}
}

void delTree(node * tree) { // Delete the tree
	if (tree) { // If the tree is not empty
		delTree(tree -> left); // Delete the left subtree
		delTree(tree -> right); // Delete the right subtree
		free(tree);
	}
}

node * search(node **tree, int val) { // Search for a key element in the tree
	if(!(*tree)) { // If the tree is empty
		return NULL; // Return NULL
	}
	if (val < (*tree) -> data) { // If the value is less than the data of the current node
		search(&((*tree) -> left), val); // Search in the left subtree
	}
	else if (val > (*tree) -> data) { // If the value is greater than the data of the current node
		search(&((*tree) -> right), val); // Search in the right subtree
	}
	else if (val == (*tree) -> data) { // If the value is equal to the data of the current node
		return *tree; // Return the current node
	}
}

int main() {
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
	printPostOrder(root);
	printf("In order display\n");
	printInOrder(root);
	printf("Post order display\n");
	printPostOrder(root);
	tmp=search(&root, 4);
	if(tmp) {
	 	printf("Searched node = %d\n", tmp -> data);
	}
	else {
	 	printf("Data not found in tree\n");
	}
	delTree(root);
	return 0;
}