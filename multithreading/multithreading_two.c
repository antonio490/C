#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_func(void *value){

    printf("thread_func execution\n");

    int *num = (int *) value;

    printf("value passed to thread_func is: %d \n", *num);

    return NULL;
}

// gcc -o multithreading multithreading_two.c -lpthread

int main(int argc, char **argv){

    pthread_t thread;

    printf("main execution\n");

    int num = 656;

    pthread_create(&thread, NULL, thread_func, &num);

    pthread_join(thread_func, NULL);

    return EXIT_SUCCESS;
}