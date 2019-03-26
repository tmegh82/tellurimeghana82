#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

struct statistics
{
	int n;
	char **a;
	//int *p;
};

void *mean(void *param)
{
	struct statistics *d = param;
	int len = d->n;
	int  sum = 0,i,j;

	for(i=1;i<=len;i++)
	{
		j = atoi(*((d->a)+i));
		printf("Val is %d\n",j);
		sum = sum + j;
		}
	double mean = (double)sum/len;
	printf("Mean is %f\n",mean);
	}


void *median(void *param)
{
	struct statistics *d = param;
	printf("Median\n");
	int i,j,sum = 0,len,n1,n2;	
	int median;
	len = d->n;
	char temp[50];
	printf("Hello 3\n");
	for(i=1;i<=len-1;i++)
	for(j=1;j<=len-i;j++)
	{
		printf("Hello\n");
		n1 = atoi(*((d->a)+j));
		printf("Value of n1 is %d\n",n1);
		n2 = atoi(*((d->a)+j+1));
		printf("Value of n2 is %d\n",n2);
		if(n1 > n2)
		{
			printf("Hello 3\n");
			strcpy(temp,*((d->a)+j));
			printf("Hello 4\n");			
			strcpy(*((d->a)+j),*((d->a)+j+1));
			strcpy(*((d->a)+j+1),temp);

			}
	}
	
	printf("Hello here\n");
	if((len)%2==0)
	{
		i = len/2;
		j = (len+1)/2;
		//median = (a[i-1]+a[j-1])/2;
		median = (atoi(*(d->a+(i-1))) + atoi(*(d->a+(j-1))))/2;

		}
	else
	{
		i = (len+1)/2;
		median = atoi(*(d->a+(i-1)));

		}
	printf("Median is %d\n",median);
	pthread_exit(0);

}


int main(int argc, char *argv[])
{	
	struct statistics data;
	data.n = argc-1;
	data.a = argv;

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
	pthread_create(&tid[0],&attr,mean,&data);
	pthread_create(&tid[1],&attr,median,&data);
	//pthread_create(&tid[2],&attr,mode,&data);
	pthread_join(tid[0],NULL);

return(0);

	}




