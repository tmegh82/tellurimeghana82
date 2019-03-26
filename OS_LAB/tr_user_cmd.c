#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctype.h>

#define MAX_SIZE 16

int main()
{
	int fd[2];
	pid_t pid;
	int nb,i;
	char buffer[MAX_SIZE];

	if(pipe(fd)==-1)
	{
		fprintf(stderr,"Pipe Failed");
		return(1);
		}
	else
	{
		pid = fork();
		if(pid==0)
		{	
			close(fd[0]);
			dup2(fd[1],1);
			execlp("ls","ls",NULL);
			close(fd[1]);
			
			}
		else
		{
			close(fd[1]);
			while(nb = read(fd[0],buffer,MAX_SIZE) > 0)
			{
				for(i=0;i<MAX_SIZE;i++)
				{buffer[i] = toupper(buffer[i]);
				printf("%c",buffer[i]);
				}
			}
			printf("\n");
		}

	}
	return(0);
}
