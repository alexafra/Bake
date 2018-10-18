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

void move_back (char * line, int start, int amount, int *error) {
    int length = strlen(line);
    if (start < 0 || (amount + start) > length) {
        *error = 1;
        *line = '\0';
        return;
    } else {
        *error = 0;
    }
    
    for (int i = start; (i + amount) < (length + 1); ++i) {
        line [i] = line[i + amount];
    }
}

char * insert_string (char * line, char * word, int position, int* error) {
    int length_line = strlen(line);
    if (position < 0 || position > length_line ) {
        *error = 1;
        
        char * new_line = (char *) malloc(sizeof(char) ); //*line = '\0'; whats up here
        new_line[0] = '\0';
        return new_line;//return line failes

    } else {
        *error = 0;
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

void skip_leading_space (char *line) {
    int jump = 0;
    while (line[jump] != '\0' && (line[jump] == '\t' || line[jump] == ' ')) {
        ++jump;
    }
    int error;
    move_back (line, 0, jump, &error);
    if (error != 0) {
        line[0] = '\0';
    }

}

//assume non empty no leading space
//worried about possible errors
char * getfirstword (char * line) { 
    skip_leading_space (line);
    int length1;

    length1 = 0;
    
    printf("\n%d\n", length1);
    while ( *(line + length1) != ' ' && *(line + length1) != '\t' && *(line + length1) != ':' && *(line + length1) != '=' ) {
        ++length1;
    }


    char * word = calloc(length1 + 1, sizeof(char));

    int i;
    for (i = 0; i < length1; ++i) {
        word[i] = line[i];
    }
    word[i] = '\0';
    return word;

}

char * get_rest_of_line (char *line) {
    
    char * firstword = getfirstword (line);
    int firstwlength = strlen(firstword);

    char * rest_of_line = strdup(line);
    skip_leading_space(rest_of_line);

    int error;
    move_back (rest_of_line, 0, firstwlength, &error);
    if (error != 0) {
        rest_of_line[0] = '\0';
        return rest_of_line;
    }

    skip_leading_space(rest_of_line);
    move_back (rest_of_line, 0, 1, &error);
    if (error != 0) {
        rest_of_line[0] = '\0';
        return rest_of_line;
    }
    skip_leading_space(rest_of_line);
    return rest_of_line;
}

//stub
char * substring(char * line, int start, int end, int * error) {
    int length = strlen(line);
    char * new_line;
    if (start < 0 || end > length || end < start) {
        *error = 1;
        
        new_line = (char *) malloc(sizeof(char) ); //*line = '\0'; whats up here
        new_line[0] = '\0';
        return new_line;//return line failes
    } else {
        *error = 0;
    }

    int newlinelength = end - start;
    new_line = calloc (length + 1, sizeof(char));

    int i;
    for (i = 0; i < newlinelength; ++i) {
        new_line[i] = line[i + start];
    }
    new_line[i] = '\0';

    return new_line;

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

    char criticalchar;

    int error; 
    move_back (line, 0, lengthfword, &error);
    if (error != 0) {
        criticalchar = '\0';
    }

    skip_leading_space (line); 
    
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



