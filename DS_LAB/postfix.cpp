#include<stdio.h>  
#include<string.h>

struct queue
{
	char a[50];
	int rend;
    };
struct queue pop(struct queue s);
struct queue push(struct queue s, char ch);

int main()
{
	struct queue s1;
	s1.rend = -1;
	printf("Enter length of the array less than 50 \n");
    int n,i,j,k = 0,m;
    scanf("%d",&n);
    
    char b[n];
    printf("Enter characters, symbols as a string into array and h at the end of input \n");
    for(i=0;i<n;++i)
    scanf("%c",&b[i] );
    for(i=0;i<n;i++)
        printf("%c ",b[i]);
    //int len = sizeof(b);
    //printf("%d",len);
    for(i=0;i<n;++i)
    {
    //	if(b[i]=='h')
    //	   printf("hi");
	if(b[i]=='h')
     	{
     		//printf("Hello\n");
		while(s1.rend!=-1)
		s1 = pop(s1);
			
       	}
	
	 else if (b[i]=='(')
       {    
        j = s1.rend;
    	while(b[i]!=')' )
    	{   
    	if(b[i]>=48 && b[i]<=57)
    	printf("%c",b[i]);
    	else
    		s1 = push(s1,b[i]);
    	
			++i;
    		
		}
		for(m=s1.rend;m<j;--m)
			s1 =pop(s1);
			
    	}
    	
	else
	{
		switch(b[i])
		{
		case '*':
			k = k+1;
			
			if(k==1)
			s1 =push(s1,b[i]);
			else if(s1.a[s1.rend]=='+'||'-')
			s1 = push(s1,b[i]);
			else
			{
			s1 = pop(s1);
			s1 = push(s1,b[i]);
		    }
		    break;
		
	    case '/':
	    	k = k+1;
			if(k==1)
			s1 = push(s1,b[i]);
			else if(s1.a[s1.rend]=='+'||'-')
			s1 = push(s1,b[i]);
			else
			{
			s1 = pop(s1);
			s1 = push(s1,b[i]);
		    }
		    break;
	    case '+':
	    	k =k+1;
          if(k==1)
	       s1 = push(s1,b[i]);
	    	else if(s1.a[s1.rend]=='-'||'+')
	    	{
	    	s1 =pop(s1);
	         s1 = push(s1,b[i]);
	       }
	    else
	    {	
		   if(s1.a[s1.rend]!='+'||'-')
		   	s1 = pop(s1);
		   	
		   	s1=pop(s1);
		   	s1=push(s1,b[i]);
	    	}
	        break;
	    case '-':
	    	k =k+1;
	    	if(k==1)
	    	 s1 = push(s1,b[i]);
	    	else if(s1.a[s1.rend]=='-'||'+')
	    	{
	    	s1 =pop(s1);
			s1 = push(s1,b[i]);
	       }
	    else
	    {	if((s1.a[s1.rend])!='+'||'-')
	    	s1 = pop(s1);
	    	printf("\nhii");
	    	s1 = pop(s1);
			s1 = push(s1,b[i]);
	    
		}
	break;
	default:
		printf("%c ",b[i]);
	}
    
}

}
}


struct queue push(struct queue s, char ch)
{
	if(s.rend==49)
	printf("Stack Full\n");
/*	else
	{
		if(s.fend==-1)
		{
		s.fend = s.fend + 1;
		s.rend = s.rend + 1;
		s.a[s.fend]= ch;
	    }*/
	else
     	{
	s.rend = s.rend + 1;
	s.a[s.rend] = ch;
      }
//printf("Inserted element is %c \n",s.a[s.rend]);
return(s);	
}


struct queue pop(struct queue s)
{
	char ch;
	   if(s.rend==-1)
	   printf("No element to pop\n");
	  /*
	   else if(s.fend==s.rend)
	   {
	   ch = s.a[s.rend] ;
	   s.rend = s.rend - 1;
	   s.fend = s.fend - 1;
       }*/
       else
       {
       	ch = s.a[s.rend];
       	s.rend = s.rend - 1;
       	if(ch!='(') 
			printf("%c ",ch);
	   }
	  
	   return(s);
}







