#include<stdio.h>
#include<string.h>

int main()
{
	
	int n,count,i,j,k,p,nb;
	int d[50];
	int pos[50];
	int b[50];

	memset(pos,-1,sizeof(memset));

	printf("Enter the size of data : ");
		scanf("%d",&n);

	printf("Enter data in the form of 0's and 1's :");
	
	for(i=0;i<n;i++)
	scanf("%d",&d[i]);
	
	count = 1;	
	p = -1;
	j = 0;
	i = 0;
	while(i<n)
	{
		if(d[i]==1)
		{
			b[j] = d[i];

			for(k=i+1;k<n && d[k] == 1 && count<5;k++)
			{
				++j;
				b[j] = d[k];
				++count;
				if(count==5)
				{
					++j;
					b[j] = 0;
					pos[++p] = j;
					}
				i = k;	
				}
			++i;
			++j;
			}
	
		else
		{
			b[j] = d[i];
			++j;
			++i;			
			}
	}

	nb = j;
	printf("Data after stuffing is :");

	for(i=0;i<nb;i++)
	printf("%d ",b[i]);
	printf("\n");

	j = 0;

	printf("Data received by Receiver after Destuffing is:");
		for(i=0;i<nb;i++)
			if(i!=pos[j])
			   printf("%d ",b[i]);
			else
			{
			    ++j;
				}
	
	printf("\n");

return(0);
}









