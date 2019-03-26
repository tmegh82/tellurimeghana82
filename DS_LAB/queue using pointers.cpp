#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *nptr; 
};
struct node *fptr = NULL;
	struct node *rptr = NULL;
	struct node *sptr = NULL;
void enqueue (int x);
void dequeue ();
void Toprint();

int main()
{
	
	
	enqueue(5);
	enqueue(6);
	enqueue(7);
	Toprint();
	dequeue();
	Toprint();
	
	
}

void enqueue (int x)
{
	struct node *temp = malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("Memory Full");
	}
	else if(fptr==NULL && rptr==NULL)
	{
		temp->nptr = NULL;
		fptr = temp;
		rptr  = temp;
		sptr = fptr;
	}
	else
	{
		temp->nptr = NULL;
		rptr->nptr = temp;
		
	}
	temp->data = x;
}

void dequeue ()
{
	int x;
	if(fptr==NULL)
	{
		printf("No element to delete");
	
	}
	else
	{
       x = fptr->data;
       fptr = fptr->nptr;
       sptr = fptr;
	}
	printf("Delted element is %d",x);
}
 void Toprint()
 {
 	if(fptr==NULL)
 	printf("Nothing to print");
 	else
 	printf("Elements are");
 	while(sptr!=NULL)
 	{   
 		int x = sptr->data;
 		sptr = sptr->nptr;
 		printf("%d",x);
	 }
 }













