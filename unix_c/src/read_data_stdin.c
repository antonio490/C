#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main( int argc, char *argv[] )
{
    int fd;
    char data[45];
    ssize_t br, bw;

    br = read( STDIN_FILENO, data, sizeof( data ) );
    if( br != sizeof( data ) )
    {
        if( br < 0 )
        {
            printf("Error reading: %s\n", strerror( errno ) );
            exit( EXIT_FAILURE );
        }
        else
            printf("Could only read %d bytes\n", br);
        
        bw = write( STDOUT_FILENO, data, br );
        if( bw != br )
        {
            printf("Could only write %d bytes\n", bw);
            exit( EXIT_FAILURE );
        }

        return EXIT_SUCCESS;
    }
}