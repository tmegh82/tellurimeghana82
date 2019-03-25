#include<stdio.h>
#include<stdlib.h>
struct node
{
	int Checkbucket;
	struct node *c1;
	struct node *c2;
	struct node *c3;
	int a[4];
	int len;
	struct node *previousptr;
};

struct node *rptr=NULL;

struct node* generatebucket()
{
	struct node *newptr=(struct node*)malloc(sizeof(struct node));
	newptr->Checkbucket=1;
	newptr->c1=NULL;
	newptr->c2=NULL;
	newptr->c3=NULL;
	newptr->previousptr=NULL;
	newptr->a[0]=-111;
	newptr->a[1]=-111;
	newptr->a[2]=-111;
	newptr->a[3]=-111;
	newptr->len=0;
	return(newptr);
}

struct node* generatenode()
{
	struct node *newptr=(struct node*)malloc(sizeof(struct node));
	newptr->Checkbucket=0;
	newptr->c1=NULL;
	newptr->c2=NULL;
	newptr->c3=NULL;
	newptr->previousptr=NULL;
	newptr->a[0]=-111;
	newptr->a[1]=-111;
	newptr->a[2]=-111;
	newptr->a[3]=-111;
	newptr->len=0;
	return(newptr);
}

struct node* ArrangeInOrder(struct node *ptr)
{
	int i,k,temp;

	if(ptr->Checkbucket==0)
	{
		ptr->c1=ArrangeInOrder(ptr->c1);
		if(ptr->c2!=NULL)
			ptr->c2=ArrangeInOrder(ptr->c2);
		if(ptr->c3!=NULL)
			ptr->c3=ArrangeInOrder(ptr->c3);
	}

	else
	{
		
		for(i=0;i<3;i++)
		{
			for(k=0;k<3-i;k++)
			{
				if(ptr->a[k]!=-111 && ptr->a[k+1]!=-111)
				{
					if(ptr->a[k]>ptr->a[k+1])
					{
						temp=ptr->a[k];
						ptr->a[k]=ptr->a[k+1];
						ptr->a[k+1]=temp;
					}
				}
			}
		}
	}
	return(ptr);
}

int FindMinimum(struct node *ptr)
{
	int i,least=ptr->a[0];
	if(ptr->Checkbucket==0)
	{
		least=FindMinimum(ptr->c1);
	}
	else
	{
	if(ptr==NULL)
		return(-111);
	else if(ptr->Checkbucket==1)
	{
		for(i=0;i<2,ptr->a[i]!=-111;i++)
			if(ptr->a[i]<least)
				least=ptr->a[i];

		return(least);
	}
	}
}

void ToPrint(struct node *ptr)
{
	int i;

	if(ptr->Checkbucket==0)
	{
	
		ToPrint(ptr->c1);
		if(ptr->c2!=NULL)
			ToPrint(ptr->c2);
		if(ptr->c3!=NULL)
			ToPrint(ptr->c3);
	}

	else
	{
		printf(" %d",ptr->len);
		for(i=0;i<3;i++)
			printf(" %d ",ptr->a[i]);
		printf("\n");
	}
}

struct node* ToInsert(int val,struct node *ptr)
{


	if(ptr==NULL)
	{
		struct node *temp;
		temp=generatebucket();
		temp->a[0]=val;
		ptr=temp;
		ptr->len++;
	}

	else if(ptr->Checkbucket==1 && ptr->len<4)
	{
		int i=0;
		while(i<4 && ptr->a[i]!=-111)
			i++;
		ptr->a[i]=val;
		ptr->len++;
		ptr=ArrangeInOrder(ptr);


	}

	else if(ptr->Checkbucket==0)
	{
		if(ptr->a[0]<val&& ptr->a[1]==-111)
			ptr->c2=ToInsert(val,ptr->c2);
		else if(ptr->a[0]>val)
			ptr->c1=ToInsert(val,ptr->c1);
		else
			ptr->c3=ToInsert(val,ptr->c3);
	}

			if(ptr->Checkbucket==1 && ptr->len==4 && ptr->previousptr==NULL)
		{
			struct node *temp;
			temp=generatenode();
			temp->c1=ptr;
			temp->c1->previousptr=temp;
			struct node *b;
			b=generatebucket();
			temp->c2=b;
			temp->c2->previousptr=temp;
			temp->c2->a[0]=ptr->a[2];
			temp->c2->len++;
			temp->c2->a[1]=ptr->a[3];
			temp->c2->len++;
			ptr->a[2]=-111;
			ptr->len--;
			ptr->a[3]=-111;
			ptr->len--;
			temp->a[0]=FindMinimum(temp->c2);
			ptr->previousptr=temp;
			return(temp);

		}


