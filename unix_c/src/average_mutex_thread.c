#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 10
#define NUM_CONSUMERS 2

typedef struct intbuffer {
    int val[MAX_NUMBERS];
    int in, out;
    pthread_mutex_t mutex;
    pthread_cond_t add, rem;
} intbuffer_t;

intbuffer_t data;

void error_exit( char *message, int status)
{
    printf("%s: %s\n", message, strerror( status ) );
    exit( EXIT_FAILURE );
}

void *avg( void *arg )
{
    int id = (int) arg;
    int sum = 0, num = 0, status;

    for(;;)
    {
        status = pthread_mutex_lock( &data.mutex );
        if( status != 0)
            error_exit("pthread_mutex_lock()", status);

        while( data.in == data.out )
        {
            status = pthread_cond_wait( &data.add, &data.mutex );
            if( status != 0)
                error_exit("pthread_cond_wait()", status);
        }

        sum += data.val[data.out];
        data.out = (data.out + 1) % MAX_NUMBERS;

        status = pthread_cond_signal( &data.rem );
        if( status != 0)
            error_exit("pthread_mutex_unlock()", status);

        num++;

        printf("Thread %d - Average of %d equals: %lf\n", id, num, (double)sum / num);
    }

    return( NULL );
}

int main( int argc, char *argv[] )
{
    pthread_T tid;
    char input[32];
    int i, status;

    data.in = 0;
    data.out = 0;

    status =  pthread_mutex_init( &data.mutex, NULL );
    if( status != 0)
        error_exit( "pthread_mutex_init()", status );
    
    status = = pthread_cond_init( &data.add, NULL );
    if( status! = 0)
        error_exit( "pthread_cond_init()", status );
    
    status = = pthread_cond_init( &data.rem, NULL );
    if( status! = 0)
        error_exit( "pthread_cond_init()", status );

    for( i=1; i <= NUM_CONSUMERS; i++)
    {
        status = pthread_create( &tid, NULL, avg, (void*)i );
        if( status != 0)
            error_exit("pthread_create()", status);
    }

    for(;;)
    {
        printf(" input> ");
        fgets(input, sizeof( input ), stdin );

        status = pthread_mutex_lock( &data.mutex );
        if( status != 0 )
            error_exit("pthread_mutex_lock()", status);
        
        // As long as there is no space in the buffer
        while( ( ( data.in +1 ) % MAX_NUMBERS ) == data.out )
        {
            status = pthread_cond_wait( &data.rem, &data.mutex );
            if( status != 0 )
                error_exit("pthread_cond_wait()", status);
        }

        data.val[data.in] = atoi( input );
        data.in = (data.in + 1) % MAX_NUMBERS;

        status = pthread_cond_broadcast( &data.add );
        if( status != 0 )
            error_exit("pthread_cond_broadcast()", status);


        status = pthread_mutex_unlock( &data.mutex );
        if( status != 0 )
            error_exit("pthread_mutex_unlock", status);
    }

    exit(0);
}