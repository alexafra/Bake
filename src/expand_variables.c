#include "bake.h"
#include "variable.h"


/*
Can you override old variables
can you override the 4 key variables

cant override old variables
can override new variables.

*/

//pos 0 should be $
//0 <= pos < length
//return null on failure

//nesting penalised????
//escaping naming??? <= highly unlikely

char * get_special_value (char * var_name) {
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

/*
	Override strategy from least to most important/
	1.set var_value to env_values
	2. set var_value to saved variables
	3. set var_value to special variable

	Each one will override the next if valid.
*/

//issues with freeing memory here.
char * get_var_value(char * var_name, Variable ** variables) {
	
	int i = 0;
	char * var_value = NULL;

	char *special_value = get_special_value(var_name);
	if (special_value != NULL) { //have an issue freeing var_value.
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
	if (env_value != NULL) {
		var_value = strdup(env_value);
	}

	if (var_value == NULL) {
		var_value = (char*) calloc(1, sizeof(char));
		var_value[0] = '\0';
	}
	return var_value;
}

//return NULL if error?
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

	//now you havbe the var name , the var length, the start of the var position.

	//delete the variable $(var_name) bit
	move_back (exp_line, pos, var_name_length + 3, &error);
	if (error != 0) {
		free (exp_line);
		exp_line = NULL;
		return exp_line;
	}

	//now you need to get the variable, and insert it into the pos position
	char * var_value = get_var_value(var_name, variables); //this will have a return value

	exp_line = insert_string (exp_line, var_value, pos, &error);
	if (error != 0) {
		free (exp_line);
		exp_line = NULL;
		return exp_line;
	}

	free(var_value);
	return exp_line;

}

// #1. $( ) any space inside becomes an unrecognisable variable <= simply wont match a varible name.
// #2. $( this is undefined and throws an error.
// #3. other braces are not acceptable
// #4. dollar sign is invisible
// #5. $ () means $is invisible and carry on '$ ()' => ' ()' 
// #6. a$b => ab, 
// #7. a$ b => a b, 
// #8. $a => a
// #9. abc$ => abc

//err 1, is index of array is out of bounds.
//err 2, is defined expected input not given ie. line[pos] != '$'
//err 3, invalid string? ie. $(hello no end of brace

//will return null on failure

char * expand_variables (char * line, Variable ** variables) {

	int length = strlen(line);
	char * subs_line = line;

	for (int i = 0; i < length; ++i ) { //doesnt hit null byte
		
		if (subs_line[i] == '$') {
			
			subs_line = substitute_variable (i, subs_line, variables);
			 //there is an issue with memory

			if (subs_line != NULL) {
				length = strlen(subs_line);
				i = 0;
			} else {
				return subs_line;
			}
		}

	}
	return subs_line;
}


//this is a toughie, time to work out your structures.
/*
	Your not making function calls

	1. check environment
	2. check variables
	3. check defined variables
*/

