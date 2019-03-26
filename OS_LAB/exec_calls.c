#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	int n;

	printf("Enter 1 for execl, 2 for execvp, 3 for execlp 4 for execv\n");
	scanf("%d",&n);

	char *args[] = {"Hello","C",NULL};
	char *args2[] = {"Hello",NULL};

	switch(n)
	{
		case 1:
			if(fork()==0)
			{
				execl("/home/meghana/hello","Hello","C",NULL);
				printf("Back to exec_calls.c\n");	
				}
			else
			{
				printf("Parent Process\n");
				}
			break;
		case 2:
			//char *args[] = {"Hello","C",NULL};
			if(fork()==0)
			{
				execvp("./hello",args);	
				printf("Back to exec_calls.c\n");
				}
			else
				printf("Parent Process\n");	
			break;	
		case 3:
			if(fork()==0)
			{
				execlp("ps","Hello",NULL);
				printf("Back to exec_calls.c\n");
				}
			else
				printf("Parent Process\n");
			break;
		case 4:
			//char *args[] = {"Hello","C",NULL};
			if(fork()==0)
			{
				execv("/bin/ls",args2);
				printf("Back to exec_calls.c\n");
				}
			else
				printf("Parent Process\n");
			break;
		default:
			printf("Wrong Input\n");
	}
	
	return(0);

	}








