#include<stdio.h>

int a[100];
void Quicksort(int p , int q);
int Partition(int beg , int end);
int count;

int main()
{
	int n , i;
	
	printf("Enter size of the array\n");
    scanf("%d",&n);
    
    printf("Enter elements into array\n");
    for(i=0; i<n ; ++i)
    scanf("%d",&a[i]);
    
    Quicksort(0,n-1);
    
    printf("Sorted array\n");
    
    for(i=0;i<n;++i)
    printf("%d\n",a[i]);
    
    printf("No of comparisons is %d\n",count);
    return(0);
}

void Quicksort(int p , int q)
{
	int j;
	if(p<q)
	{
		j = Partition(p,q);
		Quicksort(p,j-1);
		Quicksort(j+1 , q);
	}
}

int Partition(int beg , int end)
{
	int temp;
	int pivot = a[beg];
	int i =beg;
	int j = end;
	while(i<=j)
	{
		while((a[i]<=pivot) && (i<=end))
		{
	    count++;
	    i++;
	    }
		while((a[j]>pivot )&& (j>=beg))
		{
	     count++;
		j--;
	    }
		//swapping
		if(i<j)
		{
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	   }
	}
	temp = a[beg];
	a[beg] = a[j];
	a[j] = temp; 
	
	return(j);
}
