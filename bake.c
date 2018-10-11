#include "bake.h"

//  Written by Chris.McDonald@uwa.edu.au, September 2018

#if defined(__linux__)
extern  char    *strdup(const char *str);
#endif


//  DEVELOPED IN LECTURE 9  (but here using pointers)


//  ----------------------------------------------------------------------

int main(int argc, char *argv[])
{
    if(argc > 1) {
        FILE *fp        = fopen(argv[1], "r");

        if(fp == NULL) {
            perror(argv[1]);
            return 1;
        }
        while(!feof(fp)) {
            char *line = nextline(fp);  // HANDLES CONTINUATION LINES

            if(line) {
                printf("%8s()\t%s\n", __func__, line);
                free(line);
            }
        }
        fclose(fp);                     // WE OPENED IT, SO WE CLOSE IT
    }
    return 0;
}
