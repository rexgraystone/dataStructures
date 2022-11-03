/*
	11. Write a program to implement a stack using linked lists.
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * next;
};
struct node * top = NULL;

void push(int data)
{
	struct node * new = (struct node *)malloc(sizeof(struct node));
	new -> data = data;
	new -> next =  top;
	top = new;
}

void pop()
{
	struct node * ptr = top;
	if(top == NULL)
    {
		printf("Underflow");
	}
	else
    {
		printf("Element Popped - %d", ptr -> data);
		top = top -> next;
		ptr -> next = NULL;
		free(ptr);
	}
}

void display()
{
	struct node * ptr = top;
	if(top == NULL)
    {
		printf("No elements in stack\n");
	}
	else
    {
		while(ptr != NULL)
        {
			printf("%d ", ptr->data);
			ptr = ptr -> next;
		}
	}
}

int main()
{
	int data, choice;
	while(1)
    {
		printf("\n");
		printf("Enter 1 to push\nEnter 2 to pop\nEnter 3 to Display\nEnter 4 to quit: ");
		scanf("%d", &choice);
		switch(choice)
        {
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
			default:
				printf("Wrong Input!");
		}
	}
}