#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//Global Functions
extern char * nextline (FILE *);
extern void trimline (char *);
extern void modifyfile (FILE *, FILE *);
extern void skup_leading_space (char *, char *, int);
extern void move_back (char *, int, int, int);
extern void skip_leading_space (char *);
//Global Constants
#define CH_CONTINUATION         '\\'

//Global Variables
#if defined(__linux__)
	extern  char    *strdup(const char *str);
#endif

