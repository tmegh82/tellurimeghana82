   #include<stdio.h>

struct queue
{
	int a[50];
	int b[50];
	int c[50];
	int f0end;
	int r0end;
	int f1end;
	int r1end;
	int f2end;
	int r2end;
};

struct queue deletion(struct queue s1 ,int q);
struct queue insertion(struct queue s1 , int v , int x);
void Toprint(struct queue s1);


int main()
{
	struct queue s;
	s.f0end = -1;
	s.r0end = -1;
	s.f1end = -1;
	s.r1end = -1;
	s.f2end = -1;
	s.r2end = -1;
	
	int i, b,n,k,j;
	 
	 printf("\nEnter size of input provided less 150\n");
	 scanf("%d",&n);
	 
	 int p[n];
	 
printf("Enter 0 for business; and 1 for women, children, disabled; 2 for general\n");

for(i=0;i<n;++i)
scanf("%d",&p[i]);

printf("We need to classify them\n");

for(i=0;i<n;++i)
{
	if(p[i]==0)
	{
	b = 0;
	s = insertion(s,(i+1),b);
    }
	else if(p[i]==1)
	{
		b = 1;
		s = insertion(s,(i+1),b);
	}
	
	else
	{
		b =2;
		s =insertion(s,(i+1),b);
	}
		
	}
	
	printf("Enter anyvalue or -1 to terminate\n");
    scanf("%d",&k);
    
	while(k!=-1)
	{
		
	printf("Enter 110 for deletion of business plp ; 111 for 2nd category ; 112 for 3rd category; 12 for printing\n");
	scanf("%d",&j);
	
	if(j==110 || j==111 || j==112)
	
        s = deletion(s,j);
    
    else if(j==12)
    Toprint(s);
    
    else
    printf("Wrong input\n");
    
    printf("Enter anyvalue or -1 to terminate\n");
    scanf("%d",&k);
	 
	
}
}




struct queue insertion(struct queue s1 , int v , int x)
{
	switch(x)
	{
	case 0 :
		
		if(s1.f0end ==-1)
		{
		 s1.f0end = s1.f0end + 1;
		 s1.r0end = s1.r0end + 1;	
		}
		else
		s1.r0end = s1.r0end + 1;
		
		s1.a[s1.r0end] = v;
		return(s1);
		break;
	
	
	case 1:
			if(s1.f1end == -1)
		{
		 s1.f1end = s1.f1end + 1;
		 s1.r1end = s1.r1end + 1;	
		}
		else
		s1.r1end = s1.r1end + 1;
		
		s1.b[s1.r1end] = v;
		return(s1);
		break;
		
	case 2:
	
		if(s1.f2end == -1)
		{
		 s1.f2end = s1.f2end + 1;
		 s1.r2end = s1.r2end + 1;	
		}
		else
		s1.r2end = s1.r2end + 1;
		
		s1.c[s1.r2end] = v;
		return(s1);
		break;
		
		default:
			printf("Wrong Input\n");
			
	}
}
struct queue deletion(struct queue s1 ,int q)
{
	switch (q)
	{
		case 110 :
			if(s1.r0end == -1)
			printf("No element to delete\n");
			else
			s1.f0end = s1.f0end +1;
			break;
			
	case 111:
		if(s1.r1end == -1)
			printf("No element to delete\n");
			else
			s1.f1end = s1.f1end +1;
			break;
	case 112:
		if(s1.r2end == -1)
			printf("No element to delete\n");
			else
			s1.f2end = s1.f2end +1;
			break;
	default :
		printf("Wrong input\n");
}
return(s1);		
}

void Toprint(struct queue s1)
{
	printf("Business class\n");
	
	for(int i=s1.f0end;i<=s1.r0end;++i)
	 printf("%d\n",s1.a[i]);
	 
	 printf("Women/Children/Disability\n");
	 
	 for(int i=s1.f1end;i<=s1.r1end;++i)
	 printf("%d\n",s1.b[i]);
	 
	 printf("General Class\n");
	 
	 for(int i=s1.f2end;i<=s1.r2end;++i)
	 printf("%d\n",s1.c[i]);
	 
	 
}

	
