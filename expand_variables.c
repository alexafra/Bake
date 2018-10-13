#include "bake.h"

expand_variables(char *line) {
	
	int i = 0;

	while(line[i] != '$' && line[i+1] != '(') {
		i++;
	}

	
	//search until we find $()
	//temporarily store the string between ()
	//if find that... then search our global array for variable substition
	//if it finds it, then substitute it it
	//if not, check for special cases... and substitute in
	//if not, check for environmental process subsitutions, and use these

	//if all these fail, enter the empty string

	//return to the process_bakefile function 	
}