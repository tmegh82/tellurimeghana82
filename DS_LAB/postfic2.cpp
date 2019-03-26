#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct queue
{
	char a[50];
	int top;
};
struct queue s;
char pop();
void  push(char ch);

int main()
{     
	s.top = -1;
    int n,i,count = -1; 
    char d[50];
    char b[50];
	char x;
    printf("Enter characters, symbols as a string into array \n");
    scanf("%s",&b);
    int len = strlen(b);
    
    for(i=0;i<len;i++)
    {
    if(isdigit(b[i]))
     {
     	++count;
     	d[count] = b[i];
	 }
	else
	{
		switch(b[i])
		{
	case 'h':
		while(s.top!=-1)
		{
		x = pop();	
		++count;
		d[count] = x;
	}
       	break;
	
	 case '(':
        push(b[i]);
        break;
        
    case')':
         while(s.a[s.top]!='(')
        {
        x =	pop();
        ++count;
        d[count] = x;
		}
		x = pop();	
    	++count;
    	d[count] = x;
		break;
		
		case '*':
			
			if(s.top==-1)
			push(b[i]);
			else if(s.a[s.top]=='+'||'-'||'(')
			 push(b[i]);
			else
			{
		    x = pop();
		    ++count;
		    d[count] = x;
			push(b[i]);
		    }
		    break;
		
	    case '/':
			if(s.top==-1)
		      push(b[i]);
			else if(s.a[s.top]!='/')
			 push(b[i]);
			else
			{
			x = pop();
			++count;
			d[count]= x;
			 push(b[i]);
		    }
		    break;
		   case '-':  
	    case '+':
          if(s.top==-1)
	         push(b[i]);
       else	
        while(s.top!=-1)
		   	{
		   x=pop();
		   ++count;
		   d[count] = x;   
	    }
	    push(b[i]);
	        break;
	   
	    
	default:
		printf("Wrong Input\n");
	}
    
}

}
for(i=0;i<=count;++i)
printf("%c",d[i]);
}


void push( char ch)
{
	if(s.top==49)
	printf("Stack Full\n");
	else
     	{
	s.top = s.top + 1;
	s.a[s.top] = ch;
      }
}


char pop()
{
	char ch;
	   if(s.top==-1)
	   printf("No element to pop\n");
       else
       {
       	ch = s.a[s.top];
       	s.top = s.top - 1;
	   }
	  
	   return(ch);
}







