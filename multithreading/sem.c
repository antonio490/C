
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct{
    int counter;
    sem_t sem;
}Count;

void *thFunc(void *);

int main(int argc, char **argv){

    pthread_t thA, thB;
    Count c;

    sem_init(&c.sem, 0, 1);
    srandom(1000);

    pthread_create(&thA, NULL, &thFunc, &c);
    pthread_create(&thB, NULL, &thFunc, &c);

    pthread_join(thA, NULL);
    pthread_join(thB, NULL);

    exit(0);

}

void *thFunc(void *vptr){
    int i, val;
    long r;
    Count* c;

    c = (struct count*) vptr;

    for(i=0; i<100; i++){

        sem_wait(&c->sem);
        val = c->counter;
        r = random() % 100;
        usleep(r);
        printf("thread ID: %ld\t value: %d", pthread_self(), val + 1);
        c->counter = val + 1;
        sem_post(&c->sem);
        r = random() % 100;
        usleep(r);
    }
}

