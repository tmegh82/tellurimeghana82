#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

#define MSG_SIZE 100

int main()
{
	int fd1[2];
	int fd2[2];
	pid_t pid;
	int p1 = pipe(fd1);
	int p2 = pipe(fd2);
	char pbuffer[MSG_SIZE];
	char cbuffer[MSG_SIZE];
	char pstring[MSG_SIZE];
	char cstring[MSG_SIZE];

	if(p1==-1)
		printf("Error in creation of pipe 1\n");
	if(p2==-1)
		printf("Error in creation of pipe 2\n");

	if(p1!=-1 && p2!=-1)
	{
		pid = fork();
	
	
		if(pid>0)
		{
			printf("First Parent writes\n");
			close(fd1[0]);
			printf("Enter a string to be written by parent:");
			scanf("%s",pstring);		
			write(fd1[1],pstring,strlen(pstring)+1);
			close(fd1[1]);		
			close(fd2[1]);
			read(fd2[0],pbuffer,250);
				printf("Reading done by parent: %s\n",pbuffer);		
				close(fd2[0]);
		}
	
		else
		{
			close(fd1[1]);
			read(fd1[0],cbuffer,250);
			printf("Reading done by Child Process: %s\n\n",cbuffer);		
			close(fd1[0]);
			printf("Enter string that child should write:");
			scanf("%s",cstring);
			close(fd2[0]);
			write(fd2[1],cstring,strlen(cstring)+1);
			close(fd2[1]);
		}


	}



return(0);
	}





