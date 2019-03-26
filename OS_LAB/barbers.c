define CHAIRS 5



typedef int semaphore;



semaphore customers = 0;

semaphore barbers=0;

semaphore mutex=1;

int waiting=0;



void barber(void)

{

 while (TRUE) {

  P(customers);          /*go to sleep if no customers*/

  P(mutex);

  waiting=waiting-1;

  V(barbers);

  V(mutex);

  cut_hair();

 }

}



void customer(void)

{

 P(mutex);

 if (waiting lessthan CHAIRS) {

  waiting=waiting+1;

  V(customers);

  V(mutex);

  P(barbers);

  get_haircut();

 } else {

    V(mutex);

 }

}




#define CHAIRS 5                /* # chairs for waiting customers */
typedef int semaphore;          /* use your imagination */
semaphore customers = 0;        /* # of customers waiting for service */
semaph
ore barbers = 0;          /* # of barbers waiting for customers */
semaphore mutex = 1;            /* for mutual exclusion */
int waiting = 0;                /* customer are waiting (not being cut) */
void barber(void)
{
    while (TRUE) {
        down(&c
ustomers);       /* go to sleep if # of customers is 0 */
        down(&mutex);           /* acquire access to "waiting' */
        waiting = waiting 
-
 1;  /* decrement count of waiting customers */
        up(&barbers);           /* one barber is now read
y to cut hair */
        up(&mutex);             /* release 'waiting' */
        cut_hair();             /* cut hair (outside critical region */
    }
}
void customer(void)
{
    down(&mutex);               /* enter critical region */
    if (waiting < CH
AIRS) {     /* if there are no free chairs, leave */
        waiting = waiting + 1;  /* increment count of waiting customers */
        up(&customers);         /* wake up barber if necessary */
        up(&mutex);             /* release access to 'waiting'
 */
        down(&barbers);         /* go to sleep if # of free barbers is 0 */
        get_haircut();          /* be seated and be served */
    } else {
        up(&mutex);             /* shop is full; do not wait */
    }
}







