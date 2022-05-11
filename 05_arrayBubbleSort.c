/*  USe of Simple arrays parameters
    Sorting Bullble Sort
    Display each loop
    Easybut inefficient
    Sally Coder Jan 18, 2018
*/

#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int how_many, int data[], char *str)
{
    int i;
    printf("%s", str);

    for(i = 0; i < how_many; i++)
        printf("%d\t", data[i]);
}

void bubble(int data[], int how_many)
{
    int i, j;
    int go_on;

    for(i = 0; i < how_many; i++){
        print_array(how_many, data, "\ninside bubble\n");
        printf("i = %d, input any int to continue: ", i);
        scanf("%d", &go_on);
        for(j = how_many - 1; j > i; j--){
            printf("how_many = %d\n", how_many - 1);
            if(data[j-1] > data[j]){
                printf("data[j-1] = %d\n", data[j-1]);
                printf("data[j] = %d\n", data[j]);
                swap(&data[j-1], &data[j]);
            }
        }
    }
}

int main(void)
{
    const int SIZE = 5;
    int grades[5] = {100, 67, 92, 83, 88};

    print_array(SIZE, grades, "My grades\n");
    printf("\n\n");
    bubble(grades, SIZE);
    print_array(SIZE, grades, "My sorted grades\n");
    printf("\n\nbye!");
    return 0;
};