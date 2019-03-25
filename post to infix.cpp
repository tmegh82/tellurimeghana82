#include<stdio.h>
#include<ctype.h>
#define SIZE 100
struct stack
{
	int top;
	char b[SIZE];
};
struct stack s;
	void push();
	void postfix(char a[]);
	int pop();
	
int main()
{
	char a[SIZE];
	int x,i;  
	s.top = -1;

	printf("Enter characters into array and ')' to end \n");
	for(i=0;i<SIZE;++i)
	{
		scanf("%c",&a[i]);
		if(a[i]== ')');
		break;
	}
    postfix(a);
	
}


void push(int y)
{
	if(s.top==SIZE)
	printf("Memory is full\n");
	else 
	{
		s.top = s.top + 1;
		s.b[s.top] = y;
		printf("Inserted element is %d\n",s.b[s.top]);
	}
}


int pop()
{
	int x;
	if(s.top == -1)
	printf("Nothing to pop\n");
	else
	{
		x = s.b[s.top];
		s.top = s.top - 1;
		printf("Deleted element is %d\n",x);
		return(x);
	}
}

void postfix(char a[])
{
	int i,A,B,z;
	float val;
	for(i=0;a[i]!=')';++i)
	{
	if(isdigit(a[i]))
	{
		z = a[i]-'0';
	  push(z);
	}
	
	else if(a[i]=='/' || a[i]== '+' || a[i]=='-'||a[i]=='*')
	{
		A = pop();
			B = pop();
		switch(a[i])
		{
		case '+':
			val = A+B;
			break;
	    case '-':
	    	val = B-A;
	    	break;
	    case '*':
		val = A*B;
		break;
		
		case '/':
			val = (float)B/A;
			break;
		default:
			printf("Wrong Input/n");
		}
		push(val);

}
}

printf("Value of the expression is %f\n",val);
}

