
#include "bake.h"

//there cant be an equal sign in the dependencies

//trim line of carriage return or next line character, replacing with null
void trimline(char *line)
{
    while(*line != '\0') {      // loop until we reach the end of line
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
    int length;

    length = 0;
    //printf("\n1\n");
    //printf("\n%d\n", length1);
    while ( *(line + length) != ' ' && *(line + length) != '\t' && *(line + length) != ':' && *(line + length) != '='  && *(line + length) != '\0') {
        ++length;
    }


    char * word = calloc(length + 1, sizeof(char));

    int i;
    for (i = 0; i < length; ++i) {
        word[i] = line[i];
    }
    word[i] = '\0';
    return word;

}

//overshooting
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
    char * line_dup = strdup(line);
    skip_leading_space (line_dup);
    char * firstword = getfirstword (line_dup);
    int lengthfword = strlen(firstword);
    

    char criticalchar = '\0';

    int error = 0; 
    move_back (line_dup, 0, lengthfword, &error);
    if (error != 0) {
        criticalchar = '\0';
    }

    skip_leading_space (line_dup); 
    
    if (strlen(line_dup) > 0) {
        criticalchar = line_dup[0];
    } else {
        //no critical char what to do?
        criticalchar = '\0';
    }
    //could be empty
    
    free (firstword);
    free (line_dup);
    return criticalchar;

}

int numberlength (int value) {
    if (value == 0) {
        return 1;
    }
    int numsize = 0;
    int power = 10;
    int remainder;

    while (value != 0) {
        remainder = value % power;
        value = value - remainder;
        power = power * 10;
        ++numsize;
    }
    return numsize;
}


char * itoa (int value) {
    int remainder;
    
    

    int numsize = numberlength(value);

    char * numberstring = calloc(numsize + 1, sizeof(char));

    char digit;
    for (int i = 0; i < numsize; ++i) {
        remainder = value % 10;
        
        digit = '0' + remainder;
        numberstring[numsize - i - 1] = digit;

        
        value = value - remainder;
        value = value / 10;
    }
    numberstring[numsize] = '\0';
    return numberstring;
}

int numstrings (char ** stringlist) {
    int i = 0;
    while (stringlist[i] != NULL) {
        ++i;
    }
    return i;
}

char ** separate_line (char * line) {
    char ** wordlist = calloc(1, sizeof(char *));
    *wordlist = NULL;

    char * word = getfirstword(line);
    int fwlength = strlen(word);
    int fulllength = strlen(line);
    int error = 0;
    int i = 0;

    while (0 != strcmp(word, "")) {
        wordlist = realloc(wordlist, sizeof(char*) * (i + 2));
        *(wordlist + i) = word;
        *(wordlist + i + 1) = NULL;
        line = substring(line, fwlength, fulllength, &error);
        if (error != 0) {
            //something
        }

        skip_leading_space(line);
        word = getfirstword(line);
        fwlength  = strlen(word);
        fulllength = strlen(line);
        ++i;
    }
    return wordlist;
}

bool starts_with_char (char * string, char character) {
    skip_leading_space(string);
    if (strlen(string) > 0) {
        if (string[0] == character) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }

}

void add_char_to_start (char * string, char character) {
    int length = strlen(string);
    string = realloc(string, sizeof(char) * (length + 2));
    for (int i = length - 1; i >= 0; --i) {
        string[i + 1] = string[i]; 
    }
    string[0] = character;
}

void add_char_to_string_list (char ** stringlist, char character) {
    int num_strings = numstrings(stringlist);
    for (int i = 0; i < num_strings; ++i) {
        if (stringlist[i][0] != '@' && stringlist[i][0] != '-') {
            add_char_to_start(stringlist[i], character);
        } else if (stringlist[i][0] == '@' && character == '@') {
            continue;
        } else if (stringlist[i][0] == '@' && character == '-') {
            stringlist[i][0] = '-';
        } else if (stringlist[i][0] == '-' && character == '@') {
            stringlist[i][0] = '@';
        } else if (stringlist[i][0] == '-' && character == '-') {
            continue;
        }
    }
}

    //Pretty sure this works... I tested it with a number of ways in a txt file
    //May still have some bugs though



