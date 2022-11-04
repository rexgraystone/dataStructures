/*
	11. Write a program to implement a stack using linked lists.
*/

#include <stdio.h>
#include <stdlib.h>

struct node { // Structure of a node
	int data;
	struct node * next;
};
struct node * top = NULL;

void push(int data) { // Push an element into the stack
	struct node * new = (struct node *)malloc(sizeof(struct node));
	new -> data = data;
	new -> next =  top;
	top = new;
}

void pop() { // Pop an element from the stack
	struct node * ptr = top;
	if(top == NULL) { // If the stack is empty
		printf("Underflow"); // Print underflow
	}
	else { // Else pop the element from the stack
		printf("Element Popped - %d", ptr -> data);
		top = top -> next;
		ptr -> next = NULL;
		free(ptr);
	}
}

void display() { // Display the stack
	struct node * ptr = top;
	if(top == NULL) { // If the stack is empty
		printf("No elements in stack\n"); // Print no elements
	}
	else {
		while(ptr != NULL) { // Else display the stack
			printf("%d ", ptr -> data); 
			ptr = ptr -> next;
		}
	}
}

int main() {
	int data, choice;
	while(1) {
		printf("\n");
		printf("1. Push\n2. Pop\n3. Display\n4. Quit");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 0:
				exit(0);
			case 1:
				printf("Enter the data: ");
				scanf("%d", &data);
				push(data);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				printf("Wrong Input!");
		}
	}
}