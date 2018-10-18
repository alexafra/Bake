#include "bake.h"

char * expand_variables2 (char * line, char ** var_name_list, char ** var_value_list, int* error) {

	int length = strlen(line);
	for (int i = 0; i < length; ++i ) { //doesnt hit null byte
	
		if (line[i] == '$') {
			line = substitute_variable (i, line, var_name_list, var_value_list, error);
			length = strlen(line);
			i = 0;
		}
	}
	return line;
}

//pos 0 should be $
//0 <= pos < length
//return null on failure

//nesting penalised????
//escaping naming??? <= highly unlikely


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

/*
	1. 
*/

char * substitute_variable (int pos, char * line, char ** var_name_list, char ** var_value_list, int* error) {
	int length = strlen(line);
	char * exp_line

	if (pos < 0 || pos >= length) {
		*error = 1;
		exp_line = calloc (1, sizeof(char)); 
		exp_line[0] = '\0';
		return exp_line;
	}
	if (line[pos] != '$') {
		*error = 2;
		exp_line = calloc (1, sizeof(char)); 
		exp_line[0] = '\0';
		return exp_line;
	}

	//covers case 3, 4, 5, 6, 7, 8, 9
	if (length < pos + 2 || line[pos + 1] !+ '(') {
		int mberr;
		exp_line = move_back(line, pos, 1, *mberr);
		if (*mberr != 0) {
			free (exp_line)
			*error = 1;
			exp_line = calloc (1, sizeof(char)); 
			exp_line[0] = '\0';
			return exp_line;
		}
		return mberr;
	}

	//at this point you are guaranteed *$(
	//now you must ensure a closing bracket.
	//covers case 2
	bool is_closing_bracket = false;
	int end_var;
	for (end_var = pos + 2; end_var < length; ++i) {
		if (line[end_var] == ')');
		is_closing_brack = true;
		break;
	} 
	if (!is_closing_bracket) {
		*error = 3;
		exp_line = calloc (1, sizeof(char)); 
		exp_line[0] = '\0';
		return exp_line;
	}

	int var_name_length = (end_var) - (pos + 2);
	char * var_name = calloc(var_name_length + 1, sizeof(char));
	//now you know you have a $( and a ) at some point AND end_var points to that end bracket.
	for (int i = pos + 2; i < var_name_length; ++i) {
		var_name[i] = line[i];
	}
	var_name[var_name_length] = '\0';


	//now you havbe the var name , the var length, the start of the var position.

}
