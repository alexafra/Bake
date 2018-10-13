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
    if(raw[0] != '#'){
        nocomments[i] = '\n';
        i++;
    }
    nocomments[i] = '\0';

}

void move_back (char * line, int start, int amount, int length) {
    for (int i = start; i <= length - amount; ++i) {
        line [i] = line[i + jump];
    }
}

char * insert_string (char * line, char * word, int position) {
    int length_line = strlen(line);
    int length_word = strlen(word);
    int new_length - length_line + length_word + 1;

    char * new_line = malloc(sizeof(char) * new_length);

    int i = 0;
    for (i = 0; i < position; ++i) {
        *(new_line + i) = *(line + i);
    }
    for (i; i < position + length_word; ++i) {
        *(new_line + i) = *(word + i - position);
    }
    for (i; i < new_length - 1; ++i) {
        *(new_line + i) = *(line + i - length_word);
    }
    *(new_line + i) = '\0';
    return new_line;
}

void skip_leading_space (char *line) {
    int length = strlen(line);
    int jump = 0;
    while (line[jump] != '\0' && (line[jump] == '\t' || line[jump] != ' ')) {
        ++jump;
    }
    for (int i = 0, i <= length - jump; ++i) {
        line [i] = line[i + jump];
    }
}

    //Pretty sure this works... I tested it with a number of ways in a txt file
    //May still have some bugs though



