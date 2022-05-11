/*  Add random elements to array
    and then create list from the array
    Patricio Cortes
    april 23, 2022 
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

/* Generate random numbers from 1 to 20 */
#define BASE_NUM         1
#define RANGE            20
#define NUM_OVER         rand()% RANGE
#define RANDOM           NUM_OVER + BASE_NUM

/* Define struct list as typef */
typedef struct list{ 
    int data; 		// data in this element (node)
    struct list *next;	// pointer to next element (node)
} list;

/*Define the function "is_empty" */
int is_empty(const list *l){ 
    return (l == NULL);
}

/* Define function "create_list" */
/* head points to the first element of the list.
 * In the beginning, before we insert any elements 
 * into the list (the empty list), this variable
 * is initialized to NULL.
*/
list* create_list(int d)
{
    list* head = malloc(sizeof(list));
    head -> data = d;		//store the item in the new element (node)
    head -> next = NULL;	//the first element poits to NULL
    return head;		// returns the first element just created (node)
}

/* Define function "add_to_front" */
list* add_to_front(int d, list* h)
{
    list* head = create_list(d);
    head -> next = h;
    return head;
}

/*Define the function "print_list" */
void print_list(list *h, char *title)
{
  printf("%s\n", title);
  // it iterates untill the end of the list
  int i=0;
  while(h != NULL){
    printf("%d:", h -> data);
    if ((i+1) % 5 == 0) printf("\n"); //print in rows of 5 elements
    h = h -> next;
    i++;
    }
}

/*
void print_list(list *h, char *title)
{
  printf("%s\n", title);
  // it iterates untill the end of the list
  while(h != NULL){
    printf("%d:", h -> data);
    h = h -> next;
    }
}
*/

void print_array(int how_many, int data[], char *str)
{
    int i;
    printf("%s\n",str);

    for (i = 0; i < how_many; i++){
    	 printf("%d\t", data[i]);
         if ((i+1) % 5 == 0) printf("\n"); //print in rows of 5 elements
    }
    printf("\n");
}

/* Define function "array_to_list" */
list* array_to_list(int d[], int size)
{
    list* head = create_list(d[0]);
    int i;
    for(i = 1; i < size; i++)
    {
        head = add_to_front(d[i], head);
     }
    return head;
}

int main()
{
    srand(time(0)); //random numbers in every run
    int array[100] = {0};
    int i;

    for (i = 0; i < 100; i++)
        array[i] = RANDOM;

    print_array(100, array, "array created");
    list list_of_int; //create the list named "list_of_int"
    list *head = NULL; //define the head is NULL
    head = array_to_list(array, 100);
    print_list(head, "new list created from the array");
    printf("\n\n");
    return 0;
} 
