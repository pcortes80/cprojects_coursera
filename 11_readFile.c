/* Assignment week 4
 * Patricio Cortes
 * May, 2022
 * Open and read a file of integers into an array that is created with the first integer telling you how many to read.
 * So  4  9  11  12  15  would mean create an int array size 4 and read in the remaining 4 values into data[].
 * Then compute their average as a double and their max  as an int.  Print all this out neatly to the screen and to an output file named answer-hw3.
*/

#include <stdio.h>
#define MAX_HW 20

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void read_data(FILE *ptr, int d[], int *size)
{
    *size = 0;
    while(fscanf(ptr, "%d", &d[*size]) == 1)
	 (*size)++;
}

void new_array(int d[], int max_size)
{
    int i;
    int new_array[max_size];
    for(i=0; i < max_size; i++){
        new_array[i] = d[i];
	printf("%d\t", new_array[i]);
    }
    printf("\n");
}

void print_data(int d[], int size)
{
   int i;
   for(i = 0; i < size ; i++){
       printf("%d\t", d[i]);
       if ((i+1) % 10 == 0) 
	  printf("\n");
   }
   printf("\n");
}

double average(int d[], int size)
{
    int i;
    double avg = 0.0;

    for(i = 0; i < size; i++)
        avg += d[i];
    return (avg/size);
}

void bubble(int data[], int how_many)
{
    int i, j;
    int go_on;

    for(i = 0; i < how_many; i++){
        for(j = how_many - 1; j > i; j--){
            if(data[j-1] > data[j]){
                swap(&data[j-1], &data[j]);
            }
        }
    }
}

int main()
{
    int i, sz = MAX_HW, first_value;
    FILE *ifp;
    int data[MAX_HW] = {100, 0};
     
    /* read file "myfile" saved in same directory of code */
    ifp = fopen("myfile", "r"); //r means read
    read_data(ifp, data, &sz);
    printf("The original array is :\t");
    print_data(data, sz);
    printf("\n");

    /* Get the first value of data array */
    first_value = data[0];
    printf("The first value of the original array is : %d\n", first_value);
    printf("\n");

    /* Create the new array */
    int new_data[first_value];
    for(i=0; i<first_value; i++){
        new_data[i] = data[i+1];
    }
    
    /* Print the new data array */    
    printf("The new array is :\t");
    print_data(new_data, first_value);
    printf("\n");
    
    /* Calculate the average of new data array */
    printf("The average is : %f", average(new_data, first_value));
    printf("\n\n");
    fclose(ifp); //exit leads to close - so not strictly needed
   
    /* Sort new_data array */
    bubble(new_data,first_value);
  
    /* Print the sorted new data array */
    printf("The sorted new array is :\t");
    print_data(new_data, first_value);
    printf("\n");

    /* Print the max value */
    printf("The max value is : %d\n", new_data[first_value - 1]);
 
    return 0;
}
