#include "bake.h"

void trimline(char *line)
{
    while(*line != '\0') {      //  loop until we reach the end of line
        if( *line == '\n' || *line == '\r' ) {
            *line = '\0';       // overwrite with null-byte
            break;              // leave the loop early
        }
        ++line;                 // iterate through characters on line
    }
}

void remove_hash_line (char *raw, char *nocomments) {

	
    int i = 0;
	while (raw[i] != '\0' && raw[i] != '#') {
		nocomments[i] = raw[i];
		i++;
	}
    nocomments[i] = '\0';
}
