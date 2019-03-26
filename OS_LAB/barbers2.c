#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#define CHAIRS 5

sem_t barber_sleeping, mutex, barber;
int waiting = 0;

void *barbers(void *arg)
{
	
	int f;
  	 f = ((int)arg);

	if(waiting<=0)
	{	
		sem_wait(&barber_sleeping);
		printf("Barber is sleeping\n");
		}
	else
	{	
		sem_wait(&mutex);	
		waiting = waiting - 1;
		sem_post(&barber);
		sem_post(&mutex);
		printf("Barber is done with %d hair cut\n",f);
	}
	sleep(1);

}


void *customer(void *arg)
{
	int f;
  	 f = ((int)arg);

	sem_wait(&mutex);
	if(waiting<CHAIRS)
	{
		waiting = waiting + 1;		
		sleep(1);
		sem_post(&barber_sleeping);
		//sleep(1);
		sem_post(&mutex);
		sem_wait(&barber);
		printf("%d is doing his hair cut\n",f);
	}

	else
	{
		sem_post(&mutex);
		printf("Customer %d exits",f);
		pthread_exit(0);
		}
	
}


int main()
{
	int n;
	int i;

	sem_init(&barber_sleeping, 0, 1);
	sem_init(&mutex, 0, 1);	
	sem_init(&barber,0, 1);
	
	printf("Enter number of customers you want :");
	scanf("%d",&n);
	
	pthread_t tid1[n+1];
	pthread_t tid2[n];
	pthread_create(&tid1[n],NULL,*barbers,NULL);
//	sleep(1);

	for(i=0;i<n;i++)
	{
		pthread_create(&tid2[i],NULL,*customer,(void *)i);
		sleep(1);
		pthread_create(&tid1[i],NULL,*barbers,(void *)i);
	//	pthread_create(&tid2[i],NULL,*customer,(void *)i);
		}
//	pthread_create(&tid1[n],NULL,*barbers,(void*)i);
	for(i=0;i<n;i++)
	{
		pthread_join(tid1[i],NULL);
		pthread_join(tid2[i],NULL);
		}

	}


