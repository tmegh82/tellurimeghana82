#include<stdio.h>
#include<stdlib.h>

struct node
{
	int coeff;
	int powe;
	struct node *nptr ; 
};
struct node *p1 = NULL;
struct node *p2 = NULL;
struct node *sum= NULL;

struct node *createnode(struct node *p)
{
	struct node *s = NULL;
	int c,i;
	while(i!=-1)
	{
		
		printf("Enter coefficient and power\n");
		scanf("%d %d",&c ,&i);
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		if(p==NULL)
		{
			temp->coeff = c;
			temp->powe = i;
			temp->nptr = NULL;
		    p = temp; 
		    s = temp;
		}
		else
		{
			temp->coeff = c;
			temp->powe = i;
			temp->nptr = NULL;
			s->nptr = temp;
			s= temp;
			
		}
	printf("Enter any value and -1 to terminate\n");
	scanf("%d",&i);
	
}
return(p);
}

void show(struct node *p)
{
	int x,y;
	if(p== NULL)
	{
		printf("Nothing to print\n");
	}
else
{
	while((p->nptr)!=NULL)
	{
	x = p->coeff;
	y = p->powe;
	printf("Coefficient %d        %d power\n",x , y);
	p = p->nptr;
	
}
x = p->coeff;
	y = p->powe;
	printf("Coefficient %d        %d power\n",x , y);

}
}

struct node *add(struct node *z1,struct node *z2, struct node*z)
{
	struct node *s = z;
   while(z1!=NULL && z2!=NULL)
   {
   	struct node *temp = (struct node*)malloc(sizeof(struct node));
   	if(z1->powe==z2->powe )
	{
		temp->coeff = z1->coeff + z2->coeff;
		temp->powe = z1->powe;
		z1 = z1->nptr;
	z2 = z2->nptr;
	}
	else if(z1->powe > z2->powe)
	{
		temp->coeff  = z1->coeff;
		temp->powe = z1->powe;
		z1 = z1->nptr;
	}
	else
	{
		temp->coeff = z2->coeff;
		temp->powe = z2->powe;
			z2 = z2->nptr;
	}  
	
	temp->nptr = NULL;
	if(z==NULL)
	{
	s = temp;
	z = temp;
   }
	else
   {
	s->nptr = temp;
	s = temp;
   }
	   }	
	if(z1!=NULL)
	{
		while(z1!=NULL)
		{
		
       			struct node *temp = (struct node*)malloc(sizeof(struct node));
       				temp->coeff = z1->coeff;
       				temp->powe = z1->powe;
       				temp->nptr = NULL;
       				s->nptr = temp;
					   s = temp;
					   z1 = z1->nptr;
	}
	   }   
	   else 
	   {
	   	while(z2!=NULL)
	   	{
	   	struct node *temp = (struct node*)malloc(sizeof(struct node));
       				temp->coeff = z2->coeff;
       				temp->powe = z2->powe;
       				temp->nptr = NULL;
       				s->nptr = temp;
					   s = temp;
					   z2 = z2->nptr;
	   }
}
return(z);
}



struct node *prod(struct node *z1, struct node *z2 , struct node *z)
{	
struct node *m1 = z1;
struct node *m2 =z2;
struct node *m = NULL;
struct node *s = NULL;
 	while(z2!=NULL)
 	{
 		struct node *temp = (struct node*)malloc(sizeof(struct node));
 		temp->coeff = z1->coeff * z2->coeff;
 		temp->powe = z1->powe + z2->powe;
 		temp->nptr = NULL;
 		if(z==NULL)
 		{
		 z= temp;
 		s= temp;
 		z2 = z2->nptr;
 	}
 		else
 		{
 	       s->nptr = temp;
 	    	s = temp;
 			z2 = z2->nptr;
 	}
 }
 z2 = m2;
 	z1 = z1->nptr;
 	s = NULL;
 	while(z2!=NULL)
 	{
 		struct node *temp = (struct node*)malloc(sizeof(struct node));
 		temp->coeff = z1->coeff * z2->coeff;
 		temp->powe = z1->powe + z2->powe;
 		temp->nptr = NULL;
 		if(m==NULL)
 		{
		 m= temp;
 		s= temp;
 		z2 = z2->nptr;
 	}
 		else
 		{
 	       s->nptr = temp;
 	    	s = temp;
 			z2 = z2->nptr;
 	}
 }

 struct node *a = NULL;
 a = add(m,z,a);
 z = a;
 a = NULL;
  z1 = z1->nptr;
  z2 = m2;

 while(z1!=NULL)
 {
 	s = NULL;
 	m  = NULL;
 while(z2!=NULL)
 	{
 		struct node *temp = (struct node*)malloc(sizeof(struct node));
 		temp->coeff = z1->coeff * z2->coeff;
 		temp->powe = z1->powe + z2->powe;
 		temp->nptr = NULL;
 		if(m==NULL)
 		{
		 m= temp;
 		s= temp;
 		z2 = z2->nptr;
 	}
 		else
 		{
 	       s->nptr = temp;
 	    	s = temp;
 			z2 = z2->nptr;
 	}	
 }
  a = add(m,z,a);
  printf("Hello\n");
  z = a;
  a = NULL;
 z1 = z1->nptr;
 z2 = m2;

}
return(z);
 }
 


int main()
{
	struct node *p1 = NULL;
     struct node *p2 = NULL;
	struct node *sum= NULL;
	struct node *mul= NULL;
	printf("Enter 1st polynomial\n");
	p1 = createnode(p1);
	
		printf("Enter 2st polynomial\n");
			p2 = createnode(p2);
			printf("To print 1st polynomial\n");
			show(p1);
			printf("Too print 2nd polynomial\nn");
			show(p2);
			
		sum = add(p1,p2,sum);
		printf("To print sum of polynomials\n");
		show(sum);
		
		mul = prod(p1,p2,mul);
		show(mul);
		
	return(0);		
}
