#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include <sys/stat.h>

#define MAX_SIZE 256

int main()
{
	pid_t pid;

	int f = open("rein.txt", O_CREAT|O_RDWR);

     	char buffer[MAX_SIZE];

        if(f==-1)
               printf("Error in file creation\n");

	else
	{
		pid = fork();
	
		if(pid==0)
		{
	        	dup2(f, 1);
		        execlp("ls","ls",NULL);
			//close(f);			
			} 

		else
		{
			int nb;			
			int f2 = dup2(f,0);
			
			while(nb = read(f2,buffer,MAX_SIZE ) > 0)		
			write(1,buffer,MAX_SIZE);	
			printf("\n");
						
			}
	}
 
        return 0;


	}
