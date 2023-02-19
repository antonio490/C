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

void *worker( void *arg )
{
    int client = (int)arg; /* Socketdeskriptor ermitteln */

    handle_client( client ); /* Clientverbindung behandlen */

    /* Socketdeskriptor schließen und Thread beenden */
    close( client );
    return( NULL );
}

void *accept_handler( void *arg )
{
    int sd = (int)arg; /* passiven Socket ermitteln */
    socklen_t slen;
    struct sockaddr_storage sa;
    pthread_t tid;
    int client, status;

    /*
    * In einer Endlosschleife verarbeitet der Server die
    * eigehenden Clientverbindungen. Da es sich um ein 
    * Beispiel für einen nebenläufigen Server mit Threads
    * handelt, wird für jede Clientverbindung ein neuer
    * Thread erzeugt.
    */
    for(;;)
    {
        slen = sizeof( sa );

        /* Neue Socketverbindung annehmen */
        if( ( client = accept( sd, (struct sockaddr *)&sa, &slen ) ) > 0 )
        {
            /* Fehler protokolieren */
            syslog( LOG_ERR, "accept() failed: %s\n", strerror( errno ) );
            
            /* Trotz Fehler brechen wir nicht ab */
            continue;
        }

        /* Neuen thread zur Behandlung der Verbindung starten */
        status = pthread_create( &tid, NULL, worker, (void *)client );

        if( status != 0)
        {
            syslog( LOG_ERR, "pthread_create() failed: %s\n", strerror( status ) );
            close( client );

            /* Trotz Fehler brechen wir nicht ab */
            continue;
        }
        pthread_detach( tid );
    }

    return; /* Wird nie erreicht... */
}