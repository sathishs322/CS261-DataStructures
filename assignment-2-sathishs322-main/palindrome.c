#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"
#include "stack.h"
#include <ctype.h>

#define MAX_STR_LEN 256

/*
 * This function prompts the user for input and stores a maximum of `n`
 * characters of the string they enter into `dest`.  Any trailing line ending
 * characters are removed from the input string.  Returns 1 if a string was
 * successfully read from the user or 0 otherwise.
 */
int get_user_str(char* dest, int n) {
  printf("\nEnter a string, and we'll check whether it's a palindrome:\n");
  if (fgets(dest, MAX_STR_LEN, stdin) != NULL) {
    /*
     * If a string was successfully read from the user, remove any trailing
     * line ending characters.  Here's some documentation on strcspn() to help
     * understand how this works:
     *
     * https://en.cppreference.com/w/c/string/byte/strcspn
     */
    dest[strcspn(dest, "\r\n")] = '\0';
    return 1;
  } else {
    return 0;
  }
}

int main(int argc, char const *argv[]) {
  char* in = malloc(MAX_STR_LEN * sizeof(char));
  struct stack* stack=stack_create();
  struct queue* que=queue_create();

  while (get_user_str(in, MAX_STR_LEN)) {
   
    int size=strlen(in);
  
    for(int i=0;i<size;i++){
      in[i]=tolower(in[i]);
      int is_char= isalpha(in[i]);
      if(is_char!=0){
      stack_push(stack,&in[i]);
      queue_enqueue(que,&in[i]);
      }
    }
    int pali=0;
    while(stack_isempty(stack)!=1&&queue_isempty(que)!=1){
      char* s=stack_pop(stack);
      char* q=queue_dequeue(que);
      if(*s==*q){
          pali=1;
      }
      else{
        pali=0;
       break; 
      }
    }

    if(pali==1){
      printf("Your string is A palindrome\n\n");
    }
    else{
      printf("Your string is NOT a palindrome\n\n");
    }
    break;
    

    
    /*
     * Inside this loop body, you'll have an input string from the user in `in`.
     * You should use your stack and your queue to test whether that string is
     * a palindrome (i.e. a string that reads the same backward as forward, e.g.
     * "ABCBA" or "Madam, I'm Adam").  For each string input by the user,
     * print a message letting the user know whether or not their string is
     * is a palindrome.
     *
     * When you test whether the user's string is a palindrome, you should
     * ignore any non-letter characters (e.g. spaces, numbers, punctuation,
     * etc.), and you should ignore the case of letters (e.g. the characters
     * 'a' and 'A' should be considered as equal).  The C functions isalpha()
     * and tolower() from ctype.h might help with this.
     */
  }
  stack_free(stack);
  queue_free(que);
  free(in);
  return 0;
}
