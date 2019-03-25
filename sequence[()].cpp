#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
	char b[50];
	int fend;
	int sptr;
	int counta;
	int countb;
	
};
struct stack push(struct stack s1 , char val);
struct stack pop(struct stack s1, char val);

int main()
{
	struct stack s;
	s.fend = -1;
	s.counta = 0;
	s.countb= 0;
	int n,i;
	char x;
	printf("Enter size of the array");
	scanf("%d",&n);
	char a[n];
	
	printf("Enter the string using characters [,],(,)\n");
	scanf("%s",&a);
	
	int len = strlen(a);
	
	for(i=0;i<n;++i)
	{
	
	if(a[i]=='[' || a[i]=='(')
	{	
		x = a[i];
		s= push(s,x);
	    }
	else if(a[i]==']')
	{
	    x = '[';
		s = pop(s,x);
	
	}
	else if(a[i]==')')
	{
	    x = '(';
		s = pop(s,x);
	
	}
	else
	printf("Wrong Input\n");
}
if(s.counta==s.countb)
printf("Matched\n");
else
printf("Unmatched\n");
}
struct stack push(struct stack s1,char val)
{
	if(s1.fend==49)
	printf("Mmeory full\n");
	else
	{
	s1.fend = s1.fend + 1;
	s1.sptr = s1.sptr + 1;
	s1.b[s1.fend] = val;
	s1.counta = s1.counta + 1;
   }
   return(s1);
}

struct stack pop(struct stack s1,char val)
{
	char p;
	if(s1.fend == -1)
	printf("Nthing to delete\n");
	else
	{
		p  = s1.b[s1.fend];
		if(p ==val)
		{
			s1.fend = s1.fend - 1;
			s1.sptr = s1.sptr - 1;
			s1.countb = s1.countb + 1;
		
		}
		else
		{
		printf("Error and unmatched");
		exit(1);
	}
	
	}
		return(s1);
		
}








