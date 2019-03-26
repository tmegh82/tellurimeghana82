#include<stdio.h>

int data[100];
int div[100];
int n1,n2,n3;
int result[100];
int dividend[100];
// a= divisor
// b = dividend
// c = result
// n1 = data n=bits
// n2 = divisor bits
// n3 = dividend bits

void division(int *a, int *b, int *c)
{
	
	int i,j,k;
	
	printf("C aray is\n");

	for(i=0;i<n2;i++)
	{
		c[i] = b[i];
		printf("%d ",c[i]);
		}
	printf("\n");
	int p = n2;
	
	for(i=0; i<n1;i++)
	{
		if(c[0] == 1)
		{
			
			for(j=1;j<n2;j++)
			{
				if((a[j]==0 && c[j]==0) || (a[j]==1 && c[j]==1))
					c[j] = 0;
				else
					c[j] = 1;
				}	
		}
				
			for(k=0;k<n2-1;k++)
				c[k] = c[k+1];
		
			if(p< (n1 + n2 - 1))
			{
				c[k] = b[p];
				++p;
				}
			
	}
		
}



void input()
{
	printf("\nNumber of data bits you want to enter:\n");
	scanf("%d",&n1);

	printf("Enter data:\n ");	
	
	for(int i=0;i<n1;i++)
	scanf("%d",&dividend[i]);
	
	for(int i=0;i<n1;i++)
	data[i] = dividend[i];
	
	printf("Number of divisor bits:\n");
	scanf("%d",&n2);
	
	printf("Enter the divisor:\n");
	for(int i=0;i<n2;i++)
	scanf("%d",&div[i]);
	
	for(int i=n1;i<(n1+n2-1);i++)
	dividend[i] = 0;
	
	n3 = n1 + n2 -1;
}

int main()
{
	int check,k,n,m,flag = 0;
	int dividend2[100];
	
	input();
	division(div, dividend, result);
	
	
	printf("Remainder is (sender): ");
	
	for(int i=0;i<n2-1;i++)
	printf("%d",result[i]);

	printf("\n");
	
//	printf("Data sent to receiver is :");
	
	for(int i=0;i<n1;i++)
	dividend2[i] = data[i];
	
	for(int i=n1,j=0;i<(n1+n2-1),j<n2-1;i++,j++)
	dividend2[i] = result[j];
	
	printf("Data sent by sender: ");

	for(int i=0;i<(n1+n2-1);i++)
	printf("%d",dividend2[i]);
	
	printf("\n");	
	
	printf("Enter 1 if you want error and 0 for no error transmission \n ");
	scanf("%d",&k);
	
	if(k==1)
	{
		printf("Number of bit positions you want to change:");
		scanf("%d",&m);

		
		while(m!=0)
		{

		printf("Which bit (position) you want to change:");
		scanf("%d",&n);

		if(dividend2[n-1]==0)
			dividend2[n-1] = 1;
		else
			dividend2[n-1] = 0;
			
			--m;
			}	
				
		printf("Data received by receiver is :");
	
		for(int i=0;i< (n1 + n2 -1);i++)
		printf("%d",dividend2[i]);
		printf("\n");
	}
	
	if(k==0)
	{
			
		printf("Data sent to receiver is :");
	
		for(int i=0;i<(n1 + n2 -1);i++)
		printf("%d",dividend2[i]);
		printf("\n");
		}
	
	division(div, dividend2, result);
	
	printf("Remainder is (receiver) : ");
	
	for(int i=0;i<n2-1;i++)
	{
		printf("%d",result[i]);

		if(result[i]==1)
		{
			flag = 1;
			}
	}
	
	
	if(flag == 1)
		printf("\n Error detected\n");
	else
		printf("\n No Error detected\n");
		
	
}
