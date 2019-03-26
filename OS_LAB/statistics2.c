#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int n;
int a[50];

void *mean(void *param)
{
	int i,j,sum = 0,len;	
	
	for(i=0;i<=n;i++)
	{
		sum = sum + a[i];
		}
	double mean = (double)sum/n;
	printf("Mean is %f\n",mean);

	}

void *median(void *param)
{
	int i,j,sum = 0,len = n;	
	int median,temp;

	for(i=0;i<=n-2;i++)
	for(j=0;j<=n-i-2;j++)
	if(a[j]>a[j+1])
	{
		temp = a[j+1];
		a[j+1] = a[j];
		a[j] = temp;
		}

	if((len)%2==0)
	{
		i = len/2;
		j = (len+1)/2;
		median = (a[i-1]+a[j])/2;

		}
	else
	{
		i = (len+1)/2;
		median = a[i-1];

		}
	printf("Median is %d\n",median);
	pthread_exit(0);

}


void *mode(void *param)
{
	int i,j,mode,count,count_max = -1,min = 500,max = -1;

	for(i=0;i<n;i++)
	{
		if(a[i]>max)
		max = a[i];
		
		if(a[i]<min)
		min = a[i];
		}
	count = 0;

	for(i=min;i<=max;i++)
	{
		count = 0;
		for(j=0;j<n;j++)
		if(a[j]==i)
		++count;
		
		if(count>count_max)
		{
			count_max = count;
			mode = i;
			}

		}

	printf("Mode is %d\n",mode);
	pthread_exit(0);
	}



int main()
{
int i;
printf("Enter size of array: ");
scanf("%d",&n);

printf("Enter elements into array\n");

for(i=0;i<n;i++)
scanf("%d",&a[i]);

pthread_t tid[3];
pthread_attr_t attr;
pthread_attr_init(&attr);

pthread_create(&tid[0],&attr,mean,NULL);
pthread_create(&tid[1],&attr,median,NULL);
pthread_create(&tid[2],&attr,mode,NULL);

for(i=0;i<3;i++)
pthread_join(tid[i],NULL);

return(0);
}
