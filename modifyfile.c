#include "bake.h"

/*
    fp1 raw
    fp2 final
    fp3 no hash
    fp4 variables and slashes

*/
void modifyfile(FILE *fpRaw, FILE *fpFin)
{

//I"M PRETTY SURE THAT AT THE END OF THIS PROCESS WE NEED TO DELETE THE FILES THAT WE HAVE CREATED
//OTHERWISE WHEN WE RUN THE PROGRAM MORE THAN TWICE, YOU ARE GOING TO BE OPENING "bake_no_hash" or "bake_var" FILES THAT ALREADY EXIST!

//First, remove all #s from file

    FILE *fpNoHash = fopen("bake_no_hash.txt","w");

    if(fpHash == NULL)
    {
        fclose(fpRaw);
        fclose(fpFin);
        exit(EXIT_FAILURE);
    }

    char bufferLine[BUFSIZ];
    while ( fgets(bufferLine, sizeof bufferLine, fpRaw) != NULL) {      
        //is fgets getting the whole line
        //is fputs putting in the whole line
        //Not sure about EOF
        //Suppose we can have an empty string in fputs

        char no_hash[BUFSIZ];
        remove_hash_line(bufferLine, no_hash);
        int out = fputs(no_hash, fpHash);

        if (out == EOF) {
            fclose(fpRaw);
            fclose(fpFin);
            fclose(fpHash);
            exit(EXIT_FAILURE);
        }   
    }  


    //Next, create new file, joining lines separated by '\' and subsituting variable definitions

    FILE *fpNoVar = fopen("bake_var.txt","w");

    if(fpNoVar == NULL)
    {
        fclose(fpRaw);
        fclose(fpFin);
        fclose(fpNoHash);
        exit(EXIT_FAILURE);
    }

    variable_sub(fpNoHash, fpNoVar);







    // char bufferLine2[BUFSIZ];

    // //Next line will remove "\" and correct lines, then "variable_sub" will substitute in the definitions
    // while(fgets(bufferline2, sizeof bufferLine2, nextline(fpHash)) != NULL){

    //     fputs(variable_sub(), fpVar)
   
    // }
    //     //RIGHT NOW STILL TRYING TO FIGURE OUT WHAT TO DO WITH THE VARIABLE REDEFINITIONS... I THINK I SHOULD RETURN A WHOLE FILE POINTER



    //Get rid of variables
    // while(!feof(fp3)) {

    //     char *rawline = nextline(fp3);
    // }
}
