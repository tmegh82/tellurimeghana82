#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	int n,i,j,out[100];

	printf("Enter a value: ");
		scanf("%d",&n);
	pid_t pid;

	pid = vfork();
	
	if(pid==0)
	{
		int N;
		N = n;
		
		out[0] = n;
		i = 1;

		if(n%2==0)
		{
			while(N!=1)
			{
				N = N/2;
				out[i] = N;
				i++;				
				}
		}

		else
		{
			printf("Yeah number is odd\n");
			while(N!=1)
			{
				if(N%2==0)
					N = N/2;

				else
					N = (3*N+1)/2;
					
					out[i] = N;
					i++;			
				}
			
		}
	exit(0);

	}	
	
	printf("The series generated is : ");	
	for(j=0;j<i;j++)
		printf("%d ",out[j]);
	
	printf("\n");
	
	return(0);
	}





