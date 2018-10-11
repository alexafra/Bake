#include "bake.h"

/*
    fp1 raw
    fp2 final
    fp3 no hash
    fp4 variables and slashes

*/
void modifyfile(File *fp1, File *fp2)
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


    //Get rid of variables
    while(!feof(fp3)) {

        char *rawline = nextline(fp3);
    }
}
