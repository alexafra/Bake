#include "bake.h"

fill_in (char *raw, char *nocomments) {
	length = strlen(rawline);
	
	while (raw[i] != '\0' && raw[i] != '#') {
		nocomments[i] = raw[i];
		i++
	}


}


modifyfile(File *fp1, File *fp2)
{
    while(!feof(fp1)) {
        char *rawline = nextline(fp1);  // HANDLES CONTINUATION LINES
        char nocommentline[] = strlen(rawline);


        //char *nocommentline
        
        //what does return and when.
        //null means end if file
        //Otherwise is a pointer that is a string

        if (line) {
        	
        	/*
				1. reset loop when hash is found.

				2. 

        	*/
        }


        if(line) {
            printf("%8s()\t%s\n", __func__, line);
            free(line);
        }
  
    }
}