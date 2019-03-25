#include<stdio.h>

int top = -1;
int n,i,j,k,value;
int main()
{   int push(int);
    int pop();
    void Toprint();
   

   	printf("Enter the size of the array");
	scanf("%d",&n);
	
	int a[n];
	printf("Enter any value and -1 to terminate");
	
	scanf("%d",&i);
	while(i!=-1)
	{
		printf("Enter 1 for push , 2 for pop ,3 to print");
		scanf("%d",&j);
		
		if(j==1)
		{
			printf("Enter value you want to add");
			scanf("%d",&value);
			push(value);	
		}
		else if(j==2)
		pop();
		else
		Toprint();
		
		printf("Enter any value and -1 to terminate");
		scanf("%d",&i);
	}
	
	int push(int b)
	{
	    int m =b;
		if(top==n)
		printf("Memory full");
		else
		{
			top = top + 1;
			a[top] = m;
		}
	}
		
	
	
	int pop()
	{
		a[top] = NULL;
		top = top - 1;
	}
	void Toprint()
	{
		for(k=0;k<=top;++k)
		printf("%d",a[top]);
	}
	
}

