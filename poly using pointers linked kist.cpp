#include<stdio.h>
#include<stdlib.h>
#define maxdeg 50
struct poly
{
	int coeff[maxdeg];
	int highdeg;
};
struct poly *p1;
struct poly *p2;
struct poly *sum;
struct poly *mul;

struct poly readpoly(int deg,struct poly **p)
{
	struct poly *r = *p;
	int i,x;
		r->highdeg = deg;
	for(i=deg;i>=0;i--)
	{
		printf("Enter coeffecient of %d \n",i);
		scanf("%d",&x);
		r->coeff[i] =  x;
	}

}

void add()
{
	int i;
	if(p1->highdeg >= p2->highdeg)
	sum->highdeg = p1->highdeg;
	else
	sum->highdeg = p2->highdeg;
	
	for(i=0;i<=sum->highdeg;++i)
	{
    	sum->coeff[i] = p1->coeff[i] + p2->coeff[i];
	  
	   
	}
	
}

void multi()
{
	int i,j;
	mul->highdeg = p1->highdeg + p2->highdeg;
	
	if(mul->highdeg>maxdeg)
	printf("Error\n");
	else 
	for(i=0;i<=p1->highdeg;++i)
	for(j=0;j<=p2->highdeg;++j)
	{
	mul->coeff[i+j] = mul->coeff[i+j] + (p1->coeff[i]*p2->coeff[j]);

    }
	
}

void ToprintAddResult()
{
	int i;
	printf("Addition  of two polynomials is\n");
	for(i=sum->highdeg;i>=0;i--)
	printf("Coefficient  %d          Degree   %d\n",sum->coeff[i],i);
}

void ToprintMultiResult()
{
	int i;
printf("Multiplication   of two polynomials is\n");
	for(i=mul->highdeg;i>=0;i--)
	printf("Coefficient  %d          Degree   %d\n",mul->coeff[i],i);
}

void Toprint()
{
	int i;
	printf("1st polynomial is\n");
	for(i=p1->highdeg;i>=0;i--)
	printf("Coefficient  %d      Degree  %d\n",p1->coeff[i], i);
	printf("2nd polynomial is\n");
	for(i=p2->highdeg;i>=0;i--)
	printf("Coefficient  %d      Degree  %d\n",p2->coeff[i], i);
}


int main()
{
	int deg,i;
	
	printf("Enter highest deg of 1st polyomial\n");
	scanf("%d",&deg);
     readpoly(deg,&p1);
	
		printf("Enter highest deg of 2nd polyomial\n");
	scanf("%d",&deg);
    readpoly(deg,&p2);
	
	printf("Enter 1 to add \n 2 to multiply \n 3 to print the result of addition\n 4 to print result of multiplication\n 5 to print the given polynomials\n-1 to terminate\n");
    scanf("%d",&i);
    
    while(i!=-1)
    {
    	switch(i)
    	{
    		case 1:
    			add();
    			break;
    		case 2:
    			multi();
    			break;
    		case 3:
    			ToprintAddResult();
    			break;
    		case 4:
    			ToprintMultiResult();
    			break;
    		case 5:
    			Toprint();
    			break;
    		default:
    			printf("Wrong Input\n");
    			
    }
    printf("Enter 1 to add \n 2 to multiply \n 3 to print the result of addition\n 4 to print result of multiplication\n 5 to print the given polynomials\n-1 to terminate\n");
    scanf("%d",&i);
    
	}
}
    
   	
	

