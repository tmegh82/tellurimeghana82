#include<stdio.h>


void cofactor(int N,int A[N][N], int temp[N][N], int p, int q,int n)
{
	int i=0,j=0,row,column;
	
	for(row=0; row<N; row++)
	for(column=0; column<N; column++)
	{
		if(row!=p && column!=q)
		{
			temp[i][j++] = A[row][column];	
			if(j==N-1)
			{	
				i++;
				j = 0;
			}
		}
	}
}


int determinant(int N,int A[N][N], int n)
{

	int temp[N][N];
	int sign = 1,D = 0,i;

	if(n==1)
	return(A[0][0]);

	for(i=0;i<n;i++)
	{
		cofactor(N,A,temp,0,i,n);
		D = D + (sign * A[0][i] *(determinant(N,temp,n-1)));	

		sign = -sign;

	}
return(D);
}


void adjoint(int N,int A[N][N],int adj[N][N])
{
	int i,j,sign;
	int count = 0;

	if(N==1)
	{
		adj[0][0] = 1;
		return;
	}

	int temp[N][N];
	
	for(i=0;i<N;i++)
	for(j=0;j<N;j++)
	{
		cofactor(N,A,temp,i,j,N);
		sign = ((i+j)%2==0) ? 1:-1;	
		adj[i][j] = (sign)*(determinant(N,temp,N-1));

	}
}


void display(int N,int A[N][N])
{
int i,j;
	for(i=0;i<N;i++)
	{ 
	for(j=0;j<N;j++)
	{
		printf("%d ",A[i][j]);
		
	}
	printf("\n");
	}

}

int inverse(int N, int A[N][N], float result[N][N])
{
	int det = determinant(N,A,N);
	int adj[N][N],i,j;

	if(det == 0)
	{
		printf("Singular Matrix");
		return(0);
	}

	else
	{
		adjoint(N,A,adj);
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			result[i][j] = (adj[i][j])/(float)det;
		}
	}
		
		printf("Inverse Matrix is :");
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			printf("%f ",result[i][j]);
			printf("\n");
		}
		return(1);
}



int main()
{
int N,i,j;
printf("Enter the size of matrix:");
scanf("%d",&N);

int a[N][N];

for(i=0;i<N;i++)
for(j=0;j<N;j++)
scanf("%d",&a[i][j]);

printf("Given matrix is :");	
display(N,a);

/*printf("Adjoint of a matrix\n");

	int adj[N][N];
	adjoint(N,a,adj);
	display(N,adj);
*/
	float result[N][N];
	int t = inverse(N,a,result);
	
return(0);
}







