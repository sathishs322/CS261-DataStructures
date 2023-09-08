/*
 * In this file, you should implement an application that compares the
 * performance of a dynamic array and a linked list, as described in the
 * README. Don't forget to include your name and @oregonstate.edu email
 * address below.
 *
 * Name:Sabyatha Kumar
 * Email:sathishs@oregonstate.edu
 */

#include <stdlib.h>
#include <stdio.h>

#include "dynarray.h"
#include "list.h"
#include "time.h"

#define TEST_DATA_SIZE 1000000

/*
 * This function generates and an array of random integers of size n.
 */
int* generate_random_array(int n) {
  int* arr = malloc(n * sizeof(int));
  int i;

  for (i = 0; i < n; i++) {
    arr[i] = rand();
  }
  return arr;
}

int main(int argc, char const *argv[]) {
  int* test_data = generate_random_array(TEST_DATA_SIZE);
  struct dynarray* array= dynarray_create();
  clock_t total_dyn=0;
  clock_t max_dyn=0;
  clock_t total_l=0;
  clock_t max_l=0;

  struct list* l=list_create();

  for(int i=0;i<TEST_DATA_SIZE;i++){
    clock_t start_l = clock();
    list_insert(l, &(test_data[i]));
    clock_t stop_l = clock();
    clock_t elpased_l = stop_l-start_l ;
    total_l+=elpased_l;
    
    if(elpased_l>max_l){
      max_l=elpased_l;
    }
  }
  printf("\nLINKED LIST\n");
  printf("Total time to add elements into list: %f sec\n",((double)(total_l))/CLOCKS_PER_SEC);
  printf("Max time taken to insert one element : %f sec\n",((double)(max_l))/CLOCKS_PER_SEC);

  for(int i=0;i<TEST_DATA_SIZE;i++){
    clock_t start_d = clock();
    dynarray_insert(array, &(test_data[i]));
    clock_t stop_d = clock();
    clock_t elpased_d = stop_d-start_d ;
    total_dyn+=elpased_d;

    if(elpased_d>max_dyn){
      max_dyn=elpased_d;
    }
  }
  printf("\nDYNAMIC ARRAY\n");
  printf("Total time to add elements into dyn array: %f sec\n",((double)(total_dyn))/CLOCKS_PER_SEC);
  printf("Max time taken to insert one element : %f sec\n\n",((double)(max_dyn))/CLOCKS_PER_SEC);
   

  free(test_data);
  list_free(l);
  dynarray_free(array);
  
  /*
   * You should write code here to insert the data in test_data into a
   * dynamic array using the dynamic array interface you implemented.  As
   * you're doing this, measure two things:
   *   1. The total amount of time it takes to insert all the data into the
   *      dynamic array.
   *   2. The maximum amount of time it takes to insert any single element into
   *      the dynamic array.
   * To help with this, you can use the C functions time() and difftime()
   * from time.h.  Don't forget to include time.h above!
   */

   /*
    * You should write code here to insert the data in test_data into a
    * linked list using the linked list interface you implemented.  As
    * you're doing this, measure two things:
    *   1. The total amount of time it takes to insert all the data into the
    *      linked list.
    *   2. The maximum amount of time it takes to insert any single element into
    *      the linked list.
    * Again, you can use the C functions time() and difftime() from time.h to
    * help with this.
    *
    * How do the times associated with the dynamic array compare to the times
    * associated with the linked list?  How does this change if you modify the
    * value of TEST_DATA_SIZE above?
    * The dynamic array times are shorter than the total time for the linked list for 1,000,000 elements. 
    * but as you descrese the data size the linked list is faster. 
    */

  return 0;
}
