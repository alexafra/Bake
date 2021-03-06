/* CITS2002 Project 2018 
Names:              Alex Franzis,   Kieren Underwood
Student numbers:    21988858,       21315543 
*/


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
#include <time.h>
#include <getopt.h>


//Global Functions
extern char * nextline (FILE *);
extern void internal_representation (FILE *);
//extern char * substitute_variable (int pos, char * line, Variable * variable, int* error);


//string modifier methods
extern void trimline (char *);
extern void move_back (char *, int, int, int*);
extern char * insert_string (char *, char *, int, int*);
extern void skip_leading_space (char *);
extern char * getfirstword (char *);
extern char getcriticalchar (char *);
extern char * substring(char *, int , int, int*);
extern char * get_rest_of_line (char *);
extern char * itoa (int);
extern int numberlength (int); 
extern bool starts_with_char (char *, char);
extern int numstrings (char **);
extern char ** separate_line (char *);

//expand variable methods
extern char * expand_variables(char *, Variable **);
extern char * get_special_value (char *);
extern char * get_var_value(char *, Variable **);
extern char * substitute_variable(int, char *, Variable ** );

//process variable/action/target methods
extern void process_variable_definition(char *, char *);
extern void process_target_definition(char *, char *);
extern void process_action_definition(char * );


extern void print_bakefile (void);

//checking dependency and executing actions methods
extern int is_dependency_target (char * );
extern bool is_dependency_url (char * );
extern bool is_dependency_file (char * );
extern void execute_actions (int, bool, bool, bool);
extern bool is_target_older (char *, char *);
extern bool process_target (int, bool, bool, bool ) ;
extern void process_bake ( bool, bool, bool );
extern bool is_url_accessible (char *dependency);
extern bool startswith (char *, char* );
extern time_t get_modification_date (char *);
extern bool is_older (time_t, time_t);

//key global variable helper methods
int get_num_variables (void);
int get_num_targets (void);

//Target line
extern bool check_if_url(char *);

//Global Variables
extern Variable ** variables;
extern Target ** targets;

//Global Constants
#define CH_CONTINUATION         '\\'

//Global Variables
#if defined(__linux__)
	extern  char    *strdup(const char *str);
#endif

