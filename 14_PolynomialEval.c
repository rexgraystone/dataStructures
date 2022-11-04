/*
    14. Write a program to evaluate a polynomial expression.
*/

#include <stdio.h>
#include <stdlib.h>

struct node { // Structure of a node
    int coef;
    int expo;
    struct node* next;
};

struct node* insertPoly(struct node* tHead, int c, int e); // Insert a node into the polynomial
struct node* append(struct node* tHead, int c, int e); // Append a node into the polynomial
struct node* polyAddition(struct node* p1tHead, struct node* p2tHead); // Add two polynomials
void display(struct node* tHead); // Display the polynomial

void main() {
    int a, b, n, i;
    struct node* p1head,* p2head,* p3head;
    p1head = p2head = NULL;
    printf("Enter the no of terms of polynomial 1:");
    scanf("%d", &n);
    printf("\nEnter the polynomial as required:");
    for(i = 0; i < n; i++) {
        printf("\nEnter the coefficient and exponent of the term %d with a space",i+1);
        scanf("%d%d", &a, &b);
        p1head = insertPoly(p1head, a, b); 
    }
    printf("\nEnter the no of terms of polynomial 2: ");
    scanf("%d", &n);
    printf("\nEnter the polynomial as required:");
    for(i = 0; i < n; i++) {
        printf("\nEnter the coefficient and exponent of the term %d: ",i+1);
        scanf("%d%d", &a, &b);
        p2head = insertPoly(p2head, a, b);
    }
    p3head = polyAddition(p1head, p2head);
    printf("\nThe polynomial 1 is: ");
    display(p1head);
    printf("\nThe polynomial 2 is: ");
    display(p2head);
    printf("\nThe sum of the two polynomials is..");
    display(p3head);
}

struct node* append(struct node* tHead,int c,int e) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> coef = c; // Assign the coefficient
    newNode -> expo = e; // Assign the exponent
    newNode -> next = NULL; // Assign the next pointer
    if(tHead == NULL) { // If the polynomial is empty
	    return newNode; 
    }
    struct node* last = tHead; 
    while(last -> next != NULL) { // Else traverse to the last node
        last = last -> next;
    }
    last -> next = newNode; // Append the node
    return tHead;
}

struct node* insertPoly(struct node* tHead,int c,int e)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> coef = c; // Assign the coefficient
    newNode -> expo = e; // Assign the exponent
    newNode -> next = NULL; // Assign the next pointer to NULL
    if(tHead == NULL) { // If the polynomial is empty
        return newNode;
    }
    struct node* prev, * curr; 
    prev = curr = tHead;
    while(curr != NULL && curr ->expo > e) { // Else traverse to the correct position
        prev = curr;
        curr = curr -> next;
    }
    if(curr == tHead) { // If the node is to be inserted at the beginning    
        newNode -> next = curr;
        return newNode;
    }
    else if(curr == NULL) { // If the node is to be inserted at the end      
        prev -> next = newNode;
        newNod -> next = NULL;
    }
    else { // If the node is to be inserted in the middle
        newNode -> next = curr;
        prev -> next = newNode;
    }
    return tHead;
}

struct node* polyAddition(struct node* p1tHead, struct node* p2tHead) { // Add two polynomials
    struct node* ans = NULL;
    struct node* t1, * t2;
    t1 = p1tHead;
    t2 = p2tHead;
    while(t1 != NULL && t2 != NULL) { // Traverse both the polynomials
        if(t1 -> expo > t2 -> expo) { // If the exponent of the first polynomial is greater than the second
            ans = append(ans, t1 -> coef, t1 -> expo);
            t1 = t1 -> next;
        }
        else if(t1->expo < t2->expo) { // If the exponent of the second polynomial is greater than the first
            ans = append(ans, t2 -> coef, t2 -> expo);
            t2 = t2 -> next;
        }
        else { // If the exponents of both polynomials are equal
            ans = append(ans, (t1 -> coef) + (t2 -> coef), t1 -> expo);
            t1 = t1 -> next;
            t2 = t2 -> next;
        }
    }
    while(t1 != NULL) { // If the first polynomial has more terms         
        ans = append(ans, t1 -> coef, t1 -> expo);
        t1 = t1 -> next;
    }
    while(t2 != NULL) { // If the second polynomial has more terms           
        ans = append(ans, t2 -> coef, t2 -> expo);
        t2 = t2 -> next;
    }
    return ans;
}

void display(struct node* tHead) { // Display the polynomial
    struct node* temp = tHead;
    if(temp == NULL) { // If the polynomial is empty
        printf("\nEmpty List"); // Display empty list
    }
    else {
        while(temp -> next != NULL) { // Else traverse the polynomial
            printf(" %dx^%d +", temp -> coef, temp -> expo);
            temp = temp -> next;
        }
       printf(" %dx^%d ", temp -> coef, temp -> expo);
    }
}