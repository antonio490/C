#include <stdio.h>
#include <stdlib.h>

#define WINDOW_SIZE 10


float rollingAvg(int index, int len, float *temp_array)
{
    float sum = 0;

    if(index >= WINDOW_SIZE) index = 0;
    if(len >= WINDOW_SIZE) len = WINDOW_SIZE;

    for(int i=0; i<WINDOW_SIZE; i++){
        sum += temp_array[i];
    }

    return sum / len;
}


void main()
{
    float temp_array[WINDOW_SIZE] = {0};
    int index = 0, len = 0;
    float num, avg;

    while(1)
    {
        printf("Enter temperature value: ");
        scanf("%f", &num);
        
        temp_array[index] = num;
        index++;
        len++;

        avg = rollingAvg(index, len, temp_array);
        printf("\tAverage: %.2f\n", avg);
    }

}