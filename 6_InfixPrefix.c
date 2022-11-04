/*
	6. Write a program to convert an infix expression to postfix expression using stack.
*/

#include <stdio.h>
#include <string.h>

#define MAX 20

void infixToPrefix(char infix[20], char prefix[20]);
void reverseString(char array[30]);
char pop();
void push(char symbol);
int isOperator(char symbol);
int prcd(char symbol);
int top=-1;
char stack[MAX];

void main() {
	char infix[20], prefix[20], temp;
	printf("Enter infix operation: ");
	scanf("%s", infix);
	infixToPrefix(infix, prefix);
	reverseString(prefix);
	printf("The Prefix is: %s", prefix);
}

void infixToPrefix(char infix[20], char prefix[20]) { // Reverse the infix expression.
	int i, j = 0;
	char symbol;
	stack[++top]='#';
	reverseString(infix);
	for (i=0; i<strlen(infix); i++) {
		symbol = infix[i];
		if (isOperator(symbol) == 0) {
			prefix[j] = symbol;
			j++;
		} 
		else {
			if (symbol == ')') {
				push(symbol);
			} 
			else if(symbol == '(') {
				while (stack[top]!=')') {
					prefix[j]=pop();
					j++;
				}
				pop();
			} 
			else {
				if (prcd(stack[top]) <= prcd(symbol)) {
					push(symbol);
				} 
			  	else {
					while(prcd(stack[top]) >= prcd(symbol)) {
						prefix[j]=pop();
						j++;
					}
					push(symbol);
				 }
			  } 
		   }
	}
	while (stack[top]!='#') 
	{
		prefix[j]=pop();
		j++;
	}
	prefix[j]='\0';
}

void reverseString(char array[30]) { // Reverse the string.
	int i,j;
	char temp[100];
	for (i=strlen(array)-1, j=0; i+1!=0; --i, ++j) {
		temp[j]=array[i];
	}
	temp[j]='\0';
	strcpy(array,temp);

}

char pop() { // Pop an element from the stack
	char a;
	a=stack[top];
	top--;
	return a;
}

void push(char symbol) { // Push an element into the stack.
	top++;
	stack[top]=symbol;
}

int prcd(char symbol) { // Return the priority of the operator
	switch(symbol) {
		case '+':
		case '-':
		        return 2;
		        break;
		case '*':
		case '/':
		        return 4;
		        break;
		case '$':
		case '^':
		        return 6;
		        break;
		case '#':
		        case '(':
		        case ')':
		        return 1;
		break;
	}
}

int isOperator(char symbol) {
	switch(symbol) {
		        case '+':
		        case '-':
		        case '*':
		        case '/':
		        case '^':
		        case '$':
		        case '&':
		        case '(':
		        case ')':
		        	return 1;
					break;
		default:
		        return 0;
	}
}