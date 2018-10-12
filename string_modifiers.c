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
    //Remove everything in the line past the #. If starts with #, remove line totally.
    int i = 0;
    while (raw[i] != '\0' && raw[i] != '#') {
        nocomments[i] = raw[i];
        i++;
    }
    if(raw[0] == '#'){
        //Enter nothing into char, and move to the lext line
    }
    else if(raw[i] == '#'){
        //Add newline character
        nocomments[i] = '\n';
        i++;
    }
    nocomments[i] = '\0';

    //Pretty sure this works... I tested it with a number of ways in a txt file
    //May still have some bugs though
}



