#include<stdio.h>

struct stack
	{
		int a[5];
		int top;
	};
	

	struct stack push(struct stack s1,int b);
	struct stack pop(struct stack s1);	
	void Toprint(struct stack s1);
int main()
{ 
   int i,j ,k,value;
   struct stack s;
		s.top = -1;
	printf("Enter any value and -1 to terminate\n");
	
	scanf("%d",&i);
	while(i!=-1)
	{
		printf("Enter 1 for push , 2 for pop ,3 to print\n");
		scanf("%d",&j);
		
		if(j==1)
		{
			printf("Enter value you want to add\n");
			scanf("%d",&value);
		s = push(s,value);	
		}
		else if(j==2)
		s = pop(s);
		else
		Toprint(s);
		
		printf("Enter any value and -1 to terminate\n");
		scanf("%d",&i);
	}
}
	struct stack push(struct stack s1,int b)
	{
	    int m =b;
		if(s1.top==4)
		printf("Memory full\n");
		else
		{
			s1.top = s1.top + 1;
			s1.a[s1.top] = m;
		}
		return(s1);
	}
		struct stack pop(struct stack s1)
	{
	    if(s1.top==-1)
	    printf("No element to pop\n");
	    else
	    {
		s1.a[s1.top] = NULL;
		s1.top = s1.top - 1;
	    }
		return(s1);
	}
		void Toprint(struct stack s1)
	{
		int k ;
		for(k=0;k<=s1.top;++k)
		printf("%d",s1.a[k]);
	}



	
