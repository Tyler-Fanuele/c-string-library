#ifndef my_string_h
#define my_string_h
#include <stdlib.h>
#include <stdio.h>
#include "status.h"
#include "bool.h"

typedef void *MY_STRING; // void for my_string

struct my_string
{
    int capacity;
    int size;
    char *string;
};
typedef struct my_string My_string;

// default constructor
MY_STRING string_init_default(void);

// cstring constructor
MY_STRING string_init(const char *c_string);

// destructor
void string_destroy(MY_STRING *pString);

// Gives one string the deep copy contentes of the other
Status string_assignment(MY_STRING *pLeft, MY_STRING Right);

// returns capacity
int string_get_capacity(MY_STRING hMy_string);

// returns size
int string_get_size(MY_STRING hMy_string);

// returns the string contained in the string
char *string_c_str(MY_STRING hMy_string);

// returns the char at the index given
char *string_at(MY_STRING hMy_string, int index);

// pushed back a char to the string
Status string_push_back(MY_STRING hMy_string, char item);

//  returns if the string is empty or not
Bool string_empty(MY_STRING hMy_string);

// concatinates the 2 strings
Status string_concat(MY_STRING hResult, MY_STRING hAppend);

// pops off the last char
Status string_pop_back(MY_STRING hMy_string);

// compares strings
int string_compare(MY_STRING hLeft_string, MY_STRING hRight_string);

// finds string in string 
int string_find(MY_STRING hLString, MY_STRING hRString);

// basically an extraction operator for the string 
Status string_extraction(MY_STRING hMy_string, FILE *fp);

// basically an insertion operator for the string
Status string_insertion(MY_STRING hMy_string, FILE *fp);

#endif // (my_string_h) //  leaks -atExit -- ./string
