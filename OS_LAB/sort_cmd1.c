#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int n = argc - 2;
	int temp;
	
	int ar[n];
	
	
	printf("Input array is: ");
	
	for(int i=0;i<n;i++)
		printf("%c",*argv[i+2]);
	printf("\n");

	for(int i=0;i<n;i++)
		ar[i] = atoi(argv[i + 2]);

	for(int i=0; i<=n-1;i++)
	{
		for(int j=0; j<=n-2-i; j++)
		{
			if(ar[j+1] < ar[j])
			{
				temp = ar[j+1];
				 ar[j+1] = ar[j];
				 ar[j] = temp; 
				}		
		}	


	}


	printf("Sorted array is: ");

	for(int i=0;i<=n-1;i++)
	printf("%d",ar[i]);

	printf("\n");
}


