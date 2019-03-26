#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>


void bubble_sort(int count_arg , ...)
{
	int i,j,temp;
	int n  = count_arg;
	int ar[n];

	 va_list list;
 	va_start(list, count_arg);

	  for(j=0; j<n; j++)
	   {
	     //printf("%d", va_arg(list, int));
		ar[j] = va_arg(list, int);
   		}

	va_end(list);

	
	printf("Input Array\n");

	for(i=0;i<n;i++)
	{
		printf("%d ",ar[i]);
		
		}
	printf("\n");

	
	
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=n-2-i;j++)
		{
			if(ar[j+1] < ar[j])
			{
				temp = ar[j+1];
				ar[j+1] = ar[j];
				ar[j] = temp;
				}
	
			}
		}
	
	printf("After sorting\n");

	for(i=0;i<=n-1;i++)
	printf("%d ",ar[i]);
	printf("\n");


	}





int main()
{
	bubble_sort(3,7,1,2);
	bubble_sort(5,9,1,3,0,7);


	}

