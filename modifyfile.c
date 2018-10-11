#include "bake.h"

modifyfile(File *fp1, File *fp2)
{
    FILE *fp3 = fopen("back_no_hash.txt","w");

    if(fp3 == NULL)
    {
        fclose(fp1);
        fclose(fp2);
        fclose(fp3);
        return 1;
    }

    char bufferLine[BUFSIZ];
    while ( fgets(bufferLine, sizeof bufferLine, fp1) != NULL) {
        //is fgets getting the whole line
        //is fputs putting in the whole line
        char no_hash[BUFSIZ];

        remove_hash_line(bufferline, no_hash);

        int out = fputs(no_hash, fp3);

        //Not sure
        if (out == EOF) {
            fclose(fp1);
            fclose(fp2);
            fclose(fp3);
            exit(EXIT_FAILURE);
        }   
    }  



    while(!feof(fp3)) {

        char *rawline = nextline(fp3);  // HANDLES CONTINUATION LINES
        char nocommentline[strlen(rawline)]


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