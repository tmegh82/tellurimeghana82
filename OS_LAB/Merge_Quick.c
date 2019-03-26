#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int n;
int a[50];
int b[50];
int low,high;

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
	while(j<=mid)
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
int i;
printf("Enter size of array: ");
scanf("%d",&n);

printf("Enter elements into array\n");

for(i=0;i<n;i++)
scanf("%d",&a[i]);


low = 0;
high = n-1;

pthread_t tid;
pthread_attr_t attr;
pthread_attr_init(&attr);

pthread_create(&tid,&attr,merge_sort,NULL);

pthread_join(tid,NULL);

for(i=0;i<n;i++)
printf("%d  ",b[i]);
printf("\n");

return(0);
}




