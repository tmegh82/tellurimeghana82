#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<ctype.h>

sem_t writeblock,mutex;
int data = 0, rcount = 0;


void *reader(void *arg)
{
	  int f;
  	 f = ((int)arg);
	sem_wait(&mutex);
	rcount = rcount + 1;		
	if(rcount==1)
	sem_wait(&writeblock);		
	sem_post(&mutex);
	
	printf("Data read by %d is %d\n",f,data);
	sem_wait(&mutex);
	rcount = rcount - 1;
	if(rcount==0)
	sem_post(&writeblock);
	sem_post(&mutex);

	}


void *writer(void *arg)
{
	   int f;
  	 f = ((int)arg);
	sem_wait(&writeblock);
	++data;
	printf("Data written by %d is %d\n",f,data);
	sleep(1);
	sem_post(&writeblock);

	}

int main()
{
	int i,j;
	pthread_t wtid[3],rtid[3];
	sem_init(&mutex,0,1);
	sem_init(&writeblock,0,1);
	for(i=0;i<=2;i++)
	{
		pthread_create(&wtid[i],NULL,writer,(void *)i);
		pthread_create(&rtid[i],NULL,reader,(void *)i);
		}

	for(j=0;j<=2;j++)
	{
		pthread_join(wtid[j],NULL);
		pthread_join(rtid[j],NULL);
		}

	return(0);

	}




