#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<ctype.h>

int main()
{

	signal(SIGKILL,SIG_IGN);
	while(1)
	{
		printf("Hii\n");
		}
return(0);
	}
