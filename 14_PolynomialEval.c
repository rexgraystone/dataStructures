/*
    14. Write a program to evaluate a polynomial expression.
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coef;
    int expo;
    struct node* next;
};

struct node* insertPoly(struct node* tHead,int c,int e);
struct node* append(struct node* tHead,int c,int e);
struct node* polyAddition(struct node* p1tHead,struct node* p2tHead);
void display(struct node* tHead);

void main()
{
    int a, b, n, i;
    struct node* p1head,* p2head,* p3head;
    p1head=p2head=NULL;
    printf("Enter the no of terms of polynomial 1:");
    scanf("%d", &n);
    printf("\nEnter the polynomial as required:");
    for(i=0;i<n;i++) 
    {
        printf("\nEnter the coefficient and exponent of the term %d with a space",i+1);
        scanf("%d%d", &a, &b);
        p1head=insertPoly(p1head, a, b); 
    }
    printf("\nEnter the no of terms of polynomial 2: ");
    scanf("%d",&n);
    printf("\nEnter the polynomial as required:");
    for(i=0;i<n;i++)
    {
        printf("\nEnter the coefficient and exponent of the term %d: ",i+1);
        scanf("%d%d", &a, &b);
        p2head=insertPoly(p2head, a, b);
    }
    p3head=polyAddition(p1head, p2head);
    printf("\nThe polynomial 1 is: ");
    display(p1head);
    printf("\nThe polynomial 2 is: ");
    display(p2head);
    printf("\nThe sum of the two polynomials is..");
    display(p3head);
}

struct node* append(struct node* tHead,int c,int e)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->coef=c;
    newNode->expo=e;
    newNode->next=NULL;
    if(tHead==NULL) 
	    return newNode; 
    struct node* last = tHead; 
    while(last->next!=NULL)
        last=last->next;
    last->next=newNode; 
    return tHead;
}

struct node* insertPoly(struct node* tHead,int c,int e)
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->coef=c;
    newNode->expo=e;
    newNode->next=NULL; 
    if(tHead==NULL)    
	    return newNode;
    struct node* prev,* curr;
    prev=curr=tHead;
    while(curr!=NULL && curr->expo>e)
    {
        prev=curr;
        curr=curr->next;
    }
    if(curr==tHead)
    {            
        newNode->next=curr;
        return newNode;
    }
    else if(curr==NULL)
    {        
        prev->next=newNode;
        newNode->next=NULL;
    }
    else
    {
        newNode->next=curr;
        prev->next=newNode;
    }
    return tHead;
}

struct node* polyAddition(struct node* p1tHead, struct node* p2tHead)
{
    struct node* ans=NULL;
    struct node* t1, * t2;
    t1=p1tHead;
    t2=p2tHead;
    while(t1!=NULL && t2!=NULL)
	{
        if(t1->expo > t2->expo)
	    {
            ans=append(ans,t1->coef,t1->expo);
            t1=t1->next;
        }
        else if(t1->expo < t2->expo)
	    {
            ans=append(ans,t2->coef,t2->expo);
            t2=t2->next;
        }
        else
	    {
            ans=append(ans,(t1->coef)+(t2->coef),t1->expo);
            t1=t1->next;
            t2=t2->next;
        }
    }
    while(t1!=NULL)
    {            
        ans=append(ans,t1->coef,t1->expo);
        t1=t1->next;
    }
    while(t2!=NULL)
    {            
        ans=append(ans,t2->coef,t2->expo);
        t2=t2->next;
    }
    return ans;
}

void display(struct node* tHead)
{
    struct node* temp=tHead;
    if(temp==NULL)
    {
        printf("\nEmpty List");
    }
    else
    {
        while(temp->next!=NULL)
	    {
            printf(" %dx^%d +", temp->coef, temp->expo);
            temp=temp->next;
        }
       printf(" %dx^%d ", temp->coef, temp->expo);
    }
}