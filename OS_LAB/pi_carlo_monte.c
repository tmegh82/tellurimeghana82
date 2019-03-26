#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>
#define total_count 10000055
int rem_iteration,t;
int iteration;

struct data
{
	int c;
	int s;
	int ti;
};

int m = 0;
double pi[50];

void *pi_calc(void *param)
{
		struct data *a = param;
		int k = a->ti;
		double x;
		double y,d;	
		int j;
		int upper = 1, lower = 0;
		++m;
	//printf("m is %d :",m);
		
	if(rem_iteration!=0 && k==t-1)
	{
		for(j=0;j<rem_iteration;j++)
		{
			x = (double)(rand()%(upper - lower + 1))+lower;
			y = (double)(rand()%(upper - lower + 1))+lower;
			//d = sqrt((x*x) + (y*y));
			d = x*x + y*y;
			if(d<=1)
			{
				a->c = a->c + 1; 		
			}  	
			a->s = a->s + 1;  	
		}
	}

	else
	{
		for(j=0;j<iteration;j++)
		{
			x = (double)(rand()%(upper - lower + 1))+lower;
			y = (double)(rand()%(upper - lower + 1))+lower;
			//d = sqrt((x*x) + (y*y));
			d = x*x + y*y;
			if(d<=1)
			{
				a->c = a->c + 1; 	
					//printf("c_count: %d\n",a->c);
			}  	
			a->s = a->s + 1; 	
		}
	}
		//printf("s_count: %d\n",a->s);
		//printf("c_coun: %d\n",a->c);
		
	pthread_exit(0);	
		
		
	}


int main()
{
	int i,j;
	double final_pi;
	
	struct data d;

	d.c = 0;
	d.s = 0;

	printf("Enter number of threads:");
	scanf("%d",&t);

	iteration = total_count/t;
	rem_iteration = total_count%t;

	if(rem_iteration!=0)
		t = t + 1;

	pthread_t tid[t];
		
	for(i=0;i<t;i++)
	{
		d.ti = i;
		pthread_create(&tid[i],NULL,pi_calc,&d);	
		}

	for(j=0;j<t;j++)
	pthread_join(tid[j],NULL);

		printf("s_count: %d\n",d.s);
		printf("c_coun: %d\n",d.c);
	
	final_pi = (double)(4*d.c)/d.s;

	printf("Final Estimation of pi: %f\n",final_pi);
	
	return(0);

	}








