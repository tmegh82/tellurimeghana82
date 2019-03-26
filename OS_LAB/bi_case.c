#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<ctype.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>


#define MAX_SIZE 256

int main()
{
	int fd1[2];
	int fd2[2];
	int p1 = pipe(fd1);
	int p2 = pipe(fd2);
	pid_t pid;
	char buffer[MAX_SIZE];
	char buffer2[MAX_SIZE];
	char ipstring[MAX_SIZE];
	int i;
	if(p1==-1)
	{
		fprintf(stderr,"Error in pipe creation\n");
		return(1);
		}

	if(p2==-1)
	{
		fprintf(stderr,"Error in pipe 2 creation\n");
		return(1);
		}


	if(p1!=-1 && p2!=-1)
	{
		pid = fork();
		if(pid>0)
		{
			printf("Enter a string: ");	
			scanf("%[^\n]s",ipstring);
			//gets(ipstring);

			close(fd1[0]);
			write(fd1[1],ipstring,strlen(ipstring));
			close(fd1[1]);

			sleep(5);
			printf("Parent after child exists\n");
			printf("Output is:");
			close(fd2[1]);
			read(fd2[0],buffer2,MAX_SIZE);
				printf("%s",buffer2);

			printf("\n");
			close(fd2[0]);
			}	
		
		else
		{
			close(fd1[1]);
			printf("Child Process: Input string is ");

			while(read(fd1[0],buffer,MAX_SIZE)>0)
			printf("%s",buffer);
			printf("\n");
		
			for(i=0;i<=strlen(buffer);i++)
			{
				if(islower(buffer[i]))
					buffer[i] = toupper(buffer[i]);
				else
				{
					if(isupper(buffer[i]))
					buffer[i] = tolower(buffer[i]);
				}
				
			}

			close(fd2[0]);
			write(fd2[1],buffer,strlen(buffer));
			close(fd2[1]);
			
			printf("\nCompletion  of child process\n");
			
			}
		}
	else
	return(1);

return(0);
	}
