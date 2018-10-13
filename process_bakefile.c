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
void process_bakefile(FILE *fp) {
    bool just_processed_target = false;
    //Set environemnt and special cases into variable arrays.
    set_var_exp();

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
            just_processed_target = false;
            continue;
        }

        //expand any varibles in the line
        expand_variables(line);

        firstword = getfirstword(line);

        //Gets the first non whitespace character after the first word.
        criticalChar = getcriticalChar(line);

        if (criticalChar == '=') { //variable definition
            process_variable_definition(word, rest_of_line);
            just_processed_target = false;

        } else if (criticalChar == ':') { // target definition
            process_target_definitionb(word, rest_of_line);
            just_processed_target = true;
            
        } else { //Line is unrecognised
            printf("%s\n%s\n", "unrecognised line.", line);
            free (line);
            exit (EXIT_FAILURE);
        }




        free (line);
    }
}


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