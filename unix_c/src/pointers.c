
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

typedef struct T_STRUCT_POINT{

    float x;
    float y;
    char *p_name;

}t_s_point;

typedef struct T_STRUCT_RECT{

    t_s_point *p1;
    t_s_point *p2;
    t_s_point *p3;
    t_s_point *p4;

}t_s_rect;

t_s_point* l_side( t_s_point *p1, t_s_point *p2 )
{
    t_s_point *p3;

    p3->x = abs(p1->x - p2->x);
    p3->y = abs(p1->y - p2->y);

    return p3;
}

int main(int argc, char* argv[]){

    t_s_rect *square;
    t_s_point *p3;

    square = (t_s_rect*) malloc(sizeof(t_s_rect));
    square->p1 = (t_s_point*) malloc(sizeof(t_s_point)); 
    square->p2 = (t_s_point*) malloc(sizeof(t_s_point)); 

    square->p1->p_name = (char*)malloc(32);
    square->p2->p_name = (char*)malloc(32);


    square->p1->x = 5.2;
    square->p1->y = 5.5;
    strcpy( square->p1->p_name, "point one");

    square->p2->x = 10.4;
    square->p2->y = 5.5;
    strcpy( square->p2->p_name, "point two");

    p3 = l_side( square->p1, square->p2); 

    printf("Distance in x between %s and %s = %d \n", square->p1->p_name, square->p2->p_name, p3->x);
    printf("Distance in y = %d \n", p3->y);

    return 0;
}