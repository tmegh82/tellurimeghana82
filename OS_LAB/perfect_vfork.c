#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;
	
	int lb,ub,status;
	int k,sum,out[50],i,j;
	
	printf("Enter range of Lower bound :\n");
		scanf("%d",&lb);
	printf("Enter Upper Bound:\n");
	      scanf("%d",&ub);

	pid = vfork();
	
	if(pid>0)
	{
		wait(&status);
		//printf("Status is %d \n",status);
		printf("Child Terminated\n");
		printf("Output array:");

		for(i=0;i<k;i++)
			printf("%d ",out[i]);
			printf("\n");
		}
	else
	{
		k = 0;
		for(i=lb;i<=ub;i++)
		{
			sum = 0;
			for(j=1;j<i;j++)
			{
				if(i%j==0)
				{
				 	sum = sum + j;
					//printf("Sum is %d\n",sum);
			
				}
			}	
				
			if(sum==i)
			{
				//printf("Value of i is:%d",i);
				out[k] = i;
				k++;
				}
		}
		/*printf("Output array:");

		for(i=0;i<k;i++)
			printf("%d ",out[i]);
			
	        printf("\n");	
		*/
	exit(0);		
	
		}
return(0);
	}
