/*
    10. Write a program to evaluate postfix expressions.
*/

#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 20

int stack[20], top = -1;

void isEmpty() { // Check if the stack is empty
    if(top == -1) { // If the stack is empty, print underflow
        printf("STACK UNDERFLOW");
    }
}

void isFull() { // Check if the stack is full.
    if(top == MAX) { // If the stack is full, print overflow
        printf("STACK OVERFLOW");
    }
}

void push(int x) { // Push an element into the stack
    if(top == MAX) { // If the stack is full
        isFull(); // Print overflow
    }
    else { // Else push the element into the stack
        stack[++top] = x;
    }
}

int pop() { // Pop an element from the stack
    if(top == -1) { // If the stack is empty
        isEmpty(); // Print underflow
    }
    else { // Else pop the element from the stack
        return stack[top--];
    }
}

int postEval(char exp[]) { // Evaluate the postfix expression
    char *e;
    int num, n1, n2, tn;
    e = exp;
    while(*e != '\0') {
        if(isdigit(*e)) { // If the character is a digit
            num = *e - 48; // Convert the character to integer
            push(num);
        }
        else {
            n1 = pop();
            n2 = pop();
            switch(*e) {
                case '+':
                        tn = n1 + n2;
                        break;
                case '-':
                        tn = n1 - n2;
                        break;
                case '*':
                        tn = n1 * n2;
                        break;
                case '/':
                        tn = n1 / n2;
                        break;
                case '^':
                        tn = pow(n1, n2);
                        break;
                default: 
                        printf("\nOperator Unknown!"); 
			    return 0;    
            }
            push(tn);
        }
        e++;    
    }
    return pop();
}

int main() {   
    int ch = 1;
    char exp[MAX];  
    printf("Enter the expression: ");
    scanf("%s", exp);
    printf("\nThe Value of entered postfix %s expression is: %d\n", exp, postEval(exp));
    return 0;
}