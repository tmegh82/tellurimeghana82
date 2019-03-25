#include<stdio.h>
#include<stdlib.h>
struct node
{
	int pow;
	int coeff;
	struct node *nptr = NULL;
};

void createnode(int c , int p , struct node **temp)
{
	struct node *z; 
	z = *temp;
	
	struct node *r;
	r = (struct node*)malloc(sizeeof(struct node));
	if(z==NULL)
	{
	r->coeff = c;
	r->pow = p;
	*temp = r;
	r->nptr = (struct node*)malloc(sizeeof(struct node));
	r = r->nptr;
	r->nptr = NULL;
}
else
{
	r->coeff = c;
	r->pow = p;
	r->nptr = (struct node*)malloc(sizeeof(struct node));
	r = r->nptr;
	r->nptr = NULL;
}
}

void add(struct node *p1, struct node *p2,struct node *p)
{
	while(p1->nptr == NULL && p2->nptr == NULL)
	{
	
	if(p1->pow == p2->pow)
	{
	p->pow = p1.pow;
	p->coeff = p1->coeff + p2->coeff;
 }
	else if(p1->pow > p2.pow)
	{
		p->pow = p1->pow;
		p->coeff = p1->coeff;
	}
	else
	{
	p->pow = p2->pow;
	p->coeff = p2->coeff;
}
p1 = p1->nptr;
p2 = p2->nptr;
p->nptr = (struct node*)malloc(sizeeof(struct node));
p = p->nptr;
p->nptr = NULL;
}
}

void show(struct poly *s)
{
	while(s->nptr!=NULL)
	{
		printf("coefficient %d      power %d\n",s->coeff, s->pow);
		s = s->nptr;
	}
}

int main()
{
	struct node *poly1 = NULL;
		struct node *poly2 = NULL;
			struct node *poly = NULL;
	
      createnode(2,0,&poly1);
      createnode(5,1,&poly2);
     createnode(5,0,&poly2);
      show(poly1);
show(poly2);
 struct node *poly = (struct node*)malloc(sizeof(struct node));
     
    // Function add two polynomial numbers
   add(poly1, poly2, poly);
     
    // Display resultant List
    printf("\nAdded polynomial: ");
    show(poly);
}

