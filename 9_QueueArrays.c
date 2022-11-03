/*
    9. Write a program to implement a queue using arrays.
*/

#include <stdio.h>
#include <stdlib.h>

int queue[5];
int front = 0;
int rear = 0;

void display()
{
    for(int i = front; i < rear; ++i)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void enqueue(int a)
{
    if(rear == 4)
    {
        printf("Overflow");
    }
    else
    {
        queue[rear] = a;
        rear++;
    }
    printf("\n%d has been added to the queue\n\n", a);
}

void dequeue()
{
    if(front == rear)
    {
        printf("Underflow");
    }
    else
    {
        for(int i = 0; i < rear-1; i++)
        {
            queue[i] = queue[i+1];
        }
    }
    printf("\nElement has been deleted\n");
    rear--;
}

int main()
{
    int input,a;
    while(1)
    {
        printf("Enter 1 to insert element in queue\n");
        printf("Enter 2 to delete element last from the top of the queue\n");
        printf("Enter 3 to Display queue\n");
        printf("Enter 4 to Exit\n");
        scanf("%d", &input);
        switch(input)
	    {
            case 1:
                printf("Enter number to Push into Stack: ");
                scanf("%d", &a);
                enqueue(a);
                break;
            case 2:
                printf("\n");
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong Input!");
                break;
        }
    }
    return 0;
}