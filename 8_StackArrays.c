/*
    8. Write a program to implement a stack using arrays.
*/

#include<stdio.h>
#include<stdlib.h>

int top = -1;
int stack[20];

void push(int a)
{
    if(top == 20)
    {
        printf("Overflow\n");
        return;
    }
    else
    {
        top++;
        stack[top] = a;
    }
}

int pop()
{
    int b;
    if(top == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        b = stack[top];
        --top;
    }
    return b;
}

void display()
{
    for(int i = top; i >= 0; --i)
    {
        printf("%d\n", stack[i]);
    }
}

void peak()
{
    if(top == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("The peak element in the stack is %d.\n", stack[top]);
    }
}

int main()
{
    int input;
    int a;
    while(1)
    {
        printf("Enter 1 to Push into Stack\n");
        printf("Enter 2 to Pop item from the top of the stack\n");
        printf("Enter 3 to Display Stack\n");
        printf("Enter 4 to Display Peak element\n");
        printf("Enter 5 to Exit\n");
        scanf("%d", &input);
    switch(input)
	{
        case 1:
            printf("\nEnter number to Push into Stack: ");
            scanf("%d", &a);
            push(a);
            break;
        case 2:
            printf("\n");
            printf("Popped Item - %d\n\n", pop());
            break;
        case 3:
            printf("\n");
            display();
            break;
        case 4:
            printf("\n");
            peak();
            break;
        case 5:
            exit(0);
        default:
            printf("Wrong Input!");
        break;
        }
    }
    return 0;
}
