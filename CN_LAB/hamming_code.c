#include<stdio.h>

int main()
{
	int nd = 4,d[50],a[50],i,j,k,nh,p,m,c,h[100],parity[50],pos,n;
	int e[100];

	printf("Enter the 4 data bits: ");

	for(i=0;i<nd;i++)
	scanf("%d",&a[i]);
	
	for(i=0;i<nd;i++)
	d[nd-1-i] = a[i];
	

	i = 1;
	k = 0;

	while(k>-1)
	{
		if(i<(nd+1))
		{
			++k;
			i = i*2;
			}
		else
		break;
	}
	
	printf("Number of parity bits required is %d \n",k);
	
	nh = nd + k;
        
	int sum[k];

	sum[0] = d[0] + d[1] + d[3];
	sum[1] = d[0] + d[2] + d[3];
	sum[2] = d[1] + d[2] + d[3];

	for(i=0;i<k;i++)
	{
		if(sum[i]%2 == 0)
			parity[i] = 0;
		else
			parity[i] = 1;
		}

	printf("Parity bits are: ");
	for(i=0;i<k;i++)
	printf("%d ",parity[i]);

	p = 1;
	m = 0;
	c = 0;

	for(i=1;i<=nh;i++)
	{
		if(i==p)
		{
		   h[i] = parity[m];
			++m;
			p = p*2;
			}
		else
		{
			h[i] = d[c];	
			++c;
			}
		}

	printf("Generated parity code is : ");
	for(i=nh;i>=1;i--)
	printf("%d",h[i]);
	printf("\n");

//printf("Value of nh is %d",nh);
	printf("Enter 1 if you want to change the data bits else 0:");
	scanf("%d",&n);
	
	if(n==1)
	{
		printf("Enter the position of the data position you want to change: ");
		scanf("%d",&pos);
		
		if(h[nh - pos + 1]==1)
			h[nh-pos+1] = 0;
		else  if(h[nh - pos + 1]==0)
			h[nh - pos + 1] = 1; 
		else
			printf("Error\n");

		
		sum[0] = h[3] + h[5] + h[7] + h[1]; 
		sum[1] = h[3] + h[6] + h[7] + h[2];
		sum[2] = h[5] + h[6] + h[7] + h[4];
	
		for(i=0;i<k;i++)
		   e[i] = 0;

		for(i=0;i<k;i++)
		{
			if(sum[i]%2 == 0)
				e[i] = 0;

			if(sum[i]%2 == 1)
				e[i] = 1;
			}
		
		
		printf("Error Detected \n");
		printf("Error is in position (in data bits): ");

		for(i=k-1;i>=0;i--)
			printf("%d ",e[i]);
		printf("\n");
		
		}

	else
	{
		int count = 0;

		sum[0] = h[3] + h[5] + h[7]; //013
		sum[1] = h[3] + h[6] + h[7];//023
		sum[2] = h[5] + h[6] + h[7];//123            1234567
//1010
//0123 == 2456
//1234567
//1011010
			
		for(i=0;i<k;i++)
			e[i] = 0;
					
		for(i=0;i<k;i++)
		{
			if(sum[i]%2 == 0 && parity[i]!=0)
			{
				count = 1;
				e[i] = 1;
					}
			if(sum[i]%2 == 1 && parity[i]!=1)
			{
				e[i] = 1;
				count = 1;
			}
		}
		
	/*
		for(i=0;i<k;i++)
			printf("%d ",e[i]);
		printf("\n");*/
	
	if(count==0)
		printf("No Error Detected as no error bit is 1 \n");

	
		}
	return(0);
}

