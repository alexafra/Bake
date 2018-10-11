#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Global Functions
extern char * nextline (FILE *);
extern void trimline (char *);

//Global Constants
#define CH_CONTINUATION         '\\'

//Global Variables
#if defined(__linux__)
	extern  char    *strdup(const char *str);
#endif


//Bingo Bongo
