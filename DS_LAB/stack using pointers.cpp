#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *nptr;
};

struct node *tptr = NULL;
struct node *sptr = NULL;
void push(int x);
void pop();
void Toprint();

int main()
{
	push(5);
	push(6);
	Toprint();
	
}

void push(int x)
{
	struct node *temp = malloc(sizeof(struct node));
	if(temp==NULL)
	printf("Memory Full\n");
	else
	{
	 temp->data = x;
     temp->nptr  = sptr;
     sptr = temp;
    }
}

void pop()
{
	int x;
	if(sptr==NULL)
	printf("Nothing to pop\n");
	else
	{
		x = sptr->data;
		 sptr = sptr->nptr;
	}

	printf("Element to be deleted is %d\n",x);
}

void Toprint()

{
	tptr = sptr;
	if(sptr == NULL)
	printf("Nothing to print\n");
	else
	{
		while(tptr!=NULL)
		{
			int x = tptr->data;
			printf("%d\n",x);  
			tptr = tptr->nptr ;
		}
	}
	
}
