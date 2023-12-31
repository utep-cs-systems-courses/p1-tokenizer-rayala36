#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

/* Initializes the linked list to keep the history. */
List* init_history(){
  List* list = (List *)malloc(sizeof(List));
  list->root->next = NULL;
  return list;
}
/* Adds a history item to the end of the list; (List* list - the linked list), (char* str - the 
   string to store). */
void add_history(List* list, char* str){
  Item *item = (Item *)malloc(sizeof(Item));

/* Length value (len) of the string to add to the history is calculated here so the appropriate 
   amount of space may be allocated for it.*/
  int len;
  const char* ptr = str;
  while (*ptr != '\0')
    ptr++;
  len = (ptr - str);

  char *copy = (char *)malloc( (sizeof(char) * (len+1)) );

  // A copy of the string is created for the history.
  int i = 0;
  while(i < len){
      *(copy+i) = *(str+i);
      i++;
  }
  *(copy + i) = '\0';

  // The string's copy is created and it's place in the history. 
  item->next = NULL;
  item->str = copy;

/* The new history item is the new root, and if it is the only item in the list, it's ID value is 
   1.  Otherwise, if it is not the only item in the history, it's ID and it's place in history is 
   calculated accordingly. */
  Item *new = list->root;
  if(new == NULL){
     item->id = 1;
     list->root = item;
  }
  while(new->next != NULL)
      new = new->next;
			       
  new->next = item;
  item->id = new->id+1;
}
  
/* Retrieve the string stored in the node where Item->id == ID; (List* list - the linked list), 
   (int id - the id of the Item to find).  The appropriate message will be printed if the string 
   is not in the history. */
char* get_history(List *list, int id){
    int ID = 0;
    Item *item = list->root;
    while( (item->next) != NULL){
      if( ID == list->root->id ){
	printf(item->str);
      }
      item = item->next;
    }
    printf("Your input is not in your history :(\n");
}
/* Prints the entire contents of the list. */
void print_history(List *list){
    while( (list->root->next) != NULL){
      printf("%d %s\n", list->root->id, list->root->str );
      list->root = list->root->next;
    }
    printf("%d %s\n", list->root->id, list->root->str);
}

/* Frees the history list and the strings it references. */
void free_history(List *list){

  Item *current = list->root;
  while( (current->next) != NULL){
    current = list->root->next;
    free(list->root->str);
    free(list->root);
    list->root = current;
  }
  free(list->root->str);
  free(list->root);
  free(list);
}
