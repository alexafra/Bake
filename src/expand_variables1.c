#include "bake.h"

find_substitution(char *name) {
	//First, find out if name is contained in our global array
	while(strcmp(name, globalarray1[i]) != 0)
		//this is not yet correct

		
}

char *name

getenv(name)

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

	char name[5] 

	while(line[i] != ')') {
		name[j] = line[i];
		i++; 
		j++;
	}
	name[j+1] = '\0';


	find_substitution(name);

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