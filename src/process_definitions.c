#include "bake.h"
//process_variable_defintion
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


void process_variable_definition(char *firstword, char *rest_of_line) {

	int length = get_num_variables();
	variables = realloc(variables, sizeof(Variable*) * (length + 2));
	Variable *new_variable = calloc(1, sizeof(Variable));
	new_variable->var_name = firstword, 
	new_variable->var_value = rest_of_line;
	variables[length] = new_variable;
	variables[length + 1] = NULL;

}

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


//are we freeing up the line
//add to last target
//add to end of action
void process_action_definition(char * line) {

	char * action = strdup(line);

	int numtargets = get_num_targets();
	Target * target = targets[numtargets - 1];

	int numactions = numstrings(target->actions);

	//this is a strange line
	target->actions  = realloc (target->actions, sizeof(char*) * (numactions + 2)); //this could be ther line
	
	target->actions[numactions] = action;
	target->actions[numactions + 1] = NULL; 

}

