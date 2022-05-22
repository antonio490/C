/***********************************************/
/* Author:     Markus Zahn
 *
 * Title:      Unix-Netzwerkprogrammierung
 *             mit Threads, Sockets und SSL
 *
 * Editorial:  Springer
 *
/***********************************************/


#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <syslog.h>


void daemon_init( const char *program, int facility )
{

    pid_t pid;
    int i, sigs[] = { SIGHUP, SIGINT, SIGQUIT, SIGTSTP, SIGTTIN, SIGTTOU };
    struct sigaction action;

    /* 1. Ignore signals and create an own terminal */

    action.sa_handler = SIG_IGN;
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

        case 0: /* Child process continues running */
            openlog( program, LOG_PID, facility );
            break;

        default: /* Parent process ends */
            exit( EXIT_SUCCESS );
            break;
    }

    /* 3. Break link with terminal */

    if( setsid() < 0 )
    {
        syslog( LOG_ERR, "Failure in setsid(): %s.\n", strerror( errno ) );
        exit( EXIT_FAILURE );
    }

    switch ( pid = fork() )
    {
    case -1: /* Fail */
        syslog( LOG_ERR, "Failure in fork(): %s.\n", strerror( errno ) );
        exit( EXIT_FAILURE );
        break;
    
    case 0: /* Child process continues running */
        break;
    
    default: /* Parent process ends */
        exit( EXIT_SUCCESS );
        break;
    }

    /* 4. Close unneccesary fds */
    
    close( STDIN_FILENO );
    close( STDOUT_FILENO );
    close( STDERR_FILENO );

    /* 5. Change working directory */

    chdir( "/" );

    /* 6. Reset file mode mask */

    umask( 0 );
}


int main( int argc, char *argv[] )
{
    daemon_init( argv[0], LOG_DAEMON );
    sleep( 60 ); 
}