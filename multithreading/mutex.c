#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

struct count {
    int counter;
    pthread_mutex_t mutex;
};

void *thFunc(void *);

int main(int argc, char **argv){

    pthread_t thA, thB;
    struct count c;

    //init mutex
    pthread_mutex_init(&c.mutex, NULL);

    c.counter = 0;
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
    struct count *c;

    c = (struct count *) vptr;

    for (i = 0; i<100; i++) {
        pthread_mutex_lock(&c->mutex);
        val = c->counter;
        r = random() % 100;
        usleep(r);
        printf("%ld\t%d", pthread_self(), val + 1);
        c->counter  = val + 1;
        pthread_mutex_unlock(&c->mutex);
        r = random() % 100;
        usleep(r);
    }


}