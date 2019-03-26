#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int n,len;
//int a[50],b[50],c[50];
int result1,pos1,pos2;

void *median(void *param)
{
	int i,j,sum = 0;
	int *a = param;	
	int median,temp;
	
	if((len)%2==0)
	{
		i = (len)/2;
		j = (len+1)/2;
		median = (a[i]+a[j-1])/2;
		pos1 = j-1;
		pos2 = i;
		}
	else
	{
		i = (len+1)/2;
		median = a[i-1];
		pos1 = i-1;
		pos2 = i-1;
		}
	printf("Median is %d\n",median);
	if(len==n)
	{
	result1 = median;
	}
	pthread_exit(0);

}


int main()
{
int a[50],b[50],c[50];
int i,temp,j,k;
printf("Enter size of array: ");
scanf("%d",&n);

printf("Enter elements into array\n");

for(i=0;i<n;i++)
scanf("%d",&a[i]);

for(i=0;i<n;i++)
for(j=0;j<n-i-1;j++)
	if(a[j+1] < a[j])
	{
		temp = a[j+1];
		a[j+1] = a[j];
		a[j] = temp;
	}


for(i=0;i<n;i++)
printf("%d ",a[i]);
printf("\n");

pthread_t tid[3];
pthread_attr_t attr;
pthread_attr_init(&attr);

len  = n;

pthread_create(&tid[0],&attr,median,&a);
pthread_join(tid[0],NULL);

len = 0;
for(i=0;i<=pos1-1;i++)
{
	b[i] = a[i];
	++len;
	}

pthread_create(&tid[1],&attr,median,&b);

j = 0;
len = 0;

for(i=pos2+1;i<n;j++,i++)
{
	c[j] = a[i];
	++len;
}

pthread_create(&tid[2],&attr,median,&c);

for(i=1;i<3;i++)
pthread_join(tid[i],NULL);

return(0);
}
