#include<stdio.h>
#include<stdlib.h>

struct node
{
	char data;
	struct node *nptr;
	struct node *pptr;
};
struct node *hptr1 = NULL;
struct node *sptr1 = NULL;
struct node *hptr2 = NULL;
struct node *sptr2 = NULL;
void createlist()
{
	char c;
	printf("Enter any character or 0 to terminate\n");
	scanf(" %c",&c);
	
	while((int)c!=48)
	{
		printf("Enter character to be inserted\n");
		scanf(" %c",&c);
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp->data = c;
		temp->nptr = NULL;
		if(sptr1 == NULL)
		{
		temp->pptr = NULL;
		sptr1 = temp;
		hptr1 = temp;
	    }
	    
	else
	{
		sptr1->nptr = temp;
		temp->pptr = sptr1;
		sptr1 = temp;
	}
	printf("Enter any character or 0 to terminate\n");
	scanf(" %c",&c);
	}
	sptr1 = hptr1;
}
 
void reverselist()
 {
 	while((sptr1->nptr)!=NULL)
 	{
 		sptr1 = sptr1->nptr;
	 }
	
 	while(sptr1->pptr!=NULL)
 	{
 	 struct node *temp = (struct node*)malloc(sizeof(struct node));
	  temp->nptr = NULL;
	  temp->data = sptr1->data;
	  if(hptr2==NULL)
	  {
	  	temp->pptr = NULL;
	  	sptr2 = temp;
	  	hptr2 = temp;
		  }	
		  else
		  {
		  	temp->pptr = sptr2;
		  	sptr2->nptr = temp;
		  	sptr2 = temp;
		  }
		  sptr1 = sptr1->pptr;
	 }
struct node *temp = (struct node*)malloc(sizeof(struct node));
	  temp->nptr = NULL;
	  temp->data = sptr1->data;	 
	  temp->pptr = sptr2;
	  sptr2->nptr = temp;
		  	sptr1 = hptr1;
		  	sptr2 = hptr2;
 }

void Toprint()
{
	char x,y;
	printf("Given list\n");
	while(sptr1!= NULL)
	{
		x = sptr1->data;
		sptr1 = sptr1->nptr;
		printf("%c\n",x);
	}
	sptr1 = hptr1;
	printf("Reversed list\n");
	while(sptr2!=NULL)
	{
		y = sptr2->data;
		sptr2 = sptr2->nptr;
		printf("%c\n",y);
	}
	sptr2 = hptr2;

}

void palindrome()
{
	int flag = 0;
	while(sptr1!=NULL && sptr2!=NULL)
	{
		if(sptr1->data == sptr2->data)
		{
			flag = 1;
		}
		sptr1 = sptr1->nptr;
		sptr2 = sptr2->nptr;
	}
	sptr1 = hptr2;
	sptr2 = hptr2;
	if(flag==1)
	{
		printf("It is a palindrome\n");
	}
	else
	printf("Its not a palindrome\n");
}








int main()
{
	createlist();
	
	reverselist();
	Toprint();
	palindrome();
	

}
