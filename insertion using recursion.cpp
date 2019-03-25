#include<stdio.h>
#include<stdlib.h>
struct node
{
	int key;
	struct node *left;
	struct node *right;
};

void inorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
 	inorder(ptr->left);
 	printf("%d\n",ptr->key);
 	inorder(ptr->right);
    }
}

struct node* newnode(int key)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->left = NULL;
	temp->right = NULL;
	return(temp);
}


struct node *insertion(struct node *ptr , int key)
{
	 if(ptr ==NULL)
	 	return(newnode(key));
	 
	 if(key < ptr->key)
      ptr->left = insertion(ptr->left, key);
	 else
	 ptr->right = insertion(ptr->right , key);	 
	 
	 return(ptr);
}



struct node *deleteNode(struct node *root, int key)
{
 
    if (root == NULL)
     return root;
 
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
    struct node *current = root->right;

    while (current->left != NULL)
    {
        current = current->left;
        root->key = current->key;
        root->right = deleteNode(root->right, current->key);
    }
    
}
return (root);
}

int main()
{
	struct node *root = NULL;
	int i;
	int x;
	printf("Enter value of 1 for insertion 2 for deletion , 3 for inorder traversal and -1 to terminate\n");
	scanf("%d",&i);
	while(i!=-1)
	{
	if(i==1)
	{
	printf("Enter element to be inserted\n");
	scanf("%d",&x);
    root = insertion(root,x);
    }
    else if(i==2)
    {
    	printf("Enter element to be deleted\n");
    	scanf("%d",&x);
    	root = deleteNode(root,x);
    	inorder(root);
	}
	printf("Enter value of 1 for insertion 2 for deletion , 3 for inorder traversal and -1 to terminate\n");
		scanf("%d",&i);
    }
}