	if(ptr->Checkbucket==0 && ptr->c1->Checkbucket==1)
	{
		
		
			if(ptr->c3==NULL)
			{

				struct node *temp;
				temp=generatebucket();
				if(ptr->c1->len==4)
				{

					ptr->c3=ptr->c2;
					ptr->c2=temp;
					temp->a[0]=ptr->c1->a[2];
					temp->len++;
					temp->a[1]=ptr->c1->a[3];
					temp->len++;
					ptr->c1->a[2]=-111;
					ptr->c1->len--;
					ptr->c1->a[3]=-111;
					ptr->c1->len--;
					temp->previousptr=ptr;
									ptr->a[0]=FindMinimum(ptr->c2);
				ptr->a[1]=FindMinimum(ptr->c3);

				}


				else if(ptr->c2->len==4)
				{

					ptr->c3=temp;
					temp->a[0]=ptr->c2->a[2];
					temp->len++;
					temp->a[1]=ptr->c2->a[3];
					temp->len++;
					ptr->c2->a[2]=-111;
					ptr->c2->len--;
					ptr->c2->a[3]=-111;
					ptr->c2->len--;
					temp->previousptr=ptr;
									ptr->a[0]=FindMinimum(ptr->c2);
				ptr->a[1]=FindMinimum(ptr->c3);

				}
				
			}

			else if(ptr->c3!=NULL)
			{
				struct node *temp;
				temp=generatenode();
				struct node *b;
				b=generatebucket();
				struct node *root;
				root=generatenode();

				if(ptr->c1->len==4)
				{
					b->a[0]=ptr->c1->a[2];
					b->len++;
					b->a[1]=ptr->c1->a[3];
					b->len++;
					ptr->c1->a[2]=-111;
					ptr->c1->len--;
					ptr->c1->a[3]=-111;
					ptr->c1->len--;
					ptr->previousptr=root;
					temp->c2=ptr->c3;
					temp->c2->previousptr=temp;
					temp->c1=ptr->c2;
					temp->c1->previousptr=temp;
					ptr->c3=NULL;
					ptr->c2=b;
					b->previousptr=ptr;

					temp->a[0]=FindMinimum(temp->c2);
					ptr->a[1]=-111;
					root->c1=ptr;
					root->c2=temp;
					temp->previousptr=root;
					root->a[0]=FindMinimum(root->c2);
					ptr=root;


				}

				else if(ptr->c2->len==4)
				{
					b->a[0]=ptr->c2->a[2];
					b->len++;
					b->a[1]=ptr->c2->a[3];
					b->len++;
					ptr->c2->a[2]=-111;
					ptr->c2->len--;
					ptr->c2->a[3]=-111;
					ptr->c2->len--;
					ptr->previousptr=root;
					temp->c2=ptr->c3;
					temp->c2->previousptr=temp;
					temp->c1=b;
					temp->c1->previousptr=temp;
					ptr->c3=NULL;

					temp->a[0]=FindMinimum(temp->c2);
					ptr->a[1]=-111;
					root->c1=ptr;
					root->c2=temp;
					temp->previousptr=root;
					root->a[0]=FindMinimum(root->c2);
					ptr=root;

				}

				else if(ptr->c3->len==4)
				{
					b->a[0]=ptr->c3->a[2];
					b->len++;
					b->a[1]=ptr->c3->a[3];
					b->len++;
					ptr->c3->a[2]=-111;
					ptr->c3->len--;
					ptr->c3->a[3]=-111;
					ptr->c3->len--;
					ptr->previousptr=root;

					
					temp->c1=ptr->c3;
					temp->c1->previousptr=temp;
					temp->c2=b;
					temp->c2->previousptr=temp;
				
					ptr->c3=NULL;
					ptr->a[1]=-111;
					temp->a[0]=FindMinimum(temp->c2);
					root->c1=ptr;
					root->c2=temp;
					temp->previousptr=root;
					root->a[0]=FindMinimum(root->c2);
					ptr=root;
				}
			}
		}
	return(ptr);
}


int main()
{
int i,val;
printf("Enter 1 to Insert and 2 to print and -1 to terminate\n");
scanf("%d",&i);

while(i!=-1)
{
	
switch(i)
{
	case 1:
		printf("Enter the element you want to insert\n");
		scanf("%d",&val);
		rptr = ToInsert(val,rptr);
		break;
	case 2:
		ToPrint(rptr);
		break;
	default:
		printf("Wrong input\n");
}
printf("Enter 1 to Insert and 2 to print and -1 to terminate\n");
scanf("%d",&i);

}
}
