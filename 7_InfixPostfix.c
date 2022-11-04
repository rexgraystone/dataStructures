/*
    7. Write a program to convert an infix expression to postfix expression.
*/

#include <stdio.h>
#include <ctype.h>

#define MAX 15

char stack[MAX], top = -1;

void isEmpty() { // Check if the stack is empty
    if(top == -1) {
        printf("STACK UNDERFLOW");
    }
}

void isFull() { // Check if the stack is full
    if(top == MAX) {
        printf("STACK OVERFLOW"); // If the stack is full, print overflow
    }
}

void push(char x) { // Push an element into the stack
    if(top == MAX) { // If the stack is full
        isFull(); // Print overflow
    }
    else {
        stack[++top]=x; // Else push the element into the stack
    }
}

char pop() { // Pop an element from the stack
    if(top == -1) { // If the stack is empty
        isEmpty(); // Print underflow
    }
    else {
        return stack[top--]; // Else pop the element from the stack
    }
}

int priority(char x) { // Return the priority of the operator
    if(x == '(') {
        return 0;
    }
    if(x == '+' || x == '-') {
        return 1;
    }
    if(x == '*' || x == '/') {
        return 2;
    }
    if(x == '^') {
        return 3;
    }
}

int main() {   
    char X[MAX];
    char *e, x;
    int ch = 1;   
    while(ch) {
        printf("\nEnter INFIX Expression:");
        scanf("%s",X);
        e = X;
        printf("\nThe POSTFIX Expression:");
        while(*e != '\0') {
            if(isalnum(*e)) {
                printf("%c", *e);
            }
            else if(*e == '(') {
                push(*e);
            }
            else if(*e == ')') {
                while((x = pop() != '(')) {
                    printf("%c",x);
                }
            }
            else {
                while(priority(stack[top]) >= priority(*e)) {
                    printf("%c",pop());
                }
                push(*e);
            }
            e++;
        }
        while(top != -1) {
            printf("%c",pop());
        }
    }
    return 0;
}