
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#include <malloc.h>

/*

Thread = Lightweight process
-- Program counter
-- Register set
-- Stack space

Object: Parallelism

-- Context switching is faster.
-- Thread creation is much faster.
-- Termination is easier.
-- Communication between threads is faster.

*/

void *thFunc(void *argp){

    sleep(1);
    printf("thFunc execution\n");
    return NULL;

}

int main(){

    pthread_t th;
    pthread_create(&th, NULL, thFunc, NULL);
    pthread_join(th, NULL); 
    exit(0); 
}