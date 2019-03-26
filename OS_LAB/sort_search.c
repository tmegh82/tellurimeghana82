#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
	int i,n,j,x,a[50];
	pid_t pid;

	printf("Enter the size of the array:");
		scanf("%d",&n);
		
		printf("Enter elements into the array:");
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
		printf("Enter value you want to search:");
			scanf("%d",&x);
		
	pid = fork();
		
	if(pid>0)
	{
		int temp;
		printf("Sorting in parent process");
		/*
		printf("Array to be sorted is:");
		for(i=0;i<n;i++)
			printf("%d",a[i]);*/
		
		printf("\n");	
		
		
		for(i=0;i<=n-2;i++)
		{
			for(j=0;j<=n-2-i;j++)
			{
				if(a[j+1] < a[j])
				{
					temp = a[j+1];
					a[j+1] = a[j];
					a[j] = temp;		
				}

			}					
				
		}

		
		printf("Sorted Array:");

		for(i=0;i<n;i++)
			printf("%d ",a[i]);
		
		printf("\n");
	
	}

	else
	{
		int flag = 0, pos;
		
		printf("Searching in child process\n");

			/* int x;
			printf("Enter value you want to search:");
			scanf("%d",&x);
		*/	
		
		for(i=0;i<n;i++)
			if(a[i]==x)
			{	
				pos = i;
				flag = 1;
				break;
			}
		
		if(flag==1)	
			printf("The value %d is found at position %d\n",x,(pos + 1));	
		else
			printf("The value %d is not found\n",x);	
		exit(0);		
	}




	}
