#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

#define MSG_SIZE 16

int main()
{

pid_t pid;
int fd[2];
char buffer[MSG_SIZE];
int nb;
char string[MSG_SIZE];

	if(pipe(fd)==-1)
		printf("Error in creating a pipe\n");

	else
	{
		pid = fork();
		if(pid==0)
		{
			//close(fd[0]);
			//printf("Enter the string :");
			//scanf("%s",string);
			//write(fd[1],string,strlen(string)+1);	
			//close(fd[1]);
			close(fd[0]);		
			dup2(fd[1],1);
			execlp("ls","ls",NULL);
			close(fd[1]);
			}
		else
		{
			close(fd[1]);
			dup2(fd[0],0);
			/*while(nb = read(fd[0],buffer,MSG_SIZE) > 0)
				printf("%s",buffer);
			printf("\n");*/
			execlp("tr","tr","a-z","A-Z",NULL);
			close(fd[0]);
			}

		}







return(0);
	}
