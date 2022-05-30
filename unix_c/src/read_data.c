#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main( int argc, char*argv[] )
{
    int fd;
    char filename[] = "read.data";
    char data[45];
    ssize_t br, bw;

    fd = open( filename, O_RDONLY );
    if( fd < 0 )
    {
        printf("Can´t open data %s, error %s\n", filename, strerror( errno ));
        exit( EXIT_FAILURE );
    }

    br = read( fd, data, sizeof( data ) );
    if( br != sizeof( data ) )
    {
        if( br < 0 )
        {
            printf("Error reading file %s\n", strerror( errno ) );
            exit( EXIT_FAILURE );
        }else
            printf("Could only read %d Bytes: %s\n", br);
    }

    bw = write( STDOUT_FILENO, data, br );
    if( bw != br )
    {
        printf("Could only write %d Bytes.\n", bw );
        exit( EXIT_FAILURE );
    }

    if( close( fd ) != 0 )
    {
        printf("Could not close the fd %s: %s\n", filename, strerror( errno ));
        exit( EXIT_FAILURE );
    }


    return ( EXIT_SUCCESS );
}