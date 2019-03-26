#include<stdio.h>
#include<stdlib.h>
struct node
{
       int x;
       struct node *left, *right;
}*root=NULL, *current, *new1,*u;
struct node *queue[10];
int front=-1;
int rear=-1;
void enqueue(struct node *a)
{
     if(front==-1)
      front=rear=0;
     else
      rear++;
     queue[rear]=a;

}struct node* dequeue()
{
	if(front==-1)
	 return NULL;

	else
	{
		u=queue[front];
	      if(front==rear)
		front=rear=-1;
	      else
		front++;
	return u;
	}
}

void insert(int p)
{
     new1=(struct node*)malloc(sizeof(struct node));
       new1->x=p;
       new1->left=NULL;
       new1->right=NULL;
     if(root==NULL)
	      root=new1;

     else
     {
	 enqueue(root);
	 while(front!=-1)
	 {
	 current=dequeue();
	 // printf("%d",current->x);
	 if(current->left!=NULL)
	  enqueue(current->left);
	 if(current->right!=NULL)
	  enqueue(current->right);
	 if(current->left==NULL)
	 {
	  current->left=new1;

	  break;
	 }
	  if(current->right==NULL)
	 {
	  current->right=new1;
	  break;
	  }
	  }
	  }
}
struct node* inorder(struct node *a)
{
     if(a==NULL)
      return NULL;
     else
     {
	 inorder(a->left);
	 printf("%d->",a->x);
	 inorder(a->right);
	 }
}
int maxi=0;
void max(struct node *r)
{
	if(r==NULL)
	return;
	else
	{
		max(r->right);
		max(r->left);
		if(r->x>maxi)
		maxi=r->x;
	}
}


int maxx(struct node *r)
{
	  if(r==NULL)
	  return 0;
	int l=maxx(r->left);
	int r1=maxx(r->right);
	if(l>r1)
    	maxi=l;
	
	if(r->x>maxi)
	maxi=r->x;
	
	return maxi;
	
}
int main()
{
     int x;
     while(1)
     {
	     printf("Enter element : ");
	     scanf("%d",&x);
	     if(x==0)
	      break;
	     insert(x);
	     inorder(root);
     }
     
    maxi= maxx(root);
     printf("%d",maxi);
 }

