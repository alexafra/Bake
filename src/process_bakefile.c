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
    // int k = 0;
    // int kk = 0;

    while(!feof(fp)) {
        // ++k;
        // if (k > 155) {
        //     kk = 1;
        // }
        
        char *line = nextline(fp);  // HANDLES CONTINUATION LINES
        char * firstword;
        char criticalChar;


        if (strlen(line) == 0) {
            free (line);
            continue;
        } //were not exiting the file.

        //The line is a comment line
        if(line[0] == '#') { //this fao;s
            free (line);
            continue;
        }

        

        char * exp_line = expand_variables(line, variables);
        if (exp_line == NULL) {
            printf("%s\n%s\n", "unrecognised line.", line);
            free (exp_line);
            exit (EXIT_FAILURE);
        }

        //This line is an action
        if (line[0] == '\t' && just_processed_target == true) {
            skip_leading_space(exp_line);
            process_action_definition(exp_line);
            free (line);
            continue;
        }

        skip_leading_space(exp_line);

        int length = strlen(exp_line);

        firstword = getfirstword(exp_line);

        int firstwordlength = strlen(firstword);

        int error = 0;
        char * rest_of_line = substring(exp_line , firstwordlength, length, &error); 
        if (error != 0) {
            // free (firstword);
            // free (rest_of_line);
            free (line);
            exit (EXIT_FAILURE);
        } 
        //start and end

        //Gets the first non whitespace character after the first word.
        criticalChar = getcriticalchar(exp_line);

        if (criticalChar == '=') { //variable definition
            free(rest_of_line);
            rest_of_line = get_rest_of_line(exp_line);
            process_variable_definition(firstword, rest_of_line);
            //i think free here 
            // free (firstword);
            // free (rest_of_line);
            just_processed_target = false;

        } else if (criticalChar == ':') { // target definition
            free(rest_of_line);
            rest_of_line = get_rest_of_line(exp_line);
            process_target_definition(firstword, rest_of_line);
            
            // free (firstword);
            // free (rest_of_line);
            just_processed_target = true;
            //first_target_line = false;
            
        } else { //Line is unrecognised, printing expanded version or not??
            printf("%s\n%s\n", "unrecognised line.", line);
            // free (firstword);
            // free (rest_of_line);
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
