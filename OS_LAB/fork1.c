#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main()
{
/*
	printf("Hello");
	fork();
	//fork();
	//fork();
//	printf("Hello\n");

	}

*/

printf("Parent without backslash");

pid_t pid = fork();

if(pid==0)
{
	printf("Child\n");
	fork();
		//printf("Child");
	}

else if(pid>0)
{
	printf("Parent with back slah\n");
	}

printf("Main Parent\n");

}

