#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include <time.h>
//#include <linux/limits.h>
#include "bake.h"

// char * get_directory() {
// 	//THIS WORKS!!!!!!

// 	char *cwd = malloc(PATH_MAX);
// 	if(getcwd(cwd, PATH_MAX * sizeof(cwd)) != NULL) {
// 		return cwd;
// 	} else {
// 		perror("getcwd() error");
// 		exit(EXIT_FAILURE); //Do you even do this here?
// 	}
// }

// bool is_in_current_dir(char *targetname) {
	
// 	//THIS WORKS
// 	struct stat buf;
// 	return (stat(targetname, &buf) == 0);  
// }

// time_t get_url_time(char *url) {
// 	//curl -s -v --head http://foo.com/bar/baz.pdf 2>&1 | grep '^< Last-Modified:'
// 	FILE *header;
// 	char *filename = "time.txt";

// 	header = fopen("time.txt", "w");
// 	if (header == NULL) {
// 		printf("Failed to create file for storage\n");
// 		exit(EXIT_FAILURE);
// 	} else { 
// 	execl("curl -o ", filename, "-s -v --head ", url, "2>&1 | grep '^< Last-Modified:'", NULL);
// 	}

// 	char modification_date[100];
// 	fgets(modification_date, 100, header);

// 	printf("%s\n", modification_date);

// 	fclose(header);
// }

bool startswith(char *start_string, char *string) {

    //THIS WORKS
    //Arbitrary function for checking start of strings
    if(0 == strncmp(start_string, string, strlen(start_string)) ) {
        return true;
    } else {
        return false;   
    }
     
}   

char * geturldetails(char * url ) {
	// FILE * header;
	// header = fopen("details.txt", "w");
	// char *filename = "details.txt";

	FILE *header;
	char *filename = "time.txt";

    char * shell = getenv("SHELL");
    if (shell == NULL) {
        shell = "/bin/bash";
    }
	//Open a file to send header to
	header = fopen("time.txt", "w");
	
	//Check if the file fails to open
	if (header == NULL) {
		printf("Failed to create file for storage\n");

		exit(EXIT_FAILURE);
	} else { 
        int err = 0;

        char *shell_command = "curl -o ";
        int shell_st_length = strlen(shell_command);
        shell_command = insert_string(shell_command, filename, shell_st_length, &err);
        shell_st_length = strlen(shell_command);
        shell_command = insert_string(shell_command, " -s -v --head ", shell_st_length, &err);
        shell_st_length = strlen(shell_command);
        shell_command = insert_string(shell_command, url, shell_st_length, &err);

		//run the curl operation	
		system(shell_command);
        fclose(header);
	}
		//check the file to see where "< Last-Modified:" line is
    header = fopen("time.txt", "r");
	while(!feof(header)) {
    	char *line = nextline(header);

        if (line == NULL) { //eof
            continue;
        }
        printf("%s\n", line);
    	char *dateline = "Last-Modified:";

    	if(startswith(dateline, line)) {
            printf("\n\nHERE\n\n");
    		
    		//Copy this line into another char
    		int err;
    		move_back(line, 0, strlen(dateline), &err);

    		if(err !=0) {
    			perror("Move back method failed");
    		} else {
    			return line;
    		}
    	} else{
    		free(line);
    	}
    }	


    return "";	
} 

	
char *nextline(FILE *fp)
{
    char        *fullline       = NULL;
    int         fulllength      = 0;

    char        thisline[BUFSIZ];
    int         thislength      = 0;

    while(fgets(thisline, sizeof thisline, fp) != NULL) {
        trimline(thisline);                     // REMOVE TRAILING \n or \r
        thislength      = strlen(thisline);
        fulllength      += thislength;

       // printf("%8s()\t%s\n", __func__, thisline); 

        if(fullline == NULL) {
            fullline    = strdup(thisline);
        }
        else {
            fullline     = realloc(fullline, fulllength+1);
            strcat(fullline, thisline);
        }
		//  SHOULD WE CONTINUE READING, OR IS THE LINE COMPLETE?
        if(fullline[ fulllength-1 ] != CH_CONTINUATION) {
            break;
        }
        fullline[ --fulllength ] = '\0';        // REMOVE TRAILING '\'
    }
    return fullline;
}

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

//moves part of the string backwards from a certain position by a certain amount 
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

//inserts string at a certain position into another string
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

//skips all leading space in a string
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

//returns the rest of the string after the first word and the critical char
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

//returns a substring from a given start to an end point
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

//gets the critical char - the first non-whitespace after the first word
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

// returns the number of digits in a number
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

//converts an integer into a character string
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

//returns how many strings are in a array of strings
int numstrings (char ** stringlist) {
    int i = 0;
    while (stringlist[i] != NULL) {
        ++i;
    }
    return i;
}

//separates a string into an array of the words in the string
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

//checks if a string starts with a given character
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

//adds a given character to the start of the string
void add_char_to_start (char * string, char character) {
    int length = strlen(string);
    string = realloc(string, sizeof(char) * (length + 2));
    for (int i = length - 1; i >= 0; --i) {
        string[i + 1] = string[i]; 
    }
    string[0] = character;
}



// }


// bool url_exists(char *url) {

// 	CURL *curl;
// 	CURLcode isurl;

// 	curl = curl_easy_init();

// 	if(curl) {
// 		curl_easy_setopt(curl, CURLOPT_URL, url);

// 		//Dont send to stdout
// 		curl_easy_setopt(curl, CURLOPT_NOBODY, 1);

// 		//Send request
// 		isurl = curl_easy_perform(curl);
// 		curl_easy_cleanup(curl);
// 	}

// 	return (isurl == CURLE_OK); //? 1 : 0;
// }

	

// bool check_if_url(char *dependency) {
	
// 	//THIS WORKS
// 	//Check to see whether the dependency looks like a url
// 	char *url1 = "file://";
// 	char *url2 = "http://";
// 	char *url3 = "https://";

// 	//If yes
// 	if(startswith(url1, dependency) || startswith(url2, dependency) || startswith(url3, dependency)) {
	
// 		return true;

// 	} else {
// 	//If not a url
// 	return false;
// 	}
// }

// time_t get_modification_date(char *filename) {
	
// 	//THIS COMPILES BUT MAY NOT WORK... NOT TESTED
// 	time_t filetime;
// 	struct stat attrib;
// 	if(stat(filename, &attrib) != 0) {
// 		perror("Stat fail");
	
// 	} else {

// 	filetime = attrib.st_mtime;
// 	return filetime;
// 	}
// }

// bool is_more_recent(time_t time1, time_t time2) {
	
// 	//THIS HAS PROBLEMS WITH 'makes integer from pointer without a cast'

// 	//compare the times here...

// 	if(difftime(time1, time2) > 0) {
// 		return true;
// 	}
// 	return false;
// }


// time_t geturltime (char *url) {
	
// 	time_t timer;
// 	time(&timer);

// 	return timer;
// }

// bool is_older (time_t time1, time_t time2) {
	
// 	//Compare modification dates here

// 	if(difftime(time1, time2) < 0) {
// 		return true;
// 	}
// 	return false;
// }

int main(int argc, char *argv[]) {

	geturldetails("http://teaching.csse.uwa.edu.au/units/CITS2002/project/dependency-5m");
	exit(EXIT_SUCCESS);

}

