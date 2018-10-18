#include "bake.h"
#include "variable.h"
/*
    What about:

    target
    Whitespace
    action
    action
    whitespace 
    action

    ??
*/

/*
    ............. spaces may be ok in variables ..........
    ............. not inbetween $() ..........

    https://www.eskimo.com/~scs/cclass/int/sx8.html

    
    add our two variable methods to the heap.
    they will be destroyed after this method.
    We will end each pointer array with a \0 to determine the end.

    We dont know the length of the array
    immutable strings
    immutable pointers

    char ** var_names;
    char ** var_values;

    malloc realloc calloc free

    One variable definition per line?

    target and actions are the only things that should be global.

    //place $(PID), $(PPID), $(PWD), and $(RAND) into var_name_list and var_value_list
*/




void process_bakefile(FILE *fp) {
    bool just_processed_target = false;
    //bool first_target_line = true;


   //I ASKED CHRIS MACDONALD AND HE SAID WE WOULD BE BETTER OFF USING A STRUCTURE TO STORE THE NAME & VALUEs. 
   //YOU WOULD realloc EACH TIME YOU NEEDED TO STORE A NEW VALUE/NAME, WHICH MEANS YOU WOULDN"T DEAL WITH THE PROBLEM OF STARTING WITH ONLY 10 SPACES

    //begin with space for 10 variables.
    Variable *variable[5];    //insert the 4 variables
    //insert the null pointer

    variable[0][0].var_name = "VAR1";
    variable[0][0].var_value = "test1";
    variable[1][0].var_name = "VAR2";
    variable[1][0].var_value = "test2";
    variable[2][0].var_name = "VAR3";
    variable[2][0].var_value = "test3";
    variable[3][0].var_name = "VAR4";
    variable[3][0].var_value = "test4";
    variable[4] = NULL;




    /*
        so we want to create a list of structs.
        Each struct contains a var_name and a var_value.
        maybe use a hash.
        the end of the list is a \0.

        Can variabels be overriden
        Can key variables be overriden
    */


    
    //*no_variables = 0;
    //*variable_length = 10;
    
    //init_variables (var_name_list, var_value_list, no_variables, variable_length);
    

    while(!feof(fp)) {
        char *line = nextline(fp);  // HANDLES CONTINUATION LINES
        char * firstword;
        char criticalChar;

        //The line is a comment line
        if(line[0] == '#') {
            free (line);
            continue;
        }

        //This line is an action
        if (line[0] == '\t' && just_processed_target == true) {
            //Add action to target

            free (line);
            continue;
        }

        skip_leading_space(line);

        //The line is all whitespace
        if (strlen(line) == 0) {
            free (line);
            just_processed_target = false; //Not sure if this is correct.
            continue;
        }

        int error;
        //expand any varibles in the line
        char * exp_line = expand_variables(line, variable, &error);
        if (error != 0) {
            //do some error stuff
        }
        

        int length = strlen(exp_line);

        firstword = getfirstword(exp_line);

        int firstwordlength = strlen(firstword);

        
        char * rest_of_line = substring(exp_line , firstwordlength, length, &error);
        if (error != 0) {
            //do some error stuff
        } 
        //start and end

        //Gets the first non whitespace character after the first word.
        criticalChar = getcriticalchar(exp_line);

        if (criticalChar == '=') { //variable definition
            //process_variable_definition(firstword, rest_of_line, no_variables, variable_length);
            //i think free here 
            free (firstword);
            free (rest_of_line);
            just_processed_target = false;

        } else if (criticalChar == ':') { // target definition
            //process_target_definition(firstword, rest_of_line, no_variables, variable_length);
            //process_target_line(firstword, rest_of_line, no_variables, variable_length);
            //i think free here
            free (firstword);
            free (rest_of_line);
            just_processed_target = true;
            //first_target_line = false;
            
        } else { //Line is unrecognised
            printf("%s\n%s\n", "unrecognised line.", line);
            free (firstword);
            free (rest_of_line);
            free (line);
            exit (EXIT_FAILURE);
        }




        free (line);
        free(exp_line);
    }
}

/*
while not end of file
get the next full/continuation line
expand any variables on that line

categorise the expanded line:
  if it begins with '#', ignore this line and loop to read the next line

  if the line begins with a tab **and we've just processed a new target**, add this action to that target

  skip any leading spaces or tabs

  if we've reached the end of line, then the whole line was a blank line, so ignore it like a comment line

  now find the first 'word' on the line, collecting its characters until we find a space, tab, =, or :

  if we found '=', call   process_variable_definition(word, rest_of_line),  ideally in a different file

  if we found ':', call   process_target_definition(word, rest_of_line), ideally in a different file

  otherwise the line is unrecognised, print any error message and exit

fclose file

*/
