#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  /* Returns true if a character is a white space character (0 for false, 1 for true) */
  if(c == ' ' || c == '\t' && c != '\0')
    return 1;
  return 0;
}

int non_space_char(char c)
{
  /* Returns true if a character is NOT a white space character (0 for false, 1 for true) */
  if( !(space_char(c)) )
    return 1;
  return 0;
}

char *token_start(char *str)
{
  /* Returns a pointer to the first non-space character in an input token */
  while(space_char(*str) || (*str) == '\0' )
    str++;
  return str;
}

char *token_terminator(char *token)
{
  /* Returns a pointer to the first space character at the end of a token */
  while(non_space_char(*token) || (*token) != '\0')
    token++;
  return token;
}

int count_tokens(char *str)
{
  /* Counts tokens by detecting non-space characters */
  int t = 0;
  int in = 0;

  /* "in" is set to 0 unless it is in a string.  Otherwise, the "t" value increments by 1.*/
  // In other words, the token-counting value increases by one unless it is in a word.
  while(*str++ != EOF){
    if(space_char(*str))
      in = 0;
    else if(non_space_char(*str)){
      in = 1;
      t +=1;
    }
  }

  return t;
}



char *copy_str(char *inStr, short len)
{
  /* Allocates space to a new string constant and copies the original string */
  /* to the new, 0-terminated string, via pointers */
  char *aStr = (char *)malloc((len+1) * sizeof(char));

  // Old string is copied to new string and the new string is returned.
  while(*aStr++ = *inStr++)
    ;

  aStr[len] = '\0';

  return aStr;
}			     

char **tokenize(char *str){

  /* Allocates space to a pointer to a pointer to a char that shall be used as a token*/
  int num_tokens = count_tokens(str);
  char **token = (char**)malloc(num_tokens);
  int i = 0;
  while( (*str++) ){
    char *start = token_start(str);
    char *terminate = token_terminator(start);
    int len = (terminate - start);

    /* Establishes a token by copying the string via a pointer to the first char and terminating          with the last char.*/
    token[i] = copy_str(start, len);
    str = token_start(terminate);
    printf("Tokenized word %d: %s\n", (i+1), token[i]);
  }
  return token;
}

/* Prints tokens by accessing the pointer to the pointer to the tokens and printing the number
   value in the user's history proceeded by the token.  Process is carried out with a loop.*/
void print_tokens(char **tokens){
  int a = 0;
  while( (*tokens++) )
    printf("%d, %s", (++a), *tokens);

}

/* Takes in a pointer to a pointer to the first character of a token and frees the space 
   occupied by each token. The space occupied by every other token is freed via a loop.  Once the 
   loop has ended, the last token is freed. */
void free_tokens(char **tokens){
  int i = 0;
  while( *(tokens)++ ) {
    free(*(tokens + i));
  }
  free(tokens);
}  
