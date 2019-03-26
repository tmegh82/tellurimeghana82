#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
#include<stdlib.h>

void *prime(void *param)
{
	
	int i,count,k;

	int j = atoi(param);

	printf("Prime numbers between 1 and %d are: ",j);

	for(i=1;i<=j;i++)
	{
		k = 1;
		count = 0;

		while(k<=i)
		{
			if(i%k==0)
			++count;
			++k;
			}
		if(count==2)
		printf("%d ",i);
	}
	printf("\n");

	pthread_exit(0);
}


int main(int argc, char *argv[])
{
	pthread_t tid;
	pthread_attr_t attr;	
	pthread_attr_init(&attr);

	if(argc!=2)
	{
		fprintf(stderr,"Usage: a.out <integer value>");
		}
	
	if(atoi(argv)<0)
	{
		fprintf(stderr,"%d should be greater than 0",atoi(argv[1]));
		}

	pthread_create(&tid, &attr, prime,argv[1]);
	pthread_join(tid,NULL);
	

	return(0);
	}


