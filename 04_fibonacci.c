/*  Recursive Fibonacci
    Sally Coder Jan 18, 2018
    F(n) = F(n-1) + F(n-2); F(0) = 0, F(1) = 1
*/

#include <stdio.h>

/* define the function */
long recursive_fibonacci(int n)
{
    if (n <= 1)
        return n;
    else
        return (recursive_fibonacci(n-1) + recursive_fibonacci(n-2));
}

int main(void)
{
    int how_many = 0, i;
    printf("I want a table of Fibonacci up to n: ");
    scanf("%d", &how_many);
    printf("\n Fibonacci\n");

    for(i = 1; i <= how_many; i++)
        printf("\n%d\t %d\n",i, recursive_fibonacci(i));
        printf("\n\n");
        return 0;
}