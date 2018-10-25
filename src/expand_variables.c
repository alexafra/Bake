/* CITS2002 Project 2018 
Names:              Alex Franzis,   Kieren Underwood
Student numbers:    21988858,       21315543 
*/

#include "bake.h"
#include "variable.h"


char * get_special_value (char * var_name) {
	//Set up our special values/names
	char *special_variable[5];
	special_variable[0] = "PID";
	special_variable[1] = "PPID";
	special_variable[2] = "PWD";
	special_variable[3] = "RAND";
	special_variable[4] = "\0";

	char *special_value = NULL;

	int i = 0;
	//while tests first character in first word
	while (**(special_variable + i) != '\0') {
		if (0 == strcmp(special_variable[i], var_name)) {
			if (i == 0) {
				special_value = itoa(getpid());
			} else if (i == 1) {
				special_value = itoa(getppid());
			} else if (i == 2) {
				char * buff = calloc(BUFSIZ, sizeof(char)); //what should buffer size be
				special_value = getcwd(buff, BUFSIZ);
			} else if (i == 3) {
				special_value = itoa(rand());
			}
		}
		++i;
	}
	return special_value;
}

char * get_var_value(char * var_name, Variable ** variables) {
	
	int i = 0;
	char * var_value = NULL;

	char *special_value = get_special_value(var_name);
	//Check to see if it is one of our special cases
	if (special_value != NULL) { 
		var_value = special_value;
		return var_value;
	}
	
	//currently var_value is null.
	while (variables[i] != NULL) {
		if (0 == strcmp(variables[i]->var_name, var_name)) {
			if (var_value != NULL) {
				free (var_value);
			}
			var_value = strdup (variables[i]->var_value); //wont ever return NULL, at worst ""
		}
		++i;
	}
	if (var_value != NULL) {
		return var_value; 
	}

	char * env_value = getenv(var_name);
	//If the var is an environmental variable, set it to this
	if (env_value != NULL) {
		var_value = strdup(env_value);
	}
	//Case where we cannot find value, so put empty string
	if (var_value == NULL) {
		var_value = (char*) calloc(1, sizeof(char));
		var_value[0] = '\0';
	}
	return var_value;
}


char * substitute_variable (int pos, char * line, Variable ** variables) {
	int length = strlen(line);
	char * exp_line = NULL;
	int error;

	if (pos < 0 || pos >= length) {
		return exp_line;
	}
	if (line[pos] != '$') {
		return exp_line;
	}
	exp_line = strdup(line);

	//covers case 3, 4, 5, 6, 7, 8, 9
	if (length < pos + 2 || line[pos + 1] != '(') {


		move_back(exp_line, pos, 1, &error);
		if (error != 0) {
			free (exp_line);
			exp_line = NULL;
			return exp_line;
		}
		return exp_line;
	}

	//at this point you are guaranteed *$(
	//now you must ensure a closing bracket.
	//covers case 2
	bool is_closing_bracket = false;
	int end_var;
	for (end_var = pos + 2; end_var < length; ++end_var) {
		if (exp_line[end_var] == ')') {
			is_closing_bracket = true;
			break;
		}
	} 
	if (!is_closing_bracket) {
		free (exp_line);
		exp_line = NULL;
		return exp_line;
	}

	int var_name_length = (end_var) - (pos + 2);
	char var_name[var_name_length + 1];
	//now you know you have a $( and a ) at some point AND end_var points to that end bracket.
	for (int i = 0; i < var_name_length; ++i) {
		var_name[i] = line[i + pos + 2];
	}
	var_name[var_name_length] = '\0';

	//delete the variable $(var_name) bit
	move_back (exp_line, pos, var_name_length + 3, &error);
	if (error != 0) {
		free (exp_line);
		exp_line = NULL;
		return exp_line;
	}

	//now you need to get the variable, and insert it into the pos position
	char * var_value = get_var_value(var_name, variables); 

	exp_line = insert_string (exp_line, var_value, pos, &error);
	if (error != 0) {
		free (exp_line);
		exp_line = NULL;
		return exp_line;
	}

	free(var_value);
	return exp_line;

}

char * expand_variables (char * line, Variable ** variables) {

	int length = strlen(line);
	char * subs_line = line;

	for (int i = 0; i < length; ++i ) { //doesnt hit null byte
		
		if (subs_line[i] == '$') {
			
			subs_line = substitute_variable (i, subs_line, variables);
			 //there is an issue with memory

			if (subs_line != NULL) {
				length = strlen(subs_line);
				i = -1;
			} else {
				return subs_line;
			}
		}

	}
	return subs_line;
}


