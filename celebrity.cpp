 #include<stdio.h>
 
 	int main()
 	{
	 
	 int n,i,k,j,c;
 	printf("Enter number of persons");
 	scanf("%d",&n);
 	
 	printf("Enter binary values in the matrix");
 	
 	int a[n][n];
 	
	for(i=0;i<n;++i)
 	for(j=0;j<n;++j)
 	scanf("%d",&a[i][j]);
 	
 	for(i=0,j=1;j<n;)
 	{
 
 	if(a[i][j]==0||i==j)
 	++j;
 	else if(a[i][j]==1)
   	{
    i=j; 
    ++j; 	
    }
}
    for(c=0;c<n && (a[i][c]==0 || i==c )&& (a[c][i]==1||i==c);++c);
    if(c==n)
    printf("Celebrity is %d",(i+1));
	else   
	printf("No celebrity");
}
	 
	 
