/*
	how exactly can we allocate and reallocate global variable memory in static memory?

*/

/*
	How are variables identified?
*/

//line is a non empty, no leading space sgring.
void expand_variables (char * line, int * no_variables, char ** var_name_list, char ** var_value_list) {

	int length = strlen(line);
	for (int i = 0; i < length; ++i ) { //doesnt hit null byte
		int var_name_length = - 1
		char * var_name;

		if (line[i] == '$') {
			var_name_length = size_of_var(line, i); //iinclude %()
			var_name = get_var_name(line, i, var_name_length);
			var_value = get_var_value (var_name);

			move_back (line, i, var_name_length, length);
			line = insert_string (line, var_value, i);
			length = strlen(line);
		}
	}
	return line;
}

	// 1. find the variables using the dollar sign.
	// 2. store variable names
	// 3. find variable values
	// 4. delete variables in line
	// 5. add vairbale values 

	// $(var$(var2))
	//can you use other brackets
	//can you use wildcards



int size_of_var (char * line, int var_start_po) {

}