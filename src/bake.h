#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "variable.h"
#include <curl/curl.h>
#include <curl/easy.h>


//Global Functions
extern char * nextline (FILE *);
extern void process_bakefile (FILE *);
//extern char * substitute_variable (int pos, char * line, Variable * variable, int* error);

extern void trimline (char *);
extern void move_back (char *, int, int, int*);
extern char * insert_string (char *, char *, int, int*);
extern void skip_leading_space (char *);
extern char * getfirstword (char *);
extern char getcriticalchar (char *);
extern char * substring(char *, int , int, int*);
extern char * itoa (int);
extern int numberlength (int); 
//extern char * expand_variables2 (char *, char **, char ** , int*);

extern char * expand_variables(char *, Variable **);
extern char * get_special_value (char *);
extern char * get_var_value(char *, Variable **);
extern char * substitute_variable(int, char *, Variable ** );


extern void process_variable_definition(char *, char *);
extern void process_target_definition(char *firstword, char *rest_of_line, int *no_variables, int *variable_length);

//Global Variables
extern Variable ** variables;

//Global Constants
#define CH_CONTINUATION         '\\'

//Global Variables
#if defined(__linux__)
	extern  char    *strdup(const char *str);
#endif

