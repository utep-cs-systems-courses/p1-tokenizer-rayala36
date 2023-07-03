#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define MAX 1000

int main() {

  // A function to find the length of a character string will be needed for certain operations.
  int strlen(const char* str) {
    const char* ptr = str;

    while (*ptr != '\0') {
      ptr++;
    }
    return ptr - str;
  }

  // A new list is created and a message tells the user what they can do.
  List* list = init_history();
  printf("Welcome to Tokenizer! Press '>' to view your history, or '!(number)' to view a certain pa          rt of your history.  Press '@' to exit. Otherwise, type in anything else to add to your h          istory!");
  char str[MAX];
  // Unless the user quits, this utility should function forever.
  while(1){
    printf("> = view entire history\n");
    printf("!(number) = view part of history with that number\n");
    printf("@ = exit\n");
    printf("(anything else) = A new part of your history");

    /* Given the options above (which are printed every time a user returns an input), the strings
       are evaluated based on the operator. */
    fgets(str, MAX, stdin);
    char *aStr = str;

    // The exit function is used to escape the entire function.
    if(aStr[0] == '@')
      exit(1);

    /* To obtain a string in history via the ID value, the string proceeded by '!' is converted to        an int variable via the "atoi" function.  That value is used by the "get_history" function.        */
    if(aStr[0] = '!'){
      int i;
      char *ID;
      for(i=0; i<strlen(str); i++)
	ID[i] = str[i+1];
      int id = atoi(ID);
      get_history(list, id);
    }

    //  All contents of the list are printed with the "print_history" function.
    if(str[0] = '>'){
      print_history(list);
    }

    /*  Without any of the given operators as the first character, it can be concluded that the 
        string shall be a new element of the history.  This is done by establishing a pointer to a         pointer to a character constant that shall be tokenized.  Through this tokenized constant,         the original string constant is added to the history. */
    char **token = tokenize(str);
    add_history(list, str);
  }
  return 0;
}
