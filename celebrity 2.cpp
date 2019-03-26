#include<stdio.h>
#include<stdlib.h>
int main()
{
int n,i,j,k;
printf("Enter number of persons");
scanf("%d",&n);
int a[n][n];
srand(time(NULL));
for(i=0;i<n;++i)	
for(j=0;j<n;++j)
a[i][j]= rand()%1;

int x = rand()%n;
for(i=0;i<n;++i)
{
a[x][i]=0;
a[i][x]=1;
}
for(i=0;i<n;++i)
{
	for(j=0;(a[i][j]==0||i==j);++j)
	if(j==n)
	for(k=0;k<n && a[k][i]==1 || i==k ;++k)
	{
	
	if(k==n)
	{
	
	printf("%d is a celebrity",i+1);
	break;
}
	else
	printf("No celebrity");
}
}

}

	

