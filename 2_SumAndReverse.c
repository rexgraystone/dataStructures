/*
    2. Write a program to find the sum of digits of a number and reverse the number.
*/

#include <stdio.h>

int sumOfDigits(int n) { // sum of digits
    if(n==0) {
        return 0;
    } 
    else { 
        printf("%d", n%10);
        return (n%10)+sumOfDigits(n/10);
    }
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("\n%d", sumOfDigits(n));
    return 0;
}