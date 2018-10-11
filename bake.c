#include "bake.h"

//  Written by Chris.McDonald@uwa.edu.au, September 2018

#if defined(__linux__)

#endif


//  DEVELOPED IN LECTURE 9  (but here using pointers)


//  ----------------------------------------------------------------------

int main(int argc, char *argv[])
{
    if(argc > 1) {
        FILE *fp1        = fopen(argv[1], "r");

        if(fp1 == NULL) {
            perror(argv[1]);
            return 1;
        }
        
        File *fp2 = fopen("tempbake.txt","w");
        if(fp2 == NULL)
        {
            perror()
        }
        
        readandwrite(fp1, fp2);
         
        while(!feof(fp1)) {
            char *line = nextline(fp1);  // HANDLES CONTINUATION LINES

            if(line) {
                printf("%8s()\t%s\n", __func__, line);
                free(line);
            }
        }
        fclose(fp1);                     // WE OPENED IT, SO WE CLOSE IT
    }
    return 0;
}
