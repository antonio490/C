/***********************************************
 * Author:     Markus Zahn
 *
 * Title:      Unix-Netzwerkprogrammierung
 *             mit Threads, Sockets und SSL
 *
 * Editorial:  Springer
 *
 ***********************************************/

#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 10

typedef struct intbuffer {
    int val[MAX_NUMBERS];
    int in, out;
} intbuffer_t;

intbuffer_t data;

void *avg( void *arg )
{
    int sum = 0, num = 0;

    for(;;)
    {
        if( data.in != data.out)
        {
            sum += data.val[data.out];
            data.out = ( data.out + 1 ) % MAX_NUMBERS;

            num++;

            printf( "Average from %d is: %lf\n ", num, (double)sum / num ); 
        }
    }

    return ( NULL );
}

int main(int argc, char *arg[] )
{
    pthread_t tid;
    char input[32];
    int status;

    /* Initialize values */
    
    data.in = 0;
    data.out = 0;

    /* Start thread */

    status = pthread_create( &tid, NULL, avg, NULL );
    if( status != 0)
    {
        printf( "Failure in pthread_create(): %s\n", strerror( status ) );
        exit( 1 );
    }

    for(;;)
    {
        /* Get a new value */

        printf( "input> " );
        fgets( input, sizeof( input ), stdin );
        printf("\n");

        /* save value in buffer */

        if( ( ( data.in + 1 ) % MAX_NUMBERS ) != data.out )
        {
            data.val[data.in] = atoi( input );
            data.in = ( data.in + 1 ) % MAX_NUMBERS; 
        }
        else
            printf(" Buffer is full, repeat entry");
    }

    exit( 0 );

}