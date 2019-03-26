#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#define CHAIRS 3

sem_t ta_sleeping, mutex, ta;
int waiting = 0;

void *tas(void *arg)
{
	
	int f;
  	 f = ((int)arg);

	if(waiting<=0)
	{	
		sem_wait(&ta);
		printf("TA is sleeping\n");
		}
	else
	{	
		sem_wait(&mutex);	
		waiting = waiting - 1;
		sem_post(&ta);
		sem_post(&mutex);
		sleep(2);
		printf("TA is done with %d's assignments\n",f);
	}
	sleep(1);

}


void *student(void *arg)
{
	int f;
  	 f = ((int)arg);

	sem_wait(&mutex);
	if(waiting<CHAIRS)
	{
		waiting = waiting + 1;		
		//sleep(1);
		sem_post(&ta_sleeping);
		sleep(1);
		sem_post(&mutex);
		sem_wait(&ta);
		printf("%d is getting his assignments evaluated\n",f);
	}
	else
	{
		sem_post(&mutex);
		}
	
}


int main()
{
	int n;
	int i;

	sem_init(&ta_sleeping, 0, 1);
	sem_init(&mutex, 0, 1);	
	sem_init(&ta,0, 1);
	
	printf("Enter number of students  you want :");
	scanf("%d",&n);
	
	pthread_t tid1[n+1];
	pthread_t tid2[n];
	pthread_create(&tid1[n],NULL,*tas,NULL);
//	sleep(1);
	for(i=0;i<n;i++)
	{
		pthread_create(&tid2[i],NULL,*student,(void *)i);
		sleep(2);
		pthread_create(&tid1[i],NULL,*tas,(void *)i);
	//	pthread_create(&tid2[i],NULL,*customer,(void *)i);
		}
//	pthread_create(&tid1[n],NULL,*barbers,(void*)i);
	for(i=0;i<n;i++)
	{
		pthread_join(tid1[i],NULL);
		pthread_join(tid2[i],NULL);
		}

	}


