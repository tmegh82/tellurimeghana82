#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>



int  main(int argc , char argv[])
{
	printf("We are in hello.c\n");
	printf("pid of hello.c: %d\n",getpid());
	printf("ppid of hello.c: %d\n",getppid());
	
	return(0);

	}



