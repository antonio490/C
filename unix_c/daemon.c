#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <syslog.h>


void daemin_init( const char *program, int facility ){

    pid_t pid;
    int i, sigs[] = { SIGHUP, SIGINT, SIGQUIT, SIGTSTP, SIGTTIN, SIGTTOU };
    struct sigaction action;

    /* 1. Ignore signals and create an own terminal */

    action.__sigaction_handler = SIG_IGN;
    sigemptyset( &action.sa_mask );
    action.sa_flags = 0;

    for( i = 0; i < sizeof( sigs ) / sizeof( int ); i++ )
    {
        if( sigaction( sigs[i], &action, NULL ) < 0 )
        {
            fprintf( stderr, "%s: Failure in sigaction(): %s. \n", program, strerror( errno ) );
            exit( EXIT_FAILURE );
        }
    }

    /* 2. Convert to background process */
    switch( pid = fork() )
    {
        case -1: /* Fail */
            fprintf( stderr, "%s: Failure in fork(): %s.\n", program, strerror( errno ) );
            exit( EXIT_FAILURE );
            break;

        case 0: /* Child process ccontinues running */
            openlog( program, LOG_PID, facility );
            break;

        default: /* Parent process ends */
            exit( EXIT_SUCCESS );
            break;
    }
}