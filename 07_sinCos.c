/*  Assignment 2 week 3
    table of values for sine and cosine
    Patricio Cortés
    22-02-2022
*/

#include<stdio.h>
#include<math.h> /* has  sin(), cos() */
#define PI 3.14159

int main(void)
{ 
    double i;   //define variable i for the iteration
    // calculate sin from 0 to 90 degrees in steps of 15 degrees
    for(i = 0.0; i <= 90; i+=15)
        {printf("sin( %lf ) = %lf \n", i, sin(i * PI  / 180.0) );}
    
    printf("+++++++\n");
    
    // calculate cos from 0 to 90 degres in steps of 15 degrees    
    for(i = 0.0; i <= 90; i+=15)
        {printf("cos( %lf ) = %lf \n", i, cos(i * PI  / 180.0) );}
    
    printf("\n+++++++\n");
    return 0;
}
