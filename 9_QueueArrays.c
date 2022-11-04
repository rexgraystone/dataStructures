/*
    9. Write a program to implement a queue using arrays.
*/

#include <stdio.h>
#include <stdlib.h>

int queue[5];
int front = 0;
int rear = 0;

void display() { // Display the queue
    for(int i = front; i < rear; ++i) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void enqueue(int a) { // Enqueue an element into the queue
    if(rear == 4) { // If the queue is full
        printf("Overflow"); // Print overflow
    }
    else { // Else enqueue the element
        queue[rear] = a;
        rear++;
    }
    printf("\n%d has been added to the queue\n\n", a);
}

void dequeue() { // Dequeue an element from the queue
    if(front == rear) { // If the queue is empty
        printf("Underflow");
    }
    else { // Else dequeue the element
        for(int i = 0; i < rear-1; i++) { // Shift the elements to the left
            queue[i] = queue[i+1];
        }
    }
    printf("\nElement has been deleted\n");
    rear--;
}

int main() { 
    int input,a;
    while(1) {
        printf("Enter 1 to insert element in queue\n");
        printf("Enter 2 to delete element last from the top of the queue\n");
        printf("Enter 3 to Display queue\n");
        printf("Enter 4 to Exit\n");
        scanf("%d", &input);
        switch(input) {
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