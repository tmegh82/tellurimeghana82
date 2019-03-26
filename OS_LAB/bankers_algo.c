#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>

sem_t counter[3];
sem_t mutex;
//sem_t customer[100];

int l_balance[100];
int g_balance;

struct count
{
	int status;
	int cust_id;
	};

struct count c[3];

struct queue
{
	int front;
	int rear;
	int q[100];
	};

struct queue a;

int customer[100];




void counters(int x, int y)
{
	printf("Hello\n");

	if(x%2==0)
	{
		sem_wait(&mutex);
		l_balance[x] = l_balance[x] + 2000;
		printf("%d credietd 2000 rupees in his account\n",x);
		g_balance = g_balance + 2000;
		printf("Global balance is %d\n",g_balance);
		c[y].status = 0;
		c[y].cust_id = -1;
		sem_post(&mutex);
		printf("%d is done with counter %d \n",x,y);
		sem_post(&counter[x]);
		}
	
	else
	{
		sem_wait(&mutex);
		if(l_balance[x] - 500 >= 500)
		{
			l_balance[x] = l_balance[x] - 500;
			printf("%d debited 500 rupees in his account\n",x);
			printf("Now balance is %d\n",l_balance[x]);
			g_balance = g_balance - 500;
			printf("Global balance is %d\n",g_balance);
			c[y].status = 0;
			c[y].cust_id = -1;
			printf("%d is done with counter %d \n",x,y);
			sem_post(&mutex);
			sem_post(&counter[x]);
			}

		}

	return;
	}


void *banker(void *arg)
{
	
	int f,x;
	
  	 f = ((int)arg);
	//printf("Customer %d ",f);

	int current_status;
	int i,flag,inqueue = 0;
	//sem_wait(&mutex);

	while(customer[f]!=1)
	{
	//sem_wait(&mutex);
		//printf("Hello\n");
		flag = 0;
		for(i=0;i<3;i++)
		{
			if(c[i].status==0)
			{
				//sem_wait(&mutex);
				c[i].status = 1;
				current_status = i;
				sem_wait(&counter[i]);
				flag = 1;
				break;
			}
		 
		}
		sem_wait(&mutex);
	
		if(flag==1)
		{
			if(a.front==-1 && a.rear == a.front)
			{
				
				x = f;
				customer[f] = 1;
				c[current_status].cust_id = x;
				printf("Counter %d is free and lock acquired by %d \n",current_status,f);
				}
			else
			{
				
			
				/*a.rear = a.rear + 1;
					//if(a.front==-1)
				//a.front = a.front + 1;
				a.q[a.rear] = f;
					*/
				
				
					x = a.q[a.front];
					a.front = a.front + 1;
					c[current_status].cust_id = x;
					customer[x] = 1;
					//printf("%d added to queue\n",f);
					printf("%d acquired lock on counter %d\n",x,current_status);
			}
			
			sem_post(&mutex);
			counters(x,current_status);
				
		}
		else
		{	
			if(inqueue!=1)
			{
				a.rear = a.rear + 1;
				if(a.front==-1)
				a.front = a.front + 1;
				a.q[a.rear] = f;
				printf("%d added to queue\n",f);
				inqueue = 1;
			}
			sem_post(&mutex);
		}
}	
	
	pthread_exit(0);
								
}


int main()
{	
	
	a.front = -1;
	a.rear = -1;
	
	int i,n,j;

	for(i=0;i<3;i++)
	{	
		c[i].status = 0;
		}
	
	sem_init(&mutex,0,1);

	for(i=0;i<3;i++)
	sem_init(&counter[i],0,1);
	
	printf("Enter number of customers\n");
	scanf("%d",&n);
	
	pthread_t tid1[n];
	
	for(i=0;i<n;i++)
	{
		customer[i] = 0;
		l_balance[i] = 1000;
		}

	g_balance = 1000 * n;

	for(i=0;i<n;i++)
	{
		pthread_create(&tid1[i],NULL,*banker,(void *)i);

		}
	for(i=0;i<n;i++)
	{
		pthread_join(tid1[i],NULL);
		printf("Exited\n");	
		}
return(0);

	}









