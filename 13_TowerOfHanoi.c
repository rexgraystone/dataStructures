/*
    13. Write a program to solve Tower of Hanoi problem using recursion.
*/

#include <stdio.h>

int c=0;

void tower(int n, char beg, char mid, char end) { // Tower of Hanoi
    printf("%d. ", ++c); // Print the step number
    if(n==1) {
        printf("Move Disk 1 from Peg %c to Peg %c\n", beg, end);
        return;
    }  
    tower(n-1, beg, end, mid);
    printf("Move disk %d from Peg %c to Peg %c\n", n, beg, end);
    tower(n-1, mid, beg, end);
}

int main() {
    int n;
    printf("\nEnter number of disks in A: ");
    scanf("%d", &n); 
    printf("Follow these steps to Achieve the target position: \n");
    tower(n, 'A', 'B', 'C');
    return 0;
}