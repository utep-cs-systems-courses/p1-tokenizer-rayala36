#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define MAX 1000

int main() {

  size_t strlen(const char* str) {

    const char* ptr = str;

    while (*ptr != '\0') {
      ptr++;
    }
    return ptr - str;
  }
  List* list = init_history();
  printf("Welcome to Tokenizer! Press '>' to view your history, or '!(number)' to view a certain pa          rt of your history.  Press '@' to exit. Otherwise, type in anything else to add to your h          istory!");
  char str[MAX];
  while(1){
    printf("> = view entire history\n");
    printf("!(number) = view part of history with that number\n");
    printf("@ = exit\n");
    printf("(anything else) = A new part of your history");
    fgets(str, MAX, stdin);
    char *aStr = str;
    if(aStr[0] == '@')
      exit(1);
    if(aStr[0] = '!'){
      int i;
      char *ID;
      for(i=0; i<strlen(str); i++)
	ID[i] = str[i+1];
      int id = atoi(ID);
      get_history(list, id);
    }
    if(str[0] = '>'){
      print_history(list);
    }
    char **token = tokenize(str);
    add_history(list, str);
  }
  return 0;
}
