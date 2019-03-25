 #include<stdio.h>
#include<stdlib.h>
struct node
{
	int data ;
	struct node *nptr;
};

struct node *hptr = NULL;
struct node *sptr = NULL;
void insertion(int val, int pos);
int deletion(int pos);
void Toprint();

int main()
{
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
	int i =1;
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	{
	printf("Memory full\n");
	}
    
    else
    {
	  temp->data = val;
     
      
	 if(pos==1)
	 {
	 	temp->nptr = hptr;
	 	hptr = temp;
	 	printf("Inserted element is %d",val);
	 }
	 else
	 {
	 	while(i<pos-1)
	 	{
	 	sptr = sptr->nptr;
	 	++i;
	 }
	 	temp->nptr = sptr->nptr;
		 sptr->nptr = temp;
   		 printf("Inserted element is %d",val);	 	
	 }
	 sptr = hptr;
}

}


int deletion(int pos)
{
	int i = 1,x;
	if(hptr==NULL)
	printf("No element to delete\n");
	else
	{
		if(pos==1)
  		{
				x = hptr->data;
		hptr = hptr->nptr;
	
	}
		else
		{
            	while(i<pos-1)
            	{
		          sptr = sptr->nptr;
		          ++i;
               	}
               	x = (sptr->nptr)->data;
	           sptr->nptr = (sptr->nptr)->nptr;
	           
       }
}
      sptr = hptr; 
	return(x);
	
}


void Toprint()
{
	if(hptr==NULL)
	printf("Nothing to print\n");
	else
	{
		while(sptr!=NULL)
		{
			printf("\n%d\n",sptr->data);
			sptr= sptr->nptr;
		}
		
	}
	sptr = hptr;
}















