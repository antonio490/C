#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    char fname[128];

    printf( "input filename > " );
    fgets( fname, sizeof( fname ), stdin );
    printf("\n");

    // strcpy( fname, "/home/antonio/Documentos/Kali" );

    /* verify with access() if file exists */
    if( access( fname, F_OK ) == 0)
        printf("File %s exists \n", fname);
    else {
    
        if (access(fname, R_OK) == 0)
            printf("You have read access to '%s'\n", fname);
        if (access(fname, W_OK) == 0)
            printf("You have write access to '%s'\n", fname);
        if (access(fname, X_OK) == 0)
            printf("You have search access to '%s'\n", fname);
    }

    return 0;
}