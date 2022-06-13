#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_256  256

int leng( char *pstr )
{
    int i = 0, length = 0;

    for(i = 0; pstr[i] != '\0'; i++)
    {
       length++;                                                                                             
    }

    return length;
}

char *reverse_str( char *str )
{
    int  length = 0, i = 0, j = 0, midleng;
    char temp;

    length = leng(str);
    j = length - 1;
    midleng = length / 2;
    for(i = 0; i < midleng; i++)
    {
        temp   = str[i];
        str[i] = str[j];
        str[j] = temp;
        
        j = j - 1;
    }
    return str;
}

char *concat( char *str1, char *str2 )
{
     int length = 0, length_2 = 0, i = 0, j = 0;


     length   = leng(str1);
     length_2 = leng(str2);
     for( i = length; str2[j] != '\0'; i++, j++)
     {
         str1[i] = str2[j];
     }
     str1[i] = '\0';
     return str1;
}

int main( int argc, char* argv[] )
{
    char *str;
    char str_mem [LEN_256];
    
    strcpy(str_mem, "strings.c");
    
    str = reverse_str(str_mem);
    printf("%s \n",str);

    exit(EXIT_SUCCESS);
}