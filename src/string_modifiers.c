#include "bake.h"

//trim line of carriage return or next line character, replacing with null
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

//slide part of the string back a certain amount
//amount ahead to slide into start $ position
//Could have invalid inputs
//Be careful how you interpret length
void move_back (char * line, int start, int amount) {
    int length = strlen(line);
    for (int i = start; (i + amount) < (length + 1); ++i) {
        line [i] = line[i + amount];
    }
}

//insert a string at a point
//Will delete the old line.
//what to do if faulty position
char * insert_string (char * line, char * word, int position) {
    int length_line = strlen(line);
    if (position < 0 || position > length_line ) {
        char * err_line = (char *) calloc(1, sizeof(char));
        err_line[0] = '\0';
        //
        //MUST PRINT ERROR
        //
        return err_line;
    }
    
    int length_word = strlen(word);
    int new_length = length_line + length_word + 1;

    char * new_line = (char *) malloc(sizeof(char) * new_length);

    int i;
    for (i = 0; i < position; ++i) {
        *(new_line + i) = *(line + i);
    }
    for (; i < position + length_word; ++i) {
        *(new_line + i) = *(word + i - position);
    }
    for (; i < new_length - 1; ++i) {
        *(new_line + i) = *(line + i - length_word);
    }
    *(new_line + i) = '\0';
    return new_line;
}

//Consider all types of space perhaps not just space and tab.
//skip the leading space
void skip_leading_space (char *line) {
    int jump = 0;
    while (line[jump] != '\0' && (line[jump] == '\t' || line[jump] == ' ')) {
        ++jump;
    }
    move_back (line, 0, jump);
}

//assume non empty no leading space
char * getfirstword (char * line) { 
    skip_leading_space (line);
    int length = 0;
    while ( *(line + length) != ' ' && *(line + length) != '\t' && *(line + length) != ':' && *(line + length) != '=' ) {
        ++length;
    }
    ++length;
    char * word = calloc(length, sizeof(char));

    int i;
    for (i = 0; i < length - 1; ++i) {
        word[i] = line[i];
    }
    word[i] = '\0';
    return word;

}

char * get_rest_of_line (char *line, int firstwordlength) {
    char * rest_of_line = strdup(line);
    move_back (rest_of_line, 0, firstwordlength);
    skip_leading_space(rest_of_line);
    return rest_of_line;
}

//stub
char * substring(char * line, int start, int end) {
    char * stubstring = calloc (1, sizeof(char));
    return stubstring;

}

//assume non empty no leading space
//must be string
//what to do if no critical char?
char getcriticalchar (char * line) {
    line = strdup(line);
    skip_leading_space (line);
    char * firstword = getfirstword (line);
    int lengthfword = strlen(firstword);
    free (firstword);

    move_back (line, 0, lengthfword);
    skip_leading_space (line); 

    char criticalchar;
    if (strlen(line) > 0) {
        criticalchar = line[0];
    } else {
        //no critical char what to do?
        criticalchar = '\0';
    }
    //could be empty
    

    free (line);
    return criticalchar;

}

    //Pretty sure this works... I tested it with a number of ways in a txt file
    //May still have some bugs though



