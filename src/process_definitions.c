/* CITS2002 Project 2018 
Names:              Alex Franzis,   Kieren Underwood
Student numbers:    21988858,       21315543 
*/

#include "bake.h"

int get_num_variables (void) {
	int i = 0;

	while (variables[i] != NULL) {
		i++;
	}

	return i;
}

int get_num_targets (void) {
	int i = 0;

	while (targets[i] != NULL) {
		i++;
	}

	return i;
}

//adds variable to variables struct pointer array
void process_variable_definition(char *firstword, char *rest_of_line) {

	int length = get_num_variables();
	variables = realloc(variables, sizeof(Variable*) * (length + 2));
	Variable *new_variable = calloc(1, sizeof(Variable));
	new_variable->var_name = firstword, 
	new_variable->var_value = rest_of_line;
	variables[length] = new_variable;
	variables[length + 1] = NULL;

}

//adds target to targets struct pointer array
void process_target_definition(char *firstword, char *rest_of_line) {

	char ** dependencies = separate_line (rest_of_line);
	char ** actions = calloc(1, sizeof(char *));
	*actions = NULL;

	int length = get_num_targets();
	targets = realloc(targets, sizeof(*targets) * (length + 2));
	Target * new_target = calloc(1, sizeof(Target));
	new_target->target = firstword;
	new_target->dependencies = dependencies;
	new_target->actions = actions;
	targets[length] = new_target;
	targets[length + 1] = NULL;

}

//adds action to a target in the targets struct pointer array
void process_action_definition(char * line) {

	char * action = strdup(line);

	int numtargets = get_num_targets();
	Target * target = targets[numtargets - 1];

	int numactions = numstrings(target->actions);

	target->actions  = realloc (target->actions, sizeof(char*) * (numactions + 2)); //this could be ther line
	
	target->actions[numactions] = action;
	target->actions[numactions + 1] = NULL; 

}

