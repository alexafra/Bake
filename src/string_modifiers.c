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
char * insert_string (char * line, char * word, int position) {
    int length_line = strlen(line);
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
    free (line);
    return new_line;
}

//Consider all types of space perhaps not just space and tab.
//skip the leading space
void skip_leading_space (char *line) {
    int jump = 0;
    while (line[jump] != '\0' && (line[jump] == '\t' || line[jump] == ' ')) {
        ++jump;
    }
    move_back (line, jump, jump);
}

//assume non empty no leading space
char * getfirstword (char * line) { 
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

char * substring(char * line, int start, int end);

//assume non empty no leading space
//must be string
char getcriticalchar (char * line) {
    char * firstword = getfirstword (line);
    int lengthfword = strlen(firstword);
    free (firstword);

    char * editedline = calloc(1, sizeof(line));
    strcpy (editedline, line);

    move_back (editedline, lengthfword, lengthfword );
    skip_leading_space (editedline);
    char criticalchar = editedline[0];

    free (editedline);
    return criticalchar;

}

    //Pretty sure this works... I tested it with a number of ways in a txt file
    //May still have some bugs though



