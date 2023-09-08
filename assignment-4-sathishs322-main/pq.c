/*
 * In this file, you will write the structures and functions needed to
 * implement a priority queue.  Feel free to implement any helper functions
 * you need in this file to implement a priority queue.  Make sure to add your
 * name and @oregonstate.edu email address below:
 *
 * Name: Sabyatha Kumar
 * Email:sathishs@oregonstat.edu
 */

#include <stdlib.h>
#include <stdio.h>

#include "pq.h"
#include "dynarray.h"

/*
 * This is the structure that represents a priority queue.  You must define
 * this struct to contain the data needed to implement a priority queue.
 */

struct node{
  int priority;
  void* value;
};

struct pq{
  struct dynarray* array;
};
void percolate(struct pq* ph);
void prioritize(struct pq* ph);
int findMin(struct pq* ph, int i);

/*
 * This function should allocate and initialize an empty priority queue and
 * return a pointer to it.
 */
struct pq* pq_create() {
  struct pq* priq=malloc(sizeof(struct pq));
  priq->array=dynarray_create();
  return priq;
}

/*
 * This function should free the memory allocated to a given priority queue.
 * Note that this function SHOULD NOT free the individual elements stored in
 * the priority queue.  That is the responsibility of the caller.
 *
 * Params:
 *   pq - the priority queue to be destroyed.  May not be NULL.
 */
void pq_free(struct pq* pq) {
  dynarray_free(pq->array);
  free(pq);
  return;
}

/*
 * This function should return 1 if the specified priority queue is empty and
 * 0 otherwise.
 *
 * Params:
 *   pq - the priority queue whose emptiness is to be checked.  May not be
 *     NULL.
 *
 * Return:
 *   Should return 1 if pq is empty and 0 otherwise.
 */
int pq_isempty(struct pq* pq) {
  if (dynarray_size(pq->array)<=0){
    return 1;
  }
  return 0;
}


/*
 * This function should insert a given element into a priority queue with a
 * specified priority value.  Note that in this implementation, LOWER priority
 * values are assigned to elements with HIGHER priority.  In other words, the
 * element in the priority queue with the LOWEST priority value should be the
 * FIRST one returned.
 *
 * Params:
 *   pq - the priority queue into which to insert an element.  May not be
 *     NULL.
 *   value - the value to be inserted into pq.
 *   priority - the priority value to be assigned to the newly-inserted
 *     element.  Note that in this implementation, LOWER priority values
 *     should correspond to elements with HIGHER priority.  In other words,
 *     the element in the priority queue with the LOWEST priority value should
 *     be the FIRST one returned.
 */
void pq_insert(struct pq* pq, void* value, int priority) {
  struct node* new= malloc(sizeof(struct node));
  new->priority= priority;
  new->value=value;
  dynarray_insert(pq->array, new);
  percolate(pq);
}

void percolate(struct pq* ph){
  int last_in=dynarray_size(ph->array)-1;
  int parent_ind=(last_in-1)/2;
  int parent=((struct node*)dynarray_get(ph->array,parent_ind))->priority;
  int child=((struct node*)dynarray_get(ph->array,last_in))->priority;  

  while(parent>child){
    void* x=dynarray_get(ph->array,parent_ind);
    void* y=dynarray_get(ph->array,last_in);

    dynarray_set(ph->array,last_in,x);
    dynarray_set(ph->array,parent_ind,y);
  
   last_in=parent_ind;
   parent_ind=(last_in-1)/2;
   parent=((struct node*)dynarray_get(ph->array,parent_ind))->priority;
   child=((struct node*)dynarray_get(ph->array,last_in))->priority;  

  }
}
/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with LOWEST priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   LOWEST priority value.
 */
void* pq_first(struct pq* pq) {
  void* val=((struct node*)dynarray_get(pq->array,0))->value;
  return val;
}


/*
 * This function should return the priority value of the first item in a
 * priority queue, i.e. the item with LOWEST priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a priority value.  May not be
 *     NULL or empty.
 *
 * Return:
 *   Should return the priority value of the first item in pq, i.e. the item
 *   with LOWEST priority value.
 */
int pq_first_priority(struct pq* pq) {
  int val=((struct node*)dynarray_get(pq->array,0))->priority;
  return val;
}


/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with LOWEST priority value, and then remove that item
 * from the queue.
 *
 * Params:
 *   pq - the priority queue from which to remove a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   LOWEST priority value.
 */
void* pq_remove_first(struct pq* pq) {

  int last_in=dynarray_size(pq->array)-1;

  void *val=((struct node*)dynarray_get(pq->array,0))->value;
  
  
  
  void* root_val=dynarray_get(pq->array,0);
  void* last_val=dynarray_get(pq->array,last_in);
  
  free(root_val);
  dynarray_set(pq->array,0,last_val);
  dynarray_remove(pq->array,last_in); 
  
  prioritize(pq);

  
  return val;
}
//check log n runtime 

void prioritize(struct pq* ph){

  int i=0;
  int min=findMin(ph,i);
  
   while(min>=0&&((((struct node*)dynarray_get(ph->array,i))->priority>((struct node*)dynarray_get(ph->array,min))->priority))){
    int a=min;

    void* x=dynarray_get(ph->array,i);
    void* y=dynarray_get(ph->array,min);

    dynarray_set(ph->array,min,x);
    dynarray_set(ph->array,i,y);

    i=a;
    min=findMin(ph,i);
    
  }

}

int findMin(struct pq* ph, int i){
  int left_child=(2 * i)+ 1;
  int right_child=(2 * i)+ 2;
  int min=0;
  if((left_child<dynarray_size(ph->array))&&(right_child<dynarray_size(ph->array))){
  
  if(((struct node*)dynarray_get(ph->array,left_child))->priority>((struct node*)dynarray_get(ph->array,right_child))->priority){
    min=right_child;
  }
  else if(((struct node*)dynarray_get(ph->array,left_child))->priority<((struct node*)dynarray_get(ph->array,right_child))->priority){
    min=left_child;
  }
  else if(((struct node*)dynarray_get(ph->array,left_child))->priority==((struct node*)dynarray_get(ph->array,right_child))->priority){
    min=right_child;
  }
  }
  
  if((left_child<dynarray_size(ph->array))&&(right_child>=dynarray_size(ph->array))){
    min=left_child;
  }
  if(((left_child>=dynarray_size(ph->array))&&(right_child>=dynarray_size(ph->array)))){
    return -1;
  }

  return min;
}