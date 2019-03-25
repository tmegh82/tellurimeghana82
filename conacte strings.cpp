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

struct node *createlist(struct node *p)
{
	char c;
	printf("Enter any character or 0 to terminate\n");
	scanf(" %c",&c);
	struct node *hptr = NULL;
    struct node *sptr = NULL;
	while((int)c!=48)
	{
		printf("Enter character to be inserted\n");
		scanf(" %c",&c);
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp->data = c;
		temp->nptr = NULL;
		if(sptr == NULL)
		{
		temp->pptr = NULL;
		sptr = temp;
		hptr = temp;
		p = hptr;
	}
	else
	{
		sptr->nptr = temp;
		temp->pptr = sptr1;
		sptr = temp;
	}
	printf("Enter any character or 0 to terminate\n");
	scanf(" %c",&c);
	}
	sptr = hptr;
	return(p);
}

struct node *concates(struct node *p1, struct node *p2)
{
	struct node *sptr = NULL;
	sptr = p1;
	while(sptr->nptr!=NULL)
	{
		sptr = sptr->nptr;
	}
	sptr->nptr = p2;
	return(p1);
}

void show(struct node *p1, struct node *p2)
{
	char x;
	printf("1st string\n");
	while(p1->nptr!=NULL)
	{
		x = p1->data; 
		p1= p1->nptr;
		printf("%c\n",x);
	}
	x = p1->data;
	printf("%c\n",x);
	
	printf("2nd string\n");
	while(p2->nptr!=NULL)
	{
		x = p2->data; 
		p2 = p2->nptr;
		printf("%c\n",x);
	}
	x = p2->data;
	printf("%c\n",x);
}

void showresult(struct node *p)
{
	char x;
	printf("Concated string is\n");
	while(p->nptr!=NULL)
	{
	 x = p->data;
	 p = p->nptr;
	 printf("%c\n",x);	
	}
	x = p->data;
	printf("%c\n",x);
}


int main()
{
	struct node *s1 = NULL;
	struct node *s2 = NULL;
	struct node *s3 = NULL;
	printf("Enter 1st string\n");
	s1 = createlist(s1);
	
	printf("Enter 2nd string\n");	
    s2 = createlist(s2);
    s3 = concates(s1,s2);
    
    show(s1,s2);
    showresult(s3);
}
