#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	pid_t pid;
	int fd[2];
	int p1,p2;
	p1 = pipe(fd);

//p2 = pipe(fd2);

  char *grep_args[] = {"grep", "ps", NULL};

	if(p1==-1)
	{
		fprintf(stderr,"Error in Pipe creation");
		return(1);
		}
	
	else
	{
		pid = fork();
		if(pid==0)
		{
			close(fd[0]);
			dup2(fd[1],1);
			execlp("ps","ps",NULL);
			close(fd[1]);			
			}
		else
		{
			close(fd[1]);
			dup2(fd[0],0);
			execvp(*grep_args, grep_args);
			close(fd[0]);			
			}

		}

return(0);
	}
