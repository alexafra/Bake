/* CITS2002 Project 2018 
Names:              Alex Franzis,   Kieren Underwood
Student numbers:    21988858,       21315543 
*/

#include "bake.h"
#include "variable.h"

void internal_representation(FILE *fp) {
    bool just_processed_target = false;

    variables = (Variable **) calloc (1, sizeof(Variable*));
    *variables = NULL;

    while(!feof(fp)) {
        
        char *line = nextline(fp);  
        char * firstword;
        char criticalChar;

        if (line == NULL) { //eof
            continue;
        }

        if (strlen(line) == 0) {
            free (line);
            continue;
        }

        //The line is a comment line
        if(line[0] == '#') { 
            free (line);
            continue;
        }

        char * exp_line = expand_variables(line, variables);
        if (exp_line == NULL) {
            perror("unrecognised line.");
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
        char * rest_of_line;

        //Gets the first non whitespace character after the first word.
        criticalChar = getcriticalchar(exp_line);

        if (criticalChar == '=') { //variable definition
            rest_of_line = get_rest_of_line(exp_line);
            process_variable_definition(firstword, rest_of_line);
            just_processed_target = false;

        } else if (criticalChar == ':') { // target definition
            rest_of_line = get_rest_of_line(exp_line);
            process_target_definition(firstword, rest_of_line);
            
            just_processed_target = true;\
            
        } else { //Line is unrecognised, printing expanded version or not??
            perror("unrecognised line.");
            free (line);
            exit (EXIT_FAILURE);
        }
        free (line);
    }
}
