#include<stdio.h>

struct queue
{
	int a[50];
	int fend ;
	int rend;
};
struct queue insertion(struct queue s1, int b);
struct queue deletion(struct queue s1);
void Toprint(struct queue s1);

int main()
{
	struct queue s;
	s.fend = -1;
	s.rend = -1;
	int i,j,v;
	printf("\nEnter any number and -1 to terminate\n");
	scanf("%d",&i);
	
	while(i!=-1)
	{
		printf("Enter 1 to enter , 2 to delete , 3 to print\n");
		scanf("%d",&j);
		
		if(j==1)
		 {
		  printf("Enter a value to be inserted\n");
		  scanf("%d",&v);
		   s = insertion(s,v);
	    }
	    else if(j==2)
	    s = deletion(s);
	    
	    else if(j==3)
	    Toprint(s);
	    
	    else
	    printf("Wrong input\n");
	    
	    printf("Enter any number and -1 to terminated\n");
	    scanf("%d",&i);
		}
}


		struct queue insertion(struct queue s1 , int b)
        {    
            if(s1.rend== 49)
            printf("Memory full\n");
            
        	
             else if(s1.fend==-1 && s1.rend == -1)
               {
        	     s1.fend = s1.fend +1;
        	     s1.rend = s1.rend +1;
        	 }
        	 else {
        	     s1.rend = s1.rend +1;
        	 }
        	 s1.a[s1.rend] = b;
			 return(s1);       	 
        	
		}
		
		struct queue deletion(struct queue s1)
       {
       	int x = s1.a[s1.fend];
       	  printf("Element to be deleted %d",x);
       	
       	if(s1.rend == -1)
       	  printf("No element to delete\n");
       	  
       	  
       	else if(s1.fend == s1.rend)
       	{
       	  s1.fend = -1;
       	   s1.rend = -1;
       }
   
       	else 
       	s1.fend = s1.fend + 1;
       	
       	return(s1);
       	
	   }
      
      
      void Toprint(struct queue s1)
      {
      	int i;
      	if(s1.fend == -1)
      	printf("No element to print\n");
      	else{
      	for(i=s1.fend; i<=s1.rend ; i = i+1)
      	 printf("\n%d\n",s1.a[i]);
      }
      	
	  }











