/*
    1. Write a program to calculate addition, subtraction, multiplication and division of two numbers.
*/

#include <stdio.h>

int add(int a, int b) { // Function to add two numbers
    return a+b;
}

int subtract(int a, int b) { // Function to subtract two numbers
    return a-b;
}

int multiply(int a, int b) { // Function to multiply two numbers
    return a*b;
}

float divide(int a, int b) { // Function to divide two numbers
    if (b==0) {
        return -99999; // Return -99999 if denominator is 0
    }
    else 
        return a/b;
}

int main() {
    int ch,a,b, opt;
    do { // Do-while loop to repeat the program
        printf("0: Exit the program
                \n1: Add two integers
                \n2: Subtract two integers
                \n3: Multiply two integers
                \n4: Divide two integers
                \nYour choice is: "); // Menu
        scanf("%d", &ch);
        printf("Enter num1 and num2 with a space in between: ");
        scanf("%d%d", &a, &b);
        switch(ch) {
            case 0:
                break;
            case 1:
                printf("The sum of %d and %d is: %d",a,b,add(a,b));
                break;
            case 2:
                printf("%d subtracted from %d is: %d",a,b,subtract(a,b));
                break;
            case 3:
                printf("The product of %d and %d is: %d",a,b,multiply(a,b));
                break;
            case 4:
                printf("%d divided by %d is (Math error prints -99999): %f",a,b,divide(a,b));
                break;
            default:
                printf("Invalid choice.\n");
            }
        printf("\n\n");
        printf("Do you wish to continue? 1. Yes, 2. No\n");
        scanf("%d", &opt);
    }
    while(opt == 1); // Loop until user enters 2
    return 0;
}