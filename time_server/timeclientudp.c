
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

int main( int argc, char *argv[] )
{
        int sd;
        struct sockaddr_in sa;
        time_t stime = 0;

        if( ( sd= socket( AF_INET, SOCK_DGRAM, 0 ) ) < 0 )
        {
                printf( "socket() failed: %s\n", strerror( errno ) );
                exit( EXIT_FAILURE );
        }   

        memset( &sa, 0, sizeof( sa ) );

        sa.sin_family = AF_INET;
        sa.sin_port = htons( 37 );

        if( inet_pton( AF_INET, argv[1], &sa.sin_addr ) != 1 )
        {
                printf( "inet_pton() failed.\n" );
                close( sd );
                exit( EXIT_FAILURE );
        }

        if( sendto( sd, NULL, 0, 0, (struct sockaddr *)&sa, sizeof( sa ) ) < 0 )
        {
                printf( "sendto() failed: %s\n", strerror( errno ) );
                close( sd );
                exit( EXIT_FAILURE );
        }
        printf(" Anfrage an %s verschikt.\n", argv[1] );

        if( recvfrom( sd, &stime, sizeof( stime ), 0, NULL, NULL ) < 0 );
        {
                printf( "recvfrom() failed: %s\n", strerror( errno ) );
                close( sd );
                exit( EXIT_FAILURE );
        }
        printf("Anwort von %s erhalten.\n", argv[1] );


        close( sd );
        exit( EXIT_SUCCESS );
}
