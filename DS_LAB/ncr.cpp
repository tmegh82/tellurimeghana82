#include<stdio.h>
int main()
{
	int i,j,n,r;
	printf("Enter values of n and r such that n>=r ");
	scanf("%d, %d",&n,&r);
	
	int c[n+1][r+1];
	
	for(i=0;i<=n;++i)
	{
	for(j=0;(j<=i && j<=r);++j)
	{
	if(j==0||j==i)
	c[i][j]= 1;
	else
	c[i][j] = c[i-1][j] + c[i-1][j-1];
    }
}
    printf("The %d c %d valur is %d",n,r,c[n][r]);
  
}




