#include<stdio.h>

int main()
{
	printf("Enter size of the array");
	int n,i,j,w;
	scanf("%d",&n);
	
	int a[n];
	int b[n];
	
	for(i=0;i<n;++i)
	{
      printf("Enter weights of the item");
	  scanf("%d",&a[i]);
	  printf("Enter cost of the items");
	  scanf("%d",&b[i]);
    }
    int p[n];
	int c[n];
	int d[n];
    
    for(i=0;i<n;++i)
      p[i] = b[i]/a[i];
    
    int max = p[0];

    for(i=n-1;i>=0;--i)
    {
      for(j=0;j<=i;++j)
      {
        if(max<p[j])
        {
        max = p[j];
         }
     }
        p[j] = p[i];
        p[i] = max;
        c[i] = a[j];
		d[i] = b[j] ;
	}
	
	printf("Enter maximum weight");
	scanf("%d",&w);
	int r = w;
	int s=0, l= 0, m = 0;
	
	for(i=n-1;i>=0;i--)
	{
		m = w/c[i];
		s = s + m *c[i];
		l = l + m*d[i];
		w = w % c[i];
		if(w==0 )
		break;	
	}
    printf("The cost of the items %d",l);
	
}
	
		
        
        
    
        
        
        
        
        
    
    
