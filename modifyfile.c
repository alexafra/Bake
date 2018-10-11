#include "bake.h"

modifyfile(File *fp1, File *fp2)
{
    while(!feof(fp1)) {
        char *line = nextline(fp1);  // HANDLES CONTINUATION LINES
        
        //what does return and when.
        //null means end if file
        //Otherwise is a pointer that is a string

        if (line) {
        	/*
				reset loop when hash is found.

        	*/
        }


        if(line) {
            printf("%8s()\t%s\n", __func__, line);
            free(line);
        }
  
    }
}