#include "bake.h"
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
    bool first_target_line = true;

    //begin with space for 10 variables.
    char ** var_name_list = calloc (10, sizeof (char *));
    char ** var_value_list = calloc (10, sizeof (char *) );
    int * no_variables = calloc (1, sizeof (int *));
    int * variable_length = calloc (1, sizeof (int *));
    
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

        //expand any varibles in the line
        line = expand_variables(line, no_variables, var_name_list, var_value_list);
        int length = strlen(line);

        firstword = getfirstword(line);
        int firstwordlength = strlen(firstword);
        char * rest_of_line = substring(line, firstwordlength, length); //start and end

        //Gets the first non whitespace character after the first word.
        criticalChar = getcriticalchar(line);

        if (criticalChar == '=') { //variable definition
            process_variable_definition(firstword, rest_of_line, no_variables, variable_length);
            //i think free here 
            free (firstword);
            free (rest_of_line);
            just_processed_target = false;

        } else if (criticalChar == ':') { // target definition
            process_target_definition(firstword, rest_of_line, no_variables, variable_length);
            //process_target_line(firstword, rest_of_line, no_variables, variable_length);
            //i think free here
            free (firstword);
            free (rest_of_line);
            just_processed_target = true;
            first_target_line = false;
            
        } else { //Line is unrecognised
            printf("%s\n%s\n", "unrecognised line.", line);
            free (firstword);
            free (rest_of_line);
            free (line);
            exit (EXIT_FAILURE);
        }




        free (line);
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