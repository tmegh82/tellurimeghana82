#include <pthread.h>
#include <stdio.h>
#include<stdlib.h>

//int sum; 
void *runner(void *param); 

int main(int argc, char *argv[])
{
	pthread_t tid; /* the thread identifier */
	pthread_attr_t attr; 

	if (argc != 2) {
	fprintf(stderr,"usage: a.out <integer value> \n");
	return -1;
	}

	if (atoi(argv[1]) < 0) {
	fprintf(stderr,"%d must be >= 0 \n",atoi(argv[1]));
	return -1;
	}
	
	//printf("HEllo\n");

	pthread_attr_init(&attr);
	
	//printf("HEllo\n");

	pthread_create(&tid,&attr,runner,argv[1]);
	
	printf("HEllo\n");

	pthread_join(tid,NULL);
}

//	printf("sum = %d \ n",sum);

void *runner(void *param)
{
	
	//printf("HEllo\n");

	int i, j = atoi(param);
	int k,count;

	for (i = 1; i <= j; i++)
	{	k = 1;
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

pthread_exit(0);
	}







