#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>

int main()
{

char ar[100],b[10][100];
pid_t pid;

int i =-1,j,a;

printf("Enter !! to display last command exectued\n\t ! n to display the last n commands\n\t or enter command\n");

	while(1)
	{
		++i;
		printf("Enter the command relatively: ");
		scanf("%s",ar);
		
		strcpy(b[i],ar);

		pid = fork();
		
		if(pid>0)
		{
			wait(NULL);
			}

		else
			if(pid==0)
			{
				if(ar[0]=='!' && ar[1]=='!')
				{
					printf("It prints all the commands executed:\n");
					
					for(j=0;j<i;j++)
						printf("%s\n",b[j]);	
				}				
				else if(ar[0]=='!' && ar[1]>=48 && ar[1]<=57 && ar[1]<=(48+i) )
				{
					a = ar[1] - 48;
					printf("Here are the last %d commands executed:\n",a);
	
					for(j=i-1;j>(i-1-(ar[1]-48));j--)
						printf("%s\n",b[j]);
				}
	
				else
				{
					execlp(ar,"Hello",NULL);
				}
				exit(0);
			}
	
			else	
				printf("Failed to create child process\n");
			
	}
	return(0);

}





