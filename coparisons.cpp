#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,s1 = 0,s2 =0,j,counta =0,countb=0,m,k,key;
	float a1,a2;
	time_t t;
	srand((unsigned)time_t(&t));
	for(n=10;n<10000;n=n*10)
	{
	
	int a[n];
	for(j=0;j<1000;++j)
	{
		a[0]= rand()%100;
		for(k=0;k<n;++k)
		
			a[k]= a[k-1]+rand()%100;
			key = rand()%100;
			for(m = 0;m<n;++m)
			if(a[m]==key)
			{
			counta++;
			break;
		}
		int b=0, e=n-1,m;
		while(b<=e)
		{
			m = (b+e)/2;
			if(key==a[m])
			{
			
			countb++;
			break;
		}
		else if(key<a[m])
		e = m-1;
		else
		b = m+1;
		countb++;
	}

	s1 = s1 + counta;
	s2 = s2+countb;
}
	a1 = s1/1000.0;
	a2 = s2/1000.0;
	printf("%d \t    %g\tvvv%g\t\n",n,a1,a2);
}
return(0);
}
