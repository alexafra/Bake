#include "bake.h"
//process_variable_defintion
int get_variables_length() {
	int i = 0;

	while (variables[i] != NULL) {
		i++;
	}

	return i;
}

void process_variable_definition(char *firstword, char *rest_of_line) {

	int length = get_variables_length();
	variables = realloc(variables, sizeof(Variable*) * (length + 2));
	Variable *new_variable = calloc(1, sizeof(Variable));
	new_variable->var_name = firstword, 
	new_variable->var_value = rest_of_line;
	variables[length] = new_variable;
	variables[length + 1] = NULL;

}



//I think this wont have problems.
// void free_variable (int pos) {

// 	free(variables[pos]->var_name);
// 	free(variables[pos]->var_value);

// 	free (variables[pos]);

// }
