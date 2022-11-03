/*
    Write a program to find rthe sum of digits of a number and reverse the number.
*/

#include <stdio.h>

int sod(int n) 
{
    if(n==0) 
    {
        return 0;
    } 
    else 
    {
        printf("%d", n%10);
        return (n%10)+sod(n/10);
    }
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("\n%d", sod(n));
    return 0;
}