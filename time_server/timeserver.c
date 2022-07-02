#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define SRVPORT 1037
#define BACKLOG 32

int main( int argc, char *argv[] )
{
        int sd, client;
        struct sockaddr_in sa;
        time_t stime;

        /* TCP Socket anlegen */
        if( ( sd = socket( AF_INET, SOCK_STREAM, 0 ) ) < 0 )
        {
                printf( "socket() failed: %s\n", strerror( errno ) );
                exit( EXIT_FAILURE );
        }

        /* Initialisierung der socket-adress struktur */
        memset( &sa, 0, sizeof( sa ) );
        sa.sin_family      = AF_INET;
        sa.sin_port        = htons( SRVPORT );
        sa.sin_addr.s_addr = htonl( INADDR_ANY );

        /* Socket an socket-addresse binden */
        if( bind( sd, (struct sockaddr *)&sa, sizeof( sa ) ) < 0 )
        {
                printf( "bind() failed:%s\n", strerror( errno ) );
                close( sd );
                exit( EXIT_FAILURE );
        }

        /* aktiven socket in passiven socket umwandeln */
        if( listen(sd, BACKLOG ) < 0 )
        {
                printf("listen() failed %s\n", strerror( errno ) );
                close( sd );
                exit( EXIT_FAILURE );
        }
        
        for(;;)
        {

                /* NEUE socketverbindung annehmen */
                if( ( client = accept( sd, NULL, NULL ) ) < 0 )
                {
                        printf( "accept() failed %s\n", strerror( errno ) );
                        close( sd );
                        exit( EXIT_FAILURE );
                }

                /* Sekunden auf basis 1.1.1900 umrechnen und senden */
                stime = htonl( (long)time( NULL ) + 2208988800UL );
                write( client, &stime, sizeof( stime ) );

                close( client );
        }
}






