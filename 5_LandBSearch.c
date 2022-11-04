/*
    5. Write a program to search an element in a 2D array using Linear Search and Binary Search algorithms.
*/

#include <stdio.h>

void bsort(int n, int* ptr) { // Bubble sort function
    int i, j, t;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (*(ptr + j) < *(ptr + i)) {
                t = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = t;
            }
        }
    }
}

int linearSearch(int a[], int n, int val) { // Linear search function
    for (int i = 0; i < n; i++) {  
        if (a[i] == val) { 
            return i+1; 
        } 
    }  
    return -1;  
}  

int binarySearch(int arr[],int b,int l,int x) { // Binary search function
    if(l>=b) {
        int m = (b + l)/2;  
	    if(arr[m]==x) { 
            return m;    
        }    
        else if(arr[m]>x) {
            return binarySearch(arr,b,m-1,x); 
        }
	    else {
            return binarySearch(arr,m+1,l,x); 
        }   
    }
    return -1;
}

int main() {
    int i, n, arr[100];
    int ch, x, index;
    printf("Enter the Number of Elements:"); // Input the number of elements
    scanf("%d", &n);
    printf("\nEnter Array unique Elements:"); // Input the elements
    for(i = 0; i < n; i++) { 
	    scanf("%d", &arr[i]);  
    }
    printf("\nEnter the Element to be searched:");
    scanf("%d", &x);    
    printf("\n1. Linear Search\t2. Binary Search\nMake your choice:"); // Input the choice
    scanf("%d", &ch);  
    if(ch==1) {
        index = linearSearch(arr, n, x); // Call the linear search function
        if(index == -1) { // If the element is not found
            printf("\nElement not found"); // Print element not found
        }
        else { // Else print the index of the element
            printf("\nElement found at position %d", index);
        }
    }
    else if(ch==2) {   
        bsort(n, arr);
        index = binarySearch(arr, 0, n-1, x); // Call the binary search function
        if(index == -1) { // If the element is not found
            printf("\nElement not found"); // Print element not found
        }
        else { // Else print the index of the element
            printf("\nElement found at position %d", index+1);
        }
    }
    printf("\nArray Elements:");
    for (i = 0; i < n; i++) { // Print the array
	    printf("%d ", arr[i]);
    }
    return 0;
}