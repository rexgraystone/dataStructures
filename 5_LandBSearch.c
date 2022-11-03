/*
    5. Write a program to search an element in a 2D array using Linear Search and Binary Search algorithms.
*/

#include <stdio.h>

void bsort(int n, int* ptr)
{
    int i, j, t;
    for (i = 0; i < n; i++) 
   {
        for (j = i + 1; j < n; j++) 
	    {
            if (*(ptr + j) < *(ptr + i)) 
	        {
                t = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = t;
            }
        }
    }
}

int binarySearch(int arr[],int b,int l,int x)
{
    if(l>=b)
    {
        int m = (b + l)/2;  
	    if(arr[m]==x) 
            return m;        
        else if(arr[m]>x) 
            return binarySearch(arr,b,m-1,x); 
	    else 
            return binarySearch(arr,m+1,l,x);    
    }
    return -1;
}

int linearSearch(int a[], int n, int val) 
{  
    for (int i = 0; i < n; i++)  
    {  
        if (a[i] == val)  
        return i+1;  
    }  
    return -1;  
}  

int main()
{
    int i, n, arr[100];
    int ch, x, index;
    printf("Enter the Number of Elements:");
    scanf("%d", &n);
    printf("\nEnter Array unique Elements:");
    for(i = 0; i < n; i++)
    { 
	    scanf("%d", &arr[i]);        
    }
    printf("\nEnter the Element to be searched:");
    scanf("%d", &x);    
    printf("\n1.Linear Search\t2. binarySearchary Search\nMake your choice:");
    scanf("%d", &ch);  
    if(ch==1)
    {
	    index = linearSearch(arr, n, x);
    }
    else if(ch==2)
    {   
        bsort(n, arr);
        index=binarySearch(arr, 0, n-1, x);
    }
    if(index!=-1)
    {
	    printf("\n\nElement found at Index: %d",index);
    }
    else 
	{
	    printf("\nElement Not found in Array!");    
  	}  
    printf("\nArray Elements:");
    for (i = 0; i < n; i++)  
    {    
	    printf("%d ", arr[i]);
    }
    return 0;
}