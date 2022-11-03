/*
    10. Write a program to evaluate postfix expressions.
*/

#include <stdio.h>
#include<ctype.h>
#include<math.h>

#define MAX 20

int stack[20], top=-1;

void isempty()
{
    if(top==-1)
        printf("STACK UNDERFLOW");
}

void isfull()
{
    if(top==MAX)
        printf("STACK OVERFLOW");
}

void push(int x)
{
    if(top==MAX)
        isfull();
    else
        stack[++top]=x;
}

int pop()
{
    if(top==-1)
        isempty();
    else
        return stack[top--];
}

int posteval(char exp[])
{
    char *e;
    int num, n1, n2, tn;
    e=exp;
    while(*e!='\0')
    {
        if(isdigit(*e))
        {
            num=*e-48;
            push(num);
        }
        else
        {
            n1=pop();
            n2=pop();
            switch(*e)
            {
                case '+':
                        tn=n1+n2;
                        break;
                case '-':
                        tn=n1-n2;
                        break;
                case '*':
                        tn=n1*n2;
                        break;
                case '/':
                        tn=n1/n2;
                        break;
                case '^':
                        tn=pow(n1, n2);
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

int main()
{   
    int ch=1;
    char exp[MAX];  
    printf("Enter the expression: ");
    scanf("%s", exp);
    printf("\nThe Value of entered postfix %s expression is: %d\n", exp, posteval(exp));
    return 0;
}