#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

//Global Functions
extern char * nextline (FILE *);
extern void process_bakefile (FILE *);

extern void trimline (char *);
extern void move_back (char *, int, int, int*);
extern char * insert_string (char *, char *, int, int*);
extern void skip_leading_space (char *);
extern char * getfirstword (char *);
extern char getcriticalchar (char *);
extern char * substring(char *, int , int, int*);
extern char * expand_variables(char * line, int * no_variables, char ** var_name_list, char ** var_value_list, int *);

extern void init_variables (char **, char **, int *, int *);
extern void process_variable_definition(char *, char *, int *, int *);
extern void process_target_definition(char *firstword, char *rest_of_line, int *no_variables, int *variable_length);

//Global Variables
extern char * name[];
extern char * substitution[];

//Global Constants
#define CH_CONTINUATION         '\\'

//Global Variables
#if defined(__linux__)
	extern  char    *strdup(const char *str);
#endif

