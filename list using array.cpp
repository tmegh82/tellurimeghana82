 #include<stdio.h>
#include<stdlib.h>
#define SIZE 50
struct node
{
	int a[SIZE];
	int data ;
	int ptr;
};
struct node s;
void insertion(int val, int pos);
int deletion(int pos);
void Toprint();

int main()
{
	s.ptr = -1;
	int i,j,x,p;
	printf("Enter 1 for insertion , 2 for deletion , 3 for printing and -1 to terminate\n");
	scanf("%d",&i);
	while(i!=-1)
	{
	   switch(i)
	   {
	   case 1:
	   	printf("Enter value and position of element to be inserted\n");
	   	scanf("%d %d",&x,&p);
	   	insertion(x,p);
        break;
        
        case 2:
        	printf("Enter position of the element to be deleted\n");
        	scanf("%d",&x);
        	j = deletion(x);
        	printf("Deleted element is %d",j);
        	break;
        	
        case 3:
        	Toprint();
        	break;
        default:
        	printf("Wrong input");
}
printf("Enter 1 for insertion , 2 for deletion , 3 for printing and -1 to terminate\n");
scanf("%d",&i);
	}
}
	
	
	


void insertion(int val, int pos)
{
	int i = s.ptr;
	if(s.ptr==SIZE-1)
	{
	printf("Memory full\n");
	}
    
    else
    {
	  while(i>=pos-1)
	  {
	  	s.a[i+1] = s.a[i];
	  	--i;
	  }
	  s.a[pos-1] = val;
	  s.ptr = s.ptr + 1;
    }

}



int deletion(int pos)
{
	int i,x;
	if(s.ptr == -1)
	printf("Nothung to print");
	else
	{ 
	    i = pos-1;
	    x = s.a[i];
		while(i<s.ptr)
        {
        	s.a[i] = s.a[i+1];
        	++i;
		}
		s.ptr = s.ptr -1;
 	    return(x);	
	}
	
	
}


void Toprint()
{
	int i;
	if(s.ptr == -1)
	printf("Nothing to print\n");
	else
	{ 
	i = 0;
		while(i<=s.ptr)
		{
			printf("\n%d\n",s.a[i]);
		   ++i;
		}
		
	}

}















