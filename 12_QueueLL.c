/*
    12. Write a program to implement a queue using linked lists.
*/

#include <stdio.h>
#include <stdlib.h>

struct node { // Structure of a node
    int data;
    struct node * next;
};
struct node * front = NULL;
struct node * rear = NULL;

void enqueue(int data) { // Enqueue an element into the queue
    struct node * new = (struct node *)malloc(sizeof(struct node));
    new -> data = data;
    if(front == NULL) { // If the queue is empty
        front = new; // Set the front to the new node
        rear = new; // Set the rear to the new node
    }
    else { // Else enqueue the element
        rear -> next = new; // Set the next of the rear to the new node
        rear = new; // Set the rear to the new node
        new -> next = NULL; // Set the next of the new node to NULL
    }
}

void dequeue() { // Dequeue an element from the queue
    if(front == NULL) { // If the queue is empty
        printf("Underflow"); // Print underflow
    }
    else { // Else dequeue the element
        front = front -> next;
    }
}

void traverse() { // Traverse the queue
    struct node * ptr = front;
    while(ptr != NULL) { // While the pointer is not NULL
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }
}

int main() {
    int data, input;
    while(1) {
        printf("\n");
        printf("1. Enqueue\n2. to Dequeue\n3. to Traverse\n4. to Quit");
        printf("\nEnter your choice: ");
        scanf("%d", &input);
        switch(input) {
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
            case 4:
                exit(0);
            default:
                printf("Wrong input");
        }
    }
    return 0;
}