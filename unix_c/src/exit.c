/***********************************************/
/* Author:     Markus Zahn
 *
 * Title:      Unix-Netzwerkprogrammierung
 *             mit Threads, Sockets und SSL
 *
 * Editorial:  Springer
 *
/***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void exit_handler( void )
{
    printf( "Sir Quickly räumt auf \n" );
}

int main( int argc, char *argv[] )
{
    if( atexit( exit_handler ) != 0 )
    {
        printf( "Kann Exit-Handler nicht registrieren \n" );
        exit( EXIT_FAILURE );
    }

    printf( "Irgendwie..." );

    if( argc > 1 )
    {
        if( strcmp( argv[1], "exit" ) == 0 )
            exit( EXIT_SUCCESS );
        else
            _exit( EXIT_SUCCESS );
    }

    printf( "und sowiese \n" );

    return( EXIT_SUCCESS );
}

/*
    1. Run program without arguments ----->  Irgendwie... und sowiese.
                                             Sie Quickly räumt auf.

    2. Run program with exit as argument --> Irgendwie... Sir Quickly räumt auf.

    3. Run with a different parameter ------> NULL


*/