#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{


	int n;	
	pid_t pid;

	printf("Enter 1 to simulate orphan process and 2 for zombie process\n");
	scanf("%d",&n);

	switch(n)
	{
	case 1:
	
		pid = fork();
		if(pid>0)
		{
			printf("Parent Process completed\n");

			}

		else
		{
			sleep(10);
			printf("Child Process\n");
			}

		break;
	
	case 2:
		pid = fork();

		if(pid==0)
		{
			printf("Child exited\n");
			exit(0);
			}
		else
		{
			sleep(10);
			printf("Parent exited\n");
			}
		break;
	
	default:
		printf("Wrong Input\n");
	
	}

	return(0);
}
