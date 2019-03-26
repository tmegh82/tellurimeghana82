#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int n;

void *mean(void *p)
{
	char **a = p;

	int  sum = 0,i;
	int j ;

	for(i=1;i<n;i++)
	{
		j = atoi(*(a+i));
		printf("Values are %d\n",j);
		sum = sum + j;
		}
	double mean = (double)sum/(n-1);
	printf("Mean is %f\n",mean);
	}


int main(int argc, char *argv[])
{
	n = argc;
	printf("Addresses\n");

	printf("argv[0] is %p \n",(argv));
	printf("argv[1] is %p \n",(argv+1));
	printf("argv[2] is %p \n",(argv+2));

	printf("Values\n");

	printf("argv[0] is %s \n",*(argv+0));
	printf("argv[1] is %d \n",atoi(*(argv+1)));
	printf("argv[2] is %d \n",atoi(*(argv+2)));

	printf("Sizes\n");

	printf("size of 0 %lu\n",sizeof(argv+0));
	printf("size of 1 %lu\n",sizeof(argv[1]));
	printf("size of 2 %lu\n",sizeof(argv[2]));

	pthread_t tid[3];
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&tid[0],&attr,mean,argv);
	pthread_join(tid[0],NULL);

return(0);

	}




