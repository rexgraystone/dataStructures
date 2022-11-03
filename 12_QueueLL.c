/*
    12. Write a program to implement a queue using linked lists.
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};
struct node * front = NULL;
struct node * rear = NULL;

void enqueue(int data)
{
    struct node * new = (struct node *)malloc(sizeof(struct node));
    new -> data = data;
    if(front == NULL)
    {
        front  = new;
        rear = new;
    }
    else
    {
        rear -> next = new;
        rear = new;
        new -> next = NULL;
    }
}

void dequeue()
{
    if(front == NULL)
    {
        printf("Underflow");
    }
    else
    {
        front = front -> next;
    }
}

void traverse()
{
    struct node * ptr = front;
    while(ptr != NULL)
    {
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }
}

int main()
{
    int data, input;
    while(1)
    {
        printf("\n");
        printf("Enter 1 to Enqueue\nEnter 2 to Dequeue\nEnter 3 to Traverse- ");
        scanf("%d", &input);
        switch(input)
        {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                printf("Dequeueing the first element from the queue...\n");
                dequeue();
                break;
            case 3:
                traverse();
                break;
            default:
                printf("Wrong input");
        }
    }
    return 0;
}