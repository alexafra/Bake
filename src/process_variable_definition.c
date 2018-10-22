#include "bake.h"

int get_variables_length() {
	for int i = 0;

	while (variables[i] != '\0') {
		i++
	}

	return i;
}

void process_variable_definition(char *firstword, char *rest_of_line) {

	int length = get_variables_length();
	realloc(length + 1, sizeof(Variable));
	variables[length]->var_name = firstword;
	variables[length]->var_value = rest_of_line;
}

