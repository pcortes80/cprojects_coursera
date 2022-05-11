/*  Factorial
    Simple Recursion
*/

#include <stdio.h>

/* define de factorial funtion */
long int recursive_factorial(int n)
{
    if (n==1)
        return 1;   //rule : it must have an ending point
    else
        return (recursive_factorial(n-1)*n); // rule : it must be simpler
}

int main(void)
{
    int how_many = 0, i;
    printf("I want a table of factorial up to n: ");
    scanf("%d", &how_many);
    printf("\n factorials\n");

    for(i = 1; i <= how_many; i++)
        printf("\n%d\t %d\n",i, recursive_factorial(i));
        printf("\n\n");
        return 0;
}
