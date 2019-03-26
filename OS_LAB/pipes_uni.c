#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>


#define MSG_SIZE 16

int main()
{

	int fd[2];

	char buffer[MSG_SIZE];
	int nbytes;
	char ch1[MSG_SIZE] = "Hello world 1";
	char ch2[MSG_SIZE] = "Hello world 2";
	char ch3[MSG_SIZE] = "Hello world 3";

	if(pipe(fd)==-1)
		printf("Error in creating pipe\n");
	
	else
	{
		pid_t pid;
		pid = fork();
		
		if(pid>0)
		{
			printf("Parent process Writes\n");
			close(fd[0]);
			write(fd[1],ch1,MSG_SIZE);
			write(fd[1],ch2,MSG_SIZE);
			write(fd[1],ch3,MSG_SIZE);
			close(fd[1]);
		}
		
		else
		{
			printf("Child process reads\n");
			close(fd[1]);
			while((nbytes = read(fd[0],buffer,MSG_SIZE)) > 0)
				printf("%s\n",buffer);
			close(fd[0]);
			
		}		
	
	}


return(0);
	}
