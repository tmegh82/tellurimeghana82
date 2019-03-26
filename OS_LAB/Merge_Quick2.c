#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define MAX 4
int n;
int a[50];
int b[50];
int part = 0;
struct data
{
	int p;
	int q;
	int ti;
	};


void merge(int beg, int end)
{
	int mid = (beg + end)/2; 
	
	int i = beg,j = mid + 1,k = 0;

	while(i<=mid && j<=end)
	{
		if(a[i]<a[j])
		{
			b[k] = a[i];
			i++;
			}
		else
		{
			b[k] = a[j];
			j++;
			}
		k++;

		}
	
	while(i<=mid)
	{
		b[k] = a[i];
		k++;
		i++;
		}
	while(j<=end)
	{
		b[k] = a[j];
		k++;
		j++;

		}
	for(i=beg;i<=end;i++)
	a[i] = b[i-beg];

	}


void merge_sort2(int p,int q)
{
	int mid = (p + q) /2;
	
	if(p < q)
	{
		
		merge_sort2(p,mid);
		merge_sort2(mid+1,q);
		merge(p,q);
		}
}


void *merge_sort(void *param)
{	

	struct data *d = param;
	int thread_part = part++;
	int low = thread_part  * (d->q /4);
	int high = (thread_part + 1) * (d->q /4);

	
	int mid = (low + high)/2;
	

	if(low < high)
	{
		
		merge_sort2(low,mid);
		merge_sort2(mid+1,high);
		merge(low,high);
		}

}


int main()
{
struct data d;

int i,m;
printf("Enter size of array: ");
scanf("%d",&n);

printf("Enter elements into array\n");

for(i=0;i<n;i++)
{
	scanf("%d",&a[i]);
	}

d.p = 0;
d.q = n-1;

pthread_t tid[4];

for(m=0;m<4;m++)
{
d.ti = i;
pthread_create(&tid[i],NULL,merge_sort,&d);
}


for(m=0;m<4;m++)
pthread_join(tid[i],NULL);

merge(0,(d.q/2));
merge(d.q/2,d.q);
merge(0,d.q);

	printf("From Merge Sort\n");		
	for(i=0;i<n;i++)
	printf("%d  ",b[i]);
	printf("\n");
	
	printf("From Quick Sort\n");		
	for(i=0;i<n;i++)
	printf("%d  ",b[i]);
	printf("\n");


return(0);
}






