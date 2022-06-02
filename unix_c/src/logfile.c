#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *log = NULL;
    FILE *passwd = NULL;    

    if( ( log = fopen( "logfile.log", "a" ) ) == NULL )
        return( EXIT_FAILURE );


    setvbuf( log, NULL, _IONBF, 0 ); /* Not buffering */

    #ifdef DEBUG
        fprintf( log, "Start from %s with %d argument(s).\n" argv[0], argc );
    #endif


    if( ( passwd = fopen( "/etc/shadow", "r" ) ) == NULL )
    {
        fprintf( log, "Open the file /etc/shadow: %s\n", strerror( errno ) );
        return( EXIT_FAILURE );
    }

    return( EXIT_SUCCESS );
}