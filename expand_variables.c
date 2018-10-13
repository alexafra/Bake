#include "bake.h"

expand_variables(char *line) {
	
	int i = 0;
	int j = 0;
	//Search until you find $(
	while(line[i] != '$' && line[i+1] != '(') {
		if(line[i] == '\0') {
			return;
		}
		i++;
	}
	i = i + 2;

	char *name;
	while(line[i] != ')') {
		name[j] = line[i];
	}

	do something here about exchanging the name

	i = 0;

	while (line[i] != '$' && line[i+1] != '(') {
		if(line[i] == '\0') {
			return;
		}
		i++
	}
	free(name);
	expand_variables();

	//search until we find $()
	//temporarily store the string between ()
	//if find that... then search our global array for variable substition
	//if it finds it, then substitute it it
	//if not, check for special cases... and substitute in
	//if not, check for environmental process subsitutions, and use these

	//if all these fail, enter the empty string

	//repeat all this for the possible next variable substitution
	//return to the process_bakefile function 	
}