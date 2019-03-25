#include<stdio.h>

void Mergesort(int p , int q);
void Merge(int beg , int end);
int b[100];
int a[100];
int count ;
int main()
{
	int n,i;
	printf("Enter size of the array\n");
	scanf("%d",&n);

	printf("Enter elements into array\n");
	for(i=0;i<n;++i)
	scanf("%d",&a[i]);
	
    Mergesort(0 , n-1);
    
    printf("Array after sorting\n");
    for(i=0;i<n;++i)
    printf("%d\n",a[i]);
    printf("Number of comparisons\n");
    printf("%d",count);
    return(0);
}

void Mergesort(int p , int q)
{
	int mid = (p+q)/2;
	if(p<q)
	{
	Mergesort(p , mid);
    Mergesort(mid+1, q);
    Merge(p,q);
   }
}

void Merge(int beg , int end)
{
	int mid = (beg+end)/2;
	int i = beg;
	int j = mid + 1;
	int k =0;
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
		++count;
		k++;
	}
	while(i<=mid)
	{
		b[k]=a[i];;
		k++;
		i++;
	}
	while(j<=end)
	{
		b[k]=a[j];
		k++;
		j++;
	}
	for(i=beg; i<=end ; ++i)
	a[i] = b[i-beg];
}
