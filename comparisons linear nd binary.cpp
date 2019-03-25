  #include<stdio.h>
#include<stdlib.h>
int main()
{
    time_t t;
	srand((unsigned )time_t(&t));
	int i,j,k,counta = 0,countb = 0,key,s1,s2;
	float avg1;
	float avg2;
	
	for(i=10;i<=10000;i = i*10)
	{
	int a[i];
	
	for(j=0;j<1000;++j)
	{
		a[j] = rand()%100;
     }
     key = a[rand()%1000];
    for(k=0;k<1000;++k)
    {
    	if(key==a[k])
    	{
		break;
		counta++;
        }
	counta++;
	int beg = 0;
	int end = i-1;
	int mid;
	
	while(beg<=end)
	{
		mid = beg + end;
		if(a[mid]==key)
		{
		countb++;
		break;
	   }
	   else if(a[beg]<key)
	   beg = mid + 1;
	   else
	   end = mid - 1;
	   
	   countb++;
}
}
}
  s1 = counta;
  s2 = countb;
  avg1 = counta/1000.0;
  avg2 = countb/1000.0;
  printf("\nAverge comparisons of linear search is %f\n",avg1);
  printf("Average comparisons if binary search is %f\n",avg2);
}
