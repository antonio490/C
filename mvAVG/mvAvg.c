#include <stdio.h>
#include <stdlib.h>

#define WINDOW_SIZE 10


void main()
{
    float temp_array[WINDOW_SIZE] = {0};
    int index = 0, len = 0;
    float num, sum;

    while(1)
    {
        printf("Enter temperature value: ");
        scanf("%f", &num);
        temp_array[index] = num;
        index++;
        len++;
        sum = 0;

        if(index >= WINDOW_SIZE) index = 0;
        if(len >= WINDOW_SIZE) len = WINDOW_SIZE;

        for(int i=0; i<WINDOW_SIZE; i++){
            sum += temp_array[i];
        }

        printf("\tSum: %.2f\t Length: %d\n", sum, len);
        printf("\tAverage: %.2f\n", sum / len);
    }

}