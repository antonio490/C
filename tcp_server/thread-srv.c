#include <errno.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <syslog.h>
#include <unistd.h>

#include "server.h"

void sigcatcher( void )
{
    int status, signal;
    sigset_t sigset;

    /* signalmaske initialisieren */
    sigemptyset( &sigset );
    sigaddset( &sigset, SIGTERM );

    for(;;)
    {
        sigwait( &sigset, &signal );
        if( signal == SIGTERM )
            break;
    }

    return;
}