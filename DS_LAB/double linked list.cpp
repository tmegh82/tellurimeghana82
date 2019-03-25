#include<stdio.h>
#include<stdlib.h>
struct list
{
	int data;
	struct list *nptr = NULL;
	struct list *pptr = NULL;
};
struct list *hptr = NULL;
 void insertion(int val,int pos);
  void deletion(int pos);
   void Toprint();
   
 int main()
 {
 	int i, val, pos;
 	printf("Enter 1 for insertion, 2 for deletion ,  3 for Toprint, and -1 to terminate");
 	scanf("%d",&i);
 	while(i!=-1)
 	{
 		switch(i)
 		{
 			case 1:
 				printf("Enter value to be inserted and its pos\n");
 				scanf("%d %d",&val,&pos);
 				insertion(val,pos);
 				break;
 			case 2:
 				printf("Enter position to be deleted\n");
 				scanf("%d",&pos);
 				deletion(pos);
 				break;
 			case 3:
 				Toprint();
 				break;
 			default:
 				printf("Wrong Input\n");
 			}
 				printf("Enter 1 for insertion, 2 for deletion ,  3 for Toprint, and -1 to terminate");
 	        scanf("%d",&i);
	 }
 	
 }
 
 int Isempty()
 {
 	if(hptr==NULL)
 	return(1);
 	else
 	return(0);
 }
 void insertion(int val,int pos)
 {
 	int i =1;
 	struct list *temp = (struct list*)malloc(sizeof(struct list));
 	if(temp == NULL)
 	{
 		printf("Memory is Full\n");
	 }
	 else if(pos==1)
	 {
	 	temp->nptr = hptr;
	 	hptr = temp;
	 	temp->data =val;
	 	temp->pptr = NULL;
	 	
	 }
	 
	 else
	 {
	 	struct list *sptr = hptr; 
	 	while(i<pos-1)
	 	{
	 		sptr = sptr->nptr;
		 }
		 temp->pptr = sptr;
		 temp->nptr = sptr->nptr;
		  sptr->nptr = temp;
		  temp->data = val;
	 }
 }
 
 
 void deletion(int pos)
 {
 	int i = 1,x;
 	if(Isempty()==1)
 	printf("No element to delete\n");
 	else if(pos==1)
 	{
 		x = hptr->data;
 		hptr = hptr->nptr;
 		hptr->pptr = NULL;
 		printf("Element to be deleted is%d\n",x);
 	}
 	else
 	{
 		struct list *sptr = hptr;
 		while(i<pos-1)
 		{
 			sptr = sptr->nptr;
		 }
		 
		 x = (sptr->nptr)->data;
		 sptr->nptr = (sptr->nptr)->nptr;
		 printf("Deleted element is %d\n",x);
	 }
 }
 
 void Toprint()
 {
 	int x;
 	struct list *sptr = hptr;
 	while(sptr->nptr!=NULL)
 	{
 		x = sptr->data;
 		printf("%d\n",x);
 		sptr = sptr->nptr;
	 }
	 x = sptr->data;
	 printf("%d\n",x);
 }
 
 k
