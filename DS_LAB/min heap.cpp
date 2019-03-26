#include<stdio.h>
#include<stdlib.h>

#define asize 100

struct heap
{
	int a[asize];
	int hsize;
}H;

void check(int i)
{
	int m;
	int temp;
	if(2*i > H.hsize)
	{
	return;
	}
	
	else if((2*i+1) <= H.hsize)
	{
		m = (H.a[2*i]< H.a[2*i+1])?(2*i):(2*i+1);
		
		if(H.a[i]>H.a[m])
		{		
		temp = H.a[m];
		H.a[m] = H.a[i];
		H.a[i] = temp;
	   }
	  check(m);	
	}	
	
	else if(H.a[2*i]<H.a[i])
	{
		temp = H.a[2*i];
		H.a[2*i] = H.a[i];
		H.a[i] = temp;
	}
	
}

void insert(int val)
{
	
	H.hsize++;
	H.a[H.hsize] = val;
	int i = H.hsize;
	int temp;
	
	while(i>1 && H.a[i]<H.a[i/2])
	{
		temp = H.a[i];
		H.a[i]= H.a[i/2];
		H.a[i/2]=temp;
		i = i/2;
	}
	
}

void deletion()
{
	H.a[1] = H.a[H.hsize];
	--H.hsize;
	int i = 1;
	
	check(1);	
}
	

	
void Print()
{
	int i;
	for(i=1 ; i<=H.hsize;++i)
	printf("%d ",H.a[i]);
}


int main()
{
	int i,k;
	printf("Enter 1 for insertion\n 2 for deletion\n 3 for printing and\n -1 to terminate\n");
	scanf("%d",&i);
	
	while(i!=-1)
	{
		switch(i)
		{
			case 1:
				printf("Enter key value to be inserted\n");
				scanf("%d",&k);
				insert(k);
				break;
			case 2:
				deletion();
				break;
			case 3:
				Print();
				break;
			default:
				printf("Wrong Input\n");
				
		}
		printf("Enter 1 for insertion\n 2 for deletion\n 3 for printing and \n -1 to terminate\n");
		scanf("%d",&i);
		
	}
	
	
}

