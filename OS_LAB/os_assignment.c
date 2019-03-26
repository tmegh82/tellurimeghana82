#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

/*
Sequence of Events:
Inorder to pass through the critical section driver has to walk to bowl and put a rock in it if it is empty.
else
wait till it is empty
Only after putting a rock he can enter the critical section.
After completion of critical section he has to remove the rock from the bowl and clear the line.
*/

sem_t mutex;
sem_t rock;

struct queue
{
	int a[100];
	int head;
	int rear;
	};

struct queue q;

int driverstatus[50];
int n;
int bowlstatus = 1;

void *runner(void *param)
{
	int f = ((int)param);		
	int x;
	printf("Driver no is %d\n",f);
	
	if(f%2==0)
		printf("Driver %d wants go down line of Peru Circular Track\n",f);
	else
		printf("Driver wants go down line of Bolivilia Circular Track\n");
	sem_wait(&mutex);
	if(bowlstatus==0)
	{
		printf("There is already a rock in the bowl\n");
		if(q.head==-1 && q.rear==-1)
		{
			++q.head;
			q.a[q.head] = f;
			++q.rear;		
			}
		else
		{
			++q.rear;
			q.a[q.rear] = f;
			}
		printf("Driver %d added to queue\n",q.a[q.rear]);
	}

	sem_wait(&rock);
	if(q.head==-1)
	{
		x = f;
		}
	else
	{
		if(q.head == q.rear)
		{
			x = q.a[q.head];
			q.head = -1;
			q.rear = -1;
			}
		else
		{
			x = q.a[q.head];
			q.head = q.head + 1;
		}
	}

	driverstatus[x] = 1;
	printf("Bowl is free, Driver %d put a Rock in the bowl\n",x);
	bowlstatus = 0;
	printf("Train %d went through the circular line safely\n",x);
	sem_post(&rock);
	sem_post(&mutex);
	printf("%d Removed the rock from the bowl\n",x);

}



int main()
{
	int i;

	printf("Enter number of trains that enter the place usually:");
	scanf("%d",&n);

	sem_init(&mutex,0,1);
	sem_init(&rock,0,1);

	for(i=0;i<n;i++)
	driverstatus[i] = 0;
	
	pthread_t tid[n];
	
	for(i=0;i<n;i++)
	pthread_create(&tid[i], NULL, runner, (void *)i);

	for(i=0;i<n;i++)
	pthread_join(tid[i],NULL);

	return(0);

	}


