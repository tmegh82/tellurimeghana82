#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int n;

int c[50];

struct data
{
	int p;
	int q;
	//int a[50];
	//int c[50];
	};


void Quick_Sort2(int p, int q)
{

	int pivot,i,j,temp;

	if(p<q)
	{
		pivot = p;
		i = p;
		j = q;
	
		while(i<j)
		{
			while((c[i] <= c[pivot]) && i<q)
				i++;
			while(c[j] > c[pivot])
				j--;
			if(i<j)
			{
				temp = c[i];
				c[i] = c[j];
				c[j] = temp;
			}
		}
	
		temp = c[pivot];
		c[pivot] = c[j];
		c[j] = temp;
		Quick_Sort2(p,j-1);
		Quick_Sort2(j+1 , q);		
	

	}
	

}


void *Quick_Sort(void *param)
{

	struct data *d = param;
	int i,j,pivot,temp,first,last;
	first = d->p;
	last = d->q;

	if(d->p < d->q)
	{
		pivot = first;
		i = first;
		j = last;
	
		while(i<j)
		{
			while((c[i] <= c[pivot]) && i<last)
				i++;
			while(c[j] > c[pivot])
				j--;
			if(i<j)
			{
				temp = c[i];
				c[i] = c[j];
				c[j] = temp;
			}
		}
	
		temp = c[pivot];
		c[pivot] = c[j];
		c[j] = temp;
		Quick_Sort2(first,j-1);
		Quick_Sort2(j+1 , last);		

	}

}



int main()
{
struct data d;

int i;
printf("Enter size of array: ");
scanf("%d",&n);

printf("Enter elements into array\n");

for(i=0;i<n;i++)
{
	scanf("%d",&c[i]);
}

d.p = 0;
d.q = n-1;

pthread_t tid;

pthread_create(&tid,NULL,Quick_Sort,&d);

pthread_join(tid,NULL);

	printf("From Quick Sort:\n");
	for(i=0;i<n;i++)
	printf("%d  ",c[i]);
	printf("\n");
return(0);
}
