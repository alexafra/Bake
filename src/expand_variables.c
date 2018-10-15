/*
	how exactly can we allocate and reallocate global variable memory in static memory?

*/

/*
	How are variables identified?
*/



//assume $() is a must
//without braces its an error
//Assume () only braces allowed
//error if $() is empty
//assume space int the brackets throws an error. $(var ) or $( var )
//assume $ (var) throws an error
// what if var name is one of the saved names ie PPID = Value

	//does $ define a variable
	//does $(...) define a variable
	//what if you see $word
	//what if you see $ word

	// 1. find the variables using the dollar sign.
	// 2. store variable names
	// 3. find variable values
	// 4. delete variables in line
	// 5. add vairbale values 

	// $(var$(var2))
	//can you use other brackets
	//can you use wildcards

//line is a non empty, no leading space string.
void expand_variables (char * line, int * no_variables, char ** var_name_list, char ** var_value_list, int no_vars) {

	int length = strlen(line);
	for (int i = 0; i < length; ++i ) { //doesnt hit null byte
		int var_name_length = - 1
		char * var_name;

		if (line[i] == '$') {
			var_name_length = get_var_length (line, i , length)
			var_name = get_var_name(line, i, var_name_length);
			var_value = get_var_value (var_name, var_naem_list, var_value_list, no_vars);
			

			move_back (line, i, var_name_length + 3, length); //$() 3 extra characters
			line = insert_string(line, var_value, i);
			
			length = strlen(line);

			free(var_name);
			free (var_value);
		}
	}
	return line;
}

//Gets the var length and validates the variable
int get_var_length (char * line, int var_start, int length) {
	int i = var_start;
	if (length < i + 4) {
		printf("need a minimum length four for a variable") //should go to an error
		exit(EXIT_FAILURE);
	}
	if (line[i] != '$') {
		printf("$ not at start of variable name") //should go to an error
		exit(EXIT_FAILURE);
	}
	if (line [i + 1] != '(') {
		printf("$ not followed by (") //should go to an error
		exit(EXIT_FAILURE);
	}
	i = var_start + 2;
	while (line[i] != ')') {
		if (line[i] == '\0') {
			printf("variable does not have close bracket )") //should go to an error
			exit(EXIT_FAILURE);
		}
		if (line[i] == '\t' || line[i] == ' ') {
			printf("spaces not allowed in variable reference") //should go to an error
			exit(EXIT_FAILURE);
		}
		++i
	}
	//at this point line[i] = ')'
	int var_length = i = var_start_po - 3;
	return var_length
}

char * get_var_name(line *, int var_start, int var_name_length) {
	char * var_name = calloc (var_name_length + 1, sizeof(char));
	int i = var_start + 2;
	for (i, i < i + var_name_length; ++i) {
		var_name[i - var_start - 2] = line[i]; 
	}
	var_name[i] = '\0';
	return var_name;

}	

char * get_var_value (char * var_name, char ** var_name_list, char ** var_value_list, int no_vars) {
	for (int i = 0; i < no_vars; ++i) {
		char * saved_variable_name = *(var_name_list + i);
		if (strcmp(var_name, saved_variable_name) == 0)  {
			return *(var_value_list + i);
		}
	}
	char *  env_value = getenv(var_name);
	if (env_value == NULL) {
		env_value = calloc(1, sizeof(char));
		*env_value = '\0';
	}
	return env_value;
}

char * get_rest_of_line (char *line, int firstwordlength) {
	char * rest_of_line = strdup(line);
	int length = strlen(line)
	move_back (rest_of_line, 0, firstwordlength, length);
	skip_leading_space(rest_of_line);
	return rest_of_line;
}
	
