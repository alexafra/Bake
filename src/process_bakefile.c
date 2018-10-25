#include "bake.h"
#include "variable.h"

void process_bakefile(FILE *fp) {
    bool just_processed_target = false;

    variables = (Variable **) calloc (1, sizeof(Variable*));
    *variables = NULL;

    while(!feof(fp)) {

        
        char *line = nextline(fp);  // HANDLES CONTINUATION LINES returns null at eof, returns "" at empty line
        char * firstword;
        char criticalChar;

        if (line == NULL) { //eof
            continue;
        }

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
        if (exp_line[0] == '\t' && just_processed_target == true) {
            skip_leading_space(exp_line);
            process_action_definition(exp_line);
            free (line);
            continue;
        }

        skip_leading_space(exp_line);


        firstword = getfirstword(exp_line);


        int error = 0;
        char * rest_of_line;
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
            rest_of_line = get_rest_of_line(exp_line);
            process_variable_definition(firstword, rest_of_line);
            //i think free here 
            // free (firstword);
            // free (rest_of_line);
            just_processed_target = false;

        } else if (criticalChar == ':') { // target definition
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
